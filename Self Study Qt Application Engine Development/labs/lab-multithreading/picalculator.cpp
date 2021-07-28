/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "picalculator.h"
#include <float.h>
#include <QtMath>
#include <QTimer>
#include <QThread>
#include <QProgressBar>
#include <QAbstractEventDispatcher>
#include <QLabel>

PiCalculator::PiCalculator(QObject *observer, QLabel *label, QObject *parent) :
    QObject(parent),
    m_observer(observer),
    m_label(label),
    m_pi(1.0)
{
}

PiCalculator::~PiCalculator()
{
}

void PiCalculator::run()
{
    qreal k(3.0);
    bool minus(true);

    Q_FOREVER {
        if (k >= (DBL_MAX - 2)) {
            // TODO: Exit from the thread
        }

        m_pi += minus ? -1/k : 1/k;
        k += 2;
        minus = minus ? false : true;
        // Pi equals to m_pi * 4;

    }
}


