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
#include <QKeyEvent>
#include <QMessageBox>
#include <QSound>
#include <QDebug>
#include <QFile>
#include <QDir>

Answer::~Answer()
{
    delete ui;
}

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

Answer::Answer(QWidget *parent, QString file, int round, Player *players[NUMBER_PLAYERS]) :
        QDialog(parent), ui(new Ui::Answer), round(round), result(""), keyLock(false), fileString(file)
{
    ui->setupUi(this);
    this->insertPlayers(players);
    this->hideButtons();
    this->music = Phonon::createPlayer(Phonon::NoCategory, Phonon::MediaSource("sound/jeopardy.wav"));
    this->music->play();
}

void Answer::keyPressEvent(QKeyEvent *event)
{
    int key;

    if(this->keyListenerIsLocked() == true)
        return;

    key= event->key();
    if(key == Qt::Key_A)
    {
        processKeypress(0);
    }
    else if(key == Qt::Key_G)
    {
        processKeypress(1);
    }
    else if(key == Qt::Key_K)
    {
        processKeypress(2);
    }
}

void Answer::processKeypress(int player)
{
    this->lockKeyListener();

    this->currentPlayer = this->players[player];
    ui->currentPlayer->setText(this->currentPlayer->getName());

    this->showButtons();
}

/* Point to players - Sort of workaround */
void Answer::insertPlayers(Player *players[NUMBER_PLAYERS])
{
    for(int i = 0; i < NUMBER_PLAYERS; i++)
        this->players[i] = players[i];
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
    QString color = QString("QLabel { background-color : %1; }").arg(this->currentPlayer->getColor());
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

void Answer::on_buttonEnd_clicked()
{
    this->releaseKeyListener();

    QMessageBox msgBox;
    msgBox.setText("Are you sure?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Abort);
    msgBox.setDefaultButton(QMessageBox::Abort);
    int ret = msgBox.exec();

    if(ret == YES)
    {
        this->music->stop();
        done(-1);
    }
}

/* Stop music and return winner */
void Answer::on_buttonRight_clicked()
{
    QString resultTmp;
    resultTmp = QString("%1").arg(this->currentPlayer->getId());
    resultTmp.append(WON);
    this->result.append(resultTmp);
    this->releaseKeyListener();
    this->music->stop();
    done(this->currentPlayer->getId() - OFFSET);
}

void Answer::on_buttonWrong_clicked()
{
    QString resultTmp;
    resultTmp = QString("%1").arg(this->currentPlayer->getId());
    resultTmp.append(LOST);
    this->result.append(resultTmp);
    this->currentPlayer = NOT_DEFINED;
    this->hideButtons();
    this->releaseKeyListener();
}

void Answer::on_buttonCancel_clicked()
{
    this->currentPlayer = NOT_DEFINED;
    this->hideButtons();
    this->releaseKeyListener();
}

QString Answer::getResult()
{
    return this->result;
}

/* Read in round file and set text of label to answer */
void Answer::setAnswer(int category, int points)
{
    QString answer;

    this->getAnswer(category, points, &answer);

    QRegExp comment("##.+##");
    QRegExp imgTag("^[[]img[]]");
    QRegExp alignLeftTag("[[]l[]]");

    answer.remove(comment);

    if(answer.contains(alignLeftTag))
    {
        answer.remove(alignLeftTag);
        ui->answer->setAlignment(Qt::AlignLeft);
    }

    if(answer.contains(imgTag))
    {
        answer.remove(imgTag);

        answer.prepend(QString("/answers/%1/").arg(this->round));
        answer.prepend(QDir::currentPath());

        ui->answer->setPixmap(answer);
    }
    else
    {
        int count = answer.count("<br>");
        ui->answer->setFont(this->meassureFontSize(count));
        ui->answer->setText(answer);
    }
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

/* Open round file and get appropriate answer */
void Answer::getAnswer(int category, int points, QString *answer)
{
    int categoryFileLine;
    QString currentLine;
    QString delimiter;

    QFile file(this->getRoundFile());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open round file"));
        return;
    }

    /* Calculate round answer line */
    categoryFileLine = this->getCategoryLine(category);

    QTextStream in(&file);

    /* Step to appropriate category section */
    for(int lineNr = 0; lineNr != categoryFileLine; lineNr++)
        currentLine = in.readLine();

    /* Prepare answer and delimiter variable (Points: Answer)*/
    delimiter = QString("%1:").arg(points);

    /* Step to answer */
    while(!currentLine.startsWith(delimiter))
        currentLine = in.readLine();

    /* Remove preceding points */
    *answer = currentLine;

    answer->remove(0, ANSWER_POINTS_INDICATOR_LENGTH);
}

QString Answer::getRoundFile()
{
    return this->fileString;
}

int Answer::getCategoryLine(int category)
{
    int categoryLine;

    categoryLine = (category == 1) ? 1 : ((category - OFFSET) * NUMBER_CATEGORIES) + category;

    return categoryLine;
}
