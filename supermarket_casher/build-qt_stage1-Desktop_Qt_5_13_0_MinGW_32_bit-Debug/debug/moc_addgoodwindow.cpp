/****************************************************************************
** Meta object code from reading C++ file 'addgoodwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qt_stage1/addgoodwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addgoodwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_addgoodwindow_t {
    QByteArrayData data[17];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addgoodwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addgoodwindow_t qt_meta_stringdata_addgoodwindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "addgoodwindow"
QT_MOC_LITERAL(1, 14, 10), // "sendreshow"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "sendclass"
QT_MOC_LITERAL(4, 36, 21), // "QVector<goodsVector>&"
QT_MOC_LITERAL(5, 58, 8), // "shopList"
QT_MOC_LITERAL(6, 67, 12), // "goodsVector&"
QT_MOC_LITERAL(7, 80, 12), // "changeclasss"
QT_MOC_LITERAL(8, 93, 8), // "getclass"
QT_MOC_LITERAL(9, 102, 23), // "on_userEdit_textChanged"
QT_MOC_LITERAL(10, 126, 4), // "arg1"
QT_MOC_LITERAL(11, 131, 23), // "on_typeEdit_textChanged"
QT_MOC_LITERAL(12, 155, 23), // "on_costEdit_textChanged"
QT_MOC_LITERAL(13, 179, 24), // "on_priceEdit_textChanged"
QT_MOC_LITERAL(14, 204, 24), // "on_stockEdit_textChanged"
QT_MOC_LITERAL(15, 229, 18), // "on_sureBtn_clicked"
QT_MOC_LITERAL(16, 248, 20) // "on_cancleBtn_clicked"

    },
    "addgoodwindow\0sendreshow\0\0sendclass\0"
    "QVector<goodsVector>&\0shopList\0"
    "goodsVector&\0changeclasss\0getclass\0"
    "on_userEdit_textChanged\0arg1\0"
    "on_typeEdit_textChanged\0on_costEdit_textChanged\0"
    "on_priceEdit_textChanged\0"
    "on_stockEdit_textChanged\0on_sureBtn_clicked\0"
    "on_cancleBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addgoodwindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    2,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   70,    2, 0x0a /* Public */,
       9,    1,   75,    2, 0x08 /* Private */,
      11,    1,   78,    2, 0x08 /* Private */,
      12,    1,   81,    2, 0x08 /* Private */,
      13,    1,   84,    2, 0x08 /* Private */,
      14,    1,   87,    2, 0x08 /* Private */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    5,    7,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void addgoodwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<addgoodwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendreshow(); break;
        case 1: _t->sendclass((*reinterpret_cast< QVector<goodsVector>(*)>(_a[1])),(*reinterpret_cast< goodsVector(*)>(_a[2]))); break;
        case 2: _t->getclass((*reinterpret_cast< QVector<goodsVector>(*)>(_a[1])),(*reinterpret_cast< goodsVector(*)>(_a[2]))); break;
        case 3: _t->on_userEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_typeEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_costEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_priceEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_stockEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_sureBtn_clicked(); break;
        case 9: _t->on_cancleBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (addgoodwindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&addgoodwindow::sendreshow)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (addgoodwindow::*)(QVector<goodsVector> & , goodsVector & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&addgoodwindow::sendclass)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject addgoodwindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_addgoodwindow.data,
    qt_meta_data_addgoodwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *addgoodwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addgoodwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_addgoodwindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int addgoodwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void addgoodwindow::sendreshow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void addgoodwindow::sendclass(QVector<goodsVector> & _t1, goodsVector & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
