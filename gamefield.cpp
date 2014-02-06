/*
 * Copyright (c) 2011-2014, Christian Lange
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

GameField::GameField(QWidget *parent, int round, int categoryNr, Player *players, int playerNr, bool sound, QString fileString) :
    QDialog(parent), round(round), alreadyAnswered(0), lastWinner(NO_WINNER),
    lastPoints(0), playerNr(playerNr), categoryNr(categoryNr), sound(sound), players(players), answer(), podium(NULL),
    randomCtx(NULL), editorCtx(NULL), loadCtx(NULL), saveCtx(NULL), endRoundCtx(NULL), about(NULL), fileString(fileString)
{
}

GameField::~GameField()
{
    if(this->randomCtx != NULL)
        delete this->randomCtx;
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
    if(this->about != NULL)
        delete this->about;

    delete this->categoryLabelGrid;
    delete this->buttonGrid;
    delete this->playerLabelGrid;
    delete this->mainGrid;

    delete this->window;
}

void GameField::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        break;
    default:
        break;
    }
}

void GameField::init()
{
    this->insertLayouts();
    this->assignButtons();
    this->assignPlayerNameLabels();
    this->assignPlayerPointsLabels();
    this->assignCategoryLabels();
    this->processCategoryLabels();
    this->setNames();
    this->setPoints();
    this->setLabelColor();

    /* Declare new context menu and connect it with the right mouse button */
    this->window->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this->window, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(on_gameField_customContextMenuRequested(QPoint)));

    this->window->show();

    this->currentPlayer = this->random();
    this->updateCurrentPlayerLabel();
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

void GameField::insertLayouts()
{
    this->window = new QWidget();
    this->window->setGeometry(0, 0, GAMEFIELD_WIDTH, GAMEFIELD_HEIGHT);

    this->mainGrid = new QGridLayout();
    this->mainGrid->setSpacing(0);

    this->categoryLabelGrid = new QGridLayout();
    this->categoryLabelGrid->setSpacing(0);

    this->buttonGrid = new QGridLayout();
    this->buttonGrid->setSpacing(0);

    this->playerLabelGrid = new QGridLayout();
    this->playerLabelGrid->setSpacing(0);

    this->mainGrid->addLayout(this->categoryLabelGrid, 0, 0);
    this->mainGrid->addLayout(this->buttonGrid, 1, 0);
    this->mainGrid->addLayout(this->playerLabelGrid, 2, 0);

    this->mainGrid->setGeometry(QRect(0, 0, GAMEFIELD_WIDTH, GAMEFIELD_HEIGHT));
    this->categoryLabelGrid->setGeometry(QRect(0, 0, GAMEFIELD_WIDTH, CATEGORY_LABEL_HEIGHT));
    this->buttonGrid->setGeometry(QRect(0, CATEGORY_LABEL_HEIGHT, GAMEFIELD_WIDTH, GAMEFIELD_HEIGHT - CATEGORY_LABEL_HEIGHT - NAME_LABEL_HEIGHT - NAME_LABEL_HEIGHT));
    this->playerLabelGrid->setGeometry(QRect(0, GAMEFIELD_HEIGHT - NAME_LABEL_HEIGHT - NAME_LABEL_HEIGHT, GAMEFIELD_WIDTH, NAME_LABEL_HEIGHT + NAME_LABEL_HEIGHT));

    this->window->installEventFilter(this);
    this->window->setLayout(this->mainGrid);
}

