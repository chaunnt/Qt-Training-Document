/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Data;

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = Q_NULLPTR);
    
public Q_SLOTS:
    void data(const Data &data);

private:
    int m_counter;
};

#endif // RECEIVER_H
