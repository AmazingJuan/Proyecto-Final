/****************************************************************************
** Meta object code from reading C++ file 'reglas_juego.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Codificacion/reglas_juego.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reglas_juego.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSreglas_juegoENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSreglas_juegoENDCLASS = QtMocHelpers::stringData(
    "reglas_juego",
    "crash",
    "",
    "QGraphicsProxyWidget*",
    "widget",
    "crash_ship",
    "speed",
    "change_speed",
    "direction",
    "crear_archivo",
    "hide_screen",
    "screen",
    "show_screen",
    "shoot_label_change",
    "label_index",
    "new_text",
    "is_aligned",
    "deletion",
    "loadMenu",
    "dato",
    "try_move",
    "future_pos",
    "crash_happening",
    "dispatch_obstacles",
    "handle_end_stage",
    "outside_removal",
    "obstaculo*",
    "obs",
    "change_scene",
    "manage_shop_buttons",
    "iniciar",
    "cargar"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSreglas_juegoENDCLASS_t {
    uint offsetsAndSizes[64];
    char stringdata0[13];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[7];
    char stringdata5[11];
    char stringdata6[6];
    char stringdata7[13];
    char stringdata8[10];
    char stringdata9[14];
    char stringdata10[12];
    char stringdata11[7];
    char stringdata12[12];
    char stringdata13[19];
    char stringdata14[12];
    char stringdata15[9];
    char stringdata16[11];
    char stringdata17[9];
    char stringdata18[9];
    char stringdata19[5];
    char stringdata20[9];
    char stringdata21[11];
    char stringdata22[16];
    char stringdata23[19];
    char stringdata24[17];
    char stringdata25[16];
    char stringdata26[11];
    char stringdata27[4];
    char stringdata28[13];
    char stringdata29[20];
    char stringdata30[8];
    char stringdata31[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSreglas_juegoENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSreglas_juegoENDCLASS_t qt_meta_stringdata_CLASSreglas_juegoENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "reglas_juego"
        QT_MOC_LITERAL(13, 5),  // "crash"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 21),  // "QGraphicsProxyWidget*"
        QT_MOC_LITERAL(42, 6),  // "widget"
        QT_MOC_LITERAL(49, 10),  // "crash_ship"
        QT_MOC_LITERAL(60, 5),  // "speed"
        QT_MOC_LITERAL(66, 12),  // "change_speed"
        QT_MOC_LITERAL(79, 9),  // "direction"
        QT_MOC_LITERAL(89, 13),  // "crear_archivo"
        QT_MOC_LITERAL(103, 11),  // "hide_screen"
        QT_MOC_LITERAL(115, 6),  // "screen"
        QT_MOC_LITERAL(122, 11),  // "show_screen"
        QT_MOC_LITERAL(134, 18),  // "shoot_label_change"
        QT_MOC_LITERAL(153, 11),  // "label_index"
        QT_MOC_LITERAL(165, 8),  // "new_text"
        QT_MOC_LITERAL(174, 10),  // "is_aligned"
        QT_MOC_LITERAL(185, 8),  // "deletion"
        QT_MOC_LITERAL(194, 8),  // "loadMenu"
        QT_MOC_LITERAL(203, 4),  // "dato"
        QT_MOC_LITERAL(208, 8),  // "try_move"
        QT_MOC_LITERAL(217, 10),  // "future_pos"
        QT_MOC_LITERAL(228, 15),  // "crash_happening"
        QT_MOC_LITERAL(244, 18),  // "dispatch_obstacles"
        QT_MOC_LITERAL(263, 16),  // "handle_end_stage"
        QT_MOC_LITERAL(280, 15),  // "outside_removal"
        QT_MOC_LITERAL(296, 10),  // "obstaculo*"
        QT_MOC_LITERAL(307, 3),  // "obs"
        QT_MOC_LITERAL(311, 12),  // "change_scene"
        QT_MOC_LITERAL(324, 19),  // "manage_shop_buttons"
        QT_MOC_LITERAL(344, 7),  // "iniciar"
        QT_MOC_LITERAL(352, 6)   // "cargar"
    },
    "reglas_juego",
    "crash",
    "",
    "QGraphicsProxyWidget*",
    "widget",
    "crash_ship",
    "speed",
    "change_speed",
    "direction",
    "crear_archivo",
    "hide_screen",
    "screen",
    "show_screen",
    "shoot_label_change",
    "label_index",
    "new_text",
    "is_aligned",
    "deletion",
    "loadMenu",
    "dato",
    "try_move",
    "future_pos",
    "crash_happening",
    "dispatch_obstacles",
    "handle_end_stage",
    "outside_removal",
    "obstaculo*",
    "obs",
    "change_scene",
    "manage_shop_buttons",
    "iniciar",
    "cargar"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSreglas_juegoENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  116,    2, 0x06,    1 /* Public */,
       5,    1,  119,    2, 0x06,    3 /* Public */,
       7,    1,  122,    2, 0x06,    5 /* Public */,
       9,    0,  125,    2, 0x06,    7 /* Public */,
      10,    1,  126,    2, 0x06,    8 /* Public */,
      12,    1,  129,    2, 0x06,   10 /* Public */,
      13,    3,  132,    2, 0x06,   12 /* Public */,
      17,    0,  139,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    1,  140,    2, 0x08,   17 /* Private */,
      20,    3,  143,    2, 0x08,   19 /* Private */,
      23,    0,  150,    2, 0x08,   23 /* Private */,
      24,    0,  151,    2, 0x08,   24 /* Private */,
      25,    1,  152,    2, 0x08,   25 /* Private */,
      28,    0,  155,    2, 0x08,   27 /* Private */,
      29,    0,  156,    2, 0x0a,   28 /* Public */,
      30,    0,  157,    2, 0x0a,   29 /* Public */,
      31,    0,  158,    2, 0x0a,   30 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Float,    6,
    QMetaType::Void, QMetaType::Short,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Bool,   14,   15,   16,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::QPoint, 0x80000000 | 3, QMetaType::Bool,   21,    4,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject reglas_juego::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSreglas_juegoENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSreglas_juegoENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSreglas_juegoENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<reglas_juego, std::true_type>,
        // method 'crash'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsProxyWidget *, std::false_type>,
        // method 'crash_ship'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'change_speed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<short, std::false_type>,
        // method 'crear_archivo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hide_screen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'show_screen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'shoot_label_change'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'deletion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'try_move'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsProxyWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'dispatch_obstacles'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handle_end_stage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'outside_removal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<obstaculo *, std::false_type>,
        // method 'change_scene'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'manage_shop_buttons'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'iniciar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'cargar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void reglas_juego::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<reglas_juego *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->crash((*reinterpret_cast< std::add_pointer_t<QGraphicsProxyWidget*>>(_a[1]))); break;
        case 1: _t->crash_ship((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 2: _t->change_speed((*reinterpret_cast< std::add_pointer_t<short>>(_a[1]))); break;
        case 3: _t->crear_archivo(); break;
        case 4: _t->hide_screen((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->show_screen((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->shoot_label_change((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 7: _t->deletion(); break;
        case 8: _t->loadMenu((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->try_move((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QGraphicsProxyWidget*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 10: _t->dispatch_obstacles(); break;
        case 11: _t->handle_end_stage(); break;
        case 12: _t->outside_removal((*reinterpret_cast< std::add_pointer_t<obstaculo*>>(_a[1]))); break;
        case 13: _t->change_scene(); break;
        case 14: _t->manage_shop_buttons(); break;
        case 15: _t->iniciar(); break;
        case 16: _t->cargar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsProxyWidget* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QGraphicsProxyWidget* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< obstaculo* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (reglas_juego::*)(QGraphicsProxyWidget * );
            if (_t _q_method = &reglas_juego::crash; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (reglas_juego::*)(float );
            if (_t _q_method = &reglas_juego::crash_ship; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (reglas_juego::*)(short );
            if (_t _q_method = &reglas_juego::change_speed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (reglas_juego::*)();
            if (_t _q_method = &reglas_juego::crear_archivo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (reglas_juego::*)(int );
            if (_t _q_method = &reglas_juego::hide_screen; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (reglas_juego::*)(int );
            if (_t _q_method = &reglas_juego::show_screen; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (reglas_juego::*)(int , QString , bool );
            if (_t _q_method = &reglas_juego::shoot_label_change; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (reglas_juego::*)();
            if (_t _q_method = &reglas_juego::deletion; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject *reglas_juego::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *reglas_juego::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSreglas_juegoENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int reglas_juego::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void reglas_juego::crash(QGraphicsProxyWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void reglas_juego::crash_ship(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void reglas_juego::change_speed(short _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void reglas_juego::crear_archivo()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void reglas_juego::hide_screen(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void reglas_juego::show_screen(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void reglas_juego::shoot_label_change(int _t1, QString _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void reglas_juego::deletion()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
