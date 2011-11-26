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

    for(int i = 0; i < NUMBER_PLAYERS; i++)
        this->players[i] = NULL;

    this->gameField = NULL;
}

Jeopardy::~Jeopardy()
{
    delete ui;

    /* Don't delete field! "new Player(..)" gets called for every player seperately */
    for(int i = 0; i < NUMBER_PLAYERS; i++)
        if(this->players[i] != NULL)
            delete this->players[i];

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

/* Initialize player infos */
bool Jeopardy::initPlayers(QWidget *context)
{
    QString playerName;
    QString text;
    QString color;
    QStringList colorListOriginal;
    QStringList colorList;

    colorListOriginal << "red" << "green" << "yellow" << "blue";

    bool ok;
    bool complete = true;

    for(int i = 0; i < NUMBER_PLAYERS; i++)
    {
        /* reload colors */
        if(i == 0)
            colorList = colorListOriginal;

        /* Repeat name input until cancel buton gets pressed or valid name was entered */
        while(true)
        {
            playerName = QString("Player %1").arg(i+1);
            if(i == 0)
                playerName.append(" Key a");
            else if(i == 1)
                playerName.append(" Key g");
            else
                playerName.append(" Key k");

            text = QInputDialog::getText(context, "Enter name",playerName, QLineEdit::Normal,"", &ok);

            /* Check if name is valid */
            if(ok && !text.isEmpty())
            {
                /* Set name and color */
                this->players[i] = new Player(text, (i+1));

                color = QInputDialog::getItem(context, "Choose color ", "Color:", colorList, 0, false);
                this->players[i]->setColor(color);
                colorList.removeOne(color);

                break;
            }
            else
            {
                complete = false;
                break;
            }

        }

        /* break if input isn't correct */
        if(complete == false && i < 2)
            break;
    }

    return complete;
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

/* Open game field by round */
void Jeopardy::initGameField(int round)
{
    bool complete;
    this->music = Phonon::createPlayer(Phonon::NoCategory, Phonon::MediaSource("sound/title.ogg"));
    this->music->play();

    complete = initPlayers(this);

    this->music->stop();

    if(complete)
    {
        this->gameField = new GameField(this, round, this->players);
        this->gameField->exec();
    }
}
