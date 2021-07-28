/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "MyTest.h"

int main(int argc, char *argv[]) 
{ 
    QGuiApplication app(argc, argv);

    MyTest myTest;

    int result = QTest::qExec(&myTest, argc, argv); 

    return result;
}

