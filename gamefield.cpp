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

#include "gamefield.h"
#include "ui_gamefield.h"

GameField::GameField(QWidget *parent, int roundArg, Player *players[NUMBER_PLAYERS]) :
    QDialog(parent), ui(new Ui::gameField), round(roundArg), alreadyAnswered(NULL),
    lastWinner(NO_WINNER), answer(NULL), editor(NULL), podium(NULL),
    editorCtx(NULL), loadCtx(NULL), saveCtx(NULL), endRoundCtx(NULL)
{
    ui->setupUi(this);

    /* Declare new context menu and connect it with the right mouse button */
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_gameField_customContextMenuRequested(QPoint)));

    this->insertPlayers(players);
    this->init();
}

GameField::~GameField()
{
    delete ui;
    if(this->answer != NULL)
        delete this->answer;
    if(this->editor != NULL)
        delete this->editor;
    if(this->editorCtx != NULL)
        delete this->editorCtx;
    if(this->loadCtx != NULL)
        delete this->loadCtx;
    if(this->saveCtx != NULL)
        delete this->saveCtx;
    if(this->endRoundCtx != NULL)
        delete this->endRoundCtx;
    if(this->podium != NULL)
        delete this->podium;
}

void GameField::changeEvent(QEvent *e)
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

void GameField::init()
{
    this->assignButtons();
    this->assignPlayerNameLabels();
    this->assignPlayerPointsLabels();
    this->assignCategoryLabels();
    this->setCategoryNames();
    this->setNames();
    this->setPoints();
    this->setLabelColor();
}

void GameField::assignButtons()
{
    this->buttons[0] = ui->button_1_100;
    this->buttons[1] = ui->button_2_100;
    this->buttons[2] = ui->button_3_100;
    this->buttons[3] = ui->button_4_100;
    this->buttons[4] = ui->button_5_100;

    this->buttons[5] = ui->button_1_200;
    this->buttons[6] = ui->button_2_200;
    this->buttons[7] = ui->button_3_200;
    this->buttons[8] = ui->button_4_200;
    this->buttons[9] = ui->button_5_200;

    this->buttons[10] = ui->button_1_300;
    this->buttons[11] = ui->button_2_300;
    this->buttons[12] = ui->button_3_300;
    this->buttons[13] = ui->button_4_300;
    this->buttons[14] = ui->button_5_300;

    this->buttons[15] = ui->button_1_400;
    this->buttons[16] = ui->button_2_400;
    this->buttons[17] = ui->button_3_400;
    this->buttons[18] = ui->button_4_400;
    this->buttons[19] = ui->button_5_400;

    this->buttons[20] = ui->button_1_500;
    this->buttons[21] = ui->button_2_500;
    this->buttons[22] = ui->button_3_500;
    this->buttons[23] = ui->button_4_500;
    this->buttons[24] = ui->button_5_500;
}

void GameField::assignPlayerNameLabels()
{
    this->playerNameLabels[0] = ui->player1Name;
    this->playerNameLabels[1] = ui->player2Name;
    this->playerNameLabels[2] = ui->player3Name;
}

void GameField::assignPlayerPointsLabels()
{
    this->playerPointsLabels[0] = ui->player1Points;
    this->playerPointsLabels[1] = ui->player2Points;
    this->playerPointsLabels[2] = ui->player3Points;
}

void GameField::assignCategoryLabels()
{
    this->categories[0] = ui->category1;
    this->categories[1] = ui->category2;
    this->categories[2] = ui->category3;
    this->categories[3] = ui->category4;
    this->categories[4] = ui->category5;
}

/* Todo: refactor */
void GameField::setCategoryNames()
{
    int categoryLine;
    QString categoryName;

    this->fileString = QString("answers/%1.jrf").arg(this->round);
    QFile file(this->fileString);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open round file, please select one by yourself"));

        this->fileString = QFileDialog::getOpenFileName(this, tr("Open File"), "answers/", tr("Jeopardy Round File (*.jrf)"));
    }

    for(int i = 1; i < NUMBER_CATEGORIES + OFFSET; i++)
    {
        QFile file(this->fileString);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
          QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
          return;
        }

        QTextStream in(&file);

        int CATEGORY = i;

        /* Calculate on which line the categories in the file start */
        categoryLine = (CATEGORY == 1) ? 1 : ((CATEGORY - OFFSET) * NUMBER_CATEGORIES) + CATEGORY;

        /* Step to appropriate category section */
        for(int lineNr = 0; lineNr != categoryLine; lineNr++)
            categoryName = in.readLine();

        this->categories[CATEGORY - OFFSET]->setText(categoryName);
    }
}

