/****************************************************************************
** Meta object code from reading C++ file 'dialogbox_yesno_generic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialogbox_yesno_generic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogbox_yesno_generic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dialogbox_yesno_generic_t {
    QByteArrayData data[6];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dialogbox_yesno_generic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dialogbox_yesno_generic_t qt_meta_stringdata_dialogbox_yesno_generic = {
    {
QT_MOC_LITERAL(0, 0, 23), // "dialogbox_yesno_generic"
QT_MOC_LITERAL(1, 24, 11), // "YesNoSignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 10), // "TypeSignal"
QT_MOC_LITERAL(4, 48, 25), // "on_pushButton_yes_clicked"
QT_MOC_LITERAL(5, 74, 24) // "on_pushButton_no_clicked"

    },
    "dialogbox_yesno_generic\0YesNoSignal\0"
    "\0TypeSignal\0on_pushButton_yes_clicked\0"
    "on_pushButton_no_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dialogbox_yesno_generic[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   40,    2, 0x08 /* Private */,
       5,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dialogbox_yesno_generic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dialogbox_yesno_generic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->YesNoSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->TypeSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_yes_clicked(); break;
        case 3: _t->on_pushButton_no_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dialogbox_yesno_generic::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dialogbox_yesno_generic::YesNoSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (dialogbox_yesno_generic::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dialogbox_yesno_generic::TypeSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dialogbox_yesno_generic::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_dialogbox_yesno_generic.data,
    qt_meta_data_dialogbox_yesno_generic,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dialogbox_yesno_generic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dialogbox_yesno_generic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dialogbox_yesno_generic.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int dialogbox_yesno_generic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void dialogbox_yesno_generic::YesNoSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void dialogbox_yesno_generic::TypeSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
