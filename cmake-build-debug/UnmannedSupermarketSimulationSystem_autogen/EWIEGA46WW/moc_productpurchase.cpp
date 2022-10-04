/****************************************************************************
** Meta object code from reading C++ file 'productpurchase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../productpurchase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'productpurchase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProductPurchase_t {
    QByteArrayData data[15];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProductPurchase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProductPurchase_t qt_meta_stringdata_ProductPurchase = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ProductPurchase"
QT_MOC_LITERAL(1, 16, 10), // "returnBack"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "currentItem"
QT_MOC_LITERAL(4, 40, 16), // "saveShoppingCart"
QT_MOC_LITERAL(5, 57, 12), // "addCommodity"
QT_MOC_LITERAL(6, 70, 15), // "removeCommodity"
QT_MOC_LITERAL(7, 86, 16), // "showShoppingCart"
QT_MOC_LITERAL(8, 103, 14), // "setCurrentUser"
QT_MOC_LITERAL(9, 118, 4), // "User"
QT_MOC_LITERAL(10, 123, 2), // "us"
QT_MOC_LITERAL(11, 126, 15), // "setShoppingCart"
QT_MOC_LITERAL(12, 142, 12), // "ShoppingCart"
QT_MOC_LITERAL(13, 155, 4), // "cart"
QT_MOC_LITERAL(14, 160, 16) // "loadShoppingCart"

    },
    "ProductPurchase\0returnBack\0\0currentItem\0"
    "saveShoppingCart\0addCommodity\0"
    "removeCommodity\0showShoppingCart\0"
    "setCurrentUser\0User\0us\0setShoppingCart\0"
    "ShoppingCart\0cart\0loadShoppingCart"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductPurchase[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x0a /* Public */,
      11,    1,   68,    2, 0x0a /* Public */,
      14,    0,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

void ProductPurchase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProductPurchase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnBack(); break;
        case 1: _t->currentItem(); break;
        case 2: _t->saveShoppingCart(); break;
        case 3: _t->addCommodity(); break;
        case 4: _t->removeCommodity(); break;
        case 5: _t->showShoppingCart(); break;
        case 6: _t->setCurrentUser((*reinterpret_cast< User(*)>(_a[1]))); break;
        case 7: _t->setShoppingCart((*reinterpret_cast< ShoppingCart(*)>(_a[1]))); break;
        case 8: _t->loadShoppingCart(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProductPurchase::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ProductPurchase.data,
    qt_meta_data_ProductPurchase,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProductPurchase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductPurchase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProductPurchase.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ProductPurchase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
