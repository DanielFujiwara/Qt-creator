/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.13.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // F:/Git/qt/supermarket_casher/qt_stage1/data.qrc
  0x0,0x0,0x0,0x7b,
  0x3c,
  0x52,0x43,0x43,0x3e,0xd,0xa,0x20,0x20,0x20,0x20,0x3c,0x71,0x72,0x65,0x73,0x6f,
  0x75,0x72,0x63,0x65,0x20,0x70,0x72,0x65,0x66,0x69,0x78,0x3d,0x22,0x2f,0x22,0x3e,
  0xd,0xa,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x66,0x69,0x6c,0x65,0x3e,
  0x64,0x61,0x74,0x61,0x2e,0x71,0x72,0x63,0x3c,0x2f,0x66,0x69,0x6c,0x65,0x3e,0xd,
  0xa,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x66,0x69,0x6c,0x65,0x3e,0x75,
  0x73,0x65,0x72,0x64,0x61,0x74,0x61,0x3c,0x2f,0x66,0x69,0x6c,0x65,0x3e,0xd,0xa,
  0x20,0x20,0x20,0x20,0x3c,0x2f,0x71,0x72,0x65,0x73,0x6f,0x75,0x72,0x63,0x65,0x3e,
  0xd,0xa,0x3c,0x2f,0x52,0x43,0x43,0x3e,0xd,0xa,
    // F:/Git/qt/supermarket_casher/qt_stage1/userdata
  0x0,0x0,0x0,0x0,
  
  
};

static const unsigned char qt_resource_name[] = {
  // data.qrc
  0x0,0x8,
  0x8,0xa4,0x55,0xc3,
  0x0,0x64,
  0x0,0x61,0x0,0x74,0x0,0x61,0x0,0x2e,0x0,0x71,0x0,0x72,0x0,0x63,
    // userdata
  0x0,0x8,
  0x9,0xc8,0xa7,0x21,
  0x0,0x75,
  0x0,0x73,0x0,0x65,0x0,0x72,0x0,0x64,0x0,0x61,0x0,0x74,0x0,0x61,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/data.qrc
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x73,0x3b,0x78,0x9d,0x37,
  // :/userdata
  0x0,0x0,0x0,0x16,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x7f,
0x0,0x0,0x1,0x73,0x3b,0x6a,0xaf,0x3f,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_data)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_data)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_data)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_data)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_data)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_data)(); }
   } dummy;
}