void GameField::setNames()
{
    for(int i = 0; i < NUMBER_PLAYERS; i++)
        this->playerNameLabels[i]->setText(this->players[i]->getName());
}

void GameField::setPoints()
{
    for(int i = 0; i < NUMBER_PLAYERS; i++)
        this->playerPointsLabels[i]->setText("0");
}

void GameField::setLabelColor()
{
    QString color;

    for(int i = 0; i < NUMBER_PLAYERS; i++)
    {
        color = QString("QLabel { background-color : %1; }").arg(this->players[i]->getColor());
        this->playerNameLabels[i]->setStyleSheet(color);
    }
}

void GameField::updateGameFieldValues()
{
    this->updatePointsLabels();
    this->updateNamesLabels();
    this->setLabelColor();
}

void GameField::updatePointsLabels()
{
    QString points;

    for(int i = 0; i < NUMBER_PLAYERS; i++)
    {
        points = QString("%1").arg(this->players[i]->getPoints());
        this->playerPointsLabels[i]->setText(points);
    }
}

void GameField::updateNamesLabels()
{
    for(int i = 0; i < NUMBER_PLAYERS; i++)
        this->playerNameLabels[i]->setText(this->players[i]->getName());
}

void GameField::updateLabelsAfterAnswer()
{
    this->updatePointsLabels();
    this->updateNamesLabels();
}

void GameField::updateAfterAnswer()
{
    this->incAlreadyAnswered(1);
    this->updateLabelsAfterAnswer();
}

void GameField::openAnswer(int category, int points)
{
    this->answer = new Answer(this, this->fileString, this->round, this->players);
    this->answer->setAnswer(category, points);

    this->lastWinner = this->answer->exec();
    this->buttons[( points / POINTS_FACTOR - OFFSET) * NUMBER_CATEGORIES + category - OFFSET]->setStyleSheet(this->getButtonColorByLastWinner());
    this->lastPoints = this->answer->getPoints();
    this->result = answer->getResult();

    this->processResult();
    this->updateAfterAnswer();

    if(this->getAlreadyAnswered() < COMPLETELY_ANSWERED)
    {
        /* Do backup after each answer */
        this->openFileSaver(true);
    }
    else
    {
        this->showPodium();
        done(0);
    }
}

void GameField::showPodium()
{
    this->podium = new Podium(this, this->players);
    this->podium->exec();
}

void GameField::processResult()
{
    int playerId;

    while(this->result.length() > 0)
    {
        if(this->result.startsWith(PLAYER_ONE_STRING))
            playerId = PLAYER_ONE;
        else if(this->result.startsWith(PLAYER_TWO_STRING))
            playerId = PLAYER_TWO;
        else
            playerId = PLAYER_THREE;

        this->result.remove(0, PLAYER_INDICATOR);

        if(this->result.startsWith(WON))
            this->players[playerId]->incPoints(this->lastPoints);
        else
            this->players[playerId]->decPoints(this->lastPoints);

        this->result.remove(0, RESULT_INDICATOR);
    }
}

void GameField::insertPlayers(Player *players[NUMBER_PLAYERS])
{
    for(int i = 0; i < NUMBER_PLAYERS; i++)
        this->players[i] = players[i];
}

void GameField::setRound(int round)
{
    this->round = round;
}

int GameField::getRound()
{
    return this->round;
}

void GameField::incAlreadyAnswered(int number)
{
    this->alreadyAnswered += number;
}

void GameField::setAlreadyAnswered(int number)
{
    this->alreadyAnswered = number;
}

int GameField::getAlreadyAnswered()
{
    return this->alreadyAnswered;
}

