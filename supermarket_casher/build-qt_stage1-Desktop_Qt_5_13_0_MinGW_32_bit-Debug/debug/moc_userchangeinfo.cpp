/****************************************************************************
** Meta object code from reading C++ file 'userchangeinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qt_stage1/userchangeinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userchangeinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_userchangeinfo_t {
    QByteArrayData data[13];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_userchangeinfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_userchangeinfo_t qt_meta_stringdata_userchangeinfo = {
    {
QT_MOC_LITERAL(0, 0, 14), // "userchangeinfo"
QT_MOC_LITERAL(1, 15, 13), // "sendclasstome"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "namec"
QT_MOC_LITERAL(4, 36, 10), // "sendreshow"
QT_MOC_LITERAL(5, 47, 12), // "setclasstome"
QT_MOC_LITERAL(6, 60, 23), // "on_userEdit_textChanged"
QT_MOC_LITERAL(7, 84, 4), // "arg1"
QT_MOC_LITERAL(8, 89, 21), // "on_idEdit_textChanged"
QT_MOC_LITERAL(9, 111, 27), // "on_passworkEdit_textChanged"
QT_MOC_LITERAL(10, 139, 21), // "on_ptEdit_textChanged"
QT_MOC_LITERAL(11, 161, 20), // "on_cancleBtn_clicked"
QT_MOC_LITERAL(12, 182, 18) // "on_sureBtn_clicked"

    },
    "userchangeinfo\0sendclasstome\0\0namec\0"
    "sendreshow\0setclasstome\0on_userEdit_textChanged\0"
    "arg1\0on_idEdit_textChanged\0"
    "on_passworkEdit_textChanged\0"
    "on_ptEdit_textChanged\0on_cancleBtn_clicked\0"
    "on_sureBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_userchangeinfo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   63,    2, 0x0a /* Public */,
       6,    1,   66,    2, 0x08 /* Private */,
       8,    1,   69,    2, 0x08 /* Private */,
       9,    1,   72,    2, 0x08 /* Private */,
      10,    1,   75,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void userchangeinfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<userchangeinfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendclasstome((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendreshow(); break;
        case 2: _t->setclasstome((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_userEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_idEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_passworkEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_ptEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_cancleBtn_clicked(); break;
        case 8: _t->on_sureBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (userchangeinfo::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&userchangeinfo::sendclasstome)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (userchangeinfo::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&userchangeinfo::sendreshow)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject userchangeinfo::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_userchangeinfo.data,
    qt_meta_data_userchangeinfo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *userchangeinfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userchangeinfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_userchangeinfo.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int userchangeinfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void userchangeinfo::sendclasstome(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void userchangeinfo::sendreshow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
