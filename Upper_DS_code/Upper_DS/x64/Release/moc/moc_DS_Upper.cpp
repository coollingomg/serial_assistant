/****************************************************************************
** Meta object code from reading C++ file 'DS_Upper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../DS_Upper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DS_Upper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DS_Upper_t {
    QByteArrayData data[9];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DS_Upper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DS_Upper_t qt_meta_stringdata_DS_Upper = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DS_Upper"
QT_MOC_LITERAL(1, 9, 10), // "timerEvent"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "QTimerEvent*"
QT_MOC_LITERAL(4, 34, 5), // "event"
QT_MOC_LITERAL(5, 40, 25), // "Open_close_Button_Clicked"
QT_MOC_LITERAL(6, 66, 21), // "recevie_data_Function"
QT_MOC_LITERAL(7, 88, 24), // "send_data_button_clicked"
QT_MOC_LITERAL(8, 113, 10) // "USB_Handle"

    },
    "DS_Upper\0timerEvent\0\0QTimerEvent*\0"
    "event\0Open_close_Button_Clicked\0"
    "recevie_data_Function\0send_data_button_clicked\0"
    "USB_Handle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DS_Upper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DS_Upper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DS_Upper *_t = static_cast<DS_Upper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timerEvent((*reinterpret_cast< QTimerEvent*(*)>(_a[1]))); break;
        case 1: _t->Open_close_Button_Clicked(); break;
        case 2: _t->recevie_data_Function(); break;
        case 3: _t->send_data_button_clicked(); break;
        case 4: _t->USB_Handle(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DS_Upper::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DS_Upper.data,
      qt_meta_data_DS_Upper,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DS_Upper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DS_Upper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DS_Upper.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DS_Upper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
