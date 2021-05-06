/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Tue Sep 10 10:41:18 2019
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      26,    7,    7,    7, 0x08,
      37,    7,    7,    7, 0x08,
      56,    7,    7,    7, 0x08,
      74,   68,    7,    7, 0x08,
     117,    7,    7,    7, 0x08,
     138,   68,    7,    7, 0x08,
     181,    7,    7,    7, 0x08,
     199,    7,    7,    7, 0x08,
     218,    7,    7,    7, 0x08,
     247,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0connect_success()\0recv_msg()\0"
    "connect_success2()\0recv_msg2()\0index\0"
    "on_listWidget_c_doubleClicked(QModelIndex)\0"
    "on_connect_clicked()\0"
    "on_listWidget_s_doubleClicked(QModelIndex)\0"
    "on_left_clicked()\0on_right_clicked()\0"
    "on_clientdir_returnPressed()\0"
    "on_serverdir_returnPressed()\0"
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget *_t = static_cast<Widget *>(_o);
        switch (_id) {
        case 0: _t->connect_success(); break;
        case 1: _t->recv_msg(); break;
        case 2: _t->connect_success2(); break;
        case 3: _t->recv_msg2(); break;
        case 4: _t->on_listWidget_c_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_connect_clicked(); break;
        case 6: _t->on_listWidget_s_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_left_clicked(); break;
        case 8: _t->on_right_clicked(); break;
        case 9: _t->on_clientdir_returnPressed(); break;
        case 10: _t->on_serverdir_returnPressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
