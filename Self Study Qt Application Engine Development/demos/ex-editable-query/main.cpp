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
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
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


class EditableQueryModel :public QSqlQueryModel
{
public:
    EditableQueryModel()
    {
        refresh();
        setHeaderData( 0, Qt::Horizontal, "First Name" );
        setHeaderData( 1, Qt::Horizontal, "Surname" );
        setHeaderData( 2, Qt::Horizontal, "Title" );
        setHeaderData( 3, Qt::Horizontal, "Price" );
        setHeaderData( 4, Qt::Horizontal, "Notes" );
    }

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE
    {
        Qt::ItemFlags flags = QSqlQueryModel::flags(index);
        if (index.column() >= 2)
            flags |= Qt::ItemIsEditable;
        return flags;
    }

    bool setData(const QModelIndex &index, const QVariant& value, int /* role */)
    {
        Q_ASSERT(index.column()>= 2);

        QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 5);
        int id = data(primaryKeyIndex).toInt();

        QString field;
        switch (index.column()) {
        case 2: field = "title"; break;
        case 3: field = "price"; break;
        case 4: field = "notes"; break;
        }

        QSqlQuery query;
        query.prepare( QString("update book set %1 = ? where authorid  = ?").arg(field));
        query.addBindValue(value);
        query.addBindValue(id);
        bool ok = query.exec();
        if (!ok)
            reportError("Error running update query", query.lastError());
        refresh();
        return ok;
    }

    void refresh()
    {
        setQuery("SELECT a.firstname, a.surname, b.title, b.price, b.notes, b.authorid  FROM author a, book b WHERE a.authorid = b.authorid");
    }
};

int main(int argc, char *argv[]) {
    QGuiApplication app( argc, argv);

    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../databases/bookstore.db");
    if (!db.open())
        reportError(QString("Error When opening database. The database is expected to be located in %1").arg(db.databaseName()), db.lastError());

    EditableQueryModel model;

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
