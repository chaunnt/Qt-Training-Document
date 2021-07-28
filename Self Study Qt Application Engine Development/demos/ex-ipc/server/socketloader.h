/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SOCKETLOADER_H
#define SOCKETLOADER_H

#include <QObject>
#include <QTcpServer>

QT_FORWARD_DECLARE_CLASS(QTcpSocket)
QT_FORWARD_DECLARE_CLASS(QLabel)

class SocketLoader : public QObject
{
    Q_OBJECT
public:
    explicit SocketLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent = 0);
    ~SocketLoader();

protected Q_SLOTS:
    void slotConnection();
    void readImage();

private:
    QLabel *m_imageLabel;
    QLabel *m_textLabel;
    QTcpServer m_server;
    QTcpSocket *m_socket;
};

#endif // SOCKETLOADER_H
