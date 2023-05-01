#ifndef MYHIGHLIGHTER_H
#define MYHIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>
class MyHighLighter:public QSyntaxHighlighter
{
public:
    explicit MyHighLighter(QTextDocument *parent=nullptr);
protected:
    void highlightBlock(const QString &text);
private:
    QString mFontFamily = "Consolas";
    int mFontSize = 14;
    struct HighlightRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };

    QVector<HighlightRule> highlightRules;
    void addNormalTextFormat();
    void addNumberFormat();
    void addStringFormat();
};

#endif // MYHIGHLIGHTER_H
