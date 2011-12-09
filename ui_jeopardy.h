/********************************************************************************
** Form generated from reading UI file 'jeopardy.ui'
**
** Created: Fri Dec 9 08:28:10 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JEOPARDY_H
#define UI_JEOPARDY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Jeopardy
{
public:
    QWidget *centralWidget;
    QPushButton *buttonRound1;
    QPushButton *buttonRound2;
    QPushButton *buttonRound3;
    QPushButton *buttonRound4;

    void setupUi(QMainWindow *Jeopardy)
    {
        if (Jeopardy->objectName().isEmpty())
            Jeopardy->setObjectName(QString::fromUtf8("Jeopardy"));
        Jeopardy->resize(600, 81);
        Jeopardy->setMinimumSize(QSize(600, 81));
        centralWidget = new QWidget(Jeopardy);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        buttonRound1 = new QPushButton(centralWidget);
        buttonRound1->setObjectName(QString::fromUtf8("buttonRound1"));
        buttonRound1->setGeometry(QRect(0, 0, 151, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Andale Mono"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        buttonRound1->setFont(font);
        buttonRound1->setFlat(false);
        buttonRound2 = new QPushButton(centralWidget);
        buttonRound2->setObjectName(QString::fromUtf8("buttonRound2"));
        buttonRound2->setGeometry(QRect(150, 0, 151, 81));
        buttonRound2->setFont(font);
        buttonRound3 = new QPushButton(centralWidget);
        buttonRound3->setObjectName(QString::fromUtf8("buttonRound3"));
        buttonRound3->setGeometry(QRect(300, 0, 151, 81));
        buttonRound3->setFont(font);
        buttonRound4 = new QPushButton(centralWidget);
        buttonRound4->setObjectName(QString::fromUtf8("buttonRound4"));
        buttonRound4->setGeometry(QRect(450, 0, 151, 81));
        buttonRound4->setFont(font);
        Jeopardy->setCentralWidget(centralWidget);

        retranslateUi(Jeopardy);

        QMetaObject::connectSlotsByName(Jeopardy);
    } // setupUi

    void retranslateUi(QMainWindow *Jeopardy)
    {
        Jeopardy->setWindowTitle(QApplication::translate("Jeopardy", "Jeopardy", 0, QApplication::UnicodeUTF8));
        buttonRound1->setText(QApplication::translate("Jeopardy", "Round 1", 0, QApplication::UnicodeUTF8));
        buttonRound2->setText(QApplication::translate("Jeopardy", "Round 2", 0, QApplication::UnicodeUTF8));
        buttonRound3->setText(QApplication::translate("Jeopardy", "Round 3", 0, QApplication::UnicodeUTF8));
        buttonRound4->setText(QApplication::translate("Jeopardy", "Round 4", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Jeopardy: public Ui_Jeopardy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JEOPARDY_H
