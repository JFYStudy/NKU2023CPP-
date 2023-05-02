/****************************************************************************
** Meta object code from reading C++ file 'mytexteditbycode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CodeEditor/mytexteditbycode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytexteditbycode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyTextEditByCode_t {
    QByteArrayData data[8];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTextEditByCode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTextEditByCode_t qt_meta_stringdata_MyTextEditByCode = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MyTextEditByCode"
QT_MOC_LITERAL(1, 17, 36), // "onTextEditHorizontalScrollBar..."
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 34), // "onTextEditVerticalScrollBarCh..."
QT_MOC_LITERAL(4, 90, 18), // "onScrollBarChanged"
QT_MOC_LITERAL(5, 109, 39), // "onTextBrowserHorizontalScroll..."
QT_MOC_LITERAL(6, 149, 20), // "highlightCurrentLine"
QT_MOC_LITERAL(7, 170, 13) // "onTextChanged"

    },
    "MyTextEditByCode\0onTextEditHorizontalScrollBarChanged\0"
    "\0onTextEditVerticalScrollBarChanged\0"
    "onScrollBarChanged\0"
    "onTextBrowserHorizontalScrollBarChanged\0"
    "highlightCurrentLine\0onTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTextEditByCode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyTextEditByCode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyTextEditByCode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onTextEditHorizontalScrollBarChanged(); break;
        case 1: _t->onTextEditVerticalScrollBarChanged(); break;
        case 2: _t->onScrollBarChanged(); break;
        case 3: _t->onTextBrowserHorizontalScrollBarChanged(); break;
        case 4: _t->highlightCurrentLine(); break;
        case 5: _t->onTextChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MyTextEditByCode::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MyTextEditByCode.data,
    qt_meta_data_MyTextEditByCode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyTextEditByCode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTextEditByCode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyTextEditByCode.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyTextEditByCode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
