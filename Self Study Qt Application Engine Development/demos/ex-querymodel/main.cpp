/*************************************************************************
 *
 * Copyright (c) 2016 Qt Group Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtQuick>
#include <QtSql>

#include "tabletolistmodel.h"

void reportError( const QString& msg, const QSqlError& err )
{
    qDebug() <<
        QString("%1\nDriver Message: %2\nDatabase Message %3")
        .arg(msg)
        .arg(err.driverText())
        .arg(err.databaseText());
    qApp->exit(-1);
}



int main( int argc, char** argv )
{
    QGuiApplication app( argc, argv );

    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName("../databases/bookstore.db");
    if ( !db.open() )
        reportError( "Error When opening database", db.lastError() );

    QSqlQueryModel* model = new QSqlQueryModel;
    model->setQuery( "SELECT a.firstname, a.surname, b.title, b.price, b.notes FROM author a, book b WHERE a.authorid = b.authorid" );

    TableToListModel proxy;
    proxy.setTableModel(model);

    proxy.addColumnMapping(0, "firstName");
    proxy.addColumnMapping(1, "lastName");
    proxy.addColumnMapping(2, "title");
    proxy.addColumnMapping(3, "price");
    proxy.addColumnMapping(4, "notes");

    QQuickView view;

    view.engine()->rootContext()->setContextProperty("_model", &proxy);
    view.setSource(QUrl("qrc:/main.qml"));

    view.show();

    return app.exec();
}
