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

#ifndef ANSWER_H
#define ANSWER_H

#include <QKeyEvent>
#include <QSound>
#include <QFile>
#include <QDir>
#include <QPixmap>
#include <QTimer>
#include <QTime>
#include <QGraphicsScene>
#include <phonon/mediaobject.h>
#include <doublejeopardy.h>

#define NUMBER_MAX_PLAYERS 9
#define NUMBER_MAX_CATEGORIES 6
#define ANSWER_POINTS_INDICATOR_LENGTH 5
#define SOME_LINE_BREAKS 10
#define MORE_LINE_BREAKS 15
#define MANY_LINE_BREAKS 20
#define NO_WINNER -1
#define WON "1"
#define LOST "0"

namespace Ui {
    class Answer;
}

class Answer : public QDialog {
    Q_OBJECT
public:
    Answer(QWidget *parent = NULL, QString file = NULL, int round = 0, Player *players = NULL, int playerNr = 0, bool sound = true, int currentPlayerId = 0);
    ~Answer();
    void setAnswer(int category, int points);
    int getPoints();
    QString getResult();
    int getWinner();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Answer *ui;
    int round;
    int playerNr;
    int points;
    int currentPlayerId;
    int winner;
    unsigned int timeStarted;
    bool keyLock;
    bool isVideo;
    bool sound;
    bool doubleJeopardy;
    QString result;
    QString fileString;
    QTime *time;
    Player *players;
    Player currentPlayer;
    Phonon::MediaObject *music;
    DoubleJeopardy *dj;

    void keyPressEvent(QKeyEvent *event);
    void processKeypress(int player);
    bool keyListenerIsLocked();
    void lockKeyListener();
    void releaseKeyListener();

    void showButtons();
    void hideButtons();

    QString getRoundFile();
    QFont measureFontSize(int count);

    bool getAnswer(int category, int points, QString *answer);
    void openDoubleJeopardy();
    int getCategoryLine(int category);

    void processText(QString *answer);
    void processImg(QString *answer);
    void processSound(QString *answer);
    void processVideo(QString *answer);
    void processDoubleJeopardy(QString *answer);
    void processAlign(QString *answer);

    void prependDir(QString *answer);

private slots:
    void on_buttonCancel_clicked();
    void on_buttonWrong_clicked();
    void on_buttonRight_clicked();
    void on_buttonEnd_clicked();
};

#endif // ANSWER_H
