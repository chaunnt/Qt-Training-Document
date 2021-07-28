/*************************************************************************
 *
 * Copyright (c) 2016 Qt Group Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class QStandardItemModel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public Q_SLOTS:
    void taskFinished(const QString &name);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QStandardItemModel *m_model;
};

#endif // WIDGET_H
