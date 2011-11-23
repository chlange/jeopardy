/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created: Wed Nov 23 02:44:43 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    QPushButton *save;
    QLineEdit *linePlayer1;
    QLineEdit *linePlayer2;
    QLineEdit *linePlayer3;
    QLineEdit *player1;
    QLineEdit *player2;
    QLineEdit *player3;

    void setupUi(QDialog *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QString::fromUtf8("Editor"));
        Editor->resize(251, 170);
        Editor->setMinimumSize(QSize(251, 170));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Editor->setWindowIcon(icon);
        save = new QPushButton(Editor);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(10, 140, 231, 27));
        linePlayer1 = new QLineEdit(Editor);
        linePlayer1->setObjectName(QString::fromUtf8("linePlayer1"));
        linePlayer1->setGeometry(QRect(130, 20, 113, 27));
        linePlayer1->setInputMethodHints(Qt::ImhDigitsOnly);
        linePlayer1->setMaxLength(8);
        linePlayer1->setFrame(true);
        linePlayer2 = new QLineEdit(Editor);
        linePlayer2->setObjectName(QString::fromUtf8("linePlayer2"));
        linePlayer2->setGeometry(QRect(130, 60, 113, 27));
        linePlayer2->setInputMethodHints(Qt::ImhDigitsOnly);
        linePlayer2->setMaxLength(8);
        linePlayer3 = new QLineEdit(Editor);
        linePlayer3->setObjectName(QString::fromUtf8("linePlayer3"));
        linePlayer3->setGeometry(QRect(130, 100, 113, 27));
        linePlayer3->setInputMethodHints(Qt::ImhDigitsOnly);
        linePlayer3->setMaxLength(8);
        player1 = new QLineEdit(Editor);
        player1->setObjectName(QString::fromUtf8("player1"));
        player1->setGeometry(QRect(10, 20, 113, 27));
        player1->setInputMethodHints(Qt::ImhDigitsOnly);
        player1->setMaxLength(8);
        player1->setFrame(true);
        player2 = new QLineEdit(Editor);
        player2->setObjectName(QString::fromUtf8("player2"));
        player2->setGeometry(QRect(10, 60, 113, 27));
        player2->setInputMethodHints(Qt::ImhDigitsOnly);
        player2->setMaxLength(8);
        player2->setFrame(true);
        player3 = new QLineEdit(Editor);
        player3->setObjectName(QString::fromUtf8("player3"));
        player3->setGeometry(QRect(10, 100, 113, 27));
        player3->setInputMethodHints(Qt::ImhDigitsOnly);
        player3->setMaxLength(8);
        player3->setFrame(true);

        retranslateUi(Editor);

        QMetaObject::connectSlotsByName(Editor);
    } // setupUi

    void retranslateUi(QDialog *Editor)
    {
        Editor->setWindowTitle(QApplication::translate("Editor", "Editor", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("Editor", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
