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
private:
    Ui::MyTextEditor *ui;
    void initConnect();
    void initFont();
    void initHigglighter();
};

#endif // MYTEXTEDITOR_H
