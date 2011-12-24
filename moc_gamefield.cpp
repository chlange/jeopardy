/****************************************************************************
** Meta object code from reading C++ file 'gamefield.h'
**
** Created: Sat Dec 24 16:13:53 2011
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
      63,   10,   10,   10, 0x08,
      72,   10,   10,   10, 0x08,
      92,   10,   10,   10, 0x08,
     118,   10,   10,   10, 0x08,
     144,   10,   10,   10, 0x08,
     170,   10,   10,   10, 0x08,
     196,   10,   10,   10, 0x08,
     222,   10,   10,   10, 0x08,
     248,   10,   10,   10, 0x08,
     274,   10,   10,   10, 0x08,
     300,   10,   10,   10, 0x08,
     326,   10,   10,   10, 0x08,
     352,   10,   10,   10, 0x08,
     378,   10,   10,   10, 0x08,
     404,   10,   10,   10, 0x08,
     430,   10,   10,   10, 0x08,
     456,   10,   10,   10, 0x08,
     482,   10,   10,   10, 0x08,
     508,   10,   10,   10, 0x08,
     534,   10,   10,   10, 0x08,
     560,   10,   10,   10, 0x08,
     586,   10,   10,   10, 0x08,
     612,   10,   10,   10, 0x08,
     638,   10,   10,   10, 0x08,
     664,   10,   10,   10, 0x08,
     690,   10,   10,   10, 0x08,
     716,   10,   10,   10, 0x08,
     742,   10,   10,   10, 0x08,
     768,   10,   10,   10, 0x08,
     794,   10,   10,   10, 0x08,
     820,   10,   10,   10, 0x08,
     846,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameField[] = {
    "GameField\0\0pos\0"
    "on_gameField_customContextMenuRequested(QPoint)\0"
    "random()\0updateNamesLabels()\0"
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
        case 1: random(); break;
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
