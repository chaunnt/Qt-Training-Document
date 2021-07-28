/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "democlass.h"
#include <QDebug>

DemoClassPrivate::DemoClassPrivate(DemoClass *demoClass) :
    m_intMember(42),
    q(demoClass)
{
}

DemoClassPrivate::~DemoClassPrivate()
{
    qDebug() << "Private class destructed";
}

DemoClass::DemoClass(QObject *parent) :
    QObject(parent),
    d(new DemoClassPrivate(this))
{
}

int DemoClass::data() const
{
    return d->m_intMember;
}

void DemoClass::setData(int newValue)
{
    d->m_intMember = newValue;
}
