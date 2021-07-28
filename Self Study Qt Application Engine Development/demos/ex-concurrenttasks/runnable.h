/*************************************************************************
 *
 * Copyright (c) 2016 Qt Group Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <QRunnable>
#include <QString>
class QObject;

class Runnable : public QRunnable
{
public:
    Runnable(const QString& name, QObject *observer);
    ~Runnable();

protected:
    void run();

private:
    QObject *m_observer;
    QString m_name;
};

#endif // RUNNABLE_H
