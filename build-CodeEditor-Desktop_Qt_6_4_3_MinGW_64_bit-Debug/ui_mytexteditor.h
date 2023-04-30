/********************************************************************************
** Form generated from reading UI file 'mytexteditor.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTEXTEDITOR_H
#define UI_MYTEXTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTextEditor
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QScrollBar *horizontalScrollBar;

    void setupUi(QWidget *MyTextEditor)
    {
        if (MyTextEditor->objectName().isEmpty())
            MyTextEditor->setObjectName("MyTextEditor");
        MyTextEditor->resize(624, 395);
        verticalLayout = new QVBoxLayout(MyTextEditor);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        textBrowser = new QTextBrowser(MyTextEditor);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMaximumSize(QSize(25, 16777215));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout->addWidget(textBrowser);

        textEdit = new QTextEdit(MyTextEditor);
        textEdit->setObjectName("textEdit");
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);

        horizontalLayout->addWidget(textEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalScrollBar = new QScrollBar(MyTextEditor);
        horizontalScrollBar->setObjectName("horizontalScrollBar");
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalScrollBar);


        retranslateUi(MyTextEditor);

        QMetaObject::connectSlotsByName(MyTextEditor);
    } // setupUi

    void retranslateUi(QWidget *MyTextEditor)
    {
        MyTextEditor->setWindowTitle(QCoreApplication::translate("MyTextEditor", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTextEditor: public Ui_MyTextEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTEXTEDITOR_H
