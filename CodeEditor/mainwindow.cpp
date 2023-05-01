#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <QFontDialog>
#include <QSettings>


#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif
#include <MyTextEditByCode.h>
#include <MyTextEditor.h>
#include <QPrinter>
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
    ui->tabWidget->addTab(new MyTextEditByCode(this),"New tab");
//    qDebug()<<"Start Create New File ...";
//    currentFile.clear();
//    ui->textEdit->setText("");
}

void MainWindow::on_save_file_triggered()
{
    QString fileName;
    if(currentFile.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this,"保存文件");
        currentFile = fileName;
    }
    else
    {
        fileName = currentFile;
    }
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"warning","failed to save the file"+file.errorString());
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text =ui->textEdit->toHtml();
    out<<text;
    file.close();
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
    ui->textEdit->setText(text);
    file.close();
    saveHistory(currentFile);
}

void MainWindow::on_save_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"另存为");
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QFile::Text))
    {
        QMessageBox::warning(this,"warning","failed to save the file"+file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text =ui->textEdit->toHtml();
    out<<text;
    file.close();
}

void MainWindow::on_paste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_copy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_cut_triggered()
{
    ui->textEdit->cut();
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
        ui->textEdit->setFont(font);
    }
}

void MainWindow::on_undo_triggered()
{
    ui->textEdit->undo();
}
//加粗
void MainWindow::on_bolder_triggered(bool checked)
{
    ui->textEdit->setFontWeight(checked?QFont::Bold:QFont::Normal);
}
//斜体
void MainWindow::on_italics_triggered(bool checked)
{
    ui->textEdit->setFontItalic(checked);
}
//下划线
void MainWindow::on_underline_triggered(bool checked)
{
    ui->textEdit->setFontUnderline(checked);
}

void MainWindow::on_redo_triggered()
{
    ui->textEdit->redo();
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
    ui->textEdit->print(&printDev);
#endif
}

