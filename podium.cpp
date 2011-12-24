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

Podium::Podium(QWidget *parent, Player *players, int playerNr) :
    QDialog(parent), playerNr(playerNr)
{
    this->players = players;
}

Podium::~Podium()
{
    delete this->first;
    delete this->second;
    delete this->third;
    delete this->firstGrid;
    delete this->secondThirdGrid;
    delete this->window;
}

void Podium::init()
{
    this->window = new QWidget();
    this->mainGrid = new QGridLayout;
    this->firstGrid = new QGridLayout();
    this->secondThirdGrid = new QGridLayout();
    this->first = new QLabel();
    this->second = new QLabel();
    this->third = new QLabel();

    this->initLabels();

    this->firstGrid->addWidget(this->first);
    this->mainGrid->addLayout(this->firstGrid, 0, 0, 0);
    this->mainGrid->addLayout(this->secondThirdGrid, 1, 0, 0);
    this->window->setLayout(this->mainGrid);
    this->window->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void Podium::initLabels()
{
    this->first->setAlignment(Qt::AlignCenter);
    this->first->setFont(QFont("Helvetica [Cronyx]", 22, QFont::Bold, false));
    this->first->setMinimumSize(650, 200);
    this->first->setMaximumSize(650, 200);
    this->first->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->second->setAlignment(Qt::AlignCenter);
    this->second->setFont(QFont("Helvetica [Cronyx]", 17, -1, false));
    this->second->setMinimumSize(500, 150);
    this->second->setMaximumSize(500, 150);
    this->second->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->third->setAlignment(Qt::AlignCenter);
    this->third->setFont(QFont("Helvetica [Cronyx]", 12, -1, false));
    this->third->setMinimumSize(500, 150);
    this->third->setMaximumSize(500, 150);
    this->third->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void Podium::showPodium()
{
    this->init();
    this->sort();

    this->first->setStyleSheet(this->getLabelColorString(0));
    if(this->playerNr == 1)
        this->first->setText(QString("Guess who won... :)"));
    else
        this->first->setText(QString("** %1 **<br>%2").arg(this->players[0].getName()).arg(this->players[0].getPoints()));

    if(this->playerNr > 1)
    {
        this->second->setStyleSheet(this->getLabelColorString(1));
        this->second->setText(QString("2. %1<br>%2").arg(this->players[1].getName()).arg(this->players[1].getPoints()));
        this->secondThirdGrid->addWidget(this->second, 1, 0, 0);
    }
    else
        this->second->setVisible(false);

    if(this->playerNr > 2)
    {
        this->third->setStyleSheet(this->getLabelColorString(2));
        this->third->setText(QString("3. %1<br>%2").arg(this->players[2].getName()).arg(this->players[2].getPoints()));
        this->secondThirdGrid->addWidget(this->third, 1, 1, 0);
    }
    else
    {
        this->second->setGeometry(40, 220, 662, 171);
        this->third->setVisible(false);
    }

    this->window->show();
}

void Podium::sort()
{
    for(int i = 0; i < this->playerNr; i++)
        for(int j = 0; j < this->playerNr - 1; j++)
            if(this->players[j].getPoints() < this->players[j+1].getPoints())
                this->swap(j, j + 1);
}

void Podium::swap(int a, int b)
{
    QString nameTmp = this->players[a].getName();
    QString colorTmp = this->players[a].getColor();
    int pointsTmp = this->players[a].getPoints();

    this->players[a].setName(this->players[b].getName());
    this->players[a].setColor(this->players[b].getColor());
    this->players[a].setPoints(this->players[b].getPoints());

    this->players[b].setName(nameTmp);
    this->players[b].setColor(colorTmp);
    this->players[b].setPoints(pointsTmp);
}

QString Podium::getLabelColorString(int player)
{
    QString color;

    color = QString("QLabel { background-color : %1; }").arg(this->players[player].getColor());

    return color;
}