void GameField::assignCategoryLabels()
{
    int width, height;

    for(int i = 0; i < NUMBER_MAX_CATEGORIES; i++)
        this->categoryLabels[i] = new QLabel();

    width = GAMEFIELD_WIDTH / this->categoryNr;
    height = CATEGORY_LABEL_HEIGHT;

    for(int i = 0; i < this->categoryNr; i++)
    {
        this->categoryLabels[i]->setGeometry(0, 0, width, height);
        this->categoryLabels[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        this->categoryLabelGrid->addWidget(this->categoryLabels[i], 0, i);
    }
}

void GameField::assignButtons()
{
    for(int i = 0; i < NUMBER_MAX_ANSWERS; i++)
    {
        this->buttons[i] = new QPushButton();
        this->buttons[i]->installEventFilter(this);
    }

    for(int j = 0; j < this->categoryNr; j++)
    {
        for(int i = 0; i < NUMBER_ANSWERS; i++)
        {
            int currentButton = (NUMBER_MAX_CATEGORIES * i) + j;

            this->setDefaultButtonAppearance((i + 1) * POINTS_FACTOR, currentButton);
            this->categoryLabelGrid->addWidget(this->buttons[currentButton], i + 1, j);
        }
    }

        connect(this->buttons[0], SIGNAL(clicked()), this, SLOT(on_button_1_100_clicked()));
        connect(this->buttons[6], SIGNAL(clicked()), this, SLOT(on_button_1_200_clicked()));
        connect(this->buttons[12], SIGNAL(clicked()), this, SLOT(on_button_1_300_clicked()));
        connect(this->buttons[18], SIGNAL(clicked()), this, SLOT(on_button_1_400_clicked()));
        connect(this->buttons[24], SIGNAL(clicked()), this, SLOT(on_button_1_500_clicked()));

    if(this->categoryNr >= 2)
    {
        connect(this->buttons[1], SIGNAL(clicked()), this, SLOT(on_button_2_100_clicked()));
        connect(this->buttons[7], SIGNAL(clicked()), this, SLOT(on_button_2_200_clicked()));
        connect(this->buttons[13], SIGNAL(clicked()), this, SLOT(on_button_2_300_clicked()));
        connect(this->buttons[19], SIGNAL(clicked()), this, SLOT(on_button_2_400_clicked()));
        connect(this->buttons[25], SIGNAL(clicked()), this, SLOT(on_button_2_500_clicked()));
    }

    if(this->categoryNr >= 3)
    {
        connect(this->buttons[2], SIGNAL(clicked()), this, SLOT(on_button_3_100_clicked()));
        connect(this->buttons[8], SIGNAL(clicked()), this, SLOT(on_button_3_200_clicked()));
        connect(this->buttons[14], SIGNAL(clicked()), this, SLOT(on_button_3_300_clicked()));
        connect(this->buttons[20], SIGNAL(clicked()), this, SLOT(on_button_3_400_clicked()));
        connect(this->buttons[26], SIGNAL(clicked()), this, SLOT(on_button_3_500_clicked()));
    }

    if(this->categoryNr >= 4)
    {
        connect(this->buttons[3], SIGNAL(clicked()), this, SLOT(on_button_4_100_clicked()));
        connect(this->buttons[9], SIGNAL(clicked()), this, SLOT(on_button_4_200_clicked()));
        connect(this->buttons[15], SIGNAL(clicked()), this, SLOT(on_button_4_300_clicked()));
        connect(this->buttons[21], SIGNAL(clicked()), this, SLOT(on_button_4_400_clicked()));
        connect(this->buttons[27], SIGNAL(clicked()), this, SLOT(on_button_4_500_clicked()));
    }

    if(this->categoryNr >= 5)
    {
        connect(this->buttons[4], SIGNAL(clicked()), this, SLOT(on_button_5_100_clicked()));
        connect(this->buttons[10], SIGNAL(clicked()), this, SLOT(on_button_5_200_clicked()));
        connect(this->buttons[16], SIGNAL(clicked()), this, SLOT(on_button_5_300_clicked()));
        connect(this->buttons[22], SIGNAL(clicked()), this, SLOT(on_button_5_400_clicked()));
        connect(this->buttons[28], SIGNAL(clicked()), this, SLOT(on_button_5_500_clicked()));
    }

    if(this->categoryNr >= 6)
    {
        connect(this->buttons[5], SIGNAL(clicked()), this, SLOT(on_button_6_100_clicked()));
        connect(this->buttons[11], SIGNAL(clicked()), this, SLOT(on_button_6_200_clicked()));
        connect(this->buttons[17], SIGNAL(clicked()), this, SLOT(on_button_6_300_clicked()));
        connect(this->buttons[23], SIGNAL(clicked()), this, SLOT(on_button_6_400_clicked()));
        connect(this->buttons[29], SIGNAL(clicked()), this, SLOT(on_button_6_500_clicked()));
    }
}

void GameField::setDefaultButtonAppearance(int points, int currentButton)
{
    QFont font;
    font.setPointSize(20);

    this->buttons[currentButton]->setFont(font);
    this->buttons[currentButton]->setText(QString("%1").arg(points));
    this->buttons[currentButton]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->buttons[currentButton]->setStyleSheet("");
    this->buttons[currentButton]->setEnabled(true);
}

void GameField::assignPlayerNameLabels()
{
    int row, column, width, height;

    for(int i = 0; i < NUMBER_MAX_PLAYERS; i++)
        this->playerNameLabels[i] = new QLabel();

    height = NAME_LABEL_HEIGHT;

    for(int i = 0; i < this->playerNr; i++)
    {
        if((i + 1) <= NUMBER_MAX_PLAYERS / 2)
        {
            row = FIRST_LABEL_ROW;
            column = i * 2;
            width = GAMEFIELD_WIDTH / this->playerNr / SPLIT_FOR_TWO_LABELS;
        }
        else
        {
            row = FIRST_LABEL_ROW + 1;
            column = (i - NUMBER_MAX_PLAYERS / 2) * 2;
            width = GAMEFIELD_WIDTH / (NUMBER_MAX_PLAYERS / 2) / SPLIT_FOR_TWO_LABELS;
        }

        this->playerNameLabels[i]->setGeometry(0, 0, width, height);
        this->playerNameLabels[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        this->playerLabelGrid->addWidget(this->playerNameLabels[i], row, column);
    }
}

void GameField::assignPlayerPointsLabels()
{
    int row, column, width, height;

    for(int i = 0; i < NUMBER_MAX_PLAYERS; i++)
        this->playerPointsLabels[i] = new QLabel();

    height = NAME_LABEL_HEIGHT;

    for(int i = 0; i < this->playerNr; i++)
    {
        if((i + 1) <= NUMBER_MAX_PLAYERS / 2)
        {
            row = FIRST_LABEL_ROW;
            column = 2 * i + 1;
            width = GAMEFIELD_WIDTH / this->playerNr / SPLIT_FOR_TWO_LABELS;
        }
        else
        {
            row = FIRST_LABEL_ROW + 1;
            column = 2 * (i - NUMBER_MAX_PLAYERS / 2) + 1;
            width = GAMEFIELD_WIDTH / (NUMBER_MAX_PLAYERS / 2) / SPLIT_FOR_TWO_LABELS;
        }

        this->playerPointsLabels[i]->setGeometry(0, 0, width, height);
        this->playerPointsLabels[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        this->playerLabelGrid->addWidget(this->playerPointsLabels[i], row, column);
    }
}

void GameField::processCategoryLabels()
{
    int categoryLine;
    QFont font;
    QString categoryName;
    font.setBold(true);

    for(int i = 0; i < this->categoryNr; i++)
    {
        QFile file(this->fileString);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
          QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
          return;
        }

        QTextStream in(&file);

        /* Calculate on which line the categories in the file start */
        categoryLine = NUMBER_MAX_CATEGORIES * i + 1;

        /* Step to appropriate category section */
        for(int lineNr = 0; lineNr != categoryLine; lineNr++)
            categoryName = in.readLine();

        this->categoryLabels[i]->setFont(font);
        this->categoryLabels[i]->setGeometry(0, 0, GAMEFIELD_WIDTH / this->categoryNr, CATEGORY_LABEL_HEIGHT);
        this->categoryLabels[i]->setAlignment(Qt::AlignHCenter);
        this->categoryLabels[i]->setText(categoryName);
    }
}

void GameField::setLabelColor()
{
    QString color;

    for(int i = 0; i < this->playerNr; i++)
    {
        color = QString("QLabel { background-color : %1; color: black;}").arg(this->players[i].getColor());
        this->playerNameLabels[i]->setStyleSheet(color);
    }
}

void GameField::setPoints()
{
    for(int i = 0; i < this->playerNr; i++)
        this->playerPointsLabels[i]->setText("0");
}

void GameField::setNames()
{
    for(int i = 0; i < this->playerNr; i++)
    {
        if(this->currentPlayer == i)
            this->playerNameLabels[i]->setText(QString("%1 ***").arg(this->players[i].getName()));
        else
            this->playerNameLabels[i]->setText(this->players[i].getName());
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
    for(int i = 0; i < this->playerNr; i++)
    {
        this->playerPointsLabels[i]->setStyleSheet(QString(""));
        this->playerPointsLabels[i]->setText(QString::number(this->players[i].getPoints()));
    }
}

void GameField::updateNamesLabels()
{
    this->setNames();
    this->setLabelColor();
}

void GameField::updateLabelsAfterAnswer()
{
    this->updatePointsLabels();
    this->updateNamesLabels();
}

void GameField::updateAfterAnswer()
{
    this->incAlreadyAnswered(1);
    this->updatePointsLabels();
}

void GameField::updateCurrentPlayerLabel()
{
    this->updateNamesLabels();
    this->playerNameLabels[this->currentPlayer]->setText(QString("%1 ***").arg(this->players[this->currentPlayer].getName()));
}

QString GameField::getButtonColorByLastWinner()
{
    return QString("QPushButton { background-color : %1; color : black; }").arg(this->players[this->lastWinner].getColor());
}

void GameField::openAnswer(int category, int points)
{
    this->answer = new Answer(this, this->fileString, this->round, this->players, this->playerNr, this->sound, this->currentPlayer);
    this->answer->setAnswer(category, points);

    this->answer->exec();

    this->processAnswer(category, points);

    this->processResult();
    this->updateAfterAnswer();

    if(this->getAlreadyAnswered() < this->categoryNr * NUMBER_ANSWERS)
    {
        /* Do backup after each answer */
        this->openFileSaver(true);
    }
    else
    {
        this->showPodium();
        this->window->close();
    }
}

void GameField::processAnswer(int category, int points)
{
    QPushButton *button = this->buttons[NUMBER_MAX_CATEGORIES * (points / POINTS_FACTOR - OFFSET) + category - OFFSET];
    button->setText("");
    this->currentPlayer = this->lastWinner = this->answer->getWinner();
    this->lastPoints = this->answer->getPoints();
    this->result = answer->getResult();

    /* Write player name on button */
    if(this->lastWinner != NO_WINNER)
    {
        button->setStyleSheet(this->getButtonColorByLastWinner());
        button->setText(this->players[this->lastWinner].getName());
    }
    else
    {
        this->currentPlayer = this->random();
    }

    this->updateNamesLabels();
    this->updateCurrentPlayerLabel();
    delete this->answer;
}

void GameField::processResult()
{
    int playerId = 0;

    while(this->result.length() > 0)
    {
        for(int i = 0; i < NUMBER_MAX_PLAYERS; i++)
            if(this->result.startsWith(QString::number(i+1)))
                playerId = i;

        this->result.remove(0, PLAYER_INDICATOR);

        if(this->result.startsWith(WON))
            this->players[playerId].incPoints(this->lastPoints);
        else
            this->players[playerId].decPoints(this->lastPoints);

        this->result.remove(0, RESULT_INDICATOR);
    }
}

void GameField::openFileLoader()
{
    int lineNr = 0;
    QDir dir;
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "gameStates/", "Jeopardy Game State (*.jgs)");

    if(fileName == "")
        return;

    fileName = dir.absoluteFilePath(fileName);

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }

    delete this->window;

    QTextStream in(&file);

    QString line = in.readLine();

    for(int j = 0; j < NUMBER_MAX_PLAYERS; j++)
    {
        this->players[j].setName(line);
        line = in.readLine();
        lineNr++;

        this->players[j].setPoints(line.toInt());
        line = in.readLine();
        lineNr++;

        this->players[j].setColor(line);
        line = in.readLine();
        lineNr++;

        this->players[j].setKey(line.toInt());
        line = in.readLine();
        lineNr++;
    }

    this->alreadyAnswered = line.toInt();
    line = in.readLine();
    lineNr++;

    this->playerNr = line.toInt();
    line = in.readLine();
    lineNr++;

    this->categoryNr = line.toInt();
    line = in.readLine();
    lineNr++;

    this->init();

    /* Already questioned answers */
    for(int i = 0; i < NUMBER_MAX_ANSWERS; i++)
    {
        if(line.toInt() == 1)
            this->buttons[i]->setText("");

        this->buttons[i]->setDisabled(line.toInt());

        line = in.readLine();
        lineNr++;
    }

    /* Color buttons with player color */
    for(int i = 0; i < NUMBER_MAX_ANSWERS; i++)
    {
        if(line == "r")
            line = "red";
        else if (line == "g")
            line = "green";
        else if(line == "y")
            line = "yellow";
        else if(line == "b")
            line = "blue";
        else if(line == "gr")
            line = "gray";
        else if(line == "m")
            line = "magenta";
        else if(line == "c")
            line = "cyan";
        else if(line == "d")
            line = "darkRed";
        else if(line == "w")
            line = "white";
        else if(line == "dM")
            line = "darkMagenta";
        else
            line = "";

        if(line != "")
            for(int j = 0; j < this->playerNr; j++)
                if(this->players[j].getColor() == line)
                    this->buttons[i]->setText(this->players[j].getName());

        line.prepend("QPushButton { background-color : ");
        line.append("; }");

        this->buttons[i]->setStyleSheet(line);

        line = in.readLine();
        lineNr++;
    }

    this->updateGameFieldValues();

    file.close();
}

void GameField::openFileSaver(bool backup)
{
    QDir dir;
    QString fileName;
    QDateTime dateTime;

    if(backup == true)
        fileName = QString("gameStates/backups/backup_%1_%2").arg(this->getRound()).arg(dateTime.currentDateTime().toTime_t());
    else
        fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "gameStates/", tr("Jeopardy Game State (*.jgs)"));

    if(NOT == fileName.endsWith(".jgs"))
        fileName.append(".jgs");

    fileName = dir.absoluteFilePath(fileName);

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

        for(int i = 0; i < NUMBER_MAX_PLAYERS; i++)
        {
            stream << this->players[i].getName() << '\n';
            stream << this->players[i].getPoints() << '\n';
            stream << this->players[i].getColor() << '\n';
            stream << this->players[i].getKey() << '\n';
        }

        stream << this->alreadyAnswered << '\n';
        stream << this->playerNr << '\n';
        stream << this->categoryNr << '\n';

        for(int i = 0; i < NUMBER_MAX_ANSWERS; i++)
            stream << !this->buttons[i]->isEnabled() << '\n';

        for(int i = 0; i < NUMBER_MAX_ANSWERS; i++)
        {
            /* Just save first character of color */
            QString stylesheet = this->buttons[i]->styleSheet();
            stylesheet.remove(0,COLOR_TEXT_LENGTH);

            if(stylesheet.startsWith("gray"))
                stylesheet = "gr";
            else if(stylesheet.startsWith("darkMagenta"))
                stylesheet = "dM";
            else
            {
                /* chop string expect for first character */
                int len = stylesheet.length();
                stylesheet.chop(--len);
            }

            stream << stylesheet << '\n';
        }

        stream.flush();
        file.close();
        }
    }
}

