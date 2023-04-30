#include "myhighlighter.h"

MyHighLighter::MyHighLighter(QTextDocument *parent):QSyntaxHighlighter(parent)
{
    //对于普通文本
    addNormalTextFormat();
}

void MyHighLighter::highlightBlock(const QString &text)
{
    foreach (const HighlightRule &rule, highlightRules)
    {
        QRegExp regExp(rule.pattern);
        int index = regExp.indexIn(text);
        while (index>=0)
        {
            int length = regExp.matchedLength();
            setFormat(index,length,rule.format);
            index = regExp.indexIn(text,index+length);
        }
    }
}

void MyHighLighter::addNormalTextFormat()
{
    HighlightRule rule;
    rule.pattern = QRegExp("[a-z0-9A-Z]+");
    QTextCharFormat normalTextFormat;
    normalTextFormat.setFont(QFont(mFontFamily,mFontSize));
    normalTextFormat.setForeground(QColor(0,100,100));

    rule.format = normalTextFormat;
    highlightRules.append(rule);
}
