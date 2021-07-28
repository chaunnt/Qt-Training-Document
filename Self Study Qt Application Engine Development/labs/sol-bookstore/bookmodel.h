/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef BOOKMODEL_H
#define BOOKMODEL_H

#include <QSqlQueryModel>

class BookModel :public QSqlQueryModel
{
    Q_OBJECT
public:
    BookModel(QObject *parent = Q_NULLPTR);
    void showAuthor(int authorId);
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;

protected:
    void refresh();

private:
    int m_authorId;
    int m_latestBookId;
};

#endif /* BOOKMODEL_H */

