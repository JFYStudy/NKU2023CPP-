#include "mytexteditbycode.h"

#include <qboxlayout.h>
#include <qtextbrowser.h>
#include <QScrollBar>
#include <QTextEdit>
#include <MyHighLighter.h>
MyTextEditByCode::MyTextEditByCode(QWidget *parent)
    : QWidget{parent}
{
    //UI组件
    initWidget();

    //字体
    initFont();

    //绑定
    initConnection();

    //高亮
    initHighlight();
}

void MyTextEditByCode::initWidget()
{
    QWidget *horizontalLayoutWidget = new QWidget();
    //竖向布局
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);

    verticalLayout->setSpacing(0);
    verticalLayout->setMargin(0);

    //横向布局
    QHBoxLayout *horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
    horizontalLayout->setMargin(0);
    horizontalLayout->setSpacing(0);

    textEdit = new QTextEdit();
    textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textEdit->setLineWrapMode(QTextEdit::NoWrap);
    textBrowser = new QTextBrowser();
    textBrowser->setMaximumWidth(25);
    textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    scrollBar = new QScrollBar();
    scrollBar->setOrientation(Qt::Horizontal);

    horizontalLayout->addWidget(textBrowser);
    horizontalLayout->addWidget(textEdit);

    verticalLayout->addWidget(horizontalLayoutWidget);
    verticalLayout->addWidget(scrollBar);
}

void MyTextEditByCode::initFont()
{
    mFont = QFont("Consolas",14);
    textEdit->setFont(mFont);
    QTextBlockFormat format;
    format.setLineHeight(QFontMetrics(mFont).height()*1.1,QTextBlockFormat::FixedHeight);
    QTextCursor cursor = textEdit->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(format);
    textBrowser->setFont(mFont);


}

void MyTextEditByCode::initConnection()
{
    connect(textEdit->horizontalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(onTextEditHorizontalScrollBarChanged()));
    connect(textEdit->verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(onTextEditVerticalScrollBarChanged()));
    connect(scrollBar,SIGNAL(valueChanged(int)),this,SLOT(onScrollBarChanged()));
    connect(textBrowser->verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(onTextBrowserHorizontalScrollBarChanged()));
    connect(textEdit,SIGNAL(textChanged()),this,SLOT(onTextChanged()));

}

void MyTextEditByCode::initHighlight()
{
    new MyHighLighter(textEdit->document());
}
void MyTextEditByCode::onTextEditHorizontalScrollBarChanged()
{
   scrollBar->setMaximum(textEdit->horizontalScrollBar()->maximum());
   scrollBar->setMinimum(textEdit->horizontalScrollBar()->minimum());
   scrollBar->setPageStep(textEdit->horizontalScrollBar()->pageStep());
   scrollBar->setValue(textEdit->horizontalScrollBar()->value());
}
void MyTextEditByCode::onTextEditVerticalScrollBarChanged()
{
    scrollBar->setMaximum(textEdit->verticalScrollBar()->maximum());
    scrollBar->setMinimum(textEdit->verticalScrollBar()->minimum());
    scrollBar->setPageStep(textEdit->verticalScrollBar()->pageStep());
    textBrowser->verticalScrollBar()->setValue(textEdit->verticalScrollBar()->value());
}
void MyTextEditByCode::onScrollBarChanged()
{
    textEdit->horizontalScrollBar()->setValue(scrollBar->value());
}
void MyTextEditByCode::onTextBrowserHorizontalScrollBarChanged()
{
    textEdit->verticalScrollBar()->setValue(textBrowser->verticalScrollBar()->value());
}

void MyTextEditByCode::onTextChanged()
{

    QString text = textBrowser->toPlainText();
    int linecount = textEdit->document()->lineCount();
    int LineCount = text.trimmed().split("\n").length();
    if(LineCount>linecount)
    {
        for (int i = LineCount; i > linecount; i--) {
            text.chop((QString::number(i)+"\n").length());
        }
    }
    else if(LineCount == 1&&text.length()<1)
    {
        text += QString::number(1)+"\n";
    }
    else if(LineCount<linecount)
    {
        for (int i = LineCount; i < linecount; i++)
        {
            text += QString::number(i+1)+"\n";
        }
    }

    textBrowser->setMaximumWidth(25+QString::number(linecount).length()*10);
    textBrowser->setText(text);

    QTextBlockFormat format;
    format.setLineHeight(QFontMetrics(mFont).height()*1.1,QTextBlockFormat::FixedHeight);
    format.setAlignment(Qt::AlignRight);
    QTextCursor cursor = textBrowser->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeBlockFormat(format);
}
