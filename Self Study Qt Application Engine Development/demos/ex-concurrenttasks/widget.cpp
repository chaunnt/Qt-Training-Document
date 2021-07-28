/*************************************************************************
 *
 * Copyright (c) 2016 Qt Group Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QStandardItemModel>
#include <QRunnable>
#include <QDebug>
#include <QThreadPool>
#include <QScrollBar>
#include "widget.h"
#include "runnable.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_model(new QStandardItemModel(this))
{
    ui->setupUi(this);
    ui->tableView->setModel(m_model);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::taskFinished(const QString &name)
{
    int row(name.right(name.length() - 5).toInt());
    m_model->setData(m_model->index(row, 1), "finished");
}

void Widget::on_pushButton_clicked()
{
    QList<QStandardItem *> row;
    QString taskName = QString("Task %1").arg(m_model->rowCount());
    row << new QStandardItem(taskName) << new QStandardItem("queued");
    m_model->appendRow(row);

    Runnable *runnable = new Runnable(taskName, this);
    runnable->setAutoDelete(true);
    QThreadPool::globalInstance()->start(runnable);

    if (m_model->rowCount() < 2) {
        int width(ui->tableView->contentsRect().width() - ui->tableView->verticalScrollBar()->width());
        ui->tableView->setColumnWidth(0, width / 2);
        ui->tableView->setColumnWidth(1, width / 2);

    }
}
