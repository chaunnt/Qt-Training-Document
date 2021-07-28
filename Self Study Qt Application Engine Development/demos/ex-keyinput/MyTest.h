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

class QLineEdit;

class MyTest : public QObject
{
	Q_OBJECT

    QLineEdit *_tested;

private slots:
	void init(); 
	void cleanup(); 
	void testcase();
};

#endif

