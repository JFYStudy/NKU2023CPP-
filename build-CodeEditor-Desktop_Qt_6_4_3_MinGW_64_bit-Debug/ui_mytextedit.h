/********************************************************************************
** Form generated from reading UI file 'mytextedit.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTEXTEDIT_H
#define UI_MYTEXTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTextEdit
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QScrollBar *horizontalScrollBar;

    void setupUi(QWidget *MyTextEdit)
    {
        if (MyTextEdit->objectName().isEmpty())
            MyTextEdit->setObjectName("MyTextEdit");
        MyTextEdit->resize(582, 396);
        verticalLayout_2 = new QVBoxLayout(MyTextEdit);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        textBrowser = new QTextBrowser(MyTextEdit);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMaximumSize(QSize(20, 16777215));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout->addWidget(textBrowser);

        textEdit = new QTextEdit(MyTextEdit);
        textEdit->setObjectName("textEdit");
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);

        horizontalLayout->addWidget(textEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalScrollBar = new QScrollBar(MyTextEdit);
        horizontalScrollBar->setObjectName("horizontalScrollBar");
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalScrollBar);


        retranslateUi(MyTextEdit);

        QMetaObject::connectSlotsByName(MyTextEdit);
    } // setupUi

    void retranslateUi(QWidget *MyTextEdit)
    {
        MyTextEdit->setWindowTitle(QCoreApplication::translate("MyTextEdit", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTextEdit: public Ui_MyTextEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTEXTEDIT_H
