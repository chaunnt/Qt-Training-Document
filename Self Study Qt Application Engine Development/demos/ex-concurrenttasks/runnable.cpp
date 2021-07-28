/*************************************************************************
 *
 * Copyright (c) 2016 Qt Group Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QMetaObject>
#include <QThread>
#include "runnable.h"

Runnable::Runnable(const QString &name, QObject *observer)
    : m_observer(observer),
      m_name(name)
{
}

Runnable::~Runnable()
{
}

void Runnable::run()
{
    QThread::sleep(2);
    QMetaObject::invokeMethod(m_observer, "taskFinished", Qt::QueuedConnection, Q_ARG(QString, m_name));
}

