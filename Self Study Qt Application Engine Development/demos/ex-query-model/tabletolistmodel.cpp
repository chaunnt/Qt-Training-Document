/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "tabletolistmodel.h"

#include <QAbstractTableModel>
#include <QtDebug>

TableToListModel::TableToListModel(QObject *parent)
    : QAbstractListModel(parent),
    m_sourceModel(0)
{
}

void TableToListModel::setTableModel(QAbstractTableModel *sourceModel)
{
    m_sourceModel = sourceModel;
}

void TableToListModel::addColumnMapping(int column, const QByteArray &qmlProperty)
{
    if (m_columnToProperty.contains(column)) {
        qWarning() << Q_FUNC_INFO << "column" << column << "already mapped";
        return;
    }

    if (m_propertyToColumn.contains(qmlProperty)) {
        qWarning() << Q_FUNC_INFO << "property" << qmlProperty << "already used in mapping";
        return;
    }

    m_columnToProperty[column] = qmlProperty;
    m_propertyToColumn[qmlProperty] = column;
    m_roleToProperty[Qt::UserRole + column] = qmlProperty;
}

QHash<int, QByteArray> TableToListModel::roleNames() const
{
    return m_roleToProperty;
}

int TableToListModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) {
        return m_sourceModel->rowCount(QModelIndex());
    }

    return 0;
}

QVariant TableToListModel::data(const QModelIndex &proxyIndex, int role) const
{
    if (m_roleToProperty.contains(role)) {
        QModelIndex index = m_sourceModel->index(proxyIndex.row(), m_propertyToColumn[m_roleToProperty[role]]);
        return m_sourceModel->data(index, Qt::DisplayRole);
    }

    return QVariant();
}

QVariant TableToListModel::data(int row, const QByteArray &qmlProperty) const
{
    QModelIndex index = m_sourceModel->index(row, m_propertyToColumn[qmlProperty]);
    return m_sourceModel->data(index, Qt::DisplayRole);
}

void TableToListModel::setData(int row, const QByteArray &qmlProperty, const QVariant &value)
{
    QModelIndex index = m_sourceModel->index(row, m_propertyToColumn[qmlProperty]);
    m_sourceModel->setData(index, value);
}
