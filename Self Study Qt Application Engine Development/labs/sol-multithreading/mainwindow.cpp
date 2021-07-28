/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_worker) {
        if (m_worker->isRunning())
            m_worker->requestInterruption();
    }
}

void MainWindow::on_pushButton_released()
{
    if (m_worker) {
        if (m_worker->isRunning())
            m_worker->requestInterruption();
        return;
    }
    m_worker = new QThread();
    m_calculator = new PiCalculator(ui->progressBar, ui->label);
    m_calculator->moveToThread(m_worker);

    connect(m_worker.data(), &QThread::started, m_calculator.data(), &PiCalculator::run);
    connect(m_worker.data(), &QThread::finished, this, &MainWindow::cleanupThread);
    connect(m_worker.data(), &QThread::finished, m_calculator.data(), &PiCalculator::deleteLater);
    connect(m_worker.data(), &QThread::finished, m_worker.data(), &QThread::deleteLater);

    m_worker->start();
    ui->pushButton->setText(tr("Stop Task"));
}

void MainWindow::cleanupThread()
{
    ui->pushButton->setText(tr("Start Task"));
}
