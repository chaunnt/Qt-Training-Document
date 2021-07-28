/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QMetaType>
#include <QThread>
#include "data.h"
#include "sender.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qMetaTypeId<Data>();

    Sender sender;
    Receiver receiver;
    QThread thread;
    thread.connect(&thread, &QThread::finished, &app, &QApplication::quit);

    QObject::connect(&sender, &Sender::data, &receiver, &Receiver::data);
    receiver.moveToThread(&thread);

    thread.start();

    sender.show();
    return app.exec();
}

