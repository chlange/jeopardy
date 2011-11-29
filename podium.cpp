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

#include "podium.h"
#include "ui_podium.h"

Podium::Podium(QWidget *parent, Player *players[NUMBER_PLAYERS]) :
    QDialog(parent),
    ui(new Ui::Podium)
{
    ui->setupUi(this);
    this->insertPlayers(players);
    this->assignLabels();
    this->sort();
    this->showPodium();
}

Podium::~Podium()
{
    delete ui;
}

void Podium::changeEvent(QEvent *e)
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

void Podium::insertPlayers(Player *players[NUMBER_PLAYERS])
{
    for(int i = 0; i < NUMBER_PLAYERS; i++)
        this->players[i] = players[i];
}

void Podium::assignLabels()
{
    this->podiumPlaceLabels[FIRST_PLAYER] = ui->first;
    this->podiumPlaceLabels[SECOND_PLAYER] = ui->second;
    this->podiumPlaceLabels[THIRD_PLAYER] = ui->third;
}

void Podium::showPodium()
{
    QString text;

    for(int i = 0; i < NUMBER_PLAYERS; i++)
    {
        this->podiumPlaceLabels[i]->setStyleSheet(this->getLabelColorString(this->order[i]));

        if(i == FIRST_PLACE_PODIUM)
            text = QString("** %1 **").arg(this->players[this->order[i]]->getName());
        else
            text = QString("%1. %2").arg(i+1).arg(this->players[this->order[i]]->getName());

        this->podiumPlaceLabels[i]->setText(text);
    }
}

void Podium::sort()
{
    Player *first, *second, *third;

    first = this->players[FIRST_PLAYER];
    second = this->players[SECOND_PLAYER];
    third = this->players[THIRD_PLAYER];

    /* Manual sorting for 3 numbers scales better than known sorting algorithms, I think */
    if(first->getPoints() <= second->getPoints() && first->getPoints() <= third->getPoints())
    {
        if(second->getPoints() <= third->getPoints())
            this->setOrder(0, 1, 2);
        else
            this->setOrder(0, 2, 1);
    }
    else if(second->getPoints() <= first->getPoints() && second->getPoints() <= third->getPoints())
    {
        if(first->getPoints() <= third->getPoints())
            this->setOrder(1, 0, 2);
        else
            this->setOrder(1, 2, 0);
    }
    else
    {
        if(first->getPoints() <= second->getPoints())
            this->setOrder(2, 0, 1);
        else
            this->setOrder(2, 1, 0);

    }
}

void Podium::setOrder(int first, int second, int third)
{
    order[THIRD_PLACE] = third;
    order[SECOND_PLACE] = second;
    order[FIRST_PLACE] = first;
}

QString Podium::getLabelColorString(int player)
{
    QString color;

    color = QString("QLabel { background-color : %1; }").arg(this->players[player]->getColor());

    return color;
}