void GameField::on_gameField_customContextMenuRequested(QPoint pos)
{
    QPoint globalPos = this->mapToGlobal(pos);

    QMenu menu;
    this->editorCtx = new QAction("Editor",this);
    this->loadCtx = new QAction("Load",this);
    this->saveCtx = new QAction("Save",this);
    this->endRoundCtx = new QAction("End Round", this);

    menu.addAction(this->editorCtx);
    menu.addSeparator();
    menu.addAction(this->loadCtx);
    menu.addAction(this->saveCtx);
    menu.addSeparator();
    menu.addAction(this->endRoundCtx);

    QAction *selectedItem = menu.exec(globalPos);

    if(selectedItem == this->editorCtx)
        this->openEditor();
    else if(selectedItem == this->saveCtx)
        this->openFileSaver(false);
    else if(selectedItem == this->loadCtx)
        this->openFileLoader();
    else if(selectedItem == this->endRoundCtx)
    {
        this->showPodium();
        done(0);
    }
}

void GameField::openEditor()
{
    this->editor = new Editor(this, this->players);
    this->editor->exec();
    this->updateGameFieldValues();
}

void GameField::openFileLoader()
{
    int lineNr = 0;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "gameStates/", tr("Jeopardy Game States (*.jgs)"));

    if (fileName != "")
    {
      QFile file(fileName);
      if (!file.open(QIODevice::ReadOnly))
      {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
      }
      QTextStream in(&file);
      while (!in.atEnd())
      {
          QString line = in.readLine();
          switch(lineNr)
          {
          case 0:
          case 1:
          case 2:
              this->players[lineNr]->setName(line);
              break;
          case 3:
          case 4:
          case 5:
              this->players[lineNr - 3]->setPoints(line.toInt());
              break;
          case 6:
          case 7:
          case 8:
              this->players[lineNr - 6]->setColor(line);
              break;
          case 59:
              this->alreadyAnswered = line.toInt();
              break;
          default:
              /* Already questioned answers */
              if(9 <= lineNr && lineNr <= 33)
                  this->buttons[lineNr - 9]->setDisabled(line.toInt());
              /* Color buttons with player color */
              else if(34 <= lineNr && lineNr <= 58)
              {
                  if(line == "r")
                      line = "red";
                  else if (line == "g")
                      line = "green";
                  else if(line == "y")
                      line = "yellow";
                  else if(line == "b")
                      line = "blue";

                  line.prepend("QPushButton { background-color : ");
                  line.append("; }");
                  this->buttons[lineNr - 34]->setStyleSheet(line);
              }
              break;
          }
          lineNr++;
      }

      this->updateGameFieldValues();
      file.close();
    }
}

void GameField::openFileSaver(bool backup)
{
    QString fileName;
    QDateTime dateTime;

    if(backup == true)
    {
        fileName = QString("gameStates/backups/backup_%1_%2").arg(this->getRound()).arg(dateTime.currentDateTime().toTime_t());
    }
    else
        fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "gameStates/", tr("Jeopardy Game States (*.jgs)"));

    if(NOT == fileName.endsWith(".jgs"))
        fileName.append(".jgs");

    if (fileName != "")
    {
      QFile file(fileName);
      if (!file.open(QIODevice::WriteOnly))
      {
        QMessageBox::critical(this, tr("Error"), tr("File not writeable"));
        return;
      }
      else
      {
        QTextStream stream(&file);

        for(int i = 0; i < NUMBER_PLAYERS; i++)
            stream << this->players[i]->getName() << '\n';

        for(int i = 0; i < NUMBER_PLAYERS; i++)
            stream << this->players[i]->getPoints() << '\n';

        for(int i = 0; i < NUMBER_PLAYERS; i++)
            stream << this->players[i]->getColor() << '\n';

        for(int i = 0; i < NUMBER_CATEGORIES * NUMBER_ANSWERS; i++)
            stream << !this->buttons[i]->isEnabled() << '\n';

        for(int i = 0; i < NUMBER_CATEGORIES * NUMBER_ANSWERS; i++)
        {
            /* Just save first character of color */
            QString stylesheet = this->buttons[i]->styleSheet();
            stylesheet.remove(0,COLOR_TEXT_LENGTH);
            int len = stylesheet.length();
            stylesheet.chop(--len);

            stream << stylesheet << '\n';
        }

        stream << this->alreadyAnswered << '\n';

        stream.flush();
        file.close();
      }
    }
}

