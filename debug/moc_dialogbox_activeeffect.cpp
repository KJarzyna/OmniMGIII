/****************************************************************************
** Meta object code from reading C++ file 'dialogbox_activeeffect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialogbox_activeeffect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogbox_activeeffect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogBox_ActiveEffect_t {
    QByteArrayData data[6];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogBox_ActiveEffect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogBox_ActiveEffect_t qt_meta_stringdata_DialogBox_ActiveEffect = {
    {
QT_MOC_LITERAL(0, 0, 22), // "DialogBox_ActiveEffect"
QT_MOC_LITERAL(1, 23, 20), // "sendActiveEffectList"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 29), // "on_pushButton_confirm_clicked"
QT_MOC_LITERAL(4, 75, 50), // "on_pushButton_activeEffect_Fr..."
QT_MOC_LITERAL(5, 126, 50) // "on_pushButton_activeEffect_Fr..."

    },
    "DialogBox_ActiveEffect\0sendActiveEffectList\0"
    "\0on_pushButton_confirm_clicked\0"
    "on_pushButton_activeEffect_FromRightToLeft_clicked\0"
    "on_pushButton_activeEffect_FromLeftToRight_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogBox_ActiveEffect[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   37,    2, 0x08 /* Private */,
       4,    0,   38,    2, 0x08 /* Private */,
       5,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogBox_ActiveEffect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogBox_ActiveEffect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendActiveEffectList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_confirm_clicked(); break;
        case 2: _t->on_pushButton_activeEffect_FromRightToLeft_clicked(); break;
        case 3: _t->on_pushButton_activeEffect_FromLeftToRight_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogBox_ActiveEffect::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogBox_ActiveEffect::sendActiveEffectList)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogBox_ActiveEffect::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_DialogBox_ActiveEffect.data,
    qt_meta_data_DialogBox_ActiveEffect,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogBox_ActiveEffect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogBox_ActiveEffect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogBox_ActiveEffect.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int DialogBox_ActiveEffect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DialogBox_ActiveEffect::sendActiveEffectList(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
