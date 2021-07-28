/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QMap>
#include <QWidget>

class QProgressBar;
class QNetworkReply;
class QNetworkAccessManager;
class QFormLayout;

class DownLoader :public QWidget
{
    Q_OBJECT
public:
    DownLoader();
    void load(const QString &url);

private slots:
    void progress(qint64, qint64);
    void downloadCompleted(QNetworkReply *);
    void error();

private:
    QFormLayout *form;
    QNetworkAccessManager *network;
    QMap<QNetworkReply *, QProgressBar *> map;
};


#endif /* DOWNLOADER_H */

