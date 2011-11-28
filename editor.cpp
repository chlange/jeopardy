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

#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent, Player *players[NUMBER_PLAYERS]):
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    this->insertPlayers(players);
    this->assignPlayerNamesLines();
    this->assignPlayerPointsLines();
    this->showValues();
}

Editor::~Editor()
{
    delete ui;
}

void Editor::changeEvent(QEvent *e)
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

void Editor::insertPlayers(Player *players[NUMBER_PLAYERS])
{
    for(int i = 0; i < NUMBER_PLAYERS; i++)
        this->players[i] = players[i];
}

void Editor::assignPlayerPointsLines()
{
    this->playerPointsLines[0] = ui->linePlayer1;
    this->playerPointsLines[1] = ui->linePlayer2;
    this->playerPointsLines[2] = ui->linePlayer3;
}

void Editor::assignPlayerNamesLines()
{
    this->playerNamesLines[0] = ui->player1;
    this->playerNamesLines[1] = ui->player2;
    this->playerNamesLines[2] = ui->player3;
}

void Editor::showValues()
{
    QString points;

    for(int i = 0; i < NUMBER_PLAYERS; i++)
    {
        points = QString("%1").arg(this->players[i]->getPoints());
        this->playerPointsLines[i]->setText(points);

        this->playerNamesLines[i]->setText(this->players[i]->getName());
    }
}

 void Editor::saveChanges()
 {
     for(int i = 0; i < NUMBER_PLAYERS; i++)
     {
         this->players[i]->setPoints(this->playerPointsLines[i]->text().toInt());
         this->players[i]->setName(this->playerNamesLines[i]->text());
     }

     done(0);
 }

void Editor::on_save_clicked()
{
    this->saveChanges();
}
