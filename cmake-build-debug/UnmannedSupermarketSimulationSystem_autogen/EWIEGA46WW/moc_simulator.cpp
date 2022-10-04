/****************************************************************************
** Meta object code from reading C++ file 'simulator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../simulator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Simulator_t {
    QByteArrayData data[24];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Simulator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Simulator_t qt_meta_stringdata_Simulator = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Simulator"
QT_MOC_LITERAL(1, 10, 15), // "productPurchase"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "authentication"
QT_MOC_LITERAL(4, 42, 13), // "maskDetection"
QT_MOC_LITERAL(5, 56, 4), // "deal"
QT_MOC_LITERAL(6, 61, 18), // "searchShoppingCart"
QT_MOC_LITERAL(7, 80, 12), // "ShoppingCart"
QT_MOC_LITERAL(8, 93, 4), // "User"
QT_MOC_LITERAL(9, 98, 2), // "us"
QT_MOC_LITERAL(10, 101, 10), // "updateUser"
QT_MOC_LITERAL(11, 112, 18), // "updateShoppingCart"
QT_MOC_LITERAL(12, 131, 12), // "updateRecord"
QT_MOC_LITERAL(13, 144, 14), // "purchaseRecord"
QT_MOC_LITERAL(14, 159, 11), // "closeRecord"
QT_MOC_LITERAL(15, 171, 15), // "margoManagement"
QT_MOC_LITERAL(16, 187, 20), // "closeMargoManagement"
QT_MOC_LITERAL(17, 208, 8), // "addMargo"
QT_MOC_LITERAL(18, 217, 11), // "removeMargo"
QT_MOC_LITERAL(19, 229, 14), // "setCurrentUser"
QT_MOC_LITERAL(20, 244, 15), // "setShoppingCart"
QT_MOC_LITERAL(21, 260, 4), // "cart"
QT_MOC_LITERAL(22, 265, 7), // "setMask"
QT_MOC_LITERAL(23, 273, 1) // "m"

    },
    "Simulator\0productPurchase\0\0authentication\0"
    "maskDetection\0deal\0searchShoppingCart\0"
    "ShoppingCart\0User\0us\0updateUser\0"
    "updateShoppingCart\0updateRecord\0"
    "purchaseRecord\0closeRecord\0margoManagement\0"
    "closeMargoManagement\0addMargo\0removeMargo\0"
    "setCurrentUser\0setShoppingCart\0cart\0"
    "setMask\0m"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Simulator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    1,  103,    2, 0x08 /* Private */,
      10,    0,  106,    2, 0x08 /* Private */,
      11,    0,  107,    2, 0x08 /* Private */,
      12,    0,  108,    2, 0x08 /* Private */,
      13,    0,  109,    2, 0x08 /* Private */,
      14,    0,  110,    2, 0x08 /* Private */,
      15,    0,  111,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    0,  114,    2, 0x08 /* Private */,
      19,    1,  115,    2, 0x0a /* Public */,
      20,    1,  118,    2, 0x0a /* Public */,
      22,    1,  121,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 7, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 7,   21,
    QMetaType::Void, QMetaType::Bool,   23,

       0        // eod
};

void Simulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Simulator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->productPurchase(); break;
        case 1: _t->authentication(); break;
        case 2: _t->maskDetection(); break;
        case 3: _t->deal(); break;
        case 4: { ShoppingCart _r = _t->searchShoppingCart((*reinterpret_cast< User(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< ShoppingCart*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->updateUser(); break;
        case 6: _t->updateShoppingCart(); break;
        case 7: _t->updateRecord(); break;
        case 8: _t->purchaseRecord(); break;
        case 9: _t->closeRecord(); break;
        case 10: _t->margoManagement(); break;
        case 11: _t->closeMargoManagement(); break;
        case 12: _t->addMargo(); break;
        case 13: _t->removeMargo(); break;
        case 14: _t->setCurrentUser((*reinterpret_cast< User(*)>(_a[1]))); break;
        case 15: _t->setShoppingCart((*reinterpret_cast< ShoppingCart(*)>(_a[1]))); break;
        case 16: _t->setMask((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Simulator::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Simulator.data,
    qt_meta_data_Simulator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Simulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Simulator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Simulator.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Simulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
