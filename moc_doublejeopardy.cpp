/****************************************************************************
** Meta object code from reading C++ file 'doublejeopardy.h'
**
** Created: Sun Mar 11 16:08:56 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "doublejeopardy.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doublejeopardy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DoubleJeopardy[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DoubleJeopardy[] = {
    "DoubleJeopardy\0\0on_button_clicked()\0"
};

const QMetaObject DoubleJeopardy::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DoubleJeopardy,
      qt_meta_data_DoubleJeopardy, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DoubleJeopardy::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DoubleJeopardy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DoubleJeopardy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DoubleJeopardy))
        return static_cast<void*>(const_cast< DoubleJeopardy*>(this));
    return QDialog::qt_metacast(_clname);
}

int DoubleJeopardy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_button_clicked(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
