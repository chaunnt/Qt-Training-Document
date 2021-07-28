/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <QObject>

QT_FORWARD_DECLARE_CLASS(BookModel)
QT_FORWARD_DECLARE_CLASS(TableToListModel)
QT_FORWARD_DECLARE_CLASS(QModelIndex)
QT_FORWARD_DECLARE_CLASS(QSqlTableModel)
QT_FORWARD_DECLARE_CLASS(QSqlError)

class BookStore :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject *authorsModel READ authorsModel CONSTANT)
    Q_PROPERTY(QObject *bookModel READ bookModel CONSTANT)

public:
    explicit BookStore(QObject *parent = Q_NULLPTR);
    static void reportError(const QString &msg, const QSqlError &err);

    QObject *authorsModel() const;
    QObject *bookModel() const;

    Q_INVOKABLE void authorChanged(int row);

    // Optional Step. Comment in these functions
    /*
    Q_INVOKABLE void addAuthor();
    Q_INVOKABLE void removeAuthor(int row);

    Q_INVOKABLE void addBook();
    Q_INVOKABLE void removeBook(int row);
    */

private:
    QSqlTableModel *m_authorsModel;
    BookModel *m_bookModel;

    TableToListModel *m_authorsModelProxy;
    TableToListModel *m_bookModelProxy;

    // Used in adding new authors with a unique id (primary key)
    int m_latestAuthorId;
};

#endif /* BOOKSTORE_H */

