/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtDebug>

// For exposing database data to Qt Quick
class BookModel : public QStandardItemModel
{
public:
    enum Roles {
        TitleRole = Qt::UserRole + 1,
        AuthorRole,
        PriceRole,
        NotesRole
    };

    BookModel() : QStandardItemModel()
    {
        setSortRole(AuthorRole);
    }

    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE
    {
        QHash<int, QByteArray> mapping = QStandardItemModel::roleNames();

        mapping[TitleRole] = "title";
        mapping[AuthorRole] = "author";
        mapping[PriceRole] = "price";
        mapping[NotesRole] = "notes";

        return mapping;
    }

    void addBook(const QString &title, const QString &author, const QString &price, const QString &notes)
    {
        QStandardItem *item = new QStandardItem;
        item->setData(title, TitleRole);
        item->setData(author, AuthorRole);
        item->setData(price, PriceRole);
        item->setData(notes, NotesRole);

        appendRow(item);
    }
};

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
    if (!db.open()) {
        reportError(QString("Error When opening database. The database is expected to be located in %1").arg(db.databaseName()), db.lastError());
    }

    // Setup the data model
    BookModel model;

    // Query the database
    QSqlQuery authorQuery("SELECT authorid, firstname, surname FROM author");
    if (!authorQuery.isActive())
        reportError("Eror when running Query", authorQuery.lastError());

    while (authorQuery.next()) {
        const QString author = authorQuery.value(1).toString() + " " + authorQuery.value(2).toString();

        // Query all the books of the author.
        QSqlQuery bookQuery("SELECT title, price, notes FROM book WHERE authorid = " + authorQuery.value(0).toString());

        if (!bookQuery.isActive())
            reportError("Eror when running Query",bookQuery.lastError());

        while (bookQuery.next()) {
            model.addBook(bookQuery.value(0).toString(), author, bookQuery.value(1).toString(), bookQuery.value(2).toString());
        }
    }

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_model", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
