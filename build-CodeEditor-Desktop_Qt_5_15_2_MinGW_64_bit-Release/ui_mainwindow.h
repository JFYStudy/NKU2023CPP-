/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *new_file;
    QAction *save_file;
    QAction *open_file;
    QAction *save_as;
    QAction *paste;
    QAction *copy;
    QAction *cut;
    QAction *font;
    QAction *undo;
    QAction *redo;
    QAction *about;
    QAction *exit;
    QAction *clear_history;
    QAction *print;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_3;
    QMenu *menubianji;
    QMenu *menu_2;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QToolBar *toolBar_4;
    QToolBar *toolBar_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        new_file = new QAction(MainWindow);
        new_file->setObjectName(QString::fromUtf8("new_file"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        new_file->setIcon(icon1);
        save_file = new QAction(MainWindow);
        save_file->setObjectName(QString::fromUtf8("save_file"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_file->setIcon(icon2);
        open_file = new QAction(MainWindow);
        open_file->setObjectName(QString::fromUtf8("open_file"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        open_file->setIcon(icon3);
        save_as = new QAction(MainWindow);
        save_as->setObjectName(QString::fromUtf8("save_as"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        save_as->setIcon(icon4);
        paste = new QAction(MainWindow);
        paste->setObjectName(QString::fromUtf8("paste"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        paste->setIcon(icon5);
        copy = new QAction(MainWindow);
        copy->setObjectName(QString::fromUtf8("copy"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        copy->setIcon(icon6);
        cut = new QAction(MainWindow);
        cut->setObjectName(QString::fromUtf8("cut"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        cut->setIcon(icon7);
        font = new QAction(MainWindow);
        font->setObjectName(QString::fromUtf8("font"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        font->setIcon(icon8);
        undo = new QAction(MainWindow);
        undo->setObjectName(QString::fromUtf8("undo"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/edit_undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undo->setIcon(icon9);
        redo = new QAction(MainWindow);
        redo->setObjectName(QString::fromUtf8("redo"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/edit_redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        redo->setIcon(icon10);
        about = new QAction(MainWindow);
        about->setObjectName(QString::fromUtf8("about"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        about->setIcon(icon11);
        exit = new QAction(MainWindow);
        exit->setObjectName(QString::fromUtf8("exit"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exit->setIcon(icon12);
        clear_history = new QAction(MainWindow);
        clear_history->setObjectName(QString::fromUtf8("clear_history"));
        print = new QAction(MainWindow);
        print->setObjectName(QString::fromUtf8("print"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        print->setIcon(icon13);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 611, 351));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideMiddle);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_3 = new QMenu(menu);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menubianji = new QMenu(menubar);
        menubianji->setObjectName(QString::fromUtf8("menubianji"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);
        toolBar_4 = new QToolBar(MainWindow);
        toolBar_4->setObjectName(QString::fromUtf8("toolBar_4"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_4);
        toolBar_5 = new QToolBar(MainWindow);
        toolBar_5->setObjectName(QString::fromUtf8("toolBar_5"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_5);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menubianji->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(new_file);
        menu->addAction(open_file);
        menu->addAction(menu_3->menuAction());
        menu->addSeparator();
        menu->addAction(save_file);
        menu->addAction(save_as);
        menu->addSeparator();
        menu->addAction(exit);
        menu_3->addAction(clear_history);
        menubianji->addAction(copy);
        menubianji->addAction(paste);
        menubianji->addAction(cut);
        menubianji->addSeparator();
        menubianji->addAction(font);
        menu_2->addAction(about);
        toolBar->addAction(new_file);
        toolBar->addAction(open_file);
        toolBar->addAction(save_file);
        toolBar->addAction(save_as);
        toolBar->addAction(print);
        toolBar_2->addAction(copy);
        toolBar_2->addAction(paste);
        toolBar_2->addAction(cut);
        toolBar_3->addAction(font);
        toolBar_4->addAction(undo);
        toolBar_4->addAction(redo);
        toolBar_5->addAction(about);
        toolBar_5->addAction(exit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "VsCold", nullptr));
        new_file->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        new_file->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        save_file->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        save_file->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        open_file->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        open_file->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        save_as->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#if QT_CONFIG(shortcut)
        save_as->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        paste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        paste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        copy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        copy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        cut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(shortcut)
        cut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        font->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
#if QT_CONFIG(shortcut)
        font->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Alt+F", nullptr));
#endif // QT_CONFIG(shortcut)
        undo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
#if QT_CONFIG(shortcut)
        undo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        redo->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\201\232", nullptr));
#if QT_CONFIG(shortcut)
        redo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        about->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(shortcut)
        about->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+I", nullptr));
#endif // QT_CONFIG(shortcut)
        exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(shortcut)
        exit->setShortcut(QCoreApplication::translate("MainWindow", "Shift+Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        clear_history->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\345\216\206\345\217\262", nullptr));
        print->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260", nullptr));
#if QT_CONFIG(shortcut)
        print->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\234\200\350\277\221\346\211\223\345\274\200", nullptr));
        menubianji->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
        toolBar_3->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_3", nullptr));
        toolBar_4->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_4", nullptr));
        toolBar_5->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
