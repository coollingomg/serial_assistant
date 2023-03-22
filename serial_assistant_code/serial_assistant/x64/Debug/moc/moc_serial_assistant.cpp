/****************************************************************************
** Meta object code from reading C++ file 'serial_assistant.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../serial_assistant.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial_assistant.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serial_assistant_t {
    uint offsetsAndSizes[16];
    char stringdata0[17];
    char stringdata1[26];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[25];
    char stringdata5[16];
    char stringdata6[19];
    char stringdata7[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_serial_assistant_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_serial_assistant_t qt_meta_stringdata_serial_assistant = {
    {
        QT_MOC_LITERAL(0, 16),  // "serial_assistant"
        QT_MOC_LITERAL(17, 25),  // "Open_close_Button_Clicked"
        QT_MOC_LITERAL(43, 0),  // ""
        QT_MOC_LITERAL(44, 26),  // "recevie_plainTextEdit_data"
        QT_MOC_LITERAL(71, 24),  // "send_data_button_clicked"
        QT_MOC_LITERAL(96, 15),  // "clean_send_area"
        QT_MOC_LITERAL(112, 18),  // "clean_recevie_area"
        QT_MOC_LITERAL(131, 8)   // "slotTime"
    },
    "serial_assistant",
    "Open_close_Button_Clicked",
    "",
    "recevie_plainTextEdit_data",
    "send_data_button_clicked",
    "clean_send_area",
    "clean_recevie_area",
    "slotTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serial_assistant[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void serial_assistant::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serial_assistant *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Open_close_Button_Clicked(); break;
        case 1: _t->recevie_plainTextEdit_data(); break;
        case 2: _t->send_data_button_clicked(); break;
        case 3: _t->clean_send_area(); break;
        case 4: _t->clean_recevie_area(); break;
        case 5: _t->slotTime(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject serial_assistant::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_serial_assistant.offsetsAndSizes,
    qt_meta_data_serial_assistant,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_serial_assistant_t
, QtPrivate::TypeAndForceComplete<serial_assistant, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *serial_assistant::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serial_assistant::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serial_assistant.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int serial_assistant::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
