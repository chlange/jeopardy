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

Editor::Editor(QWidget *parent, Player *players[3]) :
    QDialog(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);
    this->insertPlayers(players);
    this->showValues();
}

Editor::~Editor()
{
    delete ui;
}

void Editor::showValues()
{
    QString points;

    points = QString("%1").arg(this->players[0]->getPoints());
    ui->linePlayer1->setText(points);

    points = QString("%1").arg(this->players[1]->getPoints());
    ui->linePlayer2->setText(points);

    points = QString("%1").arg(this->players[2]->getPoints());
    ui->linePlayer3->setText(points);

    ui->player1->setText(this->players[0]->getName());
    ui->player2->setText(this->players[1]->getName());
    ui->player3->setText(this->players[2]->getName());
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

/* Point to players - Sort of workaround */
void Editor::insertPlayers(Player *players[3])
{
    for(int i = 0; i < 3; i++)
        this->players[i] = players[i];
}

 void Editor::saveChanges()
 {
     this->players[0]->setPoints(ui->linePlayer1->text().toInt());
     this->players[1]->setPoints(ui->linePlayer2->text().toInt());
     this->players[2]->setPoints(ui->linePlayer3->text().toInt());

     this->players[0]->setName(ui->player1->text());
     this->players[1]->setName(ui->player2->text());
     this->players[2]->setName(ui->player3->text());

     done(0);
 }

void Editor::on_save_clicked()
{
    this->saveChanges();
}