QString GameField::getButtonColorByLastWinner()
{
    QString color = "";

    if(this->lastWinner == NO_WINNER)
        return color;

    color = QString("QPushButton { background-color : %1; }").arg(this->players[this->lastWinner]->getColor());

    return color;
}

/* 100 points buttons */
void GameField::on_button_1_100_clicked()
{
    this->buttons[0]->setDisabled(true);
    this->openAnswer(1, 100);
}
void GameField::on_button_2_100_clicked()
{
    this->buttons[1]->setDisabled(true);
    this->openAnswer(2, 100);
}
void GameField::on_button_3_100_clicked()
{
    this->buttons[2]->setDisabled(true);
    this->openAnswer(3, 100);
}
void GameField::on_button_4_100_clicked()
{
    this->buttons[3]->setDisabled(true);
    this->openAnswer(4, 100);
}
void GameField::on_button_5_100_clicked()
{
    this->buttons[4]->setDisabled(true);
    this->openAnswer(5, 100);
}
/* 200 points buttons */
void GameField::on_button_1_200_clicked()
{
    this->buttons[5]->setDisabled(true);
    this->openAnswer(1, 200);
}
void GameField::on_button_2_200_clicked()
{
    this->buttons[6]->setDisabled(true);
    this->openAnswer(2, 200);
}
void GameField::on_button_3_200_clicked()
{
    this->buttons[7]->setDisabled(true);
    this->openAnswer(3, 200);
}
void GameField::on_button_4_200_clicked()
{
    this->buttons[8]->setDisabled(true);
    this->openAnswer(4, 200);
}
void GameField::on_button_5_200_clicked()
{
    this->buttons[9]->setDisabled(true);
    this->openAnswer(5, 200);
}
/* 300 points buttons */
void GameField::on_button_1_300_clicked()
{
    this->buttons[10]->setDisabled(true);
    this->openAnswer(1, 300);
}
void GameField::on_button_2_300_clicked()
{
    this->buttons[11]->setDisabled(true);
    this->openAnswer(2, 300);
}
void GameField::on_button_3_300_clicked()
{
    this->buttons[12]->setDisabled(true);
    this->openAnswer(3, 300);
}
void GameField::on_button_4_300_clicked()
{
    this->buttons[13]->setDisabled(true);
    this->openAnswer(4, 300);
}
void GameField::on_button_5_300_clicked()
{
    this->buttons[14]->setDisabled(true);
    this->openAnswer(5, 300);
}
/* 400 points buttons */
void GameField::on_button_1_400_clicked()
{
    this->buttons[15]->setDisabled(true);
    this->openAnswer(1, 400);
}
void GameField::on_button_2_400_clicked()
{
    this->buttons[16]->setDisabled(true);
    this->openAnswer(2, 400);
}
void GameField::on_button_3_400_clicked()
{
    this->buttons[17]->setDisabled(true);
    this->openAnswer(3, 400);
}
void GameField::on_button_4_400_clicked()
{
    this->buttons[18]->setDisabled(true);
    this->openAnswer(4, 400);
}
void GameField::on_button_5_400_clicked()
{
    this->buttons[19]->setDisabled(true);
    this->openAnswer(5, 400);
}
/* 500 points buttons */
void GameField::on_button_1_500_clicked()
{
    this->buttons[20]->setDisabled(true);
    this->openAnswer(1, 500);
}
void GameField::on_button_2_500_clicked()
{
    this->buttons[21]->setDisabled(true);
    this->openAnswer(2, 500);
}
void GameField::on_button_3_500_clicked()
{
    this->buttons[22]->setDisabled(true);
    this->openAnswer(3, 500);
}
void GameField::on_button_4_500_clicked()
{
    this->buttons[23]->setDisabled(true);
    this->openAnswer(4, 500);
}
void GameField::on_button_5_500_clicked()
{
    this->buttons[24]->setDisabled(true);
    this->openAnswer(5, 500);
}