void GameField::openEditor()
{
    this->editor = new Editor(this, this->players, this->playerNr);
    editor->show();

    this->openFileSaver(true);
    this->updateGameFieldValues();
}

int GameField::random()
{
    srand(time(NULL));

    int rn = rand() % this->playerNr;

    return rn;
}

void GameField::resetRound()
{
    this->setAlreadyAnswered(0);
    for(int i = 0; i < this->playerNr; i++)
        this->players[i].setPoints(0);

    for(int j = 0; j < this->categoryNr; j++)
    {
        for(int i = 0; i < NUMBER_ANSWERS; i++)
        {
            int currentButton = (NUMBER_MAX_CATEGORIES * i) + j;
            this->setDefaultButtonAppearance((i + 1) * POINTS_FACTOR, currentButton);
        }
    }

    this->updatePointsLabels();
}

void GameField::on_gameField_customContextMenuRequested(QPoint pos)
{
    QPoint globalPos = this->window->mapToGlobal(pos);

    QMenu menu;
    this->randomCtx = new QAction("Random Generator", this);
    this->editorCtx = new QAction("Editor",this);
    this->loadCtx = new QAction("Load",this);
    this->saveCtx = new QAction("Save",this);
    this->endRoundCtx = new QAction("End Round", this);
    this->resetRoundCtx = new QAction("Reset Round", this);
    this->about = new QAction("About", this);

    menu.addAction(this->randomCtx);
    menu.addSeparator();
    menu.addAction(this->editorCtx);
    menu.addSeparator();
    menu.addAction(this->loadCtx);
    menu.addAction(this->saveCtx);
    menu.addSeparator();
    menu.addAction(this->endRoundCtx);
    menu.addSeparator();
    menu.addAction(this->resetRoundCtx);
    menu.addSeparator();
    menu.addAction(this->about);

    QAction *selectedItem = menu.exec(globalPos);

    if(selectedItem == this->randomCtx)
    {
        this->updateNamesLabels();
        this->currentPlayer = this->random();
        this->updateCurrentPlayerLabel();
    }
    else if(selectedItem == this->editorCtx)
        this->openEditor();
    else if(selectedItem == this->saveCtx)
        this->openFileSaver(false);
    else if(selectedItem == this->loadCtx)
        this->openFileLoader();
    else if(selectedItem == this->endRoundCtx)
    {
        this->showPodium();
        this->window->close();
    }
    else if(selectedItem == this->resetRoundCtx)
        this->resetRound();
    else if(selectedItem == this->about)
    {
        QMessageBox msgBox;
        msgBox.setText("Jeopardy!\n\nWritten by Christian Lange.\nChristian_Lange@hotmail.com\n\nwww.github.com/chlange/jeopardy\nwww.ganz-sicher.net/chlange");
        msgBox.exec();
    }
}

