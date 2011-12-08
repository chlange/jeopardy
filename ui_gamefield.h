/********************************************************************************
** Form generated from reading UI file 'gamefield.ui'
**
** Created: Thu Dec 1 12:25:52 2011
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
    QPushButton *button_1_200;
    QLabel *category5;
    QPushButton *button_3_200;
    QPushButton *button_3_100;
    QPushButton *button_2_300;
    QPushButton *button_2_400;
    QPushButton *button_5_100;
    QPushButton *button_5_400;
    QPushButton *button_4_100;
    QPushButton *button_2_100;
    QPushButton *button_5_200;
    QPushButton *button_2_200;
    QLabel *category6;
    QPushButton *button_6_200;
    QPushButton *button_6_100;
    QPushButton *button_6_400;
    QPushButton *button_6_500;
    QPushButton *button_6_300;

    void setupUi(QWidget *gameField)
    {
        if (gameField->objectName().isEmpty())
            gameField->setObjectName(QString::fromUtf8("gameField"));
        gameField->resize(1200, 635);
        gameField->setMinimumSize(QSize(998, 615));
        gameField->setMouseTracking(false);
        gameField->setContextMenuPolicy(Qt::CustomContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Initialize"), QSize(), QIcon::Normal, QIcon::Off);
        gameField->setWindowIcon(icon);
        button_4_500 = new QPushButton(gameField);
        button_4_500->setObjectName(QString::fromUtf8("button_4_500"));
        button_4_500->setGeometry(QRect(600, 480, 198, 107));
        QFont font;
        font.setFamily(QString::fromUtf8("Andale Mono"));
        font.setPointSize(18);
        button_4_500->setFont(font);
        button_5_300 = new QPushButton(gameField);
        button_5_300->setObjectName(QString::fromUtf8("button_5_300"));
        button_5_300->setGeometry(QRect(801, 260, 198, 107));
        button_5_300->setFont(font);
        button_1_400 = new QPushButton(gameField);
        button_1_400->setObjectName(QString::fromUtf8("button_1_400"));
        button_1_400->setGeometry(QRect(1, 370, 198, 107));
        button_1_400->setFont(font);
        category4 = new QLabel(gameField);
        category4->setObjectName(QString::fromUtf8("category4"));
        category4->setGeometry(QRect(600, 0, 200, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Andale Mono"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        category4->setFont(font1);
        category4->setAlignment(Qt::AlignCenter);
        button_3_300 = new QPushButton(gameField);
        button_3_300->setObjectName(QString::fromUtf8("button_3_300"));
        button_3_300->setGeometry(QRect(401, 260, 198, 107));
        button_3_300->setFont(font);
        button_4_400 = new QPushButton(gameField);
        button_4_400->setObjectName(QString::fromUtf8("button_4_400"));
        button_4_400->setGeometry(QRect(600, 370, 198, 107));
        button_4_400->setFont(font);
        button_1_300 = new QPushButton(gameField);
        button_1_300->setObjectName(QString::fromUtf8("button_1_300"));
        button_1_300->setGeometry(QRect(1, 260, 198, 107));
        button_1_300->setFont(font);
        button_5_500 = new QPushButton(gameField);
        button_5_500->setObjectName(QString::fromUtf8("button_5_500"));
        button_5_500->setGeometry(QRect(801, 480, 198, 107));
        button_5_500->setFont(font);
        button_4_200 = new QPushButton(gameField);
        button_4_200->setObjectName(QString::fromUtf8("button_4_200"));
        button_4_200->setGeometry(QRect(600, 150, 198, 107));
        button_4_200->setFont(font);
        button_4_300 = new QPushButton(gameField);
        button_4_300->setObjectName(QString::fromUtf8("button_4_300"));
        button_4_300->setGeometry(QRect(600, 260, 198, 107));
        button_4_300->setFont(font);
        category3 = new QLabel(gameField);
        category3->setObjectName(QString::fromUtf8("category3"));
        category3->setGeometry(QRect(401, 0, 200, 40));
        category3->setFont(font1);
        category3->setAlignment(Qt::AlignCenter);
        button_1_500 = new QPushButton(gameField);
        button_1_500->setObjectName(QString::fromUtf8("button_1_500"));
        button_1_500->setGeometry(QRect(1, 480, 198, 107));
        button_1_500->setFont(font);
        button_1_100 = new QPushButton(gameField);
        button_1_100->setObjectName(QString::fromUtf8("button_1_100"));
        button_1_100->setGeometry(QRect(1, 40, 198, 107));
        button_1_100->setFont(font);
        button_1_100->setFlat(false);
        category2 = new QLabel(gameField);
        category2->setObjectName(QString::fromUtf8("category2"));
        category2->setGeometry(QRect(201, 0, 200, 40));
        category2->setFont(font1);
        category2->setAlignment(Qt::AlignCenter);
        button_3_400 = new QPushButton(gameField);
        button_3_400->setObjectName(QString::fromUtf8("button_3_400"));
        button_3_400->setGeometry(QRect(401, 370, 198, 107));
        button_3_400->setFont(font);
        button_3_500 = new QPushButton(gameField);
        button_3_500->setObjectName(QString::fromUtf8("button_3_500"));
        button_3_500->setGeometry(QRect(401, 480, 198, 107));
        button_3_500->setFont(font);
        button_2_500 = new QPushButton(gameField);
        button_2_500->setObjectName(QString::fromUtf8("button_2_500"));
        button_2_500->setGeometry(QRect(201, 480, 198, 107));
        button_2_500->setFont(font);
        category1 = new QLabel(gameField);
        category1->setObjectName(QString::fromUtf8("category1"));
        category1->setGeometry(QRect(1, 0, 200, 40));
        category1->setFont(font1);
        category1->setAlignment(Qt::AlignCenter);
        button_1_200 = new QPushButton(gameField);
        button_1_200->setObjectName(QString::fromUtf8("button_1_200"));
        button_1_200->setGeometry(QRect(1, 150, 198, 107));
        button_1_200->setFont(font);
        button_1_200->setCursor(QCursor(Qt::ArrowCursor));
        category5 = new QLabel(gameField);
        category5->setObjectName(QString::fromUtf8("category5"));
        category5->setGeometry(QRect(797, 0, 200, 40));
        category5->setFont(font1);
        category5->setAlignment(Qt::AlignCenter);
        button_3_200 = new QPushButton(gameField);
        button_3_200->setObjectName(QString::fromUtf8("button_3_200"));
        button_3_200->setGeometry(QRect(401, 150, 198, 107));
        button_3_200->setFont(font);
        button_3_100 = new QPushButton(gameField);
        button_3_100->setObjectName(QString::fromUtf8("button_3_100"));
        button_3_100->setGeometry(QRect(401, 40, 198, 107));
        button_3_100->setFont(font);
        button_2_300 = new QPushButton(gameField);
        button_2_300->setObjectName(QString::fromUtf8("button_2_300"));
        button_2_300->setGeometry(QRect(201, 260, 198, 107));
        button_2_300->setFont(font);
        button_2_400 = new QPushButton(gameField);
        button_2_400->setObjectName(QString::fromUtf8("button_2_400"));
        button_2_400->setGeometry(QRect(201, 370, 198, 107));
        button_2_400->setFont(font);
        button_5_100 = new QPushButton(gameField);
        button_5_100->setObjectName(QString::fromUtf8("button_5_100"));
        button_5_100->setGeometry(QRect(801, 40, 198, 107));
        button_5_100->setFont(font);
        button_5_400 = new QPushButton(gameField);
        button_5_400->setObjectName(QString::fromUtf8("button_5_400"));
        button_5_400->setGeometry(QRect(801, 370, 198, 107));
        button_5_400->setFont(font);
        button_4_100 = new QPushButton(gameField);
        button_4_100->setObjectName(QString::fromUtf8("button_4_100"));
        button_4_100->setGeometry(QRect(601, 40, 198, 107));
        button_4_100->setFont(font);
        button_2_100 = new QPushButton(gameField);
        button_2_100->setObjectName(QString::fromUtf8("button_2_100"));
        button_2_100->setGeometry(QRect(201, 40, 198, 107));
        button_2_100->setFont(font);
        button_5_200 = new QPushButton(gameField);
        button_5_200->setObjectName(QString::fromUtf8("button_5_200"));
        button_5_200->setGeometry(QRect(801, 150, 198, 107));
        button_5_200->setFont(font);
        button_2_200 = new QPushButton(gameField);
        button_2_200->setObjectName(QString::fromUtf8("button_2_200"));
        button_2_200->setGeometry(QRect(201, 150, 198, 107));
        button_2_200->setFont(font);
        category6 = new QLabel(gameField);
        category6->setObjectName(QString::fromUtf8("category6"));
        category6->setGeometry(QRect(990, 0, 200, 40));
        category6->setFont(font1);
        category6->setAlignment(Qt::AlignCenter);
        button_6_200 = new QPushButton(gameField);
        button_6_200->setObjectName(QString::fromUtf8("button_6_200"));
        button_6_200->setGeometry(QRect(1000, 150, 198, 107));
        button_6_200->setFont(font);
        button_6_100 = new QPushButton(gameField);
        button_6_100->setObjectName(QString::fromUtf8("button_6_100"));
        button_6_100->setGeometry(QRect(1000, 40, 198, 107));
        button_6_100->setFont(font);
        button_6_400 = new QPushButton(gameField);
        button_6_400->setObjectName(QString::fromUtf8("button_6_400"));
        button_6_400->setGeometry(QRect(1000, 370, 198, 107));
        button_6_400->setFont(font);
        button_6_500 = new QPushButton(gameField);
        button_6_500->setObjectName(QString::fromUtf8("button_6_500"));
        button_6_500->setGeometry(QRect(1000, 480, 198, 107));
        button_6_500->setFont(font);
        button_6_300 = new QPushButton(gameField);
        button_6_300->setObjectName(QString::fromUtf8("button_6_300"));
        button_6_300->setGeometry(QRect(1000, 260, 198, 107));
        button_6_300->setFont(font);

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
        button_1_200->setText(QApplication::translate("gameField", "200", 0, QApplication::UnicodeUTF8));
        category5->setText(QApplication::translate("gameField", "cat5", 0, QApplication::UnicodeUTF8));
        button_3_200->setText(QApplication::translate("gameField", "200", 0, QApplication::UnicodeUTF8));
        button_3_100->setText(QApplication::translate("gameField", "100", 0, QApplication::UnicodeUTF8));
        button_2_300->setText(QApplication::translate("gameField", "300", 0, QApplication::UnicodeUTF8));
        button_2_400->setText(QApplication::translate("gameField", "400", 0, QApplication::UnicodeUTF8));
        button_5_100->setText(QApplication::translate("gameField", "100", 0, QApplication::UnicodeUTF8));
        button_5_400->setText(QApplication::translate("gameField", "400", 0, QApplication::UnicodeUTF8));
        button_4_100->setText(QApplication::translate("gameField", "100", 0, QApplication::UnicodeUTF8));
        button_2_100->setText(QApplication::translate("gameField", "100", 0, QApplication::UnicodeUTF8));
        button_5_200->setText(QApplication::translate("gameField", "200", 0, QApplication::UnicodeUTF8));
        button_2_200->setText(QApplication::translate("gameField", "200", 0, QApplication::UnicodeUTF8));
        category6->setText(QApplication::translate("gameField", "cat6", 0, QApplication::UnicodeUTF8));
        button_6_200->setText(QApplication::translate("gameField", "200", 0, QApplication::UnicodeUTF8));
        button_6_100->setText(QApplication::translate("gameField", "100", 0, QApplication::UnicodeUTF8));
        button_6_400->setText(QApplication::translate("gameField", "400", 0, QApplication::UnicodeUTF8));
        button_6_500->setText(QApplication::translate("gameField", "500", 0, QApplication::UnicodeUTF8));
        button_6_300->setText(QApplication::translate("gameField", "300", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class gameField: public Ui_gameField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFIELD_H
