/*
 * Copyright (c) 2011-2014, Christian Lange
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

#ifdef _WIN32
    #include <time.h>
#endif

#include <stdlib.h>
#include <QDir>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QFile>
#include <QColor>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>
#include <QShortcut>
#include <QDateTime>
#include <QGridLayout>
#include <editor.h>
#include <podium.h>
#include <answer.h>

#define WON "1"
#define NUMBER_ANSWERS 5
#define NUMBER_MAX_CATEGORIES 6
#define NUMBER_MAX_ANSWERS 30
#define NUMBER_ANSWERS 5
#define POINTS_FACTOR 100
#define COLOR_TEXT_LENGTH 33
#define PLAYER_INDICATOR 1
#define RESULT_INDICATOR 1
#define NOT false
#define NO_WINNER -1

#define GAMEFIELD_WIDTH 1000
#define GAMEFIELD_HEIGHT 500
#define FIRST_LABEL_ROW 7
#define CATEGORY_LABEL_HEIGHT 30
#define NAME_LABEL_HEIGHT 20
#define SPLIT_FOR_TWO_LABELS 2
#define OFFSET 1

class GameField : public QDialog {
    Q_OBJECT
public:
    GameField(QWidget *parent = NULL, int round = 0, int categoryNr = 0, Player *players = NULL, int playerNr = 0, bool sound = true, QString filesString = "");
    ~GameField();
    void init();

protected:
    void changeEvent(QEvent *e);

private:
    int round;
    int alreadyAnswered;
    int lastWinner;
    int lastPoints;
    int playerNr;
    int categoryNr;
    int currentPlayer;
    bool sound;
    Player *players;
    Editor *editor;
    Answer *answer;
    Podium *podium;
    QWidget *window;
    QGridLayout *mainGrid;
    QGridLayout *categoryLabelGrid;
    QGridLayout *buttonGrid;
    QGridLayout *playerLabelGrid;
    QAction *randomCtx;
    QAction *editorCtx;
    QAction *loadCtx;
    QAction *saveCtx;
    QAction *endRoundCtx;
    QAction *resetRoundCtx;
    QAction *about;
    QPushButton *buttons[NUMBER_MAX_ANSWERS];
    QLabel *playerNameLabels[NUMBER_MAX_PLAYERS];
    QLabel *playerPointsLabels[NUMBER_MAX_PLAYERS];
    QLabel *categoryLabels[NUMBER_MAX_CATEGORIES];
    QString result;
    QString fileString;

    void reset();

    void setRound(int round);
    int getRound();
    void incAlreadyAnswered(int number);
    void setAlreadyAnswered(int number);
    int getAlreadyAnswered();

    void insertLayouts();
    void assignButtons();
    void setDefaultButtonAppearance(int i, int currentButton);
    void assignPlayerNameLabels();
    void assignPlayerPointsLabels();
    void assignCategoryLabels();
    void processCategoryLabels();
    void setLabelColor();
    void setPoints();
    void setNames();

    void updateGameFieldValues();
    void updateLabelsAfterAnswer();
    void updateAfterAnswer();
    void updateCurrentPlayerLabel();

    QString getButtonColorByLastWinner();

    void openAnswer(int category, int points);
    void processAnswer(int category, int points);
    void processResult();
    void showPodium();

    void openFileLoader();
    void openFileSaver(bool automatedBackup);
    void openEditor();
    void resetRound();

    bool eventFilter(QObject *target, QEvent *event);
    void indicateRandom();

private slots:
    /* Context Menu */
    void on_gameField_customContextMenuRequested(QPoint pos);
    int random();
    void updateNamesLabels();
    void updatePointsLabels();
    void on_button_1_100_clicked();
    void on_button_2_100_clicked();
    void on_button_3_100_clicked();
    void on_button_4_100_clicked();
    void on_button_5_100_clicked();
    void on_button_6_100_clicked();

    void on_button_1_200_clicked();
    void on_button_2_200_clicked();
    void on_button_3_200_clicked();
    void on_button_4_200_clicked();
    void on_button_5_200_clicked();
    void on_button_6_200_clicked();

    void on_button_1_300_clicked();
    void on_button_2_300_clicked();
    void on_button_3_300_clicked();
    void on_button_4_300_clicked();
    void on_button_5_300_clicked();
    void on_button_6_300_clicked();

    void on_button_1_400_clicked();
    void on_button_2_400_clicked();
    void on_button_3_400_clicked();
    void on_button_4_400_clicked();
    void on_button_5_400_clicked();
    void on_button_6_400_clicked();

    void on_button_1_500_clicked();
    void on_button_2_500_clicked();
    void on_button_3_500_clicked();
    void on_button_4_500_clicked();
    void on_button_5_500_clicked();
    void on_button_6_500_clicked();
};

#endif // GAMEFIELD_H
