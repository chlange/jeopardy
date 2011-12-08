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

Podium::Podium(QWidget *parent, Player *players, int playerNr) :
    QDialog(parent), ui(new Ui::Podium), playerNr(playerNr)
{
    ui->setupUi(this);

    this->players = players;
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
    this->sort();

    ui->first->setStyleSheet(this->getLabelColorString(0));
    if(this->playerNr == 1)
        ui->first->setText(QString("Guess who won... :)"));
    else
        ui->first->setText(QString("** %1 **<br>%2").arg(this->players[0].getName()).arg(this->players[0].getPoints()));

    if(this->playerNr > 1)
    {
        ui->second->setStyleSheet(this->getLabelColorString(1));
        ui->second->setText(QString("2. %1<br>%2").arg(this->players[1].getName()).arg(this->players[1].getPoints()));
    }
    else
        ui->second->setVisible(false);

    if(this->playerNr > 2)
    {
        ui->third->setStyleSheet(this->getLabelColorString(2));
        ui->third->setText(QString("3. %1<br>%2").arg(this->players[2].getName()).arg(this->players[2].getPoints()));
    }
    else
    {
        ui->second->setGeometry(40, 220, 662, 171);
        ui->third->setVisible(false);
    }
}

void Podium::sort()
{
    for(int i = 0; i < this->playerNr; i++)
    {
        for(int j = 0; j < this->playerNr - 1; j++)
        {
            if(this->players[j].getPoints() < this->players[j+1].getPoints())
            {
                QString nameTmp = this->players[j].getName();
                QString colorTmp = this->players[j].getColor();
                int pointsTmp = this->players[j].getPoints();

                this->players[j].setName(this->players[j+1].getName());
                this->players[j].setColor(this->players[j+1].getColor());
                this->players[j].setPoints(this->players[j+1].getPoints());

                this->players[j+1].setName(nameTmp);
                this->players[j+1].setColor(colorTmp);
                this->players[j+1].setPoints(pointsTmp);
            }
        }
    }
}

QString Podium::getLabelColorString(int player)
{
    QString color;

    color = QString("QLabel { background-color : %1; }").arg(this->players[player].getColor());

    return color;
}
