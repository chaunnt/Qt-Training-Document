/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "MyDataTest.h"

struct MyException {};


void MyDataTest::init()
{
}

void MyDataTest::cleanup()
{
}

void MyDataTest::myTestCase_data()
{
     QTest::addColumn<int>("integer_input");
     QTest::addColumn<QString>("result");

     QTest::newRow("1st row") << 1 << "one";
     QTest::newRow("2nd row") << 2 << "two";
     QTest::newRow("3rd") << 3 << "three";
}

QString myFunction( int index )
{
	printf("%d\n", index);
	switch( index )
	{
        case 1: return QString("one");
        case 2: return QString("two");
        case 3: return QString("three");
	}

	return QString( "unknown" );
}

void MyDataTest::myTestCase()
{
	QFETCH(int, integer_input);
	QFETCH(QString, result);
    QWARN("myTestCase()");
	QCOMPARE(myFunction( integer_input ), result);
}

