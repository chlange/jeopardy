/*
 * Copyright (c) 2011-2012, Christian Lange
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

Answer::Answer(QWidget *parent, QString file, int round, Player *players, int playerNr, bool sound, int currentPlayerId) :
        QDialog(parent), ui(new Ui::Answer), round(round), playerNr(playerNr),points(0), currentPlayerId(currentPlayerId),
        winner(NO_WINNER), keyLock(false), sound(sound), doubleJeopardy(false), result(), fileString(file), players(players), currentPlayer(), dj(NULL)
{
    ui->setupUi(this);

    this->time = new QTime();
    this->time->start();
    timer = new QTimer();
    timer->setInterval(1*1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start();

    this->hideButtons();
    ui->graphicsView->setVisible(false);
    ui->videoPlayer->setVisible(false);

    if(sound)
        this->music = Phonon::createPlayer(Phonon::NoCategory, Phonon::MediaSource("sound/jeopardy.wav"));

    this->isVideo = false;
}

Answer::~Answer()
{
    delete ui;
    if(this->sound)
        delete this->music;

    if(this->dj != NULL)
        delete this->dj;

    delete this->time;
    delete timer;
}

void Answer::updateTime()
{
    int seconds = 31 - this->time->elapsed() / 1000;
    if(seconds >= 0)
        ui->time->setText(QString("%1").arg(seconds, 2));
    else
        ui->time->setText(QString("Ended..."));
}

int Answer::getWinner()
{
    return this->winner;
}

int Answer::getPoints()
{
    return this->points;
}

QString Answer::getResult()
{
    return this->result;
}

void Answer::setAnswer(int category, int points)
{
    this->points = points;
    QString answer;

    if(this->getAnswer(category, points, &answer) != true)
    {
        this->winner = NO_WINNER;
        done(0);
    }

    QRegExp comment("##.+##");
    QRegExp imgTag("^[[]img[]]");
    QRegExp videoTag("^[[]video[]]");
    QRegExp soundTag("^[[]sound[]]");
    QRegExp alignLeftTag("[[]l[]]");
    QRegExp doubleJeopardyTag("[[]dj[]]");
    QRegExp lineBreakTag("[[]b[]]");
    QRegExp noEscape("[[]nE[]]");
    QRegExp space("[[]s[]]");

    answer.remove(comment);
    answer.replace(lineBreakTag,"<br>");
    answer.replace(space, "&nbsp;");

    if(answer.contains(alignLeftTag))
        this->processAlign(&answer);

    if(answer.contains(noEscape))
    {
        answer.remove(noEscape);
        ui->answer->setTextFormat(Qt::PlainText);
    }

    if(answer.contains(doubleJeopardyTag))
        this->processDoubleJeopardy(&answer);

    if(answer.contains(imgTag))
    {
        if(this->sound)
            this->music->play();

        answer.remove(imgTag);
        answer = answer.trimmed();
        this->processImg(&answer);
    }
    else if(answer.contains(soundTag))
    {
        answer.remove(soundTag);
        answer = answer.trimmed();
        this->processSound(&answer);
    }
    else if(answer.contains(videoTag))
    {
        answer.remove(videoTag);
        answer = answer.trimmed();
        this->processVideo(&answer);
    }
    else
    {
        if(this->sound)
            this->music->play();

        this->processText(&answer);
    }
}

void Answer::processAlign(QString *answer)
{
    QRegExp alignLeftTag("[[]l[]]");
    answer->remove(alignLeftTag);
    ui->answer->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
}

void Answer::processDoubleJeopardy(QString *answer)
{
    QRegExp doubleJeopardyTag("[[]dj[]]");
    answer->remove(doubleJeopardyTag);
    this->openDoubleJeopardy();
}

void Answer::processImg(QString *answer)
{
    this->prependDir(answer);

    ui->graphicsView->setVisible(true);

    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPixmap pic(*answer);

    if(pic.height() > ui->graphicsView->height())
        pic = pic.scaledToHeight(ui->graphicsView->height() - 10);

    if(pic.width() > ui->graphicsView->width())
        pic = pic.scaledToWidth(ui->graphicsView->width() - 10);

    scene->addPixmap(pic);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void Answer::processSound(QString *answer)
{
    this->prependDir(answer);

    this->sound = true;
    this->music = Phonon::createPlayer(Phonon::NoCategory, Phonon::MediaSource(*answer));
    this->music->play();
    QTimer::singleShot(30000, this->music, SLOT(stop()));
}

void Answer::processVideo(QString *answer)
{
    this->isVideo = true;
    this->prependDir(answer);

    ui->videoPlayer->setVisible(true);
    ui->videoPlayer->play(*answer);
    QTimer::singleShot(30000, ui->videoPlayer, SLOT(stop()));
}

void Answer::processText(QString *answer)
{
    int count = answer->count("<br>");
    ui->answer->setFont(this->measureFontSize(count));
    ui->answer->setText(*answer);
}

void Answer::prependDir(QString *answer)
{
    answer->prepend(QString("/answers/%1/").arg(this->round));
    answer->prepend(QDir::currentPath());
}

void Answer::keyPressEvent(QKeyEvent *event)
{
    int key;
    int player = -1;

    if(this->sound && event->key() == Qt::Key_Shift)
    {
        if(this->isVideo == true)
        {
            ui->videoPlayer->stop();
            ui->videoPlayer->seek(0);
            QTimer::singleShot(100, ui->videoPlayer, SLOT(play()));
            QTimer::singleShot(30000, ui->videoPlayer, SLOT(stop()));
        }
        else
        {
            this->music->stop();
            QTimer::singleShot(100, this->music, SLOT(play()));
            QTimer::singleShot(30000, this->music, SLOT(stop()));
        }

        this->time->start();
    }

    if(event->key() == Qt::Key_Escape)
        this->on_buttonEnd_clicked();

    if(this->keyListenerIsLocked() == true)
        return;
    else
        this->lockKeyListener();

    key = event->key();

    for(int i = 0; i <  this->playerNr; i++)
        if(key == this->players[i].getKey())
            player = i;

    if(player != -1)
        this->processKeypress(player);
    else
        this->releaseKeyListener();
}

void Answer::processKeypress(int player)
{
    if(this->time->elapsed() < this->time->msec() + 31000)
    {
        this->currentPlayer = this->players[player];
        ui->currentPlayer->setText(this->currentPlayer.getName());

        this->showButtons();
    }
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

QFont Answer::measureFontSize(int count)
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
    this->lockKeyListener();
    this->dj = new DoubleJeopardy(this, points / 2, points * 2, this->players, this->playerNr, this->currentPlayerId);
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
        if(this->sound)
            this->music->stop();
        this->winner = NO_WINNER;
        done(0);
    }
}

void Answer::on_buttonRight_clicked()
{
    QString resultTmp;
    resultTmp = QString("%1").arg(this->currentPlayer.getId());
    resultTmp.append(WON);
    this->result.append(resultTmp);
    this->releaseKeyListener();
    if(this->sound)
        this->music->stop();
    this->winner = this->currentPlayer.getId() - OFFSET;
    done(0);
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
        if(this->sound)
            this->music->stop();
        this->winner = NO_WINNER;
        done(0);
    }
}

void Answer::on_buttonCancel_clicked()
{
    this->hideButtons();
    this->releaseKeyListener();
}
