/****************************************************************************
** Meta object code from reading C++ file 'supprimer_equipe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projet_selimbenaich/supprimer_equipe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'supprimer_equipe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_supprimer_equipe_t {
    QByteArrayData data[8];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_supprimer_equipe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_supprimer_equipe_t qt_meta_stringdata_supprimer_equipe = {
    {
QT_MOC_LITERAL(0, 0, 16), // "supprimer_equipe"
QT_MOC_LITERAL(1, 17, 33), // "on_annuler_la_suppression_cli..."
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 38), // "on_comboBox_equipe_currentInd..."
QT_MOC_LITERAL(4, 91, 4), // "arg1"
QT_MOC_LITERAL(5, 96, 21), // "on_listView_activated"
QT_MOC_LITERAL(6, 118, 5), // "index"
QT_MOC_LITERAL(7, 124, 29) // "on_supprimer_equipe_2_clicked"

    },
    "supprimer_equipe\0on_annuler_la_suppression_clicked\0"
    "\0on_comboBox_equipe_currentIndexChanged\0"
    "arg1\0on_listView_activated\0index\0"
    "on_supprimer_equipe_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_supprimer_equipe[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       5,    1,   38,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,

       0        // eod
};

void supprimer_equipe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        supprimer_equipe *_t = static_cast<supprimer_equipe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_annuler_la_suppression_clicked(); break;
        case 1: _t->on_comboBox_equipe_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_listView_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_supprimer_equipe_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject supprimer_equipe::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_supprimer_equipe.data,
      qt_meta_data_supprimer_equipe,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *supprimer_equipe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *supprimer_equipe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_supprimer_equipe.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int supprimer_equipe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
