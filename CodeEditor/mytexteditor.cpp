#include "mytexteditor.h"
#include "ui_mytexteditor.h"
#include <MyHighLighter.h>
#include <QDebug>
MyTextEditor::MyTextEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTextEditor)
{
    ui->setupUi(this);
    //绑定滚动条
    initConnect();
    //初始化字体
    initFont();
    //初始化高亮
    initHigglighter();
}

MyTextEditor::~MyTextEditor()
{
    delete ui;
}

void MyTextEditor::initConnect()
{
    connect(ui->textEdit,SIGNAL(textChanged()),this,SLOT(onTextChange()));
    connect(ui->textEdit->horizontalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(textEditScrollBarChanged()));
    connect(ui->horizontalScrollBar,SIGNAL(valueChanged(int)),this,SLOT(ScrollBarChanged()));

    connect(ui->textEdit->verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(textEditVScrollBarChanged()));
    connect(ui->textBrowser->verticalScrollBar(),SIGNAL(valueChanged(int)),this,SLOT(ScrollBrowserVscrollBarChanged()));
}

void MyTextEditor::initFont()
{
    QFont font("Consolas",14);
    ui->textEdit->setFont(font);
    ui->textBrowser->setFont(font);
}

void MyTextEditor::initHigglighter()
{
    new MyHighLighter(ui->textEdit->document());
}

void MyTextEditor::textEditScrollBarChanged()
{
    ui->horizontalScrollBar->setMinimum(ui->textEdit->horizontalScrollBar()->minimum());
    ui->horizontalScrollBar->setMaximum(ui->textEdit->horizontalScrollBar()->maximum());
    ui->horizontalScrollBar->setPageStep(ui->textEdit->horizontalScrollBar()->pageStep());
    ui->horizontalScrollBar->setValue(ui->textEdit->horizontalScrollBar()->value());
}

void MyTextEditor::ScrollBarChanged()
{
    ui->textEdit->horizontalScrollBar()->setValue(ui->horizontalScrollBar->value());
}

void MyTextEditor::onTextChange()
{
    QString text = ui->textBrowser->toPlainText();
    int linecount = ui->textEdit->document()->lineCount();
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

    ui->textBrowser->setMaximumWidth(25+QString::number(linecount).length()*10);
    ui->textBrowser->setText(text);
}

void MyTextEditor::textEditVScrollBarChanged()
{
    ui->textBrowser->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->value());
}

void MyTextEditor::ScrollBrowserVscrollBarChanged()
{
    ui->textEdit->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->value());
}


