/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "bookstore.h"
#include "bookmodel.h"
#include "tabletolistmodel.h"

#include <QtQuick>
#include <QtSql>

BookStore::BookStore(QObject *parent) :
    QObject(parent)
{
    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../databases/bookstore.db");
    if (!db.open())
        reportError("Error When opening database", db.lastError());

    // Set up the models
    m_authorsModel = new QSqlTableModel(this);
    // Step 1: Setup the author table. The author table name is simply "author"

    m_latestAuthorId = m_authorsModel->data(m_authorsModel->index(m_authorsModel->rowCount() - 1, 0)).toInt();

    m_bookModel = new BookModel(this);
    m_authorsModelProxy = new TableToListModel(this);
    m_bookModelProxy = new TableToListModel(this);

    // Step 2: setup proxies
    // author table has three fields: authorid, firstname, surname

    // The book model columns depend on the query, you are requested to
    // implement is Step 3
    // However, the book table contains the following cloumns:
    // id, authorid, title, price, notes
}

void BookStore::reportError(const QString &msg, const QSqlError &err)
{
    qDebug() <<
        QString("%1\nDriver Message: %2\nDatabase Message %3")
        .arg(msg)
        .arg(err.driverText())
        .arg(err.databaseText());
    qApp->exit(-1);
}

QObject *BookStore::authorsModel() const
{
    return m_authorsModelProxy;
}

QObject *BookStore::bookModel() const
{
    return m_bookModelProxy;
}

void BookStore::authorChanged(int row)
{
    int authorId = m_authorsModel->data(m_authorsModel->index(row, 0, QModelIndex())).toInt();
    m_bookModelProxy->showAuthor(authorId);
}

// Optional Step
// Comment in the following four functions
// They just call the relevant functionality in other classes, so no
// need to implement them.
/*
void BookStore::addAuthor()
{
    int row(m_authorsModel->rowCount());
    m_authorsModelProxy->insertItems(m_authorsModel->rowCount(), 1);

    m_latestAuthorId++;
    m_authorsModelProxy->setData(row, "authorId", m_latestAuthorId);
    m_authorsModelProxy->setData(row, "firstName", "Firstname");
    m_authorsModelProxy->setData(row, "lastName", "Lastname");
}

void BookStore::removeAuthor(int row)
{
    m_authorsModelProxy->removeItem(row);
}

void BookStore::addBook()
{
    m_bookModelProxy->insertItems(m_bookModel->rowCount(), 1);
}

void BookStore::removeBook(int row)
{
    m_bookModelProxy->removeItem(row);
}
*/
