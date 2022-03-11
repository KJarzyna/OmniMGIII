/****************************************************************************
** Meta object code from reading C++ file 'calculator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../calculator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_calculator_t {
    QByteArrayData data[46];
    char stringdata0[1148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_calculator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_calculator_t qt_meta_stringdata_calculator = {
    {
QT_MOC_LITERAL(0, 0, 10), // "calculator"
QT_MOC_LITERAL(1, 11, 16), // "CalculatorClosed"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 23), // "GetDifficultyReasonSlot"
QT_MOC_LITERAL(4, 53, 6), // "reason"
QT_MOC_LITERAL(5, 60, 25), // "GetSelectedActionItemSlot"
QT_MOC_LITERAL(6, 86, 2), // "id"
QT_MOC_LITERAL(7, 89, 4), // "name"
QT_MOC_LITERAL(8, 94, 21), // "ActionDialogBoxClosed"
QT_MOC_LITERAL(9, 116, 9), // "db_closed"
QT_MOC_LITERAL(10, 126, 14), // "GetDiceResults"
QT_MOC_LITERAL(11, 141, 12), // "QVector<int>"
QT_MOC_LITERAL(12, 154, 5), // "dices"
QT_MOC_LITERAL(13, 160, 19), // "DiceDialogBoxClosed"
QT_MOC_LITERAL(14, 180, 20), // "CalculationsApproved"
QT_MOC_LITERAL(15, 201, 8), // "approved"
QT_MOC_LITERAL(16, 210, 30), // "ActiveEffectDialogBoxConfirmed"
QT_MOC_LITERAL(17, 241, 4), // "list"
QT_MOC_LITERAL(18, 246, 32), // "on_pushButton_AccMod_add_clicked"
QT_MOC_LITERAL(19, 279, 35), // "on_pushButton_AccMod_remove_c..."
QT_MOC_LITERAL(20, 315, 32), // "on_pushButton_DmgMod_add_clicked"
QT_MOC_LITERAL(21, 348, 34), // "on_pushButton_DmgMod_add_2_cl..."
QT_MOC_LITERAL(22, 383, 35), // "on_comboBox_select_player_act..."
QT_MOC_LITERAL(23, 419, 5), // "index"
QT_MOC_LITERAL(24, 425, 44), // "on_comboBox_select_difficulty..."
QT_MOC_LITERAL(25, 470, 4), // "arg1"
QT_MOC_LITERAL(26, 475, 35), // "on_comboBox_select_action_act..."
QT_MOC_LITERAL(27, 511, 31), // "on_pushButton_calculate_clicked"
QT_MOC_LITERAL(28, 543, 35), // "on_comboBox_select_target_act..."
QT_MOC_LITERAL(29, 579, 43), // "on_pushButton_continue_calcul..."
QT_MOC_LITERAL(30, 623, 29), // "on_pushButton_approve_clicked"
QT_MOC_LITERAL(31, 653, 32), // "on_pushButton_disapprove_clicked"
QT_MOC_LITERAL(32, 686, 34), // "on_pushButton_deleteEffect_cl..."
QT_MOC_LITERAL(33, 721, 31), // "on_pushButton_addEffect_clicked"
QT_MOC_LITERAL(34, 753, 34), // "on_checkBox_sukces_check_M_cl..."
QT_MOC_LITERAL(35, 788, 7), // "checked"
QT_MOC_LITERAL(36, 796, 34), // "on_pushButton_AccMod_add_M_cl..."
QT_MOC_LITERAL(37, 831, 37), // "on_pushButton_AccMod_remove_M..."
QT_MOC_LITERAL(38, 869, 34), // "on_pushButton_DmgMod_add_M_cl..."
QT_MOC_LITERAL(39, 904, 37), // "on_pushButton_DmgMod_remove_M..."
QT_MOC_LITERAL(40, 942, 37), // "on_comboBox_select_player_M_a..."
QT_MOC_LITERAL(41, 980, 44), // "on_tabWidget_calculation_type..."
QT_MOC_LITERAL(42, 1025, 31), // "on_pushButton_approve_M_clicked"
QT_MOC_LITERAL(43, 1057, 34), // "on_pushButton_disapprove_M_cl..."
QT_MOC_LITERAL(44, 1092, 26), // "on_pushButton_copy_clicked"
QT_MOC_LITERAL(45, 1119, 28) // "on_pushButton_copy_2_clicked"

    },
    "calculator\0CalculatorClosed\0\0"
    "GetDifficultyReasonSlot\0reason\0"
    "GetSelectedActionItemSlot\0id\0name\0"
    "ActionDialogBoxClosed\0db_closed\0"
    "GetDiceResults\0QVector<int>\0dices\0"
    "DiceDialogBoxClosed\0CalculationsApproved\0"
    "approved\0ActiveEffectDialogBoxConfirmed\0"
    "list\0on_pushButton_AccMod_add_clicked\0"
    "on_pushButton_AccMod_remove_clicked\0"
    "on_pushButton_DmgMod_add_clicked\0"
    "on_pushButton_DmgMod_add_2_clicked\0"
    "on_comboBox_select_player_activated\0"
    "index\0on_comboBox_select_difficultylevel_activated\0"
    "arg1\0on_comboBox_select_action_activated\0"
    "on_pushButton_calculate_clicked\0"
    "on_comboBox_select_target_activated\0"
    "on_pushButton_continue_calculations_clicked\0"
    "on_pushButton_approve_clicked\0"
    "on_pushButton_disapprove_clicked\0"
    "on_pushButton_deleteEffect_clicked\0"
    "on_pushButton_addEffect_clicked\0"
    "on_checkBox_sukces_check_M_clicked\0"
    "checked\0on_pushButton_AccMod_add_M_clicked\0"
    "on_pushButton_AccMod_remove_M_clicked\0"
    "on_pushButton_DmgMod_add_M_clicked\0"
    "on_pushButton_DmgMod_remove_M_clicked\0"
    "on_comboBox_select_player_M_activated\0"
    "on_tabWidget_calculation_type_currentChanged\0"
    "on_pushButton_approve_M_clicked\0"
    "on_pushButton_disapprove_M_clicked\0"
    "on_pushButton_copy_clicked\0"
    "on_pushButton_copy_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calculator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  179,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  180,    2, 0x08 /* Private */,
       5,    2,  183,    2, 0x08 /* Private */,
       8,    1,  188,    2, 0x08 /* Private */,
      10,    1,  191,    2, 0x08 /* Private */,
      13,    0,  194,    2, 0x08 /* Private */,
      14,    1,  195,    2, 0x08 /* Private */,
      16,    1,  198,    2, 0x08 /* Private */,
      18,    0,  201,    2, 0x08 /* Private */,
      19,    0,  202,    2, 0x08 /* Private */,
      20,    0,  203,    2, 0x08 /* Private */,
      21,    0,  204,    2, 0x08 /* Private */,
      22,    1,  205,    2, 0x08 /* Private */,
      24,    1,  208,    2, 0x08 /* Private */,
      26,    1,  211,    2, 0x08 /* Private */,
      27,    0,  214,    2, 0x08 /* Private */,
      28,    1,  215,    2, 0x08 /* Private */,
      29,    0,  218,    2, 0x08 /* Private */,
      30,    0,  219,    2, 0x08 /* Private */,
      31,    0,  220,    2, 0x08 /* Private */,
      32,    0,  221,    2, 0x08 /* Private */,
      33,    0,  222,    2, 0x08 /* Private */,
      34,    1,  223,    2, 0x08 /* Private */,
      36,    0,  226,    2, 0x08 /* Private */,
      37,    0,  227,    2, 0x08 /* Private */,
      38,    0,  228,    2, 0x08 /* Private */,
      39,    0,  229,    2, 0x08 /* Private */,
      40,    1,  230,    2, 0x08 /* Private */,
      41,    1,  233,    2, 0x08 /* Private */,
      42,    0,  236,    2, 0x08 /* Private */,
      43,    0,  237,    2, 0x08 /* Private */,
      44,    0,  238,    2, 0x08 /* Private */,
      45,    0,  239,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::QStringList,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void calculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<calculator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CalculatorClosed(); break;
        case 1: _t->GetDifficultyReasonSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->GetSelectedActionItemSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->ActionDialogBoxClosed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->GetDiceResults((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 5: _t->DiceDialogBoxClosed(); break;
        case 6: _t->CalculationsApproved((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->ActiveEffectDialogBoxConfirmed((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_AccMod_add_clicked(); break;
        case 9: _t->on_pushButton_AccMod_remove_clicked(); break;
        case 10: _t->on_pushButton_DmgMod_add_clicked(); break;
        case 11: _t->on_pushButton_DmgMod_add_2_clicked(); break;
        case 12: _t->on_comboBox_select_player_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_comboBox_select_difficultylevel_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_comboBox_select_action_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_pushButton_calculate_clicked(); break;
        case 16: _t->on_comboBox_select_target_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_pushButton_continue_calculations_clicked(); break;
        case 18: _t->on_pushButton_approve_clicked(); break;
        case 19: _t->on_pushButton_disapprove_clicked(); break;
        case 20: _t->on_pushButton_deleteEffect_clicked(); break;
        case 21: _t->on_pushButton_addEffect_clicked(); break;
        case 22: _t->on_checkBox_sukces_check_M_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->on_pushButton_AccMod_add_M_clicked(); break;
        case 24: _t->on_pushButton_AccMod_remove_M_clicked(); break;
        case 25: _t->on_pushButton_DmgMod_add_M_clicked(); break;
        case 26: _t->on_pushButton_DmgMod_remove_M_clicked(); break;
        case 27: _t->on_comboBox_select_player_M_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_tabWidget_calculation_type_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_pushButton_approve_M_clicked(); break;
        case 30: _t->on_pushButton_disapprove_M_clicked(); break;
        case 31: _t->on_pushButton_copy_clicked(); break;
        case 32: _t->on_pushButton_copy_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (calculator::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&calculator::CalculatorClosed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject calculator::staticMetaObject = { {
    &QFrame::staticMetaObject,
    qt_meta_stringdata_calculator.data,
    qt_meta_data_calculator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *calculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calculator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_calculator.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int calculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    return _id;
}

// SIGNAL 0
void calculator::CalculatorClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
