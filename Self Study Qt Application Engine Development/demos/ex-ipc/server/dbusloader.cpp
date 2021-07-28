/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "dbusloader.h"

#include <QLabel>
#include <QImage>

DBusLoader::DBusLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent) :
    QObject(parent),
    m_imageLabel(imageLabel),
    m_textLabel(textLabel),
    m_connection("Random")
{
    m_adaptor = new IpcDemoInterfaceAdaptor(this);
    m_connection = QDBusConnection::sessionBus();
    m_connection.registerObject("/IpcDemo", this);
    m_connection.registerService("com.theQtCompany.ImageLoader");
}

void DBusLoader::loadImage(const QDBusVariant &in0)
{
    QImage image;
    QByteArray array(in0.variant().value<QByteArray>());
    QBuffer buffer(&array);
    buffer.open(QBuffer::ReadOnly);
    QDataStream in(&buffer);
    in >> image;

    m_imageLabel->setPixmap(QPixmap::fromImage(image));
    m_textLabel->setText(tr("New image loaded using D-BUS."));
}


