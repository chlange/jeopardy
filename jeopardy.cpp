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

#include "jeopardy.h"
#include "ui_jeopardy.h"

Jeopardy::Jeopardy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Jeopardy)
{
    ui->setupUi(this);

    this->players = NULL;
    this->gameField = NULL;
}

Jeopardy::~Jeopardy()
{
    delete ui;

    if(this->players != NULL)
        delete [] this->players;

    if(this->gameField != NULL)
        delete this->gameField;
}

void Jeopardy::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Jeopardy::initGameField(int round)
{
    bool complete;
    this->music = Phonon::createPlayer(Phonon::NoCategory, Phonon::MediaSource("sound/title.ogg"));
    //this->music->play();

    complete = this->setCategoryNr();

    if(NOT == complete)
    {
        this->music->stop();
        return;
    }

    complete = this->setPlayerNr();

    if(NOT == complete)
    {
        this->music->stop();
        return;
    }

    complete = this->initPlayers();

    if(NOT == complete)
    {
        this->music->stop();
        return;
    }

    this->startRound(round);
}

bool Jeopardy::setPlayerNr()
{
    bool ok;

    this->playerNr = QInputDialog::getInt(this, "Select number of players", "Number of players", 3, 2, NUMBER_MAX_PLAYERS, 1, &ok);

    this->players = new Player[NUMBER_MAX_PLAYERS];

    return ok;
}

bool Jeopardy::setCategoryNr()
{
    bool ok;

    this->categoryNr = QInputDialog::getInt(this, "Select number of categories", "Number of categories", 5, 1, 6, 1, &ok);

    return ok;
}

bool Jeopardy::initPlayers()
{
    QString playerName;
    QString text;
    QString key;
    QString color;
    QStringList keyListOrg;
    QStringList keyList;
    QStringList colorList;
    int keys[36];

    colorList << "red" << "green" << "yellow" << "blue" << "gray" << "magenta";
    keyList << "a" << "b" << "c" << "d"  << "e" << "f" << "g" << "h" << "i" << "j" << "k" << "l" << "m"
            << "n" << "o" << "p" << "q" << "r" << "s" << "t" << "u" << "v" << "w" << "x" << "y" << "z"
             << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "0";
    keyListOrg = keyList;

    for(int i = 0; i < 26; i++)
        keys[i] = 0x41 + i;
    for(int i = 26; i < 36; i++)
        keys[i] = 0x30 + (i - 26);

    bool ok;
    bool complete = true;

    for(int i = 0; i < this->playerNr; i++)
    {
        playerName = QString("Player %1").arg(i+1);

        text = QInputDialog::getText(this, "Enter name", playerName, QLineEdit::Normal,"", &ok);

        /* Check if name is valid */
        if(ok && !text.isEmpty())
        {
            this->players[i].setName(text);
            this->players[i].setId(i+1);

            key = QInputDialog::getItem(this, "Choose key", "Choose key:", keyList, 0, false);
            this->players[i].setKey(keys[keyListOrg.indexOf(key)]);
            keyList.removeOne(key);

            color = QInputDialog::getItem(this, "Choose color ", "Color:", colorList, 0, false);
            this->players[i].setColor(color);
            colorList.removeOne(color);
        }
        else
        {
            complete = false;
            break;
        }
    }
    return complete;
}

void Jeopardy::startRound(int round)
{
    this->gameField = new GameField(this, round, this->categoryNr, this->players, this->playerNr);
}

void Jeopardy::on_buttonRound1_clicked()
{
    initGameField(1);
}

void Jeopardy::on_buttonRound2_clicked()
{
    initGameField(2);
}

void Jeopardy::on_buttonRound3_clicked()
{
    initGameField(3);
}

void Jeopardy::on_buttonRound4_clicked()
{
    initGameField(4);
}