void GameField::showPodium()
{
    this->podium = new Podium(this, this->players, this->playerNr);
    this->podium->showPodium();
}

bool GameField::eventFilter(QObject *target, QEvent *event)
{
    if(target == this->window && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

        /* Open random user picker if "r" gets pressed */
        if(keyEvent->key() == Qt::Key_R)
        {
            this->indicateRandom();
            this->updateNamesLabels();
            this->currentPlayer = this->random();
            this->updateCurrentPlayerLabel();
        }

        for(int i = 0; i < this->playerNr; i++)
        {
            /* Indicate key press of player over label */
            if(this->players[i].getKey() == keyEvent->key())
            {
                this->playerNameLabels[i]->setStyleSheet(QString("background-color: black; color: white;"));
                this->playerNameLabels[i]->setText(QString("%1 - it works").arg(this->players[i].getName()));
                QTimer::singleShot(200, this, SLOT(updateNamesLabels()));

                if(this->players[i].getPressed() > 13)
                {
                    this->players[i].decPoints(50);
                    QTimer::singleShot(200, this, SLOT(updatePointsLabels()));
                    QMessageBox::critical(this, tr("Error"),
                                         QString("%1 - That's enough - 50 points subtracted").arg(this->players[i].getName()));
                }
                else if(this->players[i].getPressed() > 10)
                {
                    int untilSub = 13 - this->players[i].getPressed() + 1;
                    QString until = (untilSub != 1) ? QString("presses") : QString("press");
                    QMessageBox::critical(this, tr("Error"),
                                         QString("%1 - You raped your key %2 times!\n%3 %4 until subtraction").arg(this->players[i].getName()).arg(this->players[i].getPressed()).arg(untilSub).arg(until));
                }

                this->players[i].incPressed();
            }
        }
    }

    return QDialog::eventFilter(target, event);
}

