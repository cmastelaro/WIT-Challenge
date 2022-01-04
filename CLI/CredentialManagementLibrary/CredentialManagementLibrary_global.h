#ifndef CREDENTIALMANAGEMENTLIBRARY_GLOBAL_H
#define CREDENTIALMANAGEMENTLIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>

#include <memory>
#include <string>
#include <map>
#include <future>
#include <mutex>
#include <iostream>

#if defined(CREDENTIALMANAGEMENTLIBRARY_LIBRARY)
#  define CREDENTIALMANAGEMENTLIBRARY_EXPORT Q_DECL_EXPORT
#else
#  define CREDENTIALMANAGEMENTLIBRARY_EXPORT Q_DECL_IMPORT
#endif

#endif // CREDENTIALMANAGEMENTLIBRARY_GLOBAL_H
