/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef PICALCULATOR_H
#define PICALCULATOR_H

#include <QObject>

QT_FORWARD_DECLARE_CLASS(QLabel)

const quint32 TIMER_DURATION = 30000;

class PiCalculator : public QObject
{
    Q_OBJECT
public:
    explicit PiCalculator(QObject *observer, QLabel *label, QObject *parent = Q_NULLPTR);
    ~PiCalculator();

public Q_SLOTS:
    void run();

private:
    QObject *m_observer;
    QLabel *m_label;
    qreal m_pi;
};

#endif // PICALCULATOR_H
