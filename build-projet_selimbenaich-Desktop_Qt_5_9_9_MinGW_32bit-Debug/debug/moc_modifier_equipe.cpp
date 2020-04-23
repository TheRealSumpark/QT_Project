/****************************************************************************
** Meta object code from reading C++ file 'modifier_equipe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projet_selimbenaich/modifier_equipe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modifier_equipe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_modifier_equipe_t {
    QByteArrayData data[11];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_modifier_equipe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_modifier_equipe_t qt_meta_stringdata_modifier_equipe = {
    {
QT_MOC_LITERAL(0, 0, 15), // "modifier_equipe"
QT_MOC_LITERAL(1, 16, 18), // "on_b_image_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 27), // "on_afficher_modif_activated"
QT_MOC_LITERAL(4, 64, 5), // "index"
QT_MOC_LITERAL(5, 70, 29), // "on_afficher_modif_2_activated"
QT_MOC_LITERAL(6, 100, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(7, 124, 33), // "on_Appliquer_modification_cli..."
QT_MOC_LITERAL(8, 158, 18), // "on_Annuler_clicked"
QT_MOC_LITERAL(9, 177, 27), // "on_modifier_equipe_finished"
QT_MOC_LITERAL(10, 205, 6) // "result"

    },
    "modifier_equipe\0on_b_image_clicked\0\0"
    "on_afficher_modif_activated\0index\0"
    "on_afficher_modif_2_activated\0"
    "on_pushButton_3_clicked\0"
    "on_Appliquer_modification_clicked\0"
    "on_Annuler_clicked\0on_modifier_equipe_finished\0"
    "result"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modifier_equipe[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    1,   50,    2, 0x08 /* Private */,
       5,    1,   53,    2, 0x08 /* Private */,
       6,    0,   56,    2, 0x08 /* Private */,
       7,    0,   57,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void modifier_equipe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        modifier_equipe *_t = static_cast<modifier_equipe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_b_image_clicked(); break;
        case 1: _t->on_afficher_modif_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_afficher_modif_2_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_Appliquer_modification_clicked(); break;
        case 5: _t->on_Annuler_clicked(); break;
        case 6: _t->on_modifier_equipe_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject modifier_equipe::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_modifier_equipe.data,
      qt_meta_data_modifier_equipe,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *modifier_equipe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modifier_equipe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_modifier_equipe.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int modifier_equipe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
