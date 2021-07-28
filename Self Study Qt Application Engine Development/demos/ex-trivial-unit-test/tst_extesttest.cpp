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

class ExTestTest : public QObject
{
    Q_OBJECT

public:
    ExTestTest();

private:  // These two functions may be private slots as well
    // Called before any test has been executed
    void initTestCase();
    // Caleld after all the test have been executed
    void cleanupTestCase();

private Q_SLOTS: // Test case functions must be private slots
    void testCase1();
    void testCase2();

    // Called before each test case
    void init();
    // Called after each test case
    void cleanup();
};

ExTestTest::ExTestTest()
{
}

void ExTestTest::initTestCase()
{
    qDebug() << "Init test case";
}

void ExTestTest::cleanupTestCase()
{
    qDebug() << "Cleanup test case";
}

void ExTestTest::init()
{
    qDebug() << "Init";
}

void ExTestTest::cleanup()
{
    qDebug() << "Cleanup";
}

void ExTestTest::testCase1()
{
    qDebug() << "Test case";
    QVERIFY2(true, "Failure");
}

void ExTestTest::testCase2()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(ExTestTest)

#include "tst_extesttest.moc"
