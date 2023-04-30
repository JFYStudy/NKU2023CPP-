#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <qfiledialog.h>
#include <qmessagebox.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_new_file_triggered()
{
    qDebug()<<"Start Create New File ...";
    currentFile.clear();
    ui->textEdit->setText("");
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

}

void MainWindow::on_font_triggered()
{

}


void MainWindow::on_undo_triggered()
{

}


void MainWindow::on_redo_triggered()
{

}


void MainWindow::on_exit_triggered()
{

}


void MainWindow::on_print_triggered()
{

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

