/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CodeEditor/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[36];
    char stringdata0[11];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[23];
    char stringdata5[21];
    char stringdata6[19];
    char stringdata7[18];
    char stringdata8[19];
    char stringdata9[17];
    char stringdata10[18];
    char stringdata11[18];
    char stringdata12[18];
    char stringdata13[18];
    char stringdata14[20];
    char stringdata15[8];
    char stringdata16[21];
    char stringdata17[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 21),  // "on_new_file_triggered"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 22),  // "on_save_file_triggered"
        QT_MOC_LITERAL(57, 22),  // "on_open_file_triggered"
        QT_MOC_LITERAL(80, 20),  // "on_save_as_triggered"
        QT_MOC_LITERAL(101, 18),  // "on_paste_triggered"
        QT_MOC_LITERAL(120, 17),  // "on_copy_triggered"
        QT_MOC_LITERAL(138, 18),  // "on_about_triggered"
        QT_MOC_LITERAL(157, 16),  // "on_cut_triggered"
        QT_MOC_LITERAL(174, 17),  // "on_font_triggered"
        QT_MOC_LITERAL(192, 17),  // "on_undo_triggered"
        QT_MOC_LITERAL(210, 17),  // "on_redo_triggered"
        QT_MOC_LITERAL(228, 17),  // "on_exit_triggered"
        QT_MOC_LITERAL(246, 19),  // "on_bolder_triggered"
        QT_MOC_LITERAL(266, 7),  // "checked"
        QT_MOC_LITERAL(274, 20),  // "on_italics_triggered"
        QT_MOC_LITERAL(295, 22)   // "on_underline_triggered"
    },
    "MainWindow",
    "on_new_file_triggered",
    "",
    "on_save_file_triggered",
    "on_open_file_triggered",
    "on_save_as_triggered",
    "on_paste_triggered",
    "on_copy_triggered",
    "on_about_triggered",
    "on_cut_triggered",
    "on_font_triggered",
    "on_undo_triggered",
    "on_redo_triggered",
    "on_exit_triggered",
    "on_bolder_triggered",
    "checked",
    "on_italics_triggered",
    "on_underline_triggered"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    0,  105,    2, 0x08,    2 /* Private */,
       4,    0,  106,    2, 0x08,    3 /* Private */,
       5,    0,  107,    2, 0x08,    4 /* Private */,
       6,    0,  108,    2, 0x08,    5 /* Private */,
       7,    0,  109,    2, 0x08,    6 /* Private */,
       8,    0,  110,    2, 0x08,    7 /* Private */,
       9,    0,  111,    2, 0x08,    8 /* Private */,
      10,    0,  112,    2, 0x08,    9 /* Private */,
      11,    0,  113,    2, 0x08,   10 /* Private */,
      12,    0,  114,    2, 0x08,   11 /* Private */,
      13,    0,  115,    2, 0x08,   12 /* Private */,
      14,    1,  116,    2, 0x08,   13 /* Private */,
      16,    1,  119,    2, 0x08,   15 /* Private */,
      17,    1,  122,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_new_file_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_save_file_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_open_file_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_save_as_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_paste_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_copy_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_about_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cut_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_font_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_undo_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_redo_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bolder_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_italics_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_underline_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_new_file_triggered(); break;
        case 1: _t->on_save_file_triggered(); break;
        case 2: _t->on_open_file_triggered(); break;
        case 3: _t->on_save_as_triggered(); break;
        case 4: _t->on_paste_triggered(); break;
        case 5: _t->on_copy_triggered(); break;
        case 6: _t->on_about_triggered(); break;
        case 7: _t->on_cut_triggered(); break;
        case 8: _t->on_font_triggered(); break;
        case 9: _t->on_undo_triggered(); break;
        case 10: _t->on_redo_triggered(); break;
        case 11: _t->on_exit_triggered(); break;
        case 12: _t->on_bolder_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->on_italics_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->on_underline_triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
