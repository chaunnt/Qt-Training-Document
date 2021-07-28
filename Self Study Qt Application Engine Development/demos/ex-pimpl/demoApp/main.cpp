/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QDebug>
#include <democlass.h>

int main(int, char *[])
{
    DemoClass demoClass;
    demoClass.setData(2016);
    qDebug() << demoClass.data();

    return EXIT_SUCCESS;
}
