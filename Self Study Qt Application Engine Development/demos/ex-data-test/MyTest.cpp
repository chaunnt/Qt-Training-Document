/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "MyTest.h"

struct MyException {};


void MyTest::initTestCase()
{
    //QWARN("MyTest::initTestCase()");
	//throw new MyException;
}

void MyTest::cleanupTestCase()
{
    //QWARN("MyTest::cleanupTestCase()");
	//throw new MyException;
}

void MyTest::init()
{
    // QWARN("MyTest::init()");
}

void MyTest::cleanup()
{
    //QWARN("MyTest::cleanup()");
}

void MyTest::testcase()
{
    //QWARN("MyTest::testcase()");
	//throw new MyException;
}

void MyTest::anotherTestcase()
{
    //QWARN("MyTest::anotherTestcase()");
    QFAIL("Demo failure");
}


