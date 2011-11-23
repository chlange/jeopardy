/********************************************************************************
** Form generated from reading UI file 'gamefield.ui'
**
** Created: Wed Nov 23 02:44:43 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEFIELD_H
#define UI_GAMEFIELD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameField
{
public:
    QPushButton *button_4_500;
    QPushButton *button_5_300;
    QPushButton *button_1_400;
    QLabel *category4;
    QPushButton *button_3_300;
    QPushButton *button_4_400;
    QPushButton *button_1_300;
    QPushButton *button_5_500;
    QPushButton *button_4_200;
    QPushButton *button_4_300;
    QLabel *category3;
    QPushButton *button_1_500;
    QPushButton *button_1_100;
    QLabel *category2;
    QPushButton *button_3_400;
    QPushButton *button_3_500;
    QPushButton *button_2_500;
    QLabel *category1;
    QLabel *player2Name;
    QPushButton *button_1_200;
    QLabel *player2Points;
    QLabel *player3Points;
    QLabel *category5;
    QPushButton *button_3_200;
    QPushButton *button_3_100;
    QPushButton *button_2_300;
    QPushButton *button_2_400;
    QPushButton *button_5_100;
    QPushButton *button_5_400;
    QLabel *player1Points;
    QPushButton *button_4_100;
    QPushButton *button_2_100;
    QLabel *player3Name;
    QPushButton *button_5_200;
    QLabel *player1Name;
    QPushButton *button_2_200;

    void setupUi(QWidget *gameField)
    {
        if (gameField->objectName().isEmpty())
            gameField->setObjectName(QString::fromUtf8("gameField"));
        gameField->resize(998, 615);
        gameField->setMinimumSize(QSize(998, 615));
        gameField->setMouseTracking(false);
        gameField->setContextMenuPolicy(Qt::CustomContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Initialize"), QSize(), QIcon::Normal, QIcon::Off);
        gameField->setWindowIcon(icon);
        button_4_500 = new QPushButton(gameField);
        button_4_500->setObjectName(QString::fromUtf8("button_4_500"));
        button_4_500->setGeometry(QRect(600, 480, 198, 107));
        button_5_300 = new QPushButton(gameField);
        button_5_300->setObjectName(QString::fromUtf8("button_5_300"));
        button_5_300->setGeometry(QRect(801, 260, 198, 107));
        button_1_400 = new QPushButton(gameField);
        button_1_400->setObjectName(QString::fromUtf8("button_1_400"));
        button_1_400->setGeometry(QRect(1, 370, 198, 107));
        category4 = new QLabel(gameField);
        category4->setObjectName(QString::fromUtf8("category4"));
        category4->setGeometry(QRect(600, 0, 200, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Andale Mono"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        category4->setFont(font);
        category4->setAlignment(Qt::AlignCenter);
        button_3_300 = new QPushButton(gameField);
        button_3_300->setObjectName(QString::fromUtf8("button_3_300"));
        button_3_300->setGeometry(QRect(401, 260, 198, 107));
        button_4_400 = new QPushButton(gameField);
        button_4_400->setObjectName(QString::fromUtf8("button_4_400"));
        button_4_400->setGeometry(QRect(600, 370, 198, 107));
        button_1_300 = new QPushButton(gameField);
        button_1_300->setObjectName(QString::fromUtf8("button_1_300"));
        button_1_300->setGeometry(QRect(1, 260, 198, 107));
        button_5_500 = new QPushButton(gameField);
        button_5_500->setObjectName(QString::fromUtf8("button_5_500"));
        button_5_500->setGeometry(QRect(801, 480, 198, 107));
        button_4_200 = new QPushButton(gameField);
        button_4_200->setObjectName(QString::fromUtf8("button_4_200"));
        button_4_200->setGeometry(QRect(600, 150, 198, 107));
        button_4_300 = new QPushButton(gameField);
        button_4_300->setObjectName(QString::fromUtf8("button_4_300"));
        button_4_300->setGeometry(QRect(600, 260, 198, 107));
        category3 = new QLabel(gameField);
        category3->setObjectName(QString::fromUtf8("category3"));
        category3->setGeometry(QRect(401, 0, 200, 40));
        category3->setFont(font);
        category3->setAlignment(Qt::AlignCenter);
        button_1_500 = new QPushButton(gameField);
        button_1_500->setObjectName(QString::fromUtf8("button_1_500"));
        button_1_500->setGeometry(QRect(1, 480, 198, 107));
        button_1_100 = new QPushButton(gameField);
        button_1_100->setObjectName(QString::fromUtf8("button_1_100"));
        button_1_100->setGeometry(QRect(1, 40, 198, 107));
        button_1_100->setFlat(false);
        category2 = new QLabel(gameField);
        category2->setObjectName(QString::fromUtf8("category2"));
        category2->setGeometry(QRect(201, 0, 200, 40));
        category2->setFont(font);
        category2->setAlignment(Qt::AlignCenter);
        button_3_400 = new QPushButton(gameField);
        button_3_400->setObjectName(QString::fromUtf8("button_3_400"));
        button_3_400->setGeometry(QRect(401, 370, 198, 107));
        button_3_500 = new QPushButton(gameField);
        button_3_500->setObjectName(QString::fromUtf8("button_3_500"));
        button_3_500->setGeometry(QRect(401, 480, 198, 107));
        button_2_500 = new QPushButton(gameField);
        button_2_500->setObjectName(QString::fromUtf8("button_2_500"));
        button_2_500->setGeometry(QRect(201, 480, 198, 107));
        category1 = new QLabel(gameField);
        category1->setObjectName(QString::fromUtf8("category1"));
        category1->setGeometry(QRect(1, 0, 200, 40));
        category1->setFont(font);
        category1->setAlignment(Qt::AlignCenter);
        player2Name = new QLabel(gameField);
        player2Name->setObjectName(QString::fromUtf8("player2Name"));
        player2Name->setGeometry(QRect(380, 590, 120, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Andale Mono"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        player2Name->setFont(font1);
        player2Name->setAlignment(Qt::AlignCenter);
        button_1_200 = new QPushButton(gameField);
        button_1_200->setObjectName(QString::fromUtf8("button_1_200"));
        button_1_200->setGeometry(QRect(1, 150, 198, 107));
        button_1_200->setCursor(QCursor(Qt::BlankCursor));
        player2Points = new QLabel(gameField);
        player2Points->setObjectName(QString::fromUtf8("player2Points"));
        player2Points->setGeometry(QRect(500, 590, 120, 20));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        player2Points->setPalette(palette);
        player2Points->setFont(font1);
        player2Points->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        player2Points->setAlignment(Qt::AlignCenter);
        player3Points = new QLabel(gameField);
        player3Points->setObjectName(QString::fromUtf8("player3Points"));
        player3Points->setGeometry(QRect(880, 590, 120, 20));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        player3Points->setPalette(palette1);
        player3Points->setFont(font1);
        player3Points->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        player3Points->setAlignment(Qt::AlignCenter);
        category5 = new QLabel(gameField);
        category5->setObjectName(QString::fromUtf8("category5"));
        category5->setGeometry(QRect(797, 0, 200, 40));
        category5->setFont(font);
        category5->setAlignment(Qt::AlignCenter);
        button_3_200 = new QPushButton(gameField);
        button_3_200->setObjectName(QString::fromUtf8("button_3_200"));
        button_3_200->setGeometry(QRect(401, 150, 198, 107));
        button_3_100 = new QPushButton(gameField);
        button_3_100->setObjectName(QString::fromUtf8("button_3_100"));
        button_3_100->setGeometry(QRect(401, 40, 198, 107));
        button_2_300 = new QPushButton(gameField);
        button_2_300->setObjectName(QString::fromUtf8("button_2_300"));
        button_2_300->setGeometry(QRect(201, 260, 198, 107));
        button_2_400 = new QPushButton(gameField);
        button_2_400->setObjectName(QString::fromUtf8("button_2_400"));
        button_2_400->setGeometry(QRect(201, 370, 198, 107));
        button_5_100 = new QPushButton(gameField);
        button_5_100->setObjectName(QString::fromUtf8("button_5_100"));
        button_5_100->setGeometry(QRect(801, 40, 198, 107));
        button_5_400 = new QPushButton(gameField);
        button_5_400->setObjectName(QString::fromUtf8("button_5_400"));
        button_5_400->setGeometry(QRect(801, 370, 198, 107));
        player1Points = new QLabel(gameField);
        player1Points->setObjectName(QString::fromUtf8("player1Points"));
        player1Points->setGeometry(QRect(121, 590, 120, 20));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        player1Points->setPalette(palette2);
        player1Points->setFont(font1);
        player1Points->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        player1Points->setAlignment(Qt::AlignCenter);
        button_4_100 = new QPushButton(gameField);
        button_4_100->setObjectName(QString::fromUtf8("button_4_100"));
        button_4_100->setGeometry(QRect(601, 40, 198, 107));
        button_2_100 = new QPushButton(gameField);
        button_2_100->setObjectName(QString::fromUtf8("button_2_100"));
        button_2_100->setGeometry(QRect(201, 40, 198, 107));
        player3Name = new QLabel(gameField);
        player3Name->setObjectName(QString::fromUtf8("player3Name"));
        player3Name->setGeometry(QRect(760, 590, 120, 20));
        player3Name->setFont(font1);
        player3Name->setAlignment(Qt::AlignCenter);
        button_5_200 = new QPushButton(gameField);
        button_5_200->setObjectName(QString::fromUtf8("button_5_200"));
        button_5_200->setGeometry(QRect(801, 150, 198, 107));
        player1Name = new QLabel(gameField);
        player1Name->setObjectName(QString::fromUtf8("player1Name"));
        player1Name->setGeometry(QRect(1, 590, 120, 20));
        player1Name->setFont(font1);
        player1Name->setAlignment(Qt::AlignCenter);
        button_2_200 = new QPushButton(gameField);
        button_2_200->setObjectName(QString::fromUtf8("button_2_200"));
        button_2_200->setGeometry(QRect(201, 150, 198, 107));

        retranslateUi(gameField);

        QMetaObject::connectSlotsByName(gameField);
    } // setupUi

    void retranslateUi(QWidget *gameField)
    {
        gameField->setWindowTitle(QApplication::translate("gameField", "Jeopardy", 0, QApplication::UnicodeUTF8));
        button_4_500->setText(QApplication::translate("gameField", "500", 0, QApplication::UnicodeUTF8));
        button_5_300->setText(QApplication::translate("gameField", "300", 0, QApplication::UnicodeUTF8));
        button_1_400->setText(QApplication::translate("gameField", "400", 0, QApplication::UnicodeUTF8));
        category4->setText(QApplication::translate("gameField", "cat4", 0, QApplication::UnicodeUTF8));
        button_3_300->setText(QApplication::translate("gameField", "300", 0, QApplication::UnicodeUTF8));
        button_4_400->setText(QApplication::translate("gameField", "400", 0, QApplication::UnicodeUTF8));
        button_1_300->setText(QApplication::translate("gameField", "300", 0, QApplication::UnicodeUTF8));
        button_5_500->setText(QApplication::translate("gameField", "500", 0, QApplication::UnicodeUTF8));
        button_4_200->setText(QApplication::translate("gameField", "200", 0, QApplication::UnicodeUTF8));
        button_4_300->setText(QApplication::translate("gameField", "300", 0, QApplication::UnicodeUTF8));
        category3->setText(QApplication::translate("gameField", "cat3", 0, QApplication::UnicodeUTF8));
        button_1_500->setText(QApplication::translate("gameField", "500", 0, QApplication::UnicodeUTF8));
        button_1_100->setText(QApplication::translate("gameField", "100", 0, QApplication::UnicodeUTF8));
        category2->setText(QApplication::translate("gameField", "cat2", 0, QApplication::UnicodeUTF8));
        button_3_400->setText(QApplication::translate("gameField", "400", 0, QApplication::UnicodeUTF8));
        button_3_500->setText(QApplication::translate("gameField", "500", 0, QApplication::UnicodeUTF8));
        button_2_500->setText(QApplication::translate("gameField", "500", 0, QApplication::UnicodeUTF8));
        category1->setText(QApplication::translate("gameField", "cat1", 0, QApplication::UnicodeUTF8));
        player2Name->setText(QApplication::translate("gameField", "Player2", 0, QApplication::UnicodeUTF8));
        button_1_200->setText(QApplication::translate("gameField", "200", 0, QApplication::UnicodeUTF8));
        player2Points->setText(QApplication::translate("gameField", "Points", 0, QApplication::UnicodeUTF8));
        player3Points->setText(QApplication::translate("gameField", "Points", 0, QApplication::UnicodeUTF8));
        category5->setText(QApplication::translate("gameField", "cat5", 0, QApplication::UnicodeUTF8));
        button_3_200->setText(QApplication::translate("gameField", "200", 0, QApplication::UnicodeUTF8));
        button_3_100->setText(QApplication::translate("gameField", "100", 0, QApplication::UnicodeUTF8));
        button_2_300->setText(QApplication::translate("gameField", "300", 0, QApplication::UnicodeUTF8));
        button_2_400->setText(QApplication::translate("gameField", "400", 0, QApplication::UnicodeUTF8));
        button_5_100->setText(QApplication::translate("gameField", "100", 0, QApplication::UnicodeUTF8));
        button_5_400->setText(QApplication::translate("gameField", "400", 0, QApplication::UnicodeUTF8));
        player1Points->setText(QApplication::translate("gameField", "Points", 0, QApplication::UnicodeUTF8));
        button_4_100->setText(QApplication::translate("gameField", "100", 0, QApplication::UnicodeUTF8));
        button_2_100->setText(QApplication::translate("gameField", "100", 0, QApplication::UnicodeUTF8));
        player3Name->setText(QApplication::translate("gameField", "Player3", 0, QApplication::UnicodeUTF8));
        button_5_200->setText(QApplication::translate("gameField", "200", 0, QApplication::UnicodeUTF8));
        player1Name->setText(QApplication::translate("gameField", "Player1", 0, QApplication::UnicodeUTF8));
        button_2_200->setText(QApplication::translate("gameField", "200", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gameField: public Ui_gameField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFIELD_H
