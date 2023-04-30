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
private:
    Ui::MyTextEditor *ui;
    void initConnect();
    void initFont();
};

#endif // MYTEXTEDITOR_H
