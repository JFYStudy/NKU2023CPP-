# 南开大学23C++大作业 VsCold 文本编辑器
> 此项目继承于 https://github.com/libaroma/course-qt-widget-notepad-demo
# 作业题目

VsCold文本编辑器

# 开发软件

Qt Creator 9.0.2社区版

Qt 5.15.2 MInGW

# 窗口示意图

## ![窗口示意](figures/窗口示意.png)

# 主要流程



## MainWindow.cpp

### 基本操作

> MainWindow窗口中的菜单栏

```cpp
//创建新文件
void on_new_file_triggered();
//保存
void on_save_file_triggered();
//打开
void on_open_file_triggered();
//另存为
void on_save_as_triggered();
//粘贴
void on_paste_triggered();
//复制
void on_copy_triggered();
//关于
void on_about_triggered();
//剪切
void on_cut_triggered();
//字体
void on_font_triggered();
//撤销
void on_undo_triggered();
//取消撤销
void on_redo_triggered();
//退出
void on_exit_triggered();
//打印
void on_print_triggered();
```
### 成员变量
```cpp
//ui界面
Ui::MainWindow *ui;
//字体
QString mFontFamily;
//字号
int mFontSize;
//设置
QSettings * mSettings;
//初始化字体
void initFont();
//初始化动作
void initAction();
//创建新的标签页
void createTab(QString fileName);
```

## mycodeeditor.cpp
> 主要的代码编辑区
> 有两个类，一个是mycodeeditor一个是Linenumberwidget用来绘制行号
### MyCodeEditor

```cpp
public:
    explicit MyCodeEditor(QWidget *parent = nullptr,QFont font = QFont("Consolas",14));
    ~MyCodeEditor();
    void LineNumberWidgetPaintEvent(QPaintEvent * event);//绘画事件
    void LineNumberWidgetMousePressEvent(QMouseEvent *event);
    void LineNumberWidgetWheelEvent(QWheelEvent *event);
    bool saveFile();
    bool saveAsFile();
    void setFileName(QString filename);
    QString getFileName();
    void setAllFont(QFont font);
    bool checkSaved();
private:
    void initConnect();
    void initHighLight();
    int getLineNumberWidgetWidth();
    LineNumberWidget * lineNumberWidget;//行号统计功能
    MyHighLighter * highlighter ;//高亮功能
    QString mFilename;//当前打开的文件的文件名，最终会显示在TabWidget上
    bool isSaved = false;//用于追踪当前文件是否已经保存
private slots:
    void highlightCurrentLine();
    void updateLineNumberWidget(QRect rect,int dy);
    void updateLineNumberWidgetWidth();
    void updateSaveState();
```
### LineNumberWidget

```cpp
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
```



## myhighter

### 解释

通过创建MyHighter类，每当编辑器有更新，则将整个页面符合要求的高亮

其中使用一个**QVector**将每一种高亮保存起来

字符的匹配，使用了**正则表达式**

> 代码高亮功能
```cpp
public:
    explicit MyHighLighter(QTextDocument *parent=nullptr,QString fontFamily="Consolas",int fontsize=14);
    void setFont(QFont font);
protected:
    void highlightBlock(const QString &text);
private:
    QString mFontFamily;
    int mFontSize;
    struct HighlightRule//结构体，用于存储需要高亮的代码的格式
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightRule> highlightRules;
    //各个格式的代码高亮
    void addNormalTextFormat();
    void addNumberFormat();
    void addStringFormat();
    void addCommentFormat();
    void addMultiLineCommentFormat(const QString &text);
    void addKeywordsFormat();
    void addClassNameFormat();
    void addFunctionFormat();
```
## 如何运行此项目
> 要求Windows
> 本项目在Qt 5.15.2 MinGW编译器环境下运行

# 测试

> 创建新文件

![image-20230520010337601](figures/创建新文件.png)

> 代码高亮

![image-20230520010622480](figures/代码高亮)
