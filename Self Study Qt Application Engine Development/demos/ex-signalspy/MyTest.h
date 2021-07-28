/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MYTEST_H
#define MYTEST_H

#include <QtTest/QTest>
#include "MyTimer.h"


class MyTest : public QObject
{
	Q_OBJECT

public:
	MyTest();

private slots:
	void testStart();
	void testStop();
};

#endif

