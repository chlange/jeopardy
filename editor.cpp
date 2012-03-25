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

#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent, Player *players, int playerNr):
    QDialog(parent), playerNr(playerNr), players(players)
{
}

Editor::~Editor()
{
    delete this->saveButton;
    delete this->lineGrid;
    delete this->saveGrid;
    delete this->mainGrid;
    delete this->window;
}

void Editor::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        break;
    default:
        break;
    }
}

void Editor::show()
{
    this->init();
    this->window->exec();
}

void Editor::init()
{
    this->insertLayouts();
    this->assignPlayerNamesLines();
    this->assignPlayerPointsLines();
    this->assignKeyBoxes();
    this->assignSaveButton();
    this->showValues();
}

void Editor::insertLayouts()
{
    this->window = new QDialog();

    this->mainGrid = new QGridLayout();
    this->lineGrid = new QGridLayout();
    this->saveGrid = new QGridLayout();

    this->mainGrid->addLayout(this->lineGrid, 0, 0);
    this->mainGrid->addLayout(this->saveGrid, 1, 0);
    this->window->setLayout(this->mainGrid);
}

void Editor::assignPlayerNamesLines()
{
    for(int i = 0; i < this->playerNr; i++)
    {
        this->playerNamesLines[i] = new QLineEdit();
        this->lineGrid->addWidget(this->playerNamesLines[i], i, 0);
    }
}

void Editor::assignPlayerPointsLines()
{
    for(int i = 0; i < this->playerNr; i++)
    {
        this->playerPointsLines[i] = new QSpinBox();
        this->playerPointsLines[i]->setSingleStep(50);
        this->playerPointsLines[i]->setMinimum(-50000);
        this->playerPointsLines[i]->setMaximum(50000);
        this->lineGrid->addWidget(this->playerPointsLines[i], i, 1);
    }
}

void Editor::assignKeyBoxes()
{
    QStringList keyList;
    keyList << "A" << "B" << "C" << "D" << "E" << "F" << "G" << "H" << "I" << "J" << "K" << "L" << "M"
            << "N" << "O" << "P" << "Q" << "R" << "S" << "T" << "U" << "V" << "W" << "X" << "Y" << "Z";

    for(int i = 0; i < this->playerNr; i++)
    {
        this->playerKeyBox[i] = new QComboBox();
        this->playerKeyBox[i]->addItems(keyList);
        this->playerKeyBox[i]->setCurrentIndex(this->players[i].getKey() - 0x41);
        this->lineGrid->addWidget(this->playerKeyBox[i], i, 2);
    }
}

void Editor::assignSaveButton()
{
    this->saveButton = new QPushButton();
    this->saveButton->setText("Save");
    this->saveGrid->addWidget(this->saveButton, 0, 0);
    QObject::connect(this->saveButton, SIGNAL(clicked()), this, SLOT(end()));
}

void Editor::showValues()
{
    for(int i = 0; i < this->playerNr; i++)
    {
        this->playerNamesLines[i]->setText(this->players[i].getName());
        this->playerPointsLines[i]->setValue(this->players[i].getPoints());
    }
}

void Editor::saveChanges()
{
    for(int i = 0; i < this->playerNr; i++)
    {
        this->players[i].setName(this->playerNamesLines[i]->text());
        this->players[i].setPoints(this->playerPointsLines[i]->value());
        this->players[i].setKey(this->playerKeyBox[i]->currentIndex() + 0x41);
    }
}

void Editor::end()
{
    this->saveChanges();
    this->window->done(0);
}
