/****************************************************************************
** Meta object code from reading C++ file 'addnewuserwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qt_stage1/addnewuserwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addnewuserwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_addnewuserwindow_t {
    QByteArrayData data[14];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addnewuserwindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addnewuserwindow_t qt_meta_stringdata_addnewuserwindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "addnewuserwindow"
QT_MOC_LITERAL(1, 17, 13), // "sendclasstome"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 9), // "fileJson&"
QT_MOC_LITERAL(4, 42, 11), // "userchangee"
QT_MOC_LITERAL(5, 54, 10), // "sendreshow"
QT_MOC_LITERAL(6, 65, 12), // "setclasstome"
QT_MOC_LITERAL(7, 78, 23), // "on_userEdit_textChanged"
QT_MOC_LITERAL(8, 102, 4), // "arg1"
QT_MOC_LITERAL(9, 107, 21), // "on_idEdit_textChanged"
QT_MOC_LITERAL(10, 129, 27), // "on_passworkEdit_textChanged"
QT_MOC_LITERAL(11, 157, 21), // "on_ptEdit_textChanged"
QT_MOC_LITERAL(12, 179, 18), // "on_sureBtn_clicked"
QT_MOC_LITERAL(13, 198, 20) // "on_cancleBtn_clicked"

    },
    "addnewuserwindow\0sendclasstome\0\0"
    "fileJson&\0userchangee\0sendreshow\0"
    "setclasstome\0on_userEdit_textChanged\0"
    "arg1\0on_idEdit_textChanged\0"
    "on_passworkEdit_textChanged\0"
    "on_ptEdit_textChanged\0on_sureBtn_clicked\0"
    "on_cancleBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addnewuserwindow[] = {

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
       5,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   63,    2, 0x0a /* Public */,
       7,    1,   66,    2, 0x08 /* Private */,
       9,    1,   69,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      11,    1,   75,    2, 0x08 /* Private */,
      12,    0,   78,    2, 0x08 /* Private */,
      13,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void addnewuserwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<addnewuserwindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendclasstome((*reinterpret_cast< fileJson(*)>(_a[1]))); break;
        case 1: _t->sendreshow(); break;
        case 2: _t->setclasstome((*reinterpret_cast< fileJson(*)>(_a[1]))); break;
        case 3: _t->on_userEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_idEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_passworkEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_ptEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_sureBtn_clicked(); break;
        case 8: _t->on_cancleBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (addnewuserwindow::*)(fileJson & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&addnewuserwindow::sendclasstome)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (addnewuserwindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&addnewuserwindow::sendreshow)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject addnewuserwindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_addnewuserwindow.data,
    qt_meta_data_addnewuserwindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *addnewuserwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addnewuserwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_addnewuserwindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int addnewuserwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void addnewuserwindow::sendclasstome(fileJson & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void addnewuserwindow::sendreshow()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
