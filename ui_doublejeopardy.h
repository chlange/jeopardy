/********************************************************************************
** Form generated from reading UI file 'doublejeopardy.ui'
**
** Created: Thu Dec 1 09:53:22 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLEJEOPARDY_H
#define UI_DOUBLEJEOPARDY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DoubleJeopardy
{
public:
    QLabel *min;
    QLabel *max;
    QPushButton *button;
    QComboBox *comboBox;
    QSpinBox *points;

    void setupUi(QDialog *DoubleJeopardy)
    {
        if (DoubleJeopardy->objectName().isEmpty())
            DoubleJeopardy->setObjectName(QString::fromUtf8("DoubleJeopardy"));
        DoubleJeopardy->resize(161, 186);
        min = new QLabel(DoubleJeopardy);
        min->setObjectName(QString::fromUtf8("min"));
        min->setGeometry(QRect(20, 50, 201, 17));
        max = new QLabel(DoubleJeopardy);
        max->setObjectName(QString::fromUtf8("max"));
        max->setGeometry(QRect(20, 120, 201, 17));
        button = new QPushButton(DoubleJeopardy);
        button->setObjectName(QString::fromUtf8("button"));
        button->setGeometry(QRect(10, 150, 141, 27));
        comboBox = new QComboBox(DoubleJeopardy);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 141, 31));
        points = new QSpinBox(DoubleJeopardy);
        points->setObjectName(QString::fromUtf8("points"));
        points->setGeometry(QRect(14, 80, 131, 27));

        retranslateUi(DoubleJeopardy);

        QMetaObject::connectSlotsByName(DoubleJeopardy);
    } // setupUi

    void retranslateUi(QDialog *DoubleJeopardy)
    {
        DoubleJeopardy->setWindowTitle(QApplication::translate("DoubleJeopardy", "Double Jeopardy", 0, QApplication::UnicodeUTF8));
        min->setText(QApplication::translate("DoubleJeopardy", "Min", 0, QApplication::UnicodeUTF8));
        max->setText(QApplication::translate("DoubleJeopardy", "Max", 0, QApplication::UnicodeUTF8));
        button->setText(QApplication::translate("DoubleJeopardy", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DoubleJeopardy: public Ui_DoubleJeopardy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLEJEOPARDY_H
