#ifndef MYCODEEDITOR_H
#define MYCODEEDITOR_H

#include <QPlainTextEdit>
#include <QWidget>
class LineNumberWidget;
class MyCodeEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit MyCodeEditor(QWidget *parent = nullptr);
    ~MyCodeEditor();

    void LineNumberWidgetPaintEvent(QPaintEvent * event);
    void LineNumberWidgetMousePressEvent(QMouseEvent *event);
    void LineNumberWidgetWheelEvent(QWheelEvent *event);
    bool saveFile();
    bool saveAsFile();
    void setFileName(QString filename);
    QString getFileName();
private:
    void initFont();
    void initConnect();
    void initHighLight();
    int getLineNumberWidgetWidth();
    LineNumberWidget * lineNumberWidget;

    QString mFilename;
private slots:
    void highlightCurrentLine();
    void updateLineNumberWidget(QRect rect,int dy);
    void updateLineNumberWidgetWidth();
protected:
    void resizeEvent(QResizeEvent *event);
signals:

};

class LineNumberWidget:public QWidget
{
public:
    explicit LineNumberWidget(MyCodeEditor *editor = nullptr):QWidget(editor)
    {
        codeEditor = editor;
    };

protected:
    void paintEvent(QPaintEvent *event) override
    {
        codeEditor->LineNumberWidgetPaintEvent(event);
    }
    void mousePressEvent(QMouseEvent *event) override
    {
        codeEditor->LineNumberWidgetMousePressEvent(event);
    }
    void wheelEvent(QWheelEvent *event) override
    {
        codeEditor->LineNumberWidgetWheelEvent(event);
    }
private:
    MyCodeEditor *codeEditor;
};

#endif // MYCODEEDITOR_H
