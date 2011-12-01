/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created: Wed Nov 30 00:42:45 2011
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *player1Name;
    QLineEdit *player3Name;
    QLineEdit *player2Name;
    QLineEdit *player2Points;
    QLineEdit *player1Points;
    QLineEdit *player3Points;
    QLineEdit *player4Name;
    QLineEdit *player5Name;
    QLineEdit *player6Name;
    QLineEdit *player4Points;
    QLineEdit *player5Points;
    QLineEdit *player6Points;
    QPushButton *save;

    void setupUi(QDialog *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QString::fromUtf8("Editor"));
        Editor->resize(251, 280);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Editor->sizePolicy().hasHeightForWidth());
        Editor->setSizePolicy(sizePolicy);
        Editor->setMinimumSize(QSize(251, 170));
        QIcon icon;
        icon.addFile(QString::fromUtf8(""), QSize(), QIcon::Normal, QIcon::Off);
        Editor->setWindowIcon(icon);
        gridLayoutWidget = new QWidget(Editor);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 231, 261));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        player1Name = new QLineEdit(gridLayoutWidget);
        player1Name->setObjectName(QString::fromUtf8("player1Name"));
        player1Name->setMinimumSize(QSize(111, 27));

        gridLayout->addWidget(player1Name, 0, 0, 1, 1);

        player3Name = new QLineEdit(gridLayoutWidget);
        player3Name->setObjectName(QString::fromUtf8("player3Name"));
        player3Name->setMinimumSize(QSize(111, 27));

        gridLayout->addWidget(player3Name, 3, 0, 1, 1);

        player2Name = new QLineEdit(gridLayoutWidget);
        player2Name->setObjectName(QString::fromUtf8("player2Name"));
        player2Name->setMinimumSize(QSize(111, 27));

        gridLayout->addWidget(player2Name, 1, 0, 1, 1);

        player2Points = new QLineEdit(gridLayoutWidget);
        player2Points->setObjectName(QString::fromUtf8("player2Points"));
        player2Points->setMinimumSize(QSize(111, 27));
        player2Points->setInputMethodHints(Qt::ImhDigitsOnly);

        gridLayout->addWidget(player2Points, 1, 1, 1, 1);

        player1Points = new QLineEdit(gridLayoutWidget);
        player1Points->setObjectName(QString::fromUtf8("player1Points"));
        player1Points->setMinimumSize(QSize(111, 27));
        player1Points->setInputMethodHints(Qt::ImhDigitsOnly);

        gridLayout->addWidget(player1Points, 0, 1, 1, 1);

        player3Points = new QLineEdit(gridLayoutWidget);
        player3Points->setObjectName(QString::fromUtf8("player3Points"));
        player3Points->setMinimumSize(QSize(111, 27));
        player3Points->setInputMethodHints(Qt::ImhDigitsOnly);

        gridLayout->addWidget(player3Points, 3, 1, 1, 1);

        player4Name = new QLineEdit(gridLayoutWidget);
        player4Name->setObjectName(QString::fromUtf8("player4Name"));
        player4Name->setMinimumSize(QSize(111, 27));

        gridLayout->addWidget(player4Name, 4, 0, 1, 1);

        player5Name = new QLineEdit(gridLayoutWidget);
        player5Name->setObjectName(QString::fromUtf8("player5Name"));
        player5Name->setMinimumSize(QSize(111, 27));

        gridLayout->addWidget(player5Name, 5, 0, 1, 1);

        player6Name = new QLineEdit(gridLayoutWidget);
        player6Name->setObjectName(QString::fromUtf8("player6Name"));
        player6Name->setMinimumSize(QSize(111, 27));

        gridLayout->addWidget(player6Name, 6, 0, 1, 1);

        player4Points = new QLineEdit(gridLayoutWidget);
        player4Points->setObjectName(QString::fromUtf8("player4Points"));
        player4Points->setMinimumSize(QSize(111, 27));
        player4Points->setInputMethodHints(Qt::ImhDigitsOnly);

        gridLayout->addWidget(player4Points, 4, 1, 1, 1);

        player5Points = new QLineEdit(gridLayoutWidget);
        player5Points->setObjectName(QString::fromUtf8("player5Points"));
        player5Points->setMinimumSize(QSize(111, 27));
        player5Points->setInputMethodHints(Qt::ImhDigitsOnly);

        gridLayout->addWidget(player5Points, 5, 1, 1, 1);

        player6Points = new QLineEdit(gridLayoutWidget);
        player6Points->setObjectName(QString::fromUtf8("player6Points"));
        player6Points->setMinimumSize(QSize(111, 27));
        player6Points->setInputMethodHints(Qt::ImhDigitsOnly);

        gridLayout->addWidget(player6Points, 6, 1, 1, 1);

        save = new QPushButton(gridLayoutWidget);
        save->setObjectName(QString::fromUtf8("save"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(save->sizePolicy().hasHeightForWidth());
        save->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(save, 7, 0, 1, 2);


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
