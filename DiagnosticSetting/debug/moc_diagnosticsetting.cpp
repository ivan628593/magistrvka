/****************************************************************************
** Meta object code from reading C++ file 'diagnosticsetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../diagnosticsetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diagnosticsetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DiagnosticSetting_t {
    QByteArrayData data[15];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DiagnosticSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DiagnosticSetting_t qt_meta_stringdata_DiagnosticSetting = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DiagnosticSetting"
QT_MOC_LITERAL(1, 18, 11), // "commit_Data"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "QWidget*"
QT_MOC_LITERAL(4, 40, 14), // "add_new_system"
QT_MOC_LITERAL(5, 55, 14), // "customMenuTree"
QT_MOC_LITERAL(6, 70, 20), // "customMenuTableCheck"
QT_MOC_LITERAL(7, 91, 13), // "delete_system"
QT_MOC_LITERAL(8, 105, 15), // "editName_system"
QT_MOC_LITERAL(9, 121, 15), // "delete_checking"
QT_MOC_LITERAL(10, 137, 12), // "item_clicked"
QT_MOC_LITERAL(11, 150, 11), // "QModelIndex"
QT_MOC_LITERAL(12, 162, 13), // "add_param_row"
QT_MOC_LITERAL(13, 176, 13), // "del_param_row"
QT_MOC_LITERAL(14, 190, 8) // "reshenie"

    },
    "DiagnosticSetting\0commit_Data\0\0QWidget*\0"
    "add_new_system\0customMenuTree\0"
    "customMenuTableCheck\0delete_system\0"
    "editName_system\0delete_checking\0"
    "item_clicked\0QModelIndex\0add_param_row\0"
    "del_param_row\0reshenie"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DiagnosticSetting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   72,    2, 0x0a /* Public */,
       5,    1,   77,    2, 0x0a /* Public */,
       6,    1,   80,    2, 0x0a /* Public */,
       7,    0,   83,    2, 0x0a /* Public */,
       8,    0,   84,    2, 0x0a /* Public */,
       9,    0,   85,    2, 0x0a /* Public */,
      10,    1,   86,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DiagnosticSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DiagnosticSetting *_t = static_cast<DiagnosticSetting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->commit_Data((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 1: _t->add_new_system((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->customMenuTree((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->customMenuTableCheck((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->delete_system(); break;
        case 5: _t->editName_system(); break;
        case 6: _t->delete_checking(); break;
        case 7: _t->item_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->add_param_row(); break;
        case 9: _t->del_param_row(); break;
        case 10: _t->reshenie(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DiagnosticSetting::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DiagnosticSetting::commit_Data)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DiagnosticSetting::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DiagnosticSetting.data,
      qt_meta_data_DiagnosticSetting,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DiagnosticSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DiagnosticSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DiagnosticSetting.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DiagnosticSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void DiagnosticSetting::commit_Data(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
