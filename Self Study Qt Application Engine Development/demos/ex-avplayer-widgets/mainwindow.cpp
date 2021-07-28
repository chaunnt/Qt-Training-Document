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

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_player(new QMediaPlayer(this)),
    m_playlist(new QMediaPlaylist(this))
{
    m_player->setPlaylist(m_playlist);
    ui->setupUi(this);
    QVideoWidget *widget = new QVideoWidget();
    m_player->setVideoOutput(widget);
    ui->centralWidget->layout()->addWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_openButton_clicked()
{
    QList<QUrl> fileList = QFileDialog::getOpenFileUrls(Q_NULLPTR, "Open Media Files", QUrl("."));
    for (const QUrl &file : fileList)
        m_playlist->addMedia(file);
}

void MainWindow::on_pauseButton_clicked()
{
    m_player->pause();
}

void MainWindow::on_playButton_clicked()
{
    if (m_player->state() == QMediaPlayer::StoppedState)
        m_playlist->setCurrentIndex(1);
    m_player->play();
}

void MainWindow::on_stopButton_clicked()
{
    m_player->stop();
}
