/********************************************************************************
** Form generated from reading UI file 'doublejeopardy.ui'
**
** Created: Sat Nov 26 04:37:18 2011
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
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DoubleJeopardy
{
public:
    QLineEdit *points;
    QLabel *min;
    QLabel *max;
    QPushButton *button;
    QComboBox *comboBox;

    void setupUi(QDialog *DoubleJeopardy)
    {
        if (DoubleJeopardy->objectName().isEmpty())
            DoubleJeopardy->setObjectName(QString::fromUtf8("DoubleJeopardy"));
        DoubleJeopardy->resize(242, 186);
        points = new QLineEdit(DoubleJeopardy);
        points->setObjectName(QString::fromUtf8("points"));
        points->setGeometry(QRect(20, 80, 201, 27));
        points->setInputMethodHints(Qt::ImhDigitsOnly);
        points->setMaxLength(4);
        min = new QLabel(DoubleJeopardy);
        min->setObjectName(QString::fromUtf8("min"));
        min->setGeometry(QRect(20, 50, 201, 17));
        max = new QLabel(DoubleJeopardy);
        max->setObjectName(QString::fromUtf8("max"));
        max->setGeometry(QRect(20, 120, 201, 17));
        button = new QPushButton(DoubleJeopardy);
        button->setObjectName(QString::fromUtf8("button"));
        button->setGeometry(QRect(20, 150, 201, 27));
        comboBox = new QComboBox(DoubleJeopardy);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 221, 31));

        retranslateUi(DoubleJeopardy);

        QMetaObject::connectSlotsByName(DoubleJeopardy);
    } // setupUi

    void retranslateUi(QDialog *DoubleJeopardy)
    {
        DoubleJeopardy->setWindowTitle(QApplication::translate("DoubleJeopardy", "Dialog", 0, QApplication::UnicodeUTF8));
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
