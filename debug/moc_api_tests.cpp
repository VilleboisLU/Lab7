/****************************************************************************
** Meta object code from reading C++ file 'api_tests.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../api_tests.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'api_tests.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_API_Tests_t {
    QByteArrayData data[9];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_API_Tests_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_API_Tests_t qt_meta_stringdata_API_Tests = {
    {
QT_MOC_LITERAL(0, 0, 9), // "API_Tests"
QT_MOC_LITERAL(1, 10, 11), // "GetUserTest"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "GetOneUserTest"
QT_MOC_LITERAL(4, 38, 22), // "GetNonExistentUserTest"
QT_MOC_LITERAL(5, 61, 18), // "PostCreateUserTest"
QT_MOC_LITERAL(6, 80, 21), // "PostBadCreateUserTest"
QT_MOC_LITERAL(7, 102, 17), // "PutUserUpdateTest"
QT_MOC_LITERAL(8, 120, 14) // "DeleteUserTest"

    },
    "API_Tests\0GetUserTest\0\0GetOneUserTest\0"
    "GetNonExistentUserTest\0PostCreateUserTest\0"
    "PostBadCreateUserTest\0PutUserUpdateTest\0"
    "DeleteUserTest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_API_Tests[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void API_Tests::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<API_Tests *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GetUserTest(); break;
        case 1: _t->GetOneUserTest(); break;
        case 2: _t->GetNonExistentUserTest(); break;
        case 3: _t->PostCreateUserTest(); break;
        case 4: _t->PostBadCreateUserTest(); break;
        case 5: _t->PutUserUpdateTest(); break;
        case 6: _t->DeleteUserTest(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject API_Tests::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_API_Tests.data,
    qt_meta_data_API_Tests,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *API_Tests::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *API_Tests::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_API_Tests.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int API_Tests::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
