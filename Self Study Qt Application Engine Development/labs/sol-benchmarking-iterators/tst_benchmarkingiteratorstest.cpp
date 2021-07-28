/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QString>
#include <QtTest>

#define Container QMap
#define QtIterator QMapIterator
#define QtMutableIterator QMutableMapIterator

bool operator<(const QPoint &p1, const QPoint &p2)
{
    return (p1.x() < p2.x() ||
            (p1.x() == p2.x() && p1.y() < p2.y()));
}

uint qHash(const QPoint &p)
{
    return qHash(p.x()) ^ qHash(p.y());
}

Container<QPoint, QString> container;
QString dummyString;

class benchmarkingIteratorsTest : public QObject
{
    Q_OBJECT

public:
    benchmarkingIteratorsTest();

private Q_SLOTS:
    void initTestCase();
    void javaStyleIterator();
    void stlStyleIterator();
    void javaStyleMutableIterator();
    void stlStyleNonConstIterator();
    void qForeach();
    void rangeBasedLoop();
};

benchmarkingIteratorsTest::benchmarkingIteratorsTest()
{
}

void benchmarkingIteratorsTest::initTestCase()
{
    // Fill in the container
    QString item("Item ");
    for (auto x = 0; x < 100; ++x) {
        for (auto y = 0; y < 100; ++y) {
            container.insert(QPoint(x, y), item + QString::number(100 * x + y));
        }
    }
}

void benchmarkingIteratorsTest::javaStyleIterator()
{
    QtIterator<QPoint, QString> iterator(container);
    QBENCHMARK {
        iterator.toFront();
        while (iterator.hasNext()) {
            dummyString = iterator.next().value();
        }
    }
}

void benchmarkingIteratorsTest::stlStyleIterator()
{
    Container<QPoint, QString>::const_iterator iterator;
    QBENCHMARK {
        iterator = container.cbegin();
        while (iterator != container.cend()) {
            dummyString = *iterator++;
        }
    }
}

void benchmarkingIteratorsTest::javaStyleMutableIterator()
{
    QtMutableIterator<QPoint, QString> mutableIterator(container);
    auto count(1);
    QBENCHMARK {
        mutableIterator.toFront();
        count = 1;
        while (mutableIterator.hasNext()) {
            mutableIterator.next();
            if ((count++ % 5) == 0) {
                mutableIterator.setValue("metI " + QString::number(count - 2));
            }
        }
    }
}

void benchmarkingIteratorsTest::stlStyleNonConstIterator()
{
    Container<QPoint, QString>::iterator mutableIterator;
    auto count(1);
    QBENCHMARK {
        mutableIterator = container.begin();
        count = 1;
        while (mutableIterator != container.end()) {
            if ((count++ % 5) == 0) {
                *mutableIterator = QString("metI " + QString::number(count - 2));
            }
            mutableIterator++;
        }
    }
}

void benchmarkingIteratorsTest::qForeach()
{
    QBENCHMARK {
        Q_FOREACH(const QString &value, container) {
            dummyString = value;
        }
    }
}

void benchmarkingIteratorsTest::rangeBasedLoop()
{
    QBENCHMARK {
        for (const QString &value : container) {
            dummyString = value;
        }
    }
}

QTEST_APPLESS_MAIN(benchmarkingIteratorsTest)

#include "tst_benchmarkingiteratorstest.moc"
