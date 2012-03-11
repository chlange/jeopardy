/****************************************************************************
** Meta object code from reading C++ file 'gamefield.h'
**
** Created: Sun Mar 11 14:32:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gamefield.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamefield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameField[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      33,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x08,
      67,   10,   63,   10, 0x08,
      76,   10,   10,   10, 0x08,
      96,   10,   10,   10, 0x08,
     122,   10,   10,   10, 0x08,
     148,   10,   10,   10, 0x08,
     174,   10,   10,   10, 0x08,
     200,   10,   10,   10, 0x08,
     226,   10,   10,   10, 0x08,
     252,   10,   10,   10, 0x08,
     278,   10,   10,   10, 0x08,
     304,   10,   10,   10, 0x08,
     330,   10,   10,   10, 0x08,
     356,   10,   10,   10, 0x08,
     382,   10,   10,   10, 0x08,
     408,   10,   10,   10, 0x08,
     434,   10,   10,   10, 0x08,
     460,   10,   10,   10, 0x08,
     486,   10,   10,   10, 0x08,
     512,   10,   10,   10, 0x08,
     538,   10,   10,   10, 0x08,
     564,   10,   10,   10, 0x08,
     590,   10,   10,   10, 0x08,
     616,   10,   10,   10, 0x08,
     642,   10,   10,   10, 0x08,
     668,   10,   10,   10, 0x08,
     694,   10,   10,   10, 0x08,
     720,   10,   10,   10, 0x08,
     746,   10,   10,   10, 0x08,
     772,   10,   10,   10, 0x08,
     798,   10,   10,   10, 0x08,
     824,   10,   10,   10, 0x08,
     850,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameField[] = {
    "GameField\0\0pos\0"
    "on_gameField_customContextMenuRequested(QPoint)\0"
    "int\0random()\0updateNamesLabels()\0"
    "on_button_1_100_clicked()\0"
    "on_button_2_100_clicked()\0"
    "on_button_3_100_clicked()\0"
    "on_button_4_100_clicked()\0"
    "on_button_5_100_clicked()\0"
    "on_button_6_100_clicked()\0"
    "on_button_1_200_clicked()\0"
    "on_button_2_200_clicked()\0"
    "on_button_3_200_clicked()\0"
    "on_button_4_200_clicked()\0"
    "on_button_5_200_clicked()\0"
    "on_button_6_200_clicked()\0"
    "on_button_1_300_clicked()\0"
    "on_button_2_300_clicked()\0"
    "on_button_3_300_clicked()\0"
    "on_button_4_300_clicked()\0"
    "on_button_5_300_clicked()\0"
    "on_button_6_300_clicked()\0"
    "on_button_1_400_clicked()\0"
    "on_button_2_400_clicked()\0"
    "on_button_3_400_clicked()\0"
    "on_button_4_400_clicked()\0"
    "on_button_5_400_clicked()\0"
    "on_button_6_400_clicked()\0"
    "on_button_1_500_clicked()\0"
    "on_button_2_500_clicked()\0"
    "on_button_3_500_clicked()\0"
    "on_button_4_500_clicked()\0"
    "on_button_5_500_clicked()\0"
    "on_button_6_500_clicked()\0"
};

const QMetaObject GameField::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GameField,
      qt_meta_data_GameField, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameField::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameField::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameField))
        return static_cast<void*>(const_cast< GameField*>(this));
    return QDialog::qt_metacast(_clname);
}

int GameField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_gameField_customContextMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: { int _r = random();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: updateNamesLabels(); break;
        case 3: on_button_1_100_clicked(); break;
        case 4: on_button_2_100_clicked(); break;
        case 5: on_button_3_100_clicked(); break;
        case 6: on_button_4_100_clicked(); break;
        case 7: on_button_5_100_clicked(); break;
        case 8: on_button_6_100_clicked(); break;
        case 9: on_button_1_200_clicked(); break;
        case 10: on_button_2_200_clicked(); break;
        case 11: on_button_3_200_clicked(); break;
        case 12: on_button_4_200_clicked(); break;
        case 13: on_button_5_200_clicked(); break;
        case 14: on_button_6_200_clicked(); break;
        case 15: on_button_1_300_clicked(); break;
        case 16: on_button_2_300_clicked(); break;
        case 17: on_button_3_300_clicked(); break;
        case 18: on_button_4_300_clicked(); break;
        case 19: on_button_5_300_clicked(); break;
        case 20: on_button_6_300_clicked(); break;
        case 21: on_button_1_400_clicked(); break;
        case 22: on_button_2_400_clicked(); break;
        case 23: on_button_3_400_clicked(); break;
        case 24: on_button_4_400_clicked(); break;
        case 25: on_button_5_400_clicked(); break;
        case 26: on_button_6_400_clicked(); break;
        case 27: on_button_1_500_clicked(); break;
        case 28: on_button_2_500_clicked(); break;
        case 29: on_button_3_500_clicked(); break;
        case 30: on_button_4_500_clicked(); break;
        case 31: on_button_5_500_clicked(); break;
        case 32: on_button_6_500_clicked(); break;
        default: ;
        }
        _id -= 33;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
