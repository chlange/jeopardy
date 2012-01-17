/*
 * Copyright (c) 2011-2012, Christian Lange
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
    sound(false), gameField(NULL)
{
    this->players = new Player[NUMBER_MAX_PLAYERS];
}

Jeopardy::~Jeopardy()
{
    if(this->players != NULL)
        delete [] this->players;

    if(this->gameField != NULL)
    {
        delete this->gameField;
        this->gameField = NULL;
    }
}

void Jeopardy::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        break;
    default:
        break;
    }
}

void Jeopardy::init()
{
    this->initMenu();
}

void Jeopardy::initMenu()
{
    this->window = new QWidget();
    this->grid = new QGridLayout();

    for(int i = 0; i < NUMBER_ROUNDS; i++)
        this->prepareButton(i);

    this->window->setLayout(this->grid);
    this->window->show();
}

void Jeopardy::prepareButton(int i)
{
    this->buttons[i] = new QPushButton();
    this->buttons[i]->setText(QString("Round %1").arg(i + 1));
    this->buttons[i]->setFont(QFont("Helvetica [Cronyx]", 13, QFont::Bold, false));
    this->buttons[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->grid->addWidget(this->buttons[i], 0, i, 0);
    this->grid->setSpacing(0);
    this->grid->setMargin(0);
    connect(this->buttons[i], SIGNAL(clicked()), this->buttons[i], SLOT(hide()));
    connect(this->buttons[i], SIGNAL(clicked()), this, SLOT(initGameField()));
}

void Jeopardy::initGameField()
{
    bool complete;

    this->round = this->getRound();
    this->setSound();

    if(this->sound)
    {
        this->music = Phonon::createPlayer(Phonon::NoCategory, Phonon::MediaSource("sound/title.ogg"));
        this->music->play();
    }

    complete = this->setCategoryNr();

    if(NOT == complete)
    {
        this->deleteSound();
        return;
    }

    complete = this->setPlayerNr();

    if(NOT == complete)
    {
        this->deleteSound();
        return;
    }

    complete = this->initPlayers();

    if(NOT == complete)
    {
        this->deleteSound();
        return;
    }

    this->deleteSound();

    this->startRound(this->round);
}

int Jeopardy::getRound()
{
   for(int i = 0; i < NUMBER_ROUNDS; i++)
       if(this->buttons[i]->isHidden())
       {
            this->round = i + 1;
            this->buttons[i]->setStyleSheet(QString("background-color: lightGray;"));
            this->buttons[i]->setHidden(false);
       }

   return this->round;
}

void Jeopardy::setSound()
{
    QMessageBox msgBox;
    msgBox.setText("Do you need sound?");
    msgBox.setWindowTitle("Sound");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);

    if(msgBox.exec() == QMessageBox::Yes)
        this->sound = true;
    else
        this->sound = false;
}

bool Jeopardy::setPlayerNr()
{
    bool ok;

    this->playerNr = QInputDialog::getInt(this, "Select number of players", "Players", 3, 1, NUMBER_MAX_PLAYERS, 1, &ok);

    return ok;
}

bool Jeopardy::setCategoryNr()
{
    bool ok;

    this->categoryNr = QInputDialog::getInt(this, "Select number of categories", "Categories", 5, 1, NUMBER_MAX_CATEGORIES, 1, &ok);

    return ok;
}

bool Jeopardy::initPlayers()
{
    bool ok, complete;
    QString playerName, text, key, color;
    QStringList keyList, colorList;

    colorList << "red" << "green" << "yellow" << "blue" << "gray" << "magenta" << "darkRed" << "cyan" << "white" << "darkMagenta";
    keyList << "A" << "B" << "C" << "D" << "E" << "F" << "G" << "H" << "I" << "J" << "K" << "L" << "M"
            << "N" << "O" << "P" << "Q" << "R" << "S" << "T" << "U" << "V" << "W" << "X" << "Y" << "Z";

    for(int i = 0; i < this->playerNr; i++)
    {
        complete = false;
        playerName = QString("Player %1").arg(i+1);

        for(;;)
        {
            text = QInputDialog::getText(this, "Enter name", playerName, QLineEdit::Normal,"", &ok);

            if(text.length() < 10)
                break;

            QMessageBox msgBox;
            msgBox.setText("Choose a name shorter than 11 letters");
            msgBox.exec();
        }

        if(!ok || text.isEmpty())
            break;

        this->players[i].setName(text);
        this->players[i].setId(i+1);
        this->players[i].setPressed(0);

        key = QInputDialog::getItem(this, "Choose key", "Choose key:", keyList, 0, false, &ok);
        if(!ok)
            break;

        this->players[i].setKey(key.at(0).toAscii());
        keyList.removeOne(key);

        color = QInputDialog::getItem(this, "Choose color ", "Color:", colorList, 0, false, &ok);
        if(!ok)
            break;

        this->players[i].setColor(color);
        colorList.removeOne(color);
        this->players[i].setPoints(0);

        complete = true;
    }
    return complete;
}

void Jeopardy::startRound(int round)
{
    this->gameField = new GameField(this, round, this->categoryNr, this->players, this->playerNr, this->sound);
    this->gameField->init();
}

void Jeopardy::deleteSound()
{
    if(this->sound)
    {
        this->music->stop();
        delete this->music;
    }
}
