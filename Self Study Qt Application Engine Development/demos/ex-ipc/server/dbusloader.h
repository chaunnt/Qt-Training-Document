/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef DBUSLOADER_H
#define DBUSLOADER_H

#include <QObject>
#include <QDBusConnection>
#include "ipcdemointerface_adaptor.h"

QT_FORWARD_DECLARE_CLASS(QLabel)

class DBusLoader : public QObject
{
    Q_OBJECT
public:
    explicit DBusLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent = 0);

public Q_SLOTS:
    void loadImage(const QDBusVariant &in0);

private:
    QLabel *m_imageLabel;
    QLabel *m_textLabel;
    IpcDemoInterfaceAdaptor *m_adaptor;
    QDBusConnection m_connection;
};

#endif // DBUSLOADER_H
