/****************************************************************************
** Resource object code
**
** Created: Wed Apr 13 13:21:53 2011
**      by: The Resource Compiler for Qt version 4.7.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtCore/qglobal.h>

static const unsigned char qt_resource_data[] = {
  // /home/kelvin/Desktop/td/src/client/client.qss
  0x0,0x0,0x0,0xe2,
  0x51,
  0x4d,0x61,0x69,0x6e,0x57,0x69,0x6e,0x64,0x6f,0x77,0x20,0x7b,0xa,0x20,0x20,0x20,
  0x20,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x69,0x6d,0x61,0x67,
  0x65,0x3a,0x20,0x75,0x72,0x6c,0x28,0x22,0x2e,0x2f,0x69,0x6d,0x67,0x2f,0x6c,0x6f,
  0x62,0x62,0x79,0x42,0x67,0x2e,0x70,0x6e,0x67,0x22,0x29,0x3b,0xa,0x7d,0xa,0xa,
  0x51,0x46,0x72,0x61,0x6d,0x65,0x23,0x62,0x67,0x46,0x72,0x61,0x6d,0x65,0x20,0x7b,
  0xa,0x20,0x20,0x20,0x20,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,
  0x69,0x6d,0x61,0x67,0x65,0x3a,0x20,0x75,0x72,0x6c,0x28,0x22,0x2e,0x2f,0x69,0x6d,
  0x67,0x2f,0x6d,0x61,0x70,0x4c,0x69,0x73,0x74,0x73,0x42,0x67,0x2e,0x70,0x6e,0x67,
  0x22,0x29,0x3b,0xa,0x20,0x20,0x20,0x20,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x20,
  0x6e,0x6f,0x6e,0x65,0x3b,0xa,0x7d,0xa,0xa,0x51,0x4c,0x69,0x73,0x74,0x57,0x69,
  0x64,0x67,0x65,0x74,0x23,0x6d,0x61,0x70,0x73,0x4c,0x69,0x73,0x74,0x20,0x7b,0xa,
  0x20,0x20,0x20,0x20,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x3a,0x20,
  0x74,0x72,0x61,0x6e,0x73,0x70,0x61,0x72,0x65,0x6e,0x74,0x3b,0xa,0x20,0x20,0x20,
  0x20,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x20,0x6e,0x6f,0x6e,0x65,0x3b,0xa,0x7d,
  0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // file
  0x0,0x4,
  0x0,0x6,0xd0,0x25,
  0x0,0x66,
  0x0,0x69,0x0,0x6c,0x0,0x65,
    // client.qss
  0x0,0xa,
  0xc,0x5a,0x1d,0x43,
  0x0,0x63,
  0x0,0x6c,0x0,0x69,0x0,0x65,0x0,0x6e,0x0,0x74,0x0,0x2e,0x0,0x71,0x0,0x73,0x0,0x73,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/file
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
  // :/file/client.qss
  0x0,0x0,0x0,0xe,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

QT_BEGIN_NAMESPACE

extern Q_CORE_EXPORT bool qRegisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

extern Q_CORE_EXPORT bool qUnregisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

QT_END_NAMESPACE


int QT_MANGLE_NAMESPACE(qInitResources_client)()
{
    QT_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_client))

int QT_MANGLE_NAMESPACE(qCleanupResources_client)()
{
    QT_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_DESTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qCleanupResources_client))

