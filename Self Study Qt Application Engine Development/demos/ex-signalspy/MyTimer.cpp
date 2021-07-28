/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "MyTimer.h"

#include <QTimerEvent>


MyTimer::MyTimer(QObject* parent)
	: QObject(parent), _timerId(0)
{
}

void MyTimer::ownStartTimer(unsigned long delay)
{
	if (!_timerId)
	{
		_timerId = startTimer(delay);
	}
}

void MyTimer::ownStopTimer()
{
	if (_timerId)
	{
		killTimer(_timerId);
		_timerId = 0;
	}
}

void MyTimer::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == _timerId)
	{
		ownStopTimer();
		emit ownTimerTimeout();
	}
}


