/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_schema.h"

class MainWindow : public QMainWindow,
                   private Ui::SchemaMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private Q_SLOTS:
    void schemaSelected(int index);
    void instanceSelected(int index);
    void validate();
    void textChanged();

private:
    void moveCursor(int line, int column);
};
#endif
