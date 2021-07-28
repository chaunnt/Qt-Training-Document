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

namespace Ui {
class MainWindow;
}

class QProcess;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

private Q_SLOTS:
    void on_lineEdit_returnPressed();
    void on_lineEdit_2_returnPressed();
    void on_pushButton_pressed();

private:
    Ui::MainWindow *ui;
    QProcess *m_process;
};

#endif // MAINWINDOW_H
