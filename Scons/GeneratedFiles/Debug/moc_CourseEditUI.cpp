/****************************************************************************
** Meta object code from reading C++ file 'CourseEditUI.h'
**
** Created: Mon 11. Jun 06:46:47 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CourseEditUI.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CourseEditUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CourseEditUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   14,   13,   13, 0x08,
     100,   80,   13,   13, 0x08,
     157,   13,   13,   13, 0x08,
     170,   13,   13,   13, 0x08,
     187,   13,   13,   13, 0x08,
     200,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CourseEditUI[] = {
    "CourseEditUI\0\0index1,index2\0"
    "tableViewCurrentRowChanged(QModelIndex,QModelIndex)\0"
    "selected,deselected\0"
    "tableViewSelectionChanged(QItemSelection,QItemSelection)\0"
    "changeItem()\0saveItemToFile()\0"
    "addNewItem()\0cancelAdd()\0"
};

void CourseEditUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CourseEditUI *_t = static_cast<CourseEditUI *>(_o);
        switch (_id) {
        case 0: _t->tableViewCurrentRowChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 1: _t->tableViewSelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 2: _t->changeItem(); break;
        case 3: _t->saveItemToFile(); break;
        case 4: _t->addNewItem(); break;
        case 5: _t->cancelAdd(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CourseEditUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CourseEditUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CourseEditUI,
      qt_meta_data_CourseEditUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CourseEditUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CourseEditUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CourseEditUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CourseEditUI))
        return static_cast<void*>(const_cast< CourseEditUI*>(this));
    if (!strcmp(_clname, "CourseEditView"))
        return static_cast< CourseEditView*>(const_cast< CourseEditUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int CourseEditUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
