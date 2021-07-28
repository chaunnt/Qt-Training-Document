/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "DownLoader.h"
#include <QLabel>
#include <QDebug>
#include <QFile>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QFormLayout>
#include <QProgressBar>

DownLoader::DownLoader()
    : QWidget()
{
    form = new QFormLayout(this);
    network = new QNetworkAccessManager(this);
    connect(network, &QNetworkAccessManager::finished, this, &DownLoader::downloadCompleted);
}

void DownLoader::load(const QString &url)
{
    QProgressBar *bar = new QProgressBar;
    bar->setRange(0,100);
    bar->setValue(0);
    form->addRow(url, bar);

    QNetworkReply *reply = network->get(QNetworkRequest(url));
    map[reply] = bar;
    connect(reply, &QNetworkReply::downloadProgress, this, &DownLoader::progress);
    connect(reply, qOverload<QNetworkReply::NetworkError>(&QNetworkReply::error), this, &DownLoader::error);
}

void DownLoader::progress(qint64 progress, qint64 total)
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    QProgressBar *bar = map[reply];
    if (total != 0)
        bar->setValue(100.0 * (progress / total));
}

void DownLoader::downloadCompleted(QNetworkReply *reply)
{
    qDebug() << "Request was " << reply->request().url();
    const QUrl url = reply->url();
    QString name = url.host() + url.path();
    name.replace("/","_");
    name.replace("\\","_");

    QFile file(name);

    Q_ASSERT(file.open(QFile::WriteOnly));
    file.write(reply->readAll());
    file.close();

    reply->deleteLater(); // Notice our responsibility!
}

void DownLoader::error()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    QProgressBar *bar = map[reply];

    int row;
    QFormLayout::ItemRole role;
    form->getWidgetPosition(bar, &row, &role);

    delete bar;
    form->setWidget(row, role, new QLabel(reply->errorString()));
}

