#include "mycodeeditor.h"

#include <MyHighLighter.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QScrollBar>
#include <QTextStream>
MyCodeEditor::MyCodeEditor(QWidget *parent)
    : QPlainTextEdit{parent}
{
    lineNumberWidget = new LineNumberWidget(this);
    //初始化字体
    initFont();

    //初始化连接
    initConnect();

    //行高亮
    highlightCurrentLine();\

    //高亮
    initHighLight();

    //设置边距
    updateLineNumberWidgetWidth();

    setLineWrapMode(QPlainTextEdit::NoWrap);
}

MyCodeEditor::~MyCodeEditor()
{
    if(lineNumberWidget)
    {
        delete lineNumberWidget;
        lineNumberWidget = nullptr;
    }
}


void MyCodeEditor::initFont()
{
    this->setFont(QFont("Consolas",14));
}

void MyCodeEditor::initConnect()
{
    //cursor
    connect(this,SIGNAL(cursorPositionChanged()),this,SLOT(highlightCurrentLine()));
    //blockCount
    connect(this,SIGNAL(blockCountChanged(int)),this,SLOT(updateLineNumberWidgetWidth()));
    //绑定行号绘制
    connect(this,SIGNAL(updateRequest(QRect,int)),this,SLOT(updateLineNumberWidget(QRect,int)));
}

void MyCodeEditor::initHighLight()
{
    new MyHighLighter(document());
}

int MyCodeEditor::getLineNumberWidgetWidth()
{
    //获取宽度
    return 8+QString::number(blockCount()+1).length()*fontMetrics().horizontalAdvance(QChar('0'));
}

void MyCodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;
    selection.format.setBackground(QColor(0,100,100,20));
    selection.format.setProperty(QTextFormat::FullWidthSelection,true);
    selection.cursor = textCursor();

    extraSelections.append(selection);

    setExtraSelections(extraSelections);
}

void MyCodeEditor::updateLineNumberWidget(QRect rect, int dy)
{
    if(dy)
        lineNumberWidget->scroll(0,dy);
    else
        lineNumberWidget->update(0,rect.y(),getLineNumberWidgetWidth(),rect.height());
}

void MyCodeEditor::updateLineNumberWidgetWidth()
{
    setViewportMargins(getLineNumberWidgetWidth(),0,0,0);
}

void MyCodeEditor::resizeEvent(QResizeEvent *event)
{
    QPlainTextEdit::resizeEvent(event);
    lineNumberWidget->setGeometry(0,0,getLineNumberWidgetWidth(),contentsRect().height());
}

void MyCodeEditor::LineNumberWidgetPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberWidget);
    //绘制区域行号
    painter.fillRect(event->rect(),QColor(100,100,100,20));
    //拿到block
    QTextBlock block = firstVisibleBlock();
    //拿到行号
    int blockNumber = block.blockNumber();
    //拿到当前的block的top
    int cursorTop = blockBoundingGeometry(textCursor().block()).translated(contentOffset()).top();

    //拿到block的top
    int top = blockBoundingGeometry(block).translated(contentOffset()).top();
    //拿到block的bottom
    int bottom = top + blockBoundingRect(block).height();
    while (block.isValid()&&top<=event->rect().bottom())
    {
        //设置画笔颜色
        painter.setPen(cursorTop == top?Qt::black:Qt::gray);
        //绘制文字
        painter.drawText(0,top,getLineNumberWidgetWidth()-4,bottom-top,Qt::AlignRight,QString::number(blockNumber+1));
        //下一个block
        block = block.next();

        top = bottom;
        bottom = top + blockBoundingRect(block).height();
        blockNumber++;
    }

}

void MyCodeEditor::LineNumberWidgetMousePressEvent(QMouseEvent *event)
{
    setTextCursor(QTextCursor(document()->findBlockByLineNumber(event->y()/fontMetrics().height()+verticalScrollBar()->value())));
}

void MyCodeEditor::LineNumberWidgetWheelEvent(QWheelEvent *event)
{
    if(event->orientation()==Qt::Horizontal)
    {
        horizontalScrollBar()->setValue(horizontalScrollBar()->value()+event->delta());
    }
    else
    {
        verticalScrollBar()->setValue(verticalScrollBar()->value()-event->delta()/4);
    }
    event->accept();
}

bool MyCodeEditor::saveFile()
{
    QString fileName;
    if(mFilename.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this,"保存文件");
        mFilename = fileName;
    }
    else
    {
        fileName = mFilename;
    }
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"warning","failed to save the file"+file.errorString());
        return 0;
    }
    QTextStream out(&file);


    out<<toPlainText();
    file.close();
    return 1;
}

bool MyCodeEditor::saveAsFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,"另存为");
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"warning","failed to save the file"+file.errorString());
        return false;
    }
    mFilename = fileName;
    QTextStream out(&file);

    QString text =toPlainText();
    out<<text;
    file.close();
    return true;
}

void MyCodeEditor::setFileName(QString filename)
{
    mFilename = filename;
}

QString MyCodeEditor::getFileName()
{
    return mFilename;
}

