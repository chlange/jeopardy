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

#include "doublejeopardy.h"
#include "ui_doublejeopardy.h"

DoubleJeopardy::DoubleJeopardy(QWidget *parent, int min, int max, Player *players, int playerNr, int currentPlayer) :
    QDialog(parent), min(min), max(max), playerNr(playerNr), currentPlayerId(currentPlayer)
{
    this->players = players;
}

DoubleJeopardy::~DoubleJeopardy()
{
    delete this->playerComboBox;
    delete this->minLabel;
    delete this->pointsSpinBox;
    delete this->maxLabel;
    delete this->startButton;

    delete this->grid;
    delete this->window;
}

void DoubleJeopardy::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        break;
    default:
        break;
    }
}

void DoubleJeopardy::show()
{
    this->window->exec();
}

void DoubleJeopardy::init()
{
    this->insertLayouts();
    this->setLabels();
}

void DoubleJeopardy::insertLayouts()
{
    this->window = new QDialog();
    this->grid = new QGridLayout();

    this->playerComboBox = new QComboBox();
    this->minLabel = new QLabel();
    this->pointsSpinBox = new QSpinBox();
    this->maxLabel = new QLabel();
    this->startButton = new QPushButton();

    this->grid->addWidget(this->playerComboBox, 0, 0);
    this->grid->addWidget(this->minLabel, 1, 0);
    this->grid->addWidget(this->pointsSpinBox, 2, 0);
    this->grid->addWidget(this->maxLabel, 3, 0);
    this->grid->addWidget(this->startButton, 4, 0);

    this->window->setGeometry(0, 0, 250, 0);
    this->window->setLayout(this->grid);
}

void DoubleJeopardy::setLabels()
{
    if(this->min < DOUBLE_JEOPARDY_MIN_POINTS)
        this->min = DOUBLE_JEOPARDY_MIN_POINTS;

    QStringList playerList;

    playerList << "Choose player";

    for(int i = 0; i < this->playerNr; i++)
        playerList << this->players[i].getName();

    this->playerComboBox->addItems(playerList);
    this->playerComboBox->setCurrentIndex(this->currentPlayerId + 1);

    this->minLabel->setText(QString("Min: %1").arg(this->min));

    this->pointsSpinBox->setMinimum(-20000);
    this->pointsSpinBox->setMaximum(20000);
    this->pointsSpinBox->setSingleStep(50);
    this->pointsSpinBox->setValue(this->max);

    this->maxLabel->setText(QString("Max: %1").arg(this->max));

    this->startButton->setText("Save");
    QObject::connect(this->startButton, SIGNAL(clicked()), this, SLOT(on_button_clicked()));
}

int DoubleJeopardy::getPoints()
{
    return this->points;
}

int DoubleJeopardy::getPlayer()
{
    return this->index;
}

void DoubleJeopardy::on_button_clicked()
{
    if(this->playerComboBox->currentIndex() == 0)
    {
         QMessageBox::critical(this, tr("Error"), tr("Choose player"));
    }
    else if(this->min <= this->pointsSpinBox->value() && this->pointsSpinBox->value() <= this->max)
    {
        this->points = this->pointsSpinBox->value();
        this->index = this->playerComboBox->currentIndex() - 1;
        this->window->done(0);
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Points out of range!"));
        this->pointsSpinBox->setValue(this->max);
    }
}
