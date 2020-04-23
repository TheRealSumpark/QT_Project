/****************************************************************************
** Meta object code from reading C++ file 'ajouter_joueur_equipe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projet_selimbenaich/ajouter_joueur_equipe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ajouter_joueur_equipe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ajouter_joueur_equipe_t {
    QByteArrayData data[7];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ajouter_joueur_equipe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ajouter_joueur_equipe_t qt_meta_stringdata_ajouter_joueur_equipe = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ajouter_joueur_equipe"
QT_MOC_LITERAL(1, 22, 38), // "on_comboBox_joueur_currentInd..."
QT_MOC_LITERAL(2, 61, 0), // ""
QT_MOC_LITERAL(3, 62, 4), // "arg1"
QT_MOC_LITERAL(4, 67, 38), // "on_comboBox_equipe_currentInd..."
QT_MOC_LITERAL(5, 106, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 130, 32) // "on_Ajouter_joueur_equipe_clicked"

    },
    "ajouter_joueur_equipe\0"
    "on_comboBox_joueur_currentIndexChanged\0"
    "\0arg1\0on_comboBox_equipe_currentIndexChanged\0"
    "on_pushButton_2_clicked\0"
    "on_Ajouter_joueur_equipe_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ajouter_joueur_equipe[] = {

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
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       5,    0,   40,    2, 0x08 /* Private */,
       6,    0,   41,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ajouter_joueur_equipe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ajouter_joueur_equipe *_t = static_cast<ajouter_joueur_equipe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBox_joueur_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_comboBox_equipe_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_Ajouter_joueur_equipe_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ajouter_joueur_equipe::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ajouter_joueur_equipe.data,
      qt_meta_data_ajouter_joueur_equipe,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ajouter_joueur_equipe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ajouter_joueur_equipe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ajouter_joueur_equipe.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ajouter_joueur_equipe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
