#include "myhighlighter.h"

#include <QTextStream>

MyHighLighter::MyHighLighter(QTextDocument *parent, QString fontFamily, int fontsize):QSyntaxHighlighter(parent)
{
    mFontFamily = fontFamily;
    mFontSize = fontsize;
    //对于普通文本
    addNormalTextFormat();

    //关键字高亮
    addKeywordsFormat();

    //对于数字
    addNumberFormat();

    //对于字符串
    addStringFormat();

    //注释高亮
    addCommentFormat();

    //类名高亮
    addClassNameFormat();

    //函数名高亮
    addFunctionFormat();
}

void MyHighLighter::setFont(QFont font)
{
    mFontFamily = font.family();
    mFontSize = font.pointSize();
}


//按行传入
void MyHighLighter::highlightBlock(const QString &text)
{
    QRegExp regExp;
    foreach (const HighlightRule &rule, highlightRules)
    {
        regExp = rule.pattern;
        int index = regExp.indexIn(text);
        while (index>=0)
        {
            int length = regExp.matchedLength();
            setFormat(index,length,rule.format);
            index = regExp.indexIn(text,index+length);
        }
    }
    addMultiLineCommentFormat(text);
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

void MyHighLighter::addCommentFormat()
{
    QTextCharFormat commentFormat;
    commentFormat.setFont(QFont(mFontFamily,mFontSize));
    commentFormat.setForeground(Qt::darkGreen);
    commentFormat.setFontItalic(true);
    HighlightRule rule;

    rule.format = commentFormat;
    //匹配单行注释
    rule.pattern = QRegExp("\\/\\/.*$");
    highlightRules.append(rule);
}

void MyHighLighter::addMultiLineCommentFormat(const QString &text)
{
    setCurrentBlockState(0);

    // /*
    QRegExp commentStartRegExp("/\\*");

    // */
    QRegExp commentEndRegExp("\\*/");
    //高亮
    QTextCharFormat multiLineCommentFormat;
    multiLineCommentFormat.setFont(QFont(mFontFamily,mFontSize));
    multiLineCommentFormat.setForeground(Qt::darkGreen);
    multiLineCommentFormat.setFontItalic(true);
    int startIndex = 0 ;
    if(previousBlockState()!=1)
    {
        startIndex = commentStartRegExp.indexIn(text);
    }
    while (startIndex>=0)
    {
        int commentLength = 0;
        int endIndex = commentEndRegExp.indexIn(text,startIndex);
        if(endIndex==-1)//没有结束
        {
            setCurrentBlockState(1);
            commentLength = text.length()-startIndex;
        }
        else//结束位置
        {
            commentLength = endIndex-startIndex+commentEndRegExp.matchedLength();
            setFormat(startIndex,commentLength,multiLineCommentFormat);
        }
        setFormat(startIndex,commentLength,multiLineCommentFormat);

        startIndex = commentStartRegExp.indexIn(text,commentLength+startIndex);
    }
}

void MyHighLighter::addKeywordsFormat()
{
    QFile file("://config/keywords.txt");
    QTextStream keywordsStream(&file);

    HighlightRule rule;
    QTextCharFormat keywordsFormat;
    keywordsFormat.setFont(QFont(mFontFamily,mFontSize));
    keywordsFormat.setForeground(QColor(Qt::darkMagenta));
    rule.format = keywordsFormat;

    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        keywordsStream.seek(0);
        QString line;
        while (!keywordsStream.atEnd())
        {
            line = keywordsStream.readLine();
            if(line!="")
            {
                rule.pattern = QRegExp("\\b"+line+"\\b");
                highlightRules.append(rule);
            }
        }
        file.close();
    }
}

void MyHighLighter::addClassNameFormat()
{
    HighlightRule rule;
    QTextCharFormat ClassNameFormat;
    ClassNameFormat.setFont(QFont(mFontFamily,mFontSize));
    ClassNameFormat.setForeground(QColor(150,20,100));
    ClassNameFormat.setFontWeight(99);


    rule.format = ClassNameFormat;

    rule.pattern = QRegExp("\\b[A-Z]+\\w*");
    highlightRules.append(rule);
}

void MyHighLighter::addFunctionFormat()
{
    HighlightRule rule;
    QTextCharFormat functionFormat;
    functionFormat.setFont(QFont(mFontFamily,mFontSize));
    functionFormat.setForeground(QColor(200,0,150));
    functionFormat.setFontWeight(99);


    rule.format = functionFormat;

    rule.pattern = QRegExp("\\w+\\(");
    highlightRules.append(rule);

    rule.pattern = QRegExp("\\)");
    highlightRules.append(rule);
}
