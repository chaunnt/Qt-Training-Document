/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <QObject>
#include "plugininterface.h"

class PluginLoader : public QObject
{
    Q_OBJECT
public:
    explicit PluginLoader(QObject *parent = 0);

public Q_SLOTS:
    QString loadPlugin1() const;
    QString loadPlugin2() const;

protected:
    QString loadPlugin(const QString &pluginName) const;
};

#endif // PLUGINLOADER_H
