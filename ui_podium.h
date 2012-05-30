/********************************************************************************
** Form generated from reading UI file 'podium.ui'
**
** Created: Fri Dec 9 08:28:10 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PODIUM_H
#define UI_PODIUM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Podium
{
public:
    QLabel *third;
    QLabel *second;
    QLabel *first;

    void setupUi(QDialog *Podium)
    {
        if (Podium->objectName().isEmpty())
            Podium->setObjectName(QString::fromUtf8("Podium"));
        Podium->resize(740, 414);
        Podium->setMinimumSize(QSize(740, 414));
        third = new QLabel(Podium);
        third->setObjectName(QString::fromUtf8("third"));
        third->setGeometry(QRect(370, 220, 331, 171));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(third->sizePolicy().hasHeightForWidth());
        third->setSizePolicy(sizePolicy);
        third->setMinimumSize(QSize(331, 171));
        QFont font;
        font.setFamily(QString::fromUtf8("Andale Mono"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        third->setFont(font);
        third->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 85, 0);"));
        third->setTextFormat(Qt::RichText);
        third->setAlignment(Qt::AlignCenter);
        second = new QLabel(Podium);
        second->setObjectName(QString::fromUtf8("second"));
        second->setGeometry(QRect(40, 220, 331, 171));
        sizePolicy.setHeightForWidth(second->sizePolicy().hasHeightForWidth());
        second->setSizePolicy(sizePolicy);
        second->setMinimumSize(QSize(331, 171));
        second->setFont(font);
        second->setStyleSheet(QString::fromUtf8("background-color: rgb(175, 175, 175);"));
        second->setTextFormat(Qt::RichText);
        second->setAlignment(Qt::AlignCenter);
        first = new QLabel(Podium);
        first->setObjectName(QString::fromUtf8("first"));
        first->setGeometry(QRect(120, 20, 501, 201));
        sizePolicy.setHeightForWidth(first->sizePolicy().hasHeightForWidth());
        first->setSizePolicy(sizePolicy);
        first->setMinimumSize(QSize(501, 201));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Andale Mono"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        first->setFont(font1);
        first->setStyleSheet(QString::fromUtf8("background-color: rgb(227, 151, 0);"));
        first->setTextFormat(Qt::RichText);
        first->setScaledContents(false);
        first->setAlignment(Qt::AlignCenter);

        retranslateUi(Podium);

        QMetaObject::connectSlotsByName(Podium);
    } // setupUi

    void retranslateUi(QDialog *Podium)
    {
        Podium->setWindowTitle(QApplication::translate("Podium", "Podium", 0, QApplication::UnicodeUTF8));
        third->setText(QString());
        second->setText(QString());
        first->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Podium: public Ui_Podium {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PODIUM_H
