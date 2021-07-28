/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QTimer>

class Thread : public QThread
{
public:
    Thread(QObject *parent = 0);
    ~Thread();

protected:
    void run();

private:
    QTimer m_timer;
};

#endif // THREAD_H
