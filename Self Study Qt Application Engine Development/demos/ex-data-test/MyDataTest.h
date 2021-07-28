/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MYDATATEST_H
#define MYDATATEST_H

#include <QtTest/QTest>


class MyDataTest : public QObject
{
	Q_OBJECT

private slots:
	void init();
	void cleanup();
	void myTestCase_data();
	void myTestCase();
};

#endif

