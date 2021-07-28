/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SIMPLELIBRARY_GLOBAL_H
#define SIMPLELIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIMPLELIBRARY_LIBRARY)
#  define SIMPLELIBRARYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SIMPLELIBRARYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DEMOLIBRARY_GLOBAL_H
