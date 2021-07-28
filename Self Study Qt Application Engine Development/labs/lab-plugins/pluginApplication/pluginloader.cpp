/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QPluginLoader>
#include "pluginloader.h"

PluginLoader::PluginLoader(QObject *parent) : QObject(parent)
{
}

QString PluginLoader::loadPlugin1() const
{
    // Hint: you can use statements like #ifdef QT_DEBUG and
    // #ifdef Q_OS_WIN to determine at compile time what the
    // actual plugin name will be (in Windows builds the DLL's
    // version number and 'd' for debug will be added to the
    // library name, when applicable).
    // Here, for simplicity, we assume this is a Windows debug
    // build and the VERSION of the plug-in is defined to be 5.x.

    // The path is relative to the folder where Plugins.exe is, i.e.
    // the application's debug folder.
    QString pluginFile("");
    return loadPlugin(pluginFile);
}

QString PluginLoader::loadPlugin2() const
{
    QString pluginFile("");
    return loadPlugin(pluginFile);
}

QString PluginLoader::loadPlugin(const QString &pluginName) const
{
    return "Not implemented yet";
}
