/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SHAREDMEMORYLOADER_H
#define SHAREDMEMORYLOADER_H

#include <QObject>
#include <QSharedMemory>

QT_FORWARD_DECLARE_CLASS(QLabel)

class SharedMemoryLoader : public QObject
{
    Q_OBJECT
public:
    explicit SharedMemoryLoader(QLabel *imageLabel, QLabel *textLabel, QObject *parent = 0);

public Q_SLOTS:
    void loadFromSharedMemory();

private:
    QLabel *m_imageLabel;
    QLabel *m_textLabel;
    QSharedMemory m_sharedMemory;
};

#endif // SHAREDMEMORYLOADER_H
