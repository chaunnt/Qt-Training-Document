/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "MyTest.h"
#include "MyDataTest.h"

int main(int argc, char *argv[]) 
{ 
    QGuiApplication app(argc, argv);

    MyTest myTest;
    MyDataTest myDataTest;

    int result1 = QTest::qExec(&myTest, argc, argv); 
    int result2 = QTest::qExec(&myDataTest, argc, argv);

    return result1 + result2;
}