void GameField::indicateRandom()
{
    for(int i = 0; i < this->playerNr; i++)
        this->playerPointsLabels[i]->setStyleSheet(QString("background-color: black"));

    QTimer::singleShot(30, this, SLOT(updatePointsLabels()));
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
void GameField::on_button_6_100_clicked()
{
    this->buttons[5]->setDisabled(true);
    this->openAnswer(6, 100);
}
/* 200 points buttons */
void GameField::on_button_1_200_clicked()
{
    this->buttons[6]->setDisabled(true);
    this->openAnswer(1, 200);
}
void GameField::on_button_2_200_clicked()
{
    this->buttons[7]->setDisabled(true);
    this->openAnswer(2, 200);
}
void GameField::on_button_3_200_clicked()
{
    this->buttons[8]->setDisabled(true);
    this->openAnswer(3, 200);
}
void GameField::on_button_4_200_clicked()
{
    this->buttons[9]->setDisabled(true);
    this->openAnswer(4, 200);
}
void GameField::on_button_5_200_clicked()
{
    this->buttons[10]->setDisabled(true);
    this->openAnswer(5, 200);
}
void GameField::on_button_6_200_clicked()
{
    this->buttons[11]->setDisabled(true);
    this->openAnswer(6, 200);
}
/* 300 points buttons */
void GameField::on_button_1_300_clicked()
{
    this->buttons[12]->setDisabled(true);
    this->openAnswer(1, 300);
}
void GameField::on_button_2_300_clicked()
{
    this->buttons[13]->setDisabled(true);
    this->openAnswer(2, 300);
}
void GameField::on_button_3_300_clicked()
{
    this->buttons[14]->setDisabled(true);
    this->openAnswer(3, 300);
}
void GameField::on_button_4_300_clicked()
{
    this->buttons[15]->setDisabled(true);
    this->openAnswer(4, 300);
}
void GameField::on_button_5_300_clicked()
{
    this->buttons[16]->setDisabled(true);
    this->openAnswer(5, 300);
}
void GameField::on_button_6_300_clicked()
{
    this->buttons[17]->setDisabled(true);
    this->openAnswer(6, 300);
}
/* 400 points buttons */
void GameField::on_button_1_400_clicked()
{
    this->buttons[18]->setDisabled(true);
    this->openAnswer(1, 400);
}
void GameField::on_button_2_400_clicked()
{
    this->buttons[19]->setDisabled(true);
    this->openAnswer(2, 400);
}
void GameField::on_button_3_400_clicked()
{
    this->buttons[20]->setDisabled(true);
    this->openAnswer(3, 400);
}
void GameField::on_button_4_400_clicked()
{
    this->buttons[21]->setDisabled(true);
    this->openAnswer(4, 400);
}
void GameField::on_button_5_400_clicked()
{
    this->buttons[22]->setDisabled(true);
    this->openAnswer(5, 400);
}
void GameField::on_button_6_400_clicked()
{
    this->buttons[23]->setDisabled(true);
    this->openAnswer(6, 400);
}
/* 500 points buttons */
void GameField::on_button_1_500_clicked()
{
    this->buttons[24]->setDisabled(true);
    this->openAnswer(1, 500);
}
void GameField::on_button_2_500_clicked()
{
    this->buttons[25]->setDisabled(true);
    this->openAnswer(2, 500);
}
void GameField::on_button_3_500_clicked()
{
    this->buttons[26]->setDisabled(true);
    this->openAnswer(3, 500);
}
void GameField::on_button_4_500_clicked()
{
    this->buttons[27]->setDisabled(true);
    this->openAnswer(4, 500);
}
void GameField::on_button_5_500_clicked()
{
    this->buttons[28]->setDisabled(true);
    this->openAnswer(5, 500);
}
void GameField::on_button_6_500_clicked()
{
    this->buttons[29]->setDisabled(true);
    this->openAnswer(6, 500);
}
