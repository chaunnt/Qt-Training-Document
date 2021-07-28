/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include <QtSql>
#include "bookmodel.h"
#include "bookstore.h"

BookModel::BookModel(QObject *parent)
    : QSqlQueryModel(parent)
{
    setQuery(QString("SELECT id FROM book"));
    if (lastError().type() != QSqlError::NoError)
        BookStore::reportError("Error checking the latest index", lastError());
    m_latestBookId = data(index(rowCount() - 1, 0)).toInt();
}

void BookModel::showAuthor(int authorId)
{
    m_authorId = authorId;
    setQuery(QString("SELECT id, authorid, title, price, notes FROM book WHERE authorid = %1").arg(authorId));
    if (lastError().type() != QSqlError::NoError)
        BookStore::reportError("Error running showAuthor query", lastError());
}

bool BookModel::setData(const QModelIndex &idx, const QVariant &value, int /*role*/)
{
    QModelIndex primaryKeyIndex = index(idx.row(), 0 , idx.parent());
    int primaryKey = data(primaryKeyIndex).toInt();

    QString field;
    switch (idx.column()) {
    case 2: field = "title"; break;
    case 3: field = "price"; break;
    case 4: field = "notes"; break;
    default: qFatal("Unknown field number %d", idx.column());
    }

    QSqlQuery query;
    query.prepare(QString("update book set %1 = :value where id = :id").arg(field));
    query.bindValue(":value", value);
    query.bindValue(":id", primaryKey);
    bool ok = query.exec();
    if (!ok)
        BookStore::reportError("Error running update command", query.lastError());
    refresh();
    return ok;
}

Qt::ItemFlags BookModel::flags(const QModelIndex &index) const
{
    return QSqlQueryModel::flags(index) | Qt::ItemIsEditable;
}

bool BookModel::removeRows(int row, int count, const QModelIndex &parent)
{
    for (auto i=0; i< count; ++i) {
        QModelIndex primaryKeyIndex = index(row + i, 0 , parent);
        int primaryKey = data(primaryKeyIndex).toInt();

        QSqlQuery query;
        query.prepare(QString("DELETE FROM book where id = :id"));
        query.bindValue(":id", primaryKey);
        bool ok = query.exec();
        if (!ok) {
            BookStore::reportError("Error running DELETE command", query.lastError());
            return false;
        }
        refresh();
    }
    return true;
}

bool BookModel::insertRows(int /*row*/, int count, const QModelIndex &/*parent*/ )
{
    for (auto i=0; i < count; ++i) {
        QSqlQuery query;

        query.prepare(QString("INSERT INTO book (id, authorId, title, price, notes) VALUES (:id, :authorId, :title, 1, :notes)"));
        query.bindValue(":id", m_latestBookId + i + 1);
        query.bindValue(":authorId", m_authorId);
        query.bindValue(":title", "Title");
        query.bindValue(":price", "1.11");
        query.bindValue(":notes", "Book notes");
        bool ok = query.exec();
        if (!ok) {
            BookStore::reportError("Error running INSERT command", query.lastError());
            return false;
        }
        m_latestBookId = query.lastInsertId().toInt();
        refresh();
    }
    return true;
}

void  BookModel::refresh()
{
    showAuthor(m_authorId);
}
