/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtCore>

#define Container QHash
#define QtIterator QHashIterator
#define QtMutableIterator QMutableHashIterator

bool operator<(const QPoint &p1, const QPoint &p2)
{
    return (p1.x() < p2.x() ||
            (p1.x() == p2.x() && p1.y() < p2.y()));
}

uint qHash(const QPoint &p)
{
    return qHash(p.x()) ^ qHash(p.y());
}

int main(int, char *[])
{
    Container<QPoint, QString> container;

    // Fill in the container
    QString item("Item ");
    for (auto x = 0; x < 100; ++x) {
        for (auto y = 0; y < 100; ++y) {
            container.insert(QPoint(x, y), item + QString::number(100 * x + y));
        }
    }
    // Qt iterator
    {
        QtIterator<QPoint, QString> iterator(container);
        while (iterator.hasNext()) {
            qDebug() << iterator.next().value();
        }
    }

    // STL const iterator
    {
        Container<QPoint, QString>::const_iterator iterator = container.cbegin();
        while (iterator != container.cend()) {
            qDebug() << *iterator++;
        }
    }

    // Mutable iterator - Set the value of every fifth element to metI n
    {
        QtMutableIterator<QPoint, QString> mutableIterator(container);
        auto count(1);
        while (mutableIterator.hasNext()) {
            mutableIterator.next();
            if ((count++ % 5) == 0) {
                mutableIterator.setValue("metI " + QString::number(count - 2));
            }
        }
    }

    // STL non-const iterator
    {
        Container<QPoint, QString>::iterator mutableIterator = container.begin();
        auto count(1);
        while (mutableIterator != container.end()) {
            if ((count++ % 5) == 0) {
                *mutableIterator = QString("metI " + QString::number(count - 2));
            }
            mutableIterator++;
        }
    }

    // Q_FOREACH
    Q_FOREACH(const QString &value, container) {
        qDebug() << value;
    }

    // Range-based for loop
    for (const QString &value : container) {
        qDebug() << value;
    }
}
