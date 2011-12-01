/*
 * Copyright (c) 2011, Christian Lange
 * (chlange) <chlange@htwg-konstanz.de> <Christian_Lange@hotmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Christian Lange nor the names of its
 *       contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL CHRISTIAN LANGE BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "answer.h"
#include "ui_answer.h"

void Answer::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

Answer::Answer(QWidget *parent, QString file, int round, Player *players, int playerNr) :
        QDialog(parent), ui(new Ui::Answer), round(round), playerNr(playerNr), result(""), keyLock(false), fileString(file), doubleJeopardy(false), currentPlayer(), dj(NULL)
{
    ui->setupUi(this);

    this->players = players;

    this->hideButtons();
    this->music = Phonon::createPlayer(Phonon::NoCategory, Phonon::MediaSource("sound/jeopardy.wav"));
    this->music->play();
}

Answer::~Answer()
{
    delete ui;
    delete this->music;
    if(this->dj != NULL)
        delete this->dj;
}

int Answer::getPoints()
{
    return this->points;
}

QString Answer::getResult()
{
    return this->result;
}

/* Read in round file and set text of label to answer */
void Answer::setAnswer(int category, int points)
{
    this->points = points;
    QString answer;

    if(this->getAnswer(category, points, &answer) != true)
        done(0);

    QRegExp comment("##.+##");
    QRegExp imgTag("^[[]img[]]");
    QRegExp alignLeftTag("[[]l[]]");
    QRegExp doubleJeopardyTag("[[]dj[]]");

    answer.remove(comment);

    if(answer.contains(alignLeftTag))
        this->processAlign(&answer);

    if(answer.contains(doubleJeopardyTag))
        this->processDoubleJeopardy(&answer);

    if(answer.contains(imgTag))
        this->processImg(&answer);
    else
        this->processText(&answer);
}

void Answer::processAlign(QString *answer)
{
    QRegExp alignLeftTag("[[]l[]]");
    answer->remove(alignLeftTag);
    ui->answer->setAlignment(Qt::AlignLeft);
}

void Answer::processDoubleJeopardy(QString *answer)
{
    QRegExp doubleJeopardyTag("[[]dj[]]");
    answer->remove(doubleJeopardyTag);
    this->openDoubleJeopardy();
}

void Answer::processImg(QString *answer)
{
    QRegExp imgTag("^[[]img[]]");
    answer->remove(imgTag);

    answer->prepend(QString("/answers/%1/").arg(this->round));
    answer->prepend(QDir::currentPath());

    ui->answer->setPixmap(*answer);
}

void Answer::processText(QString *answer)
{
    int count = answer->count("<br>");
    ui->answer->setFont(this->meassureFontSize(count));
    ui->answer->setText(*answer);
}

void Answer::keyPressEvent(QKeyEvent *event)
{
    int key;

    if(this->keyListenerIsLocked() == true)
        return;

    key = event->key();

    if(key == this->players[0].getKey())
        processKeypress(0);

    else if(this->playerNr >= 2 && key == this->players[1].getKey())
        processKeypress(1);

    else if(this->playerNr >= 3 && key == this->players[2].getKey())
        processKeypress(2);

    else if(this->playerNr >= 4 && key == this->players[3].getKey())
        processKeypress(3);

    else if(this->playerNr >= 5 && key == this->players[4].getKey())
        processKeypress(4);

    else if(this->playerNr >= 6 && key == this->players[5].getKey())
        processKeypress(5);

}

void Answer::processKeypress(int player)
{
    this->lockKeyListener();

    this->currentPlayer = this->players[player];
    ui->currentPlayer->setText(this->currentPlayer.getName());

    this->showButtons();
}

bool Answer::keyListenerIsLocked()
{
    return this->keyLock;
}

void Answer::lockKeyListener()
{
    this->keyLock = true;
}

void Answer::releaseKeyListener()
{
    this->keyLock = false;
}

void Answer::showButtons()
{
    /* Show by color and name which player should ask */
    QString color = QString("QLabel { background-color : %1; }").arg(this->currentPlayer.getColor());
    ui->currentPlayer->setStyleSheet(color);

    ui->buttonCancel->setVisible(true);
    ui->buttonRight->setVisible(true);
    ui->buttonWrong->setVisible(true);
    ui->currentPlayer->setVisible(true);
}

void Answer::hideButtons()
{
    ui->buttonCancel->setVisible(false);
    ui->buttonRight->setVisible(false);
    ui->buttonWrong->setVisible(false);
    ui->currentPlayer->setVisible(false);
}

QFont Answer::meassureFontSize(int count)
{
    QFont font;

    if(count > MANY_LINE_BREAKS)
        font.setPointSize(7);
    else if(count > MORE_LINE_BREAKS)
        font.setPointSize(15);
    else if(count > SOME_LINE_BREAKS)
        font.setPointSize(20);
    else
        font.setPointSize(28);

    return font;
}

QString Answer::getRoundFile()
{
    return this->fileString;
}

int Answer::getCategoryLine(int category)
{
    int categoryLine;

    categoryLine = NUMBER_MAX_CATEGORIES * (category - 1) + 1;

    return categoryLine;
}

/* Open round file and get appropriate answer */
bool Answer::getAnswer(int category, int points, QString *answer)
{
    int categoryFileLine;
    QString currentLine;
    QString delimiter;

    QFile file(this->getRoundFile());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open round file"));
        return false;
    }

    /* Calculate round answer line */
    categoryFileLine = this->getCategoryLine(category);
    QTextStream in(&file);

    /* Step to appropriate category section */
    for(int lineNr = 0; lineNr != categoryFileLine; lineNr++)
        currentLine = in.readLine();

    /* Prepare answer and delimiter variable (Points: Answer)*/
    delimiter = QString("%1:").arg(points);

    for(int i = 0; i < points / 100; i++)
        currentLine = in.readLine();

    /* Remove preceding points */
    *answer = currentLine;

    answer->remove(0, ANSWER_POINTS_INDICATOR_LENGTH);
    
    return true;
}

void Answer::openDoubleJeopardy()
{
    this->dj = new DoubleJeopardy(this, points / 2, points * 2, this->players, this->playerNr);
    dj->init();
    dj->show();
    this->currentPlayerId = dj->getPlayer();
    this->points = dj->getPoints();
    this->doubleJeopardy = true;

    this->processKeypress(this->currentPlayerId);
}

void Answer::on_buttonEnd_clicked()
{
    this->releaseKeyListener();

    QMessageBox msgBox;
    msgBox.setText("Are you sure?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Abort);
    msgBox.setDefaultButton(QMessageBox::Abort);
    int ret = msgBox.exec();

    if(ret == QMessageBox::Yes)
    {
        this->music->stop();
        done(NO_WINNER);
    }
}

/* Stop music and return winner */
void Answer::on_buttonRight_clicked()
{
    QString resultTmp;
    resultTmp = QString("%1").arg(this->currentPlayer.getId());
    resultTmp.append(WON);
    this->result.append(resultTmp);
    this->releaseKeyListener();
    this->music->stop();
    done(this->currentPlayer.getId() - OFFSET);
}

void Answer::on_buttonWrong_clicked()
{
    QString resultTmp;
    resultTmp = QString("%1").arg(this->currentPlayer.getId());
    resultTmp.append(LOST);
    this->result.append(resultTmp);
    this->hideButtons();
    this->releaseKeyListener();
    if(this->doubleJeopardy)
    {
        this->music->stop();
        done(NO_WINNER);
    }
}

void Answer::on_buttonCancel_clicked()
{
    this->hideButtons();
    this->releaseKeyListener();
}
