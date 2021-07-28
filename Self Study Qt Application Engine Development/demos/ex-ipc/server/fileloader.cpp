/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "fileloader.h"
#include <QLabel>
#include <QFileSystemWatcher>
#include <QFile>
#include <QImage>
#include <QDir>

FileLoader::FileLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent) :
    QObject(parent),
    m_watcher(new QFileSystemWatcher(this)),
    m_imageLabel(imageLabel),
    m_textLabel(textLabel)
{
    m_watcher->addPath(QDir::tempPath());
    connect(m_watcher, &QFileSystemWatcher::directoryChanged, this, &FileLoader::loadFile);
}

void FileLoader::loadFile()
{
    QFile inFile(QString(QDir::tempPath() + "/imageFile"));
    QImage image;
    if (!inFile.open(QFile::ReadOnly))
        return; // tmp directory was not changed by the client app
    QDataStream in(&inFile);
    in >> image;

    m_imageLabel->setPixmap(QPixmap::fromImage(image));
    m_textLabel->setText(tr("New image loaded from a file."));
}

