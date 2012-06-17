/****************************************************************************
** Meta object code from reading C++ file 'CoursesUi.h'
**
** Created: Sun 10. Jun 22:47:21 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CoursesUi.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CoursesUi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CoursesUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      28,   10,   10,   10, 0x08,
      43,   10,   10,   10, 0x08,
      55,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CoursesUI[] = {
    "CoursesUI\0\0selectedCourse()\0removeCourse()\0"
    "addCourse()\0editCourse()\0"
};

void CoursesUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CoursesUI *_t = static_cast<CoursesUI *>(_o);
        switch (_id) {
        case 0: _t->selectedCourse(); break;
        case 1: _t->removeCourse(); break;
        case 2: _t->addCourse(); break;
        case 3: _t->editCourse(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CoursesUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CoursesUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CoursesUI,
      qt_meta_data_CoursesUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CoursesUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CoursesUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CoursesUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CoursesUI))
        return static_cast<void*>(const_cast< CoursesUI*>(this));
    if (!strcmp(_clname, "CoursesView"))
        return static_cast< CoursesView*>(const_cast< CoursesUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int CoursesUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
