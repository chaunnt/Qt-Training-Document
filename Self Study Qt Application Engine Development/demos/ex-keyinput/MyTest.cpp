/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QLineEdit>
#include "MyTest.h"


void MyTest::init()
{
	_tested = new QLineEdit("default");
}

void MyTest::cleanup()
{
	delete _tested;
}

void MyTest::testcase()
{
    QString defaultValue("default");
    QString input("abc");
    QTest::keyClicks(_tested, input);
    QString result(_tested->text());
    QString expected(defaultValue + input);
    QCOMPARE(result, expected);
}

