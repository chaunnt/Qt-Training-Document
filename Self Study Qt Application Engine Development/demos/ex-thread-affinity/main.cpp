/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QThread>
#include <QPushButton>
#include "thread.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    QPushButton button("Quit");
    QObject::connect(&button, &QPushButton::clicked, &application, &QCoreApplication::quit);

    QThread::currentThread()->setObjectName("GUI Thread");

    Thread thread;
    QObject::connect(&button, &QPushButton::clicked, &thread, &QThread::quit);
    thread.start();

    button.show();
    return application.exec();
}
