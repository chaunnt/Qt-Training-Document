/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SENDER_H
#define SENDER_H

#include <QPushButton>

class Data;

class Sender : public QPushButton
{
    Q_OBJECT
public:
    explicit Sender(QWidget *parent = Q_NULLPTR);
    
signals:
    void data(const Data &);

protected Q_SLOTS:
    void sendData();

private:
    int m_integer;
};

#endif // SENDER_H
