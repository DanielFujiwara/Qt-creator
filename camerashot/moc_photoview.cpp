/****************************************************************************
** Meta object code from reading C++ file 'photoview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "photoview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'photoview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_photoview_t {
    QByteArrayData data[9];
    char stringdata0[143];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_photoview_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_photoview_t qt_meta_stringdata_photoview = {
    {
QT_MOC_LITERAL(0, 0, 9), // "photoview"
QT_MOC_LITERAL(1, 10, 12), // "sendshowList"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "showListonWidget"
QT_MOC_LITERAL(4, 41, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 63, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(6, 95, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 112, 4), // "item"
QT_MOC_LITERAL(8, 117, 25) // "on_listWidget_itemClicked"

    },
    "photoview\0sendshowList\0\0showListonWidget\0"
    "on_pushButton_clicked\0"
    "on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_listWidget_itemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_photoview[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       8,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void photoview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        photoview *_t = static_cast<photoview *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendshowList(); break;
        case 1: _t->showListonWidget(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (photoview::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&photoview::sendshowList)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject photoview::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_photoview.data,
      qt_meta_data_photoview,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *photoview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *photoview::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_photoview.stringdata0))
        return static_cast<void*>(const_cast< photoview*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int photoview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void photoview::sendshowList()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
