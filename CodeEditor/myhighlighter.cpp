#include "myhighlighter.h"

MyHighLighter::MyHighLighter(QTextDocument *parent):QSyntaxHighlighter(parent)
{
    //对于普通文本
    addNormalTextFormat();

    //对于数字
    addNumberFormat();

    //对于字符串
    addStringFormat();
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
    normalTextFormat.setForeground(QColor(0,0,0));

    rule.format = normalTextFormat;
    highlightRules.append(rule);
}

void MyHighLighter::addNumberFormat()
{
    HighlightRule rule;
    rule.pattern = QRegExp("\\b\\d+|\\d+\\.\\d+\\b");
    QTextCharFormat numberFormat;
    numberFormat.setFont(QFont(mFontFamily,mFontSize));
    numberFormat.setForeground(QColor(250,80,50));

    rule.format = numberFormat;
    highlightRules.append(rule);
}

void MyHighLighter::addStringFormat()
{
    QTextCharFormat stringFormat;
    stringFormat.setFont(QFont(mFontFamily,mFontSize));
    stringFormat.setForeground(QColor(0,200,180));
    HighlightRule rule;

    rule.format = stringFormat;
    //匹配单引号
    rule.pattern = QRegExp("'[^']*'");
    highlightRules.append(rule);
    //匹配双引号
    rule.pattern = QRegExp("\"[^\"]*\"");
    highlightRules.append(rule);

    rule.pattern = QRegExp("`[^`]*`");
    highlightRules.append(rule);
}
