/****************************************************************************
** Meta object code from reading C++ file 'simplecasherctrl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qt_stage1/simplecasherctrl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simplecasherctrl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_simplecasherctrl_t {
    QByteArrayData data[16];
    char stringdata0[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_simplecasherctrl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_simplecasherctrl_t qt_meta_stringdata_simplecasherctrl = {
    {
QT_MOC_LITERAL(0, 0, 16), // "simplecasherctrl"
QT_MOC_LITERAL(1, 17, 6), // "sendID"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 2), // "ID"
QT_MOC_LITERAL(4, 28, 5), // "setID"
QT_MOC_LITERAL(5, 34, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 58, 14), // "screenshowTime"
QT_MOC_LITERAL(7, 73, 25), // "on_listWidget_itemClicked"
QT_MOC_LITERAL(8, 99, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 116, 4), // "item"
QT_MOC_LITERAL(10, 121, 17), // "on_addBtn_clicked"
QT_MOC_LITERAL(11, 139, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(12, 163, 20), // "on_reduceBtn_clicked"
QT_MOC_LITERAL(13, 184, 27), // "on_listWidget_2_itemClicked"
QT_MOC_LITERAL(14, 212, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(15, 236, 21) // "on_pushButton_clicked"

    },
    "simplecasherctrl\0sendID\0\0ID\0setID\0"
    "on_pushButton_2_clicked\0screenshowTime\0"
    "on_listWidget_itemClicked\0QListWidgetItem*\0"
    "item\0on_addBtn_clicked\0on_pushButton_3_clicked\0"
    "on_reduceBtn_clicked\0on_listWidget_2_itemClicked\0"
    "on_pushButton_4_clicked\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_simplecasherctrl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   72,    2, 0x0a /* Public */,
       5,    0,   75,    2, 0x08 /* Private */,
       6,    0,   76,    2, 0x08 /* Private */,
       7,    1,   77,    2, 0x08 /* Private */,
      10,    0,   80,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    1,   83,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void simplecasherctrl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<simplecasherctrl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->screenshowTime(); break;
        case 4: _t->on_listWidget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->on_addBtn_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        case 7: _t->on_reduceBtn_clicked(); break;
        case 8: _t->on_listWidget_2_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_4_clicked(); break;
        case 10: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (simplecasherctrl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&simplecasherctrl::sendID)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject simplecasherctrl::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_simplecasherctrl.data,
    qt_meta_data_simplecasherctrl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *simplecasherctrl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *simplecasherctrl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_simplecasherctrl.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int simplecasherctrl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void simplecasherctrl::sendID(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
