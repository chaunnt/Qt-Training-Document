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


class MyTest : public QObject
{
	Q_OBJECT

	void initTestCase();
	void cleanupTestCase();
private slots:
	void init(); // needs to be under private slots
	void cleanup(); // needs to be under private slots
	void testcase();
	void anotherTestcase();
};

#endif

