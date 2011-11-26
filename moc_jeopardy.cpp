/****************************************************************************
** Meta object code from reading C++ file 'jeopardy.h'
**
** Created: Sat Nov 26 17:24:20 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "jeopardy.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jeopardy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Jeopardy[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      36,    9,    9,    9, 0x08,
      62,    9,    9,    9, 0x08,
      88,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Jeopardy[] = {
    "Jeopardy\0\0on_buttonRound1_clicked()\0"
    "on_buttonRound2_clicked()\0"
    "on_buttonRound3_clicked()\0"
    "on_buttonRound4_clicked()\0"
};

const QMetaObject Jeopardy::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Jeopardy,
      qt_meta_data_Jeopardy, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Jeopardy::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Jeopardy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Jeopardy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Jeopardy))
        return static_cast<void*>(const_cast< Jeopardy*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Jeopardy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_buttonRound1_clicked(); break;
        case 1: on_buttonRound2_clicked(); break;
        case 2: on_buttonRound3_clicked(); break;
        case 3: on_buttonRound4_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
