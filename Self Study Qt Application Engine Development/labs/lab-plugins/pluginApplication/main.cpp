/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QGuiApplication>
#include <QLibraryInfo>
#include <QQmlApplicationEngine>
#include "pluginloader.h"

static QObject *createPluginLoader(QQmlEngine *, QJSEngine *)
{
    PluginLoader *pluginLoader = new PluginLoader();
    return pluginLoader;
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterSingletonType<PluginLoader>("io.qt.pluginobject", 1, 0, "PluginLoader", createPluginLoader);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
