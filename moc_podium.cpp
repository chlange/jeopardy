
QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Podium[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Podium[] = {
    "Podium\0"
};

const QMetaObject Podium::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Podium,
      qt_meta_data_Podium, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Podium::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Podium::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Podium::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Podium))
        return static_cast<void*>(const_cast< Podium*>(this));
    return QDialog::qt_metacast(_clname);
}

int Podium::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
