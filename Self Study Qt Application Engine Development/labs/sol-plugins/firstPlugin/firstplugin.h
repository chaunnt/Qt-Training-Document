/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef FIRSTPLUGIN_H_
#define FIRSTPLUGIN_H_

#include "plugininterface.h"

class FirstPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "io.qt.SimpleInterface" FILE "dummyPlugin.json")
    Q_INTERFACES(PluginInterface)

public:
    FirstPlugin();
    QString getTheString(void) const;
};

#endif
