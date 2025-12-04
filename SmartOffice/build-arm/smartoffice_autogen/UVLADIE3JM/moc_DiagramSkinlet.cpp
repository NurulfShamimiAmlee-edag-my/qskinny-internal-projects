/****************************************************************************
** Meta object code from reading C++ file 'DiagramSkinlet.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/DiagramSkinlet.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DiagramSkinlet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14DiagramSkinletE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN14DiagramSkinletE = QtMocHelpers::stringData(
    "DiagramSkinlet",
    "",
    "QskSkin*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN14DiagramSkinletE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       2,   18, // constructors
       4,       // flags
       0,       // signalCount

 // constructors: parameters
    0x80000000 | 1, 0x80000000 | 2,    1,
    0x80000000 | 1,

 // constructors: name, argc, parameters, tag, flags, initial metatype offsets
       0,    1,   14,    1, 0x0e,    1 /* Public */,
       0,    0,   17,    1, 0x2e,    2 /* Public | MethodCloned */,

       0        // eod
};

Q_CONSTINIT const QMetaObject DiagramSkinlet::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QskSkinlet>::value,
    qt_meta_stringdata_ZN14DiagramSkinletE.offsetsAndSizes,
    qt_meta_data_ZN14DiagramSkinletE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN14DiagramSkinletE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DiagramSkinlet, std::true_type>,
        // constructor 'DiagramSkinlet'
        QtPrivate::TypeAndForceComplete<QskSkin *, std::false_type>
    >,
    nullptr
} };

void DiagramSkinlet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<DiagramSkinlet *>(_o);
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { DiagramSkinlet *_r = new DiagramSkinlet((*reinterpret_cast<std::add_pointer_t<QskSkin*>>(_a[1])));
            if (_a[0]) *reinterpret_cast<void**>(_a[0]) = _r; } break;
        case 1: { DiagramSkinlet *_r = new DiagramSkinlet();
            if (_a[0]) *reinterpret_cast<void**>(_a[0]) = _r; } break;
        default: break;
        }
    }
    if (_c == QMetaObject::ConstructInPlace) {
        switch (_id) {
        case 0: { new (_a[0]) DiagramSkinlet((*reinterpret_cast<std::add_pointer_t<QskSkin*>>(_a[1]))); } break;
        case 1: { new (_a[0]) DiagramSkinlet(); } break;
        default: break;
        }
    }
    (void)_t;
}
QT_WARNING_POP
