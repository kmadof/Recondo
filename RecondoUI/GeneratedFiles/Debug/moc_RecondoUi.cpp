/****************************************************************************
** Meta object code from reading C++ file 'RecondoUi.h'
**
** Created: Sun 10. Jun 10:18:21 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RecondoUi.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RecondoUi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RecondoUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      21,   10,   10,   10, 0x08,
      38,   10,   10,   10, 0x08,
      53,   10,   10,   10, 0x08,
      66,   10,   10,   10, 0x08,
      79,   10,   10,   10, 0x08,
      94,   10,   10,   10, 0x08,
     111,   10,   10,   10, 0x08,
     127,   10,   10,   10, 0x08,
     143,   10,   10,   10, 0x08,
     161,   10,   10,   10, 0x08,
     178,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RecondoUI[] = {
    "RecondoUI\0\0doThing()\0showCourseForm()\0"
    "startLection()\0endLection()\0showAnswer()\0"
    "nextQuestion()\0setQualityZero()\0"
    "setQualityOne()\0setQualityTwo()\0"
    "setQualityThree()\0setQualityFour()\0"
    "setQualityFive()\0"
};

void RecondoUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RecondoUI *_t = static_cast<RecondoUI *>(_o);
        switch (_id) {
        case 0: _t->doThing(); break;
        case 1: _t->showCourseForm(); break;
        case 2: _t->startLection(); break;
        case 3: _t->endLection(); break;
        case 4: _t->showAnswer(); break;
        case 5: _t->nextQuestion(); break;
        case 6: _t->setQualityZero(); break;
        case 7: _t->setQualityOne(); break;
        case 8: _t->setQualityTwo(); break;
        case 9: _t->setQualityThree(); break;
        case 10: _t->setQualityFour(); break;
        case 11: _t->setQualityFive(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData RecondoUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RecondoUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RecondoUI,
      qt_meta_data_RecondoUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RecondoUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RecondoUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RecondoUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RecondoUI))
        return static_cast<void*>(const_cast< RecondoUI*>(this));
    if (!strcmp(_clname, "RecondoView"))
        return static_cast< RecondoView*>(const_cast< RecondoUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RecondoUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE