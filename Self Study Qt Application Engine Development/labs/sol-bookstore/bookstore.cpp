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
    m_authorsModel->setTable("author");
    m_authorsModel->select();

    m_latestAuthorId = m_authorsModel->data(m_authorsModel->index(m_authorsModel->rowCount() - 1, 0)).toInt();

    m_bookModel = new BookModel(this);

    m_authorsModelProxy = new TableToListModel(this);
    m_authorsModelProxy->setTableModel(m_authorsModel);
    m_authorsModelProxy->addColumnMapping(0, "authorId");
    m_authorsModelProxy->addColumnMapping(1, "firstName");
    m_authorsModelProxy->addColumnMapping(2, "lastName");

    m_bookModelProxy = new TableToListModel(this);
    m_bookModelProxy->setTableModel(m_bookModel);
    m_bookModelProxy->addColumnMapping(2, "title");
    m_bookModelProxy->addColumnMapping(3, "price");
    m_bookModelProxy->addColumnMapping(4, "notes");
}

BookStore::~BookStore()
{
    QSqlDatabase::database().close();
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
