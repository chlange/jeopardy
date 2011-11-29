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

#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QFile>
#include <QColor>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <editor.h>
#include <podium.h>
#include <answer.h>

#define PLAYER_ONE_STRING "1"
#define PLAYER_TWO_STRING "2"
#define WON "1"
#define PLAYER_ONE 0
#define PLAYER_TWO 1
#define PLAYER_THREE 2
#define NUMBER_ANSWERS 5
#define COMPLETELY_ANSWERED 25
#define POINTS_FACTOR 100
#define NO_WINNER -1
#define COLOR_TEXT_LENGTH 33
#define PLAYER_INDICATOR 1
#define RESULT_INDICATOR 1
#define NOT false

namespace Ui {
    class gameField;
}

class GameField : public QDialog {
    Q_OBJECT
public:
    GameField(QWidget *parent = NULL, int round = 0, Player *players[NUMBER_PLAYERS] = NULL);
    ~GameField();
    void init();
    void setRound(int round);
    int getRound();
    /* Methods to check if game field is playes completely */
    void incAlreadyAnswered(int number);
    void setAlreadyAnswered(int number);
    int getAlreadyAnswered();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::gameField *ui;
    int round;
    int alreadyAnswered;
    int lastWinner;
    int lastPoints;
    Player *players[NUMBER_PLAYERS];
    Answer *answer;
    Editor *editor;
    Podium *podium;
    QAction *editorCtx;
    QAction *loadCtx;
    QAction *saveCtx;
    QAction *endRoundCtx;
    QPushButton *buttons[NUMBER_CATEGORIES * NUMBER_ANSWERS];
    QLabel *playerNameLabels[NUMBER_PLAYERS];
    QLabel *playerPointsLabels[NUMBER_PLAYERS];
    QLabel *categories[NUMBER_CATEGORIES];
    QString result;
    QString fileString;

    void assignButtons();
    void assignPlayerNameLabels();
    void assignPlayerPointsLabels();
    void assignCategoryLabels();
    void setCategoryNames();
    void setLabelColor();
    void setPoints();
    void setNames();
    void insertPlayers(Player *players[NUMBER_PLAYERS]);

    void updateGameFieldValues();
    void updatePointsLabels();
    void updateNamesLabels();
    void updateLabelsAfterAnswer();
    void updateAfterAnswer();

    QString getButtonColorByLastWinner();

    void openFileLoader();
    void openFileSaver(bool automatedBackup);
    void openEditor();

    void openAnswer(int category, int points);
    void processResult();
    void showPodium();

private slots:
    /* Context Menu */
    void on_gameField_customContextMenuRequested(QPoint pos);
    void on_button_1_100_clicked();
    void on_button_2_100_clicked();
    void on_button_3_100_clicked();
    void on_button_4_100_clicked();
    void on_button_5_100_clicked();
    void on_button_1_200_clicked();
    void on_button_2_200_clicked();
    void on_button_3_200_clicked();
    void on_button_4_200_clicked();
    void on_button_5_200_clicked();
    void on_button_1_300_clicked();
    void on_button_2_300_clicked();
    void on_button_3_300_clicked();
    void on_button_4_300_clicked();
    void on_button_5_300_clicked();
    void on_button_1_400_clicked();
    void on_button_2_400_clicked();
    void on_button_3_400_clicked();
    void on_button_4_400_clicked();
    void on_button_5_400_clicked();
    void on_button_1_500_clicked();
    void on_button_2_500_clicked();
    void on_button_3_500_clicked();
    void on_button_4_500_clicked();
    void on_button_5_500_clicked();
};

#endif // GAMEFIELD_H
