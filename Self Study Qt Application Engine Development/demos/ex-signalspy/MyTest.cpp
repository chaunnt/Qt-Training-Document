/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "MyTest.h"

#include <QSignalSpy>


MyTest::MyTest()
{
}

void MyTest::testStart()
{
	MyTimer timer;
    QSignalSpy spy(&timer, &MyTimer::ownTimerTimeout);

    // precondition
    QVERIFY(spy.isValid());
    QVERIFY(spy.isEmpty());

	const unsigned long int Period = 2;
    timer.ownStartTimer(Period);

    QVERIFY(spy.wait(Period * 10));

    // postcondition
    const int result = spy.count();
    QCOMPARE(result, 1);
    QList<QVariant> theCall = spy.takeFirst();
    QVERIFY(theCall.isEmpty());
}

void MyTest::testStop()
{
	MyTimer timer;
    QSignalSpy spy(&timer, &MyTimer::ownTimerTimeout);

    // precondition
    QVERIFY(spy.isValid());
    QVERIFY(spy.isEmpty());

	const unsigned long int Period = 2;
    timer.ownStartTimer(Period);
	timer.ownStopTimer();

    QVERIFY(!spy.wait(Period * 10));

    // postcondition
    const int result = spy.count();
    QCOMPARE(result, 0);
}

