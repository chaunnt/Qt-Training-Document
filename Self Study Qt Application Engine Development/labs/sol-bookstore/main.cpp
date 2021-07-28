/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "bookstore.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    BookStore bookStore;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_bookStore", &bookStore);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
