/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QDebug>
#include <QThread>

#include "receiver.h"
#include "data.h"

Receiver::Receiver(QObject *parent) :
    QObject(parent),
    m_counter(0)
{
}

void Receiver::data(const Data &data)
{
    qDebug() << "Receiver says: " << data.m_integer << *data.m_pointer << data.m_string;
    // Let's finish the thread
    if (++m_counter > 4) {
        qDebug() << "Thread going to be finished";
        thread()->quit();
    }
}

