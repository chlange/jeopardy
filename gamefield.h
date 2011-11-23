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

#include <QDialog>
#include <player.h>
#include <QMenu>
#include <editor.h>
#include <podium.h>
#include <answer.h>
#include <QAction>
#include <QLabel>

namespace Ui {
    class gameField;
}

class GameField : public QDialog {
    Q_OBJECT
public:
    GameField(QWidget *parent = 0);
    GameField(QWidget *parent = 0, int round = 1, Player *players[3] = 0);
    ~GameField();
    void init();
    void setRound(int round);
    int getRound();
    /* Methods to check if game field is playes completely */
    void incAnswered(int number);
    void setAnswered(int number);
    int getAnswered();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::gameField *ui;
    int round;
    int alreadyAnswered;
    int lastWinner;
    Player *players[3];
    Answer *answer;
    Editor *editor;
    Podium *podium;
    QAction *editorCtx;
    QAction *loadCtx;
    QAction *saveCtx;
    QAction *endRoundCtx;
    QPushButton *buttons[25];
    QLabel *playerNameLabels[3];
    QLabel *playerPointsLabels[3];
    QLabel *categories[5];

    void setCategoryNames();
    void setLabelColor();
    void setPoints();
    void setNames();
    void openAnswer(int category, int points);
    void processResult(QString result, int points);
    /* Update points and names */
    void updateGameFieldValues();
    /* Update names on game field */
    void updateNames();
    /* Update points of players on game field */
    void updatePoints();
    /* Point to players - Sort of workaround */
    void insertPlayers(Player *players[3]);
    /* Calculate points after answer gets closed */
    void calcPoints(Player *player, QString result, int points);
    void showPodium();
    /*
     * Save game state
     *
     * @param backup automated backup every answer without file dialog prompt in gameStates/backup
     */
    void openFileSaver(bool backup);
    /* Open Editor to change player points */
    void openEditor();
    /* Load game State */
    void openFileLoader();
    QString getButtonColor();
    void assignButtons();
    void assignPlayerNameLabels();
    void assignPlayerPointsLabels();
    void assignCategoryLabels();

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
