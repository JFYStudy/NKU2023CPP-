#ifndef MYTEXTEDITOR_H
#define MYTEXTEDITOR_H

#include <QWidget>

namespace Ui {
class MyTextEditor;
}

class MyTextEditor : public QWidget
{
    Q_OBJECT

public:
    explicit MyTextEditor(QWidget *parent = nullptr);
    ~MyTextEditor();
private slots:
    void textEditScrollBarChanged();
    void ScrollBarChanged();
    void onTextChange();
    void textEditVScrollBarChanged();
    void ScrollBrowserVscrollBarChanged();
    void highlightCurrentLine();
private:
    Ui::MyTextEditor *ui;
    void initConnect();
    void initFont();
    void initHigglighter();
    QFont mFont;
};

#endif // MYTEXTEDITOR_H
