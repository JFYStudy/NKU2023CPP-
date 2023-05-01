#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <QFontDialog>
#include <QSettings>
#include <MyCodeEditor.h>
#include <QPrinter>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#include <QTextStream>
#endif
#endif
#endif

QSettings * mSettings;
QList<QString> getHistory();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tabWidget);
    if(mSettings==NULL)
    {
        mSettings = new QSettings("setting.ini",QSettings::IniFormat);

    }
    getHistory();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//保存并且打开历史记录
void saveHistory(QString path)
{
    //获取数组的长度
    int size = mSettings->beginReadArray("history");
    mSettings->endArray();//
    //打开写入
    mSettings->beginWriteArray("history");
    mSettings->setArrayIndex(size+1);
    //保存
    mSettings->setValue("path",path);
    //关闭
    mSettings->endArray();
}
//获取历史记录
QList<QString> getHistory()
{
    int size = mSettings->beginReadArray("history");
    QList<QString> lists;
    for (int i = 0; i < size; i++)
    {
        mSettings->setArrayIndex(i);
        QString path = mSettings->value("path").toString();
        lists.append(path);
    }

    mSettings->endArray();
    return lists;
}
void MainWindow::on_new_file_triggered()
{
//    MyTextEditor * mytexteditor = new MyTextEditor(this);
//    ui->tabWidget->addTab(mytexteditor,"New tab");
//    ui->tabWidget->addTab(new MyTextEditByCode(this),"New tab");
    ui->tabWidget->addTab(new MyCodeEditor(this),"New tab");
//    qDebug()<<"Start Create New File ...";
//    currentFile.clear();
//    ui->textEdit->setText("");
}

void MainWindow::on_save_file_triggered()
{
    MyCodeEditor *codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();
    if(codeEditor)
    {
        if(codeEditor->saveFile())
        {
            QString filename = codeEditor->getFileName();
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),filename);
        }
        else
        {
            QMessageBox::warning(this,"warning","failed to save the file");
        }

    }
}

void MainWindow::on_open_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"open file");
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"warning","failed to open the file"+file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    MyCodeEditor * codeEditor = new MyCodeEditor(this);
    codeEditor->setPlainText(text);
    ui->tabWidget->addTab(codeEditor,currentFile);

    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
    file.close();
}

void MainWindow::on_save_as_triggered()
{
    MyCodeEditor *codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();
    if(codeEditor)
    {
        if(codeEditor->saveAsFile())
        {
            QString filename = codeEditor->getFileName();
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),filename);
        }
        else
        {
            QMessageBox::warning(this,"warning","failed to save the file");
        }

    }

}

void MainWindow::on_paste_triggered()
{
    MyCodeEditor *codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();
    if(codeEditor)
    {
        codeEditor->paste();
    }
}

void MainWindow::on_copy_triggered()
{
    MyCodeEditor *codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();
    if(codeEditor)
    {
        codeEditor->copy();
    }
}

void MainWindow::on_cut_triggered()
{
    MyCodeEditor *codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();
    if(codeEditor)
    {
        codeEditor->cut();
    }
}

void MainWindow::on_about_triggered()
{
    QMessageBox::about(this,"Welcome to MKeditor","This is a markdown editor based on qt, welcome!");
}
//字体
void MainWindow::on_font_triggered()
{
    bool fontSleceted;
    QFont font = QFontDialog::getFont(&fontSleceted,this);
    if(fontSleceted)
    {
//        ui->textEdit->setFont(font);
    }
}

void MainWindow::on_undo_triggered()
{
    MyCodeEditor *codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();
    if(codeEditor)
    {
        codeEditor->undo();
    }
}


void MainWindow::on_redo_triggered()
{
    MyCodeEditor *codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();
    if(codeEditor)
    {
        codeEditor->redo();
    }
}

void MainWindow::on_exit_triggered()
{
    QCoreApplication::exit();
}



void MainWindow::on_clear_history_triggered()
{

}


void MainWindow::on_print_triggered()
{
#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printer)
    QPrinter printDev;
#if QT_CONFIG(printdialog)
    QPrintDialog dialog(&printDev,this);
    if(dialog.exec()==QDialog::Rejected)
        return;
#endif
    MyCodeEditor *codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();
    if(codeEditor)
    {
        codeEditor->print(&printDev);
    }
#endif
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    delete ui->tabWidget->currentWidget();
    ui->tabWidget->removeTab(index);
}

