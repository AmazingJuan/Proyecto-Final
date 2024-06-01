/****************************************************************************
** Meta object code from reading C++ file 'obstaculo.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Codificacion/obstaculo.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'obstaculo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSobstaculoENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSobstaculoENDCLASS = QtMocHelpers::stringData(
    "obstaculo",
    "collect_coin",
    "",
    "crash_management",
    "ask_move",
    "future_pos",
    "QGraphicsProxyWidget*",
    "widget",
    "crash_happening",
    "handle_timeout",
    "crash_timeout",
    "start_crash",
    "change_speed",
    "value"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSobstaculoENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[10];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[9];
    char stringdata5[11];
    char stringdata6[22];
    char stringdata7[7];
    char stringdata8[16];
    char stringdata9[15];
    char stringdata10[14];
    char stringdata11[12];
    char stringdata12[13];
    char stringdata13[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSobstaculoENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSobstaculoENDCLASS_t qt_meta_stringdata_CLASSobstaculoENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "obstaculo"
        QT_MOC_LITERAL(10, 12),  // "collect_coin"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 16),  // "crash_management"
        QT_MOC_LITERAL(41, 8),  // "ask_move"
        QT_MOC_LITERAL(50, 10),  // "future_pos"
        QT_MOC_LITERAL(61, 21),  // "QGraphicsProxyWidget*"
        QT_MOC_LITERAL(83, 6),  // "widget"
        QT_MOC_LITERAL(90, 15),  // "crash_happening"
        QT_MOC_LITERAL(106, 14),  // "handle_timeout"
        QT_MOC_LITERAL(121, 13),  // "crash_timeout"
        QT_MOC_LITERAL(135, 11),  // "start_crash"
        QT_MOC_LITERAL(147, 12),  // "change_speed"
        QT_MOC_LITERAL(160, 5)   // "value"
    },
    "obstaculo",
    "collect_coin",
    "",
    "crash_management",
    "ask_move",
    "future_pos",
    "QGraphicsProxyWidget*",
    "widget",
    "crash_happening",
    "handle_timeout",
    "crash_timeout",
    "start_crash",
    "change_speed",
    "value"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSobstaculoENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    0,   57,    2, 0x06,    2 /* Public */,
       4,    3,   58,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   65,    2, 0x08,    7 /* Private */,
      10,    0,   66,    2, 0x08,    8 /* Private */,
      11,    1,   67,    2, 0x0a,    9 /* Public */,
      12,    1,   70,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint, 0x80000000 | 6, QMetaType::Bool,    5,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Short,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject obstaculo::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsProxyWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSobstaculoENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSobstaculoENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSobstaculoENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<obstaculo, std::true_type>,
        // method 'collect_coin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'crash_management'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ask_move'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsProxyWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'handle_timeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'crash_timeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'start_crash'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsProxyWidget *, std::false_type>,
        // method 'change_speed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<short, std::false_type>
    >,
    nullptr
} };

void obstaculo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<obstaculo *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->collect_coin(); break;
        case 1: _t->crash_management(); break;
        case 2: _t->ask_move((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QGraphicsProxyWidget*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 3: _t->handle_timeout(); break;
        case 4: _t->crash_timeout(); break;
        case 5: _t->start_crash((*reinterpret_cast< std::add_pointer_t<QGraphicsProxyWidget*>>(_a[1]))); break;
        case 6: _t->change_speed((*reinterpret_cast< std::add_pointer_t<short>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsProxyWidget* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsProxyWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (obstaculo::*)();
            if (_t _q_method = &obstaculo::collect_coin; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (obstaculo::*)();
            if (_t _q_method = &obstaculo::crash_management; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (obstaculo::*)(QPoint , QGraphicsProxyWidget * , bool );
            if (_t _q_method = &obstaculo::ask_move; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *obstaculo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *obstaculo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSobstaculoENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "fisicas"))
        return static_cast< fisicas*>(this);
    return QGraphicsProxyWidget::qt_metacast(_clname);
}

int obstaculo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsProxyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void obstaculo::collect_coin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void obstaculo::crash_management()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void obstaculo::ask_move(QPoint _t1, QGraphicsProxyWidget * _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
