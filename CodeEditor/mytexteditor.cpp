#include "mytexteditor.h"
#include "ui_mytexteditor.h"
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
}

void MyTextEditor::initFont()
{
    QFont font("Source Code Pro",14);
    ui->textEdit->setFont(font);
    ui->textBrowser->setFont(font);
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
    int linecount = ui->textEdit->document()->lineCount();
    QString text = "";
    for (int i = 0; i < linecount; i++)
    {
        text += QString::number(i+1)+"\n";
    }
    ui->textBrowser->setMaximumWidth(25+QString::number(linecount).length()*5);
    ui->textBrowser->setText(text);
}


