#ifndef MYHIGHLIGHTER_H
#define MYHIGHLIGHTER_H

#include <QObject>
#include <QSyntaxHighlighter>
class MyHighLighter:public QSyntaxHighlighter
{
public:
    explicit MyHighLighter(QTextDocument *parent=nullptr,QString fontFamily="Consolas",int fontsize=14);
    void setFont(QFont font);
protected:
    void highlightBlock(const QString &text);
private:
    QString mFontFamily;
    int mFontSize;
    struct HighlightRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };

    QVector<HighlightRule> highlightRules;
    void addNormalTextFormat();
    void addNumberFormat();
    void addStringFormat();
    void addCommentFormat();
    void addMultiLineCommentFormat(const QString &text);
    void addKeywordsFormat();
    void addClassNameFormat();
    void addFunctionFormat();
};

#endif // MYHIGHLIGHTER_H
