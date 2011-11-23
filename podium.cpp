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

Podium::Podium(QWidget *parent, Player *players[3]) :
    QDialog(parent),
    ui(new Ui::Podium)
{
    ui->setupUi(this);
    this->insertPlayers(players);
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

void Podium::showPodium()
{
    QString text;

    ui->first->setStyleSheet(this->getLabelColorString(this->order[2]));
    text = QString("** %1 **").arg(this->players[this->order[2]]->getName());
    ui->first->setText(text);

    ui->second->setStyleSheet(this->getLabelColorString(this->order[1]));
    text = QString("2. %1").arg(this->players[this->order[1]]->getName());
    ui->second->setText(text);

    ui->third->setStyleSheet(this->getLabelColorString(this->order[0]));
    text = QString("3. %1").arg(this->players[this->order[0]]->getName());
    ui->third->setText(text);
}

QString Podium::getLabelColorString(int player)
{
    QString color;

    color = QString("QLabel { background-color : %1; }").arg(this->players[player]->getColor());

    return color;
}

void Podium::sort()
{
    Player *first, *second, *third;

    first = this->players[0];
    second = this->players[1];
    third = this->players[2];

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
    order[0] = first;
    order[1] = second;
    order[2] = third;
}

/* Point to players - Sort of workaround */
void Podium::insertPlayers(Player *players[3])
{
    for(int i = 0; i < 3; i++)
        this->players[i] = players[i];
}
