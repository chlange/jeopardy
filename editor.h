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

#ifndef EDITOR_H
#define EDITOR_H

#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QComboBox>
#include <QObject>
#include <QMessageBox>
#include <player.h>

#define NUMBER_MAX_PLAYERS 9

class Editor : public QDialog {
    Q_OBJECT
public:
    Editor(QWidget *parent = NULL, Player *players = NULL, int playerNr = 0);
    ~Editor();
    void show();

protected:
    void changeEvent(QEvent *e);

private:
    int playerNr;
    Player *players;
    QDialog *window;
    QGridLayout *mainGrid;
    QGridLayout *lineGrid;
    QGridLayout *saveGrid;
    QLineEdit *playerNamesLines[NUMBER_MAX_PLAYERS];
    QSpinBox *playerPointsLines[NUMBER_MAX_PLAYERS];
    QComboBox *playerKeyBox[NUMBER_MAX_PLAYERS];

    QPushButton *saveButton;

    void init();
    void insertLayouts();
    void assignPlayerPointsLines();
    void assignPlayerNamesLines();
    void assignKeyBoxes();
    void assignSaveButton();

    void showValues();

    void saveChanges();

private slots:
    void end();
};

#endif // EDITOR_H
