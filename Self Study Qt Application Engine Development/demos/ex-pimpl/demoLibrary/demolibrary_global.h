/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef DEMOLIBRARY_GLOBAL_H
#define DEMOLIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DEMOLIBRARY_LIBRARY)
#  define DEMOLIBRARYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DEMOLIBRARYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DEMOLIBRARY_GLOBAL_H
