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

#ifndef ANSWER_H
#define ANSWER_H

#include <QKeyEvent>
#include <QSound>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <phonon/phonon>
#include <doublejeopardy.h>

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
    Answer(QWidget *parent = NULL, QString file = NULL, int round = NULL, Player *players[NUMBER_PLAYERS] = NULL);
    ~Answer();
    QString getResult();
    /* Read in round file and set text of label to answer */
    void setAnswer(int category, int points);
    int getPoints();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Answer *ui;
    int round;
    int points;
    int currentPlayerId;
    QString result;
    bool keyLock;
    QString fileString;
    bool doubleJeopardy;
    Player *players[NUMBER_PLAYERS];
    Player *currentPlayer;
    Phonon::MediaObject *music;
    DoubleJeopardy *dj;

    void showButtons();
    void hideButtons();

    void insertPlayers(Player *players[NUMBER_PLAYERS]);
    void keyPressEvent(QKeyEvent *event);
    void processKeypress(int player);
    bool keyListenerIsLocked();
    void lockKeyListener();
    void releaseKeyListener();

    QString getRoundFile();
    QFont meassureFontSize(int count);
    int getCategoryLine(int category);

    void getAnswer(int category, int points, QString *answer);
    void openDoubleJeopardy();

private slots:
    void on_buttonCancel_clicked();
    void on_buttonWrong_clicked();
    void on_buttonRight_clicked();
    void on_buttonEnd_clicked();
};

#endif // ANSWER_H
