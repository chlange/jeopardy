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

#ifndef PODIUM_H
#define PODIUM_H

#include <QDialog>
#include <player.h>
#include <QLabel>

#define FIRST_PLACE_PODIUM 0
#define FIRST_PLACE 2
#define SECOND_PLACE 1
#define THIRD_PLACE 0
#define FIRST_PLAYER 0
#define SECOND_PLAYER 1
#define THIRD_PLAYER 2
#define NUMBER_PLAYERS 3

namespace Ui {
    class Podium;
}

class Podium : public QDialog {
    Q_OBJECT
public:
    Podium(QWidget *parent = NOT_DEFINED, Player *players[NUMBER_PLAYERS] = NOT_DEFINED);
    ~Podium();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Podium *ui;
    Player *players[NUMBER_PLAYERS];
    int order[NUMBER_PLAYERS];
    QLabel *podiumPlaceLabels[NUMBER_PLAYERS];

    void showPodium();
    void sort();
    void setOrder(int first, int second, int third);
    void insertPlayers(Player *players[NUMBER_PLAYERS]);
    QString getLabelColorString(int player);
    void assignLabels();
};

#endif // PODIUM_H