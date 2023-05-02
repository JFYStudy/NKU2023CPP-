#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <QFontDialog>
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



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->tabWidget);

    mSettings = new QSettings("setting.ini",QSettings::IniFormat);

    initFont();

    initAction();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initFont()
{
    mFontFamily = mSettings->value("font_family","Consolas").toString();
    mFontSize = mSettings->value("font_size",14).toInt();
}

void MainWindow::initAction()
{
    bool valid = ui->tabWidget->count()!=0;
    ui->save_file->setEnabled(valid);
    ui->save_as->setEnabled(valid);
    ui->copy->setEnabled(valid);
    ui->paste->setEnabled(valid);
    ui->cut->setEnabled(valid);
    ui->print->setEnabled(valid);
    ui->undo->setEnabled(valid);
    ui->redo->setEnabled(valid);
}


//保存并且打开历史记录

//获取历史记录

void MainWindow::on_new_file_triggered()
{
    ui->tabWidget->addTab(new MyCodeEditor(this,QFont(mFontFamily,mFontSize)),"New tab");
    initAction();
}

void MainWindow::on_save_file_triggered()
{
    MyCodeEditor *codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();
    if(codeEditor)
    {
        if(codeEditor->saveFile())
        {
            saveSuccessAction(codeEditor);
        }
        else
        {
            QMessageBox::warning(this,"warning","failed to save the file");
        }

    }
}

void MainWindow::on_open_file_triggered()
{
    createTab(QFileDialog::getOpenFileName(this,"open file"));
}

//创建tab
void MainWindow::createTab(QString fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"warning","failed to open the file"+file.errorString());
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    //创建对象
    MyCodeEditor * codeEditor = new MyCodeEditor(this,QFont(mFontFamily,mFontSize));
    codeEditor->setPlainText(text);
    //设置文件名
    codeEditor->setFileName(fileName);
    //添加tab
    ui->tabWidget->addTab(codeEditor,fileName);
    initAction();
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
            saveSuccessAction(codeEditor);
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
    QFont font = QFontDialog::getFont(&fontSleceted,QFont(mFontFamily,mFontSize),this);
    if(fontSleceted)
    {
        MyCodeEditor *codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();
        if(codeEditor)
        {
            codeEditor->setAllFont(font);
        }
        mSettings->setValue("font_family",font.family());
        mSettings->setValue("font_size",font.pointSize());
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


void MainWindow::on_print_triggered()
{
    MyCodeEditor *codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();
    if(codeEditor)
    {
#if defined(QT_PRINTSUPPORT_LIB) && QT_CONFIG(printer)
        QPrinter printDev;
#if QT_CONFIG(printdialog)
        QPrintDialog dialog(&printDev,this);
        if(dialog.exec()==QDialog::Rejected)
            return;
#endif
        codeEditor->print(&printDev);
#endif
    }
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    MyCodeEditor * codeEditor = (MyCodeEditor *)ui->tabWidget->currentWidget();

    if(!codeEditor->checkSaved())
    {
        QMessageBox::StandardButton btn = QMessageBox::question(this,"warning","Not Saved yet! Save(Y) or Quit(N)?",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

        if(btn == QMessageBox::Yes)
        {
            if(codeEditor->saveFile())
            {
                saveSuccessAction(codeEditor);
            }
            return;
        }
        else if(btn == QMessageBox::Cancel)
        {
            return;
        }
    }
    delete codeEditor;
    initAction();
}

void MainWindow::saveSuccessAction(MyCodeEditor * codeEditor)
{
    QString filename = codeEditor->getFileName();
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),filename);

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(ui->tabWidget->count()>0)
    {
        QMessageBox::StandardButton btn = QMessageBox::question(this,"警告","有未保存的文件,确定要关闭吗？",QMessageBox::Yes|QMessageBox::No);
        if(btn == QMessageBox::Yes)
        {
            event->accept();
        }
        else
        {
            event->ignore();
        }
    }
}
