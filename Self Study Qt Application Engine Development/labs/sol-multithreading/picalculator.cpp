/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "picalculator.h"
#include <float.h>
#include <QtMath>
#include <QTimer>
#include <QThread>
#include <QProgressBar>
#include <QAbstractEventDispatcher>
#include <QLabel>

PiCalculator::PiCalculator(QObject *observer, QLabel *label, QObject *parent) :
    QObject(parent),
    m_observer(observer),
    m_timer(new QTimer(this)),
    m_label(label),
    m_pi(1.0)
{
    connect(m_timer, &QTimer::timeout, this, &PiCalculator::timerExpired);
}

PiCalculator::~PiCalculator()
{
}

void PiCalculator::run()
{
    m_timer->start(TIMER_DURATION);
    qreal k(3.0);
    bool minus(true);

    Q_FOREVER {
        if (thread()->isInterruptionRequested() || k >= (DBL_MAX - 2)) {
            thread()->quit();
            return;
        }

        m_pi += minus ? -1/k : 1/k;
        k += 2;
        minus = minus ? false : true;
        // qDebug() << "Pi =" << m_pi * 4;
        if (qFloor(k) % 999 == 0) {
            QMetaObject::invokeMethod(m_observer, "setValue", Qt::QueuedConnection, Q_ARG(int, ((qreal)TIMER_DURATION - m_timer->remainingTime()) / (qreal)TIMER_DURATION * 100));
            QMetaObject::invokeMethod(m_label, "setText", Qt::QueuedConnection, Q_ARG(QString, QString("Pi = %1").arg(m_pi * 4.0, 0, 'g', 20)));
            thread()->eventDispatcher()->processEvents(QEventLoop::AllEvents);
        }
    }
}

void PiCalculator::timerExpired()
{
    thread()->requestInterruption();
}

