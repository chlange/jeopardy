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

#ifndef DOUBLEJEOPARDY_H
#define DOUBLEJEOPARDY_H

#include <QMessageBox>
#include <player.h>

#define DOUBLE_JEOPARDY_MIN_POINTS 100

namespace Ui {
    class DoubleJeopardy;
}

class DoubleJeopardy : public QDialog {
    Q_OBJECT
public:
    DoubleJeopardy(QWidget *parent = 0, int min = 0, int max = 0, Player *players[NUMBER_PLAYERS] = 0);
    ~DoubleJeopardy();
    void setLabels();
    int getPoints();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DoubleJeopardy *ui;
    int min;
    int max;
    int points;
    Player *players[NUMBER_PLAYERS];

    void insertPlayers(Player *players[NUMBER_PLAYERS]);

private slots:
    void on_button_clicked();
};

#endif // DOUBLEJEOPARDY_H
