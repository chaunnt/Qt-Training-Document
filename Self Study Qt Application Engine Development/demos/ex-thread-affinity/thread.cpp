/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QDebug>
#include "thread.h"
#include "object.h"

Thread::Thread(QObject *parent)
    : QThread(parent)
{
    setObjectName("Child thread");
    qDebug() << "Current thread" << QThread::currentThread();

    // Timer thread is changed to this thread
    // Comment out the line below to see, if the program works
    m_timer.moveToThread(this);
}

Thread::~Thread()
{
}

void Thread::run()
{
    // m_timer object belongs to this thread
    m_timer.setInterval(2000);
    m_timer.start();

    Object object;
    connect(&m_timer, &QTimer::timeout, &object, &Object::timerSlot);

    qDebug() << "Current thread" << QThread::currentThread();

    m_timer.stop();
    qDebug() << "Timer running" << m_timer.isActive();
    m_timer.start();
    qDebug() << "Timer running" << m_timer.isActive();

    QThread::run();
}

