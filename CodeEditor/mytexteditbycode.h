#ifndef MYTEXTEDITBYCODE_H
#define MYTEXTEDITBYCODE_H

#include <QWidget>
#include <qtextbrowser.h>
#include <QScrollBar>
#include <QTextEdit>
class MyTextEditByCode : public QWidget
{
    Q_OBJECT
public:
    explicit MyTextEditByCode(QWidget *parent = nullptr);

    ~MyTextEditByCode();
private slots:
    void onTextEditHorizontalScrollBarChanged();
    void onTextEditVerticalScrollBarChanged();
    void onScrollBarChanged();
    void onTextBrowserHorizontalScrollBarChanged();
    void highlightCurrentLine();
    //行号
    void onTextChanged();
private:
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QScrollBar *scrollBar;
    QFont mFont;
    void initWidget();
    void initFont();
    void initConnection();
    void initHighlight();

signals:

};

#endif // MYTEXTEDITBYCODE_H
