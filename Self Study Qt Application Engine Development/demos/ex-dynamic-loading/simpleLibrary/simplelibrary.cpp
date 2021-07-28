/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "simplelibrary_global.h"

extern "C" SIMPLELIBRARYSHARED_EXPORT double pow(int a, int b)
{
    double result(1.0);

    if (b > 0) {
        for (int i = 0; i < b; ++i)
            result *= a;
    }
    if (b < 0) {
        for (int i = 0; i < -b; ++i)
            result /= a;
    }

    return result;
}
