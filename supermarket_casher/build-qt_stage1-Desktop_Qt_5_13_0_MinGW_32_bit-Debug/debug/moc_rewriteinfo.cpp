/****************************************************************************
** Meta object code from reading C++ file 'rewriteinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qt_stage1/rewriteinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rewriteinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rewriteinfo_t {
    QByteArrayData data[20];
    char stringdata0[290];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rewriteinfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rewriteinfo_t qt_meta_stringdata_rewriteinfo = {
    {
QT_MOC_LITERAL(0, 0, 11), // "rewriteinfo"
QT_MOC_LITERAL(1, 12, 10), // "sendreloda"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "sendclass"
QT_MOC_LITERAL(4, 34, 6), // "goods&"
QT_MOC_LITERAL(5, 41, 10), // "fileclasss"
QT_MOC_LITERAL(6, 52, 4), // "name"
QT_MOC_LITERAL(7, 57, 21), // "QVector<goodsVector>&"
QT_MOC_LITERAL(8, 79, 8), // "shopList"
QT_MOC_LITERAL(9, 88, 12), // "goodsVector&"
QT_MOC_LITERAL(10, 101, 12), // "changeclasss"
QT_MOC_LITERAL(11, 114, 8), // "getclass"
QT_MOC_LITERAL(12, 123, 23), // "on_nameEdit_textChanged"
QT_MOC_LITERAL(13, 147, 4), // "arg1"
QT_MOC_LITERAL(14, 152, 23), // "on_typeEdit_textChanged"
QT_MOC_LITERAL(15, 176, 23), // "on_costEdit_textChanged"
QT_MOC_LITERAL(16, 200, 24), // "on_priceEdit_textChanged"
QT_MOC_LITERAL(17, 225, 24), // "on_stockEdit_textChanged"
QT_MOC_LITERAL(18, 250, 18), // "on_sureBtn_clicked"
QT_MOC_LITERAL(19, 269, 20) // "on_cancleBtn_clicked"

    },
    "rewriteinfo\0sendreloda\0\0sendclass\0"
    "goods&\0fileclasss\0name\0QVector<goodsVector>&\0"
    "shopList\0goodsVector&\0changeclasss\0"
    "getclass\0on_nameEdit_textChanged\0arg1\0"
    "on_typeEdit_textChanged\0on_costEdit_textChanged\0"
    "on_priceEdit_textChanged\0"
    "on_stockEdit_textChanged\0on_sureBtn_clicked\0"
    "on_cancleBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rewriteinfo[] = {

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
       3,    4,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    4,   74,    2, 0x0a /* Public */,
      12,    1,   83,    2, 0x08 /* Private */,
      14,    1,   86,    2, 0x08 /* Private */,
      15,    1,   89,    2, 0x08 /* Private */,
      16,    1,   92,    2, 0x08 /* Private */,
      17,    1,   95,    2, 0x08 /* Private */,
      18,    0,   98,    2, 0x08 /* Private */,
      19,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString, 0x80000000 | 7, 0x80000000 | 9,    5,    6,    8,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString, 0x80000000 | 7, 0x80000000 | 9,    5,    6,    8,   10,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rewriteinfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<rewriteinfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendreloda(); break;
        case 1: _t->sendclass((*reinterpret_cast< goods(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QVector<goodsVector>(*)>(_a[3])),(*reinterpret_cast< goodsVector(*)>(_a[4]))); break;
        case 2: _t->getclass((*reinterpret_cast< goods(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QVector<goodsVector>(*)>(_a[3])),(*reinterpret_cast< goodsVector(*)>(_a[4]))); break;
        case 3: _t->on_nameEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
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
            using _t = void (rewriteinfo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rewriteinfo::sendreloda)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (rewriteinfo::*)(goods & , QString , QVector<goodsVector> & , goodsVector & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rewriteinfo::sendclass)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject rewriteinfo::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_rewriteinfo.data,
    qt_meta_data_rewriteinfo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *rewriteinfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rewriteinfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rewriteinfo.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int rewriteinfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void rewriteinfo::sendreloda()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void rewriteinfo::sendclass(goods & _t1, QString _t2, QVector<goodsVector> & _t3, goodsVector & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
