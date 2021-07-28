/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>

class Object : public QObject
{
    Q_OBJECT
public:
    explicit Object(QObject *parent = Q_NULLPTR);
    ~Object();

public Q_SLOTS:
    void timerSlot();
};

#endif // OBJECT_H
