/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "fileloader.h"
#include "sharedmemoryloader.h"
#ifdef Q_OS_UNIX
#include "dbusloader.h"
#endif
#include "socketloader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget container;
    container.setGeometry(100, 100, 400, 300);
    QVBoxLayout *layout = new QVBoxLayout(&container);

    QLabel *textLabel = new QLabel;
    textLabel->setText(QObject::tr("No image received"));
    QLabel *imageLabel = new QLabel;
    imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(textLabel);
    layout->addWidget(imageLabel);
    QPushButton *loadButton = new QPushButton(QObject::tr("Load from shared memory"));
    layout->addWidget(loadButton);
    container.show();

    SharedMemoryLoader sharedMemoryLoader(imageLabel, textLabel);
    QObject::connect(loadButton, &QPushButton::clicked, &sharedMemoryLoader, &SharedMemoryLoader::loadFromSharedMemory);

    SocketLoader socketLoader(imageLabel, textLabel);

    FileLoader fileLoader(imageLabel, textLabel);
#ifdef Q_OS_UNIX
    DBusLoader dbusLoader(imageLabel, textLabel);
#endif
    return a.exec();
}
