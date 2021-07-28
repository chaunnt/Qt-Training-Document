/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "socketloader.h"
#include <QTcpSocket>
#include <QDataStream>
#include <QImage>
#include <QLabel>

SocketLoader::SocketLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent) :
    QObject(parent),
    m_imageLabel(imageLabel),
    m_textLabel(textLabel)
{
    m_server.listen(QHostAddress::LocalHost, 4242);
    connect(&m_server, &QTcpServer::newConnection, this, &SocketLoader::slotConnection);

}

SocketLoader::~SocketLoader()
{
    if (m_socket) {
        m_socket->close();
        m_socket->deleteLater();
    }
    m_server.close();
}

void SocketLoader::slotConnection()
{
    m_socket = m_server.nextPendingConnection();
    connect(m_socket, &QTcpSocket::readyRead, this, &SocketLoader::readImage);
}

void SocketLoader::readImage()
{
    QDataStream in(m_socket);
    QImage image;
    in >> image;

    m_imageLabel->setPixmap(QPixmap::fromImage(image));
    m_textLabel->setText(tr("New image loaded from a socket."));
}

