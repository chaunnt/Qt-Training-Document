/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef FILELOADER_H
#define FILELOADER_H

#include <QObject>

QT_FORWARD_DECLARE_CLASS(QFileSystemWatcher)
QT_FORWARD_DECLARE_CLASS(QLabel)

class FileLoader : public QObject
{
    Q_OBJECT
public:
    explicit FileLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent = 0);

protected Q_SLOTS:
    void loadFile();

private:
    QFileSystemWatcher *m_watcher;
    QLabel *m_imageLabel;
    QLabel *m_textLabel;
};

#endif // FILELOADER_H
