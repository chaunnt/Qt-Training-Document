/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MYTIMER_H
#define MYTIMER_H

#include <QObject>


class MyTimer : public QObject
{
	Q_OBJECT

public:
	MyTimer(QObject* parent = 0);
	virtual ~MyTimer() {}

	void ownStartTimer(unsigned long delay);
	void ownStopTimer();

signals:
	void ownTimerTimeout();

protected:
	void timerEvent(QTimerEvent *event);
	
private:
	int _timerId;
};

#endif

