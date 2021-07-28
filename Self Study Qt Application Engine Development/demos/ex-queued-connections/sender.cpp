/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "sender.h"
#include "data.h"

Sender::Sender(QWidget *parent) :
    QPushButton("Push me", parent)
{
    connect(this, &Sender::clicked, this, &Sender::sendData);

    m_integer = 42;
    setMinimumSize(200, 30);
}

void Sender::sendData()
{
    Data d(10, &m_integer, "hello");
    Q_EMIT data(d);
}

