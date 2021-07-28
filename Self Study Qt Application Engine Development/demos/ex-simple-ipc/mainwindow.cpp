/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QProcess>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_process(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if (m_process)
        m_process->close();
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    if (m_process) {
        m_process->close();
        delete m_process;
    }
    m_process = new QProcess(this);
    m_process->start(ui->lineEdit->text());
}

void MainWindow::on_lineEdit_2_returnPressed()
{
    if (!m_process)
        return;
    m_process->write(ui->lineEdit_2->text().toLatin1() + "\n");
}

void MainWindow::on_pushButton_pressed()
{
    if (m_process) {
        m_process->closeWriteChannel();
        if (!m_process->waitForFinished())
            return;
        QByteArray bytesRead = m_process->readAll();
        ui->textEdit->append(bytesRead);
    }
}


