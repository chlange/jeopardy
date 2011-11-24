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

#include <QDialog>
#include <player.h>
#include <phonon/phonon>

#define IMG_TAG 5
#define ALIGN_TAG 3
#define ANSWER_POINTS_INDICATOR_LENGTH 5
#define SOME_LINE_BREAKS 10
#define MORE_LINE_BREAKS 15
#define MANY_LINE_BREAKS 20
#define YES 0x00004000
#define WON "1"
#define LOST "0"

namespace Ui {
    class Answer;
}

class Answer : public QDialog {
    Q_OBJECT
public:
    Answer(QWidget *parent = NOT_DEFINED, int round = NOT_DEFINED, Player *players[NUMBER_PLAYERS] = NOT_DEFINED);
    ~Answer();
    QString getResult();
    /* Read in round file and set text of label to answer */
    void setAnswer(int category, int points);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Answer *ui;
    int round;
    QString result;
    Player *players[NUMBER_PLAYERS];
    Player *currentPlayer;
    Phonon::MediaObject *music;

    void showButtons();
    void hideButtons();

    /* Listen to buttons */
    /* If player presses his button all other buttons get locked and the right/wrong buttons get visible */
    void keyPressEvent(QKeyEvent *event);
    bool keyLock;
    bool keyListenerIsLocked();
    void lockKeyListener();
    void releaseKeyListener();

    /* Point to players - Sort of workaround */
    void insertPlayers(Player *players[NUMBER_PLAYERS]);
    void processKeypress(int player);
    void getAnswer(int category, int points, QString *answer);
    QString getRoundFile();
    int getCategoryLine(int category);
    QFont meassureFontSize(int count);

private slots:
    void on_buttonCancel_clicked();
    void on_buttonWrong_clicked();
    void on_buttonRight_clicked();
    void on_buttonEnd_clicked();
};

#endif // ANSWER_H
