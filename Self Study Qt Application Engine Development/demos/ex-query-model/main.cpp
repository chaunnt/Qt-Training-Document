/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QGuiApplication>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtDebug>

#include "tabletolistmodel.h"

void reportError(const QString &msg, const QSqlError &err)
{
    qDebug() <<
                QString("%1\nDriver Message: %2\nDatabase Message %3")
                .arg(msg)
                .arg(err.driverText())
                .arg(err.databaseText());
    qApp->exit(-1);
}



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../databases/bookstore.db");
    if (!db.open())
        reportError(QString("Error When opening database. The database is expected to be located in %1").arg(db.databaseName()), db.lastError());

    QSqlQueryModel model;
    model.setQuery("SELECT a.firstname, a.surname, b.title, b.price, b.notes FROM author a, book b WHERE a.authorid = b.authorid");

    TableToListModel proxy;
    proxy.setTableModel(&model);

    proxy.addColumnMapping(0, "firstName");
    proxy.addColumnMapping(1, "lastName");
    proxy.addColumnMapping(2, "title");
    proxy.addColumnMapping(3, "price");
    proxy.addColumnMapping(4, "notes");

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("_model", &proxy);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
