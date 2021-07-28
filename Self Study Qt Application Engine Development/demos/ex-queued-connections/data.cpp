/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QString>
#include "data.h"

Data::Data() :
    m_integer(-1), m_pointer(0), m_string()
{
}

Data::Data(int integerArg, int *pointerArg, const QString &stringArg) :
    m_integer(integerArg), m_pointer(pointerArg), m_string(stringArg)
{
}
