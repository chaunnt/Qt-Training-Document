/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QDebug>
#include "object.h"

Object::Object(QObject *parent) : QObject(parent)
{

}

Object::~Object()
{
}

void Object::timerSlot()
{
    qDebug() << "Timer expried.";
}

