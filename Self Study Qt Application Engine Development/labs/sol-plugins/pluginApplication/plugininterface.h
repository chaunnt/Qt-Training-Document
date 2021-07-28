/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QtPlugin>
#include <QtCore/QString>

class PluginInterface
{
public:
    virtual QString getTheString() const = 0;
};

Q_DECLARE_INTERFACE(PluginInterface, "io.qt.SimpleInterface")

#endif // PLUGININTERFACE_H
