/****************************************************************************
** Meta object code from reading C++ file 'barco.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Codificacion/barco.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'barco.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSbarcoENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSbarcoENDCLASS = QtMocHelpers::stringData(
    "barco",
    "ask_move",
    "",
    "future_pos",
    "QGraphicsProxyWidget*",
    "widget",
    "crash_happening",
    "crash_management",
    "crash_timeout",
    "shm_timeout",
    "start_crash",
    "speed",
    "start_shm"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSbarcoENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[6];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[22];
    char stringdata5[7];
    char stringdata6[16];
    char stringdata7[17];
    char stringdata8[14];
    char stringdata9[12];
    char stringdata10[12];
    char stringdata11[6];
    char stringdata12[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSbarcoENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSbarcoENDCLASS_t qt_meta_stringdata_CLASSbarcoENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "barco"
        QT_MOC_LITERAL(6, 8),  // "ask_move"
        QT_MOC_LITERAL(15, 0),  // ""
        QT_MOC_LITERAL(16, 10),  // "future_pos"
        QT_MOC_LITERAL(27, 21),  // "QGraphicsProxyWidget*"
        QT_MOC_LITERAL(49, 6),  // "widget"
        QT_MOC_LITERAL(56, 15),  // "crash_happening"
        QT_MOC_LITERAL(72, 16),  // "crash_management"
        QT_MOC_LITERAL(89, 13),  // "crash_timeout"
        QT_MOC_LITERAL(103, 11),  // "shm_timeout"
        QT_MOC_LITERAL(115, 11),  // "start_crash"
        QT_MOC_LITERAL(127, 5),  // "speed"
        QT_MOC_LITERAL(133, 9)   // "start_shm"
    },
    "barco",
    "ask_move",
    "",
    "future_pos",
    "QGraphicsProxyWidget*",
    "widget",
    "crash_happening",
    "crash_management",
    "crash_timeout",
    "shm_timeout",
    "start_crash",
    "speed",
    "start_shm"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSbarcoENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   50,    2, 0x06,    1 /* Public */,
       7,    0,   57,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   58,    2, 0x08,    6 /* Private */,
       9,    0,   59,    2, 0x08,    7 /* Private */,
      10,    1,   60,    2, 0x0a,    8 /* Public */,
      12,    0,   63,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint, 0x80000000 | 4, QMetaType::Bool,    3,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   11,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject barco::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsProxyWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSbarcoENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSbarcoENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSbarcoENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<barco, std::true_type>,
        // method 'ask_move'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsProxyWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'crash_management'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'crash_timeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'shm_timeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'start_crash'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'start_shm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void barco::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<barco *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ask_move((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QGraphicsProxyWidget*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 1: _t->crash_management(); break;
        case 2: _t->crash_timeout(); break;
        case 3: _t->shm_timeout(); break;
        case 4: _t->start_crash((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 5: _t->start_shm(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsProxyWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (barco::*)(QPoint , QGraphicsProxyWidget * , bool );
            if (_t _q_method = &barco::ask_move; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (barco::*)();
            if (_t _q_method = &barco::crash_management; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *barco::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *barco::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSbarcoENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "fisicas"))
        return static_cast< fisicas*>(this);
    return QGraphicsProxyWidget::qt_metacast(_clname);
}

int barco::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsProxyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void barco::ask_move(QPoint _t1, QGraphicsProxyWidget * _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void barco::crash_management()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
