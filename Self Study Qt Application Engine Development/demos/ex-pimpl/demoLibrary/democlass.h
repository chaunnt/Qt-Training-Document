/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef DEMOCLASS_H
#define DEMOCLASS_H

#include <QObject>
#include "demolibrary_global.h"
#include "democlass_p.h"

class DEMOLIBRARYSHARED_EXPORT DemoClass : public QObject
{
    Q_OBJECT
public:
    explicit DemoClass(QObject *parent = 0);

    int data() const;
    void setData(int newValue);

private:
    QScopedPointer<DemoClassPrivate> d;
};

#endif // DEMOCLASS_H
