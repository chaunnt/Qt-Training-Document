/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QSharedMemory>
#ifdef Q_OS_UNIX
#include "ipcdemointerface_interface.h"
#endif

QT_FORWARD_DECLARE_CLASS(QTcpSocket)

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = Q_NULLPTR);
    ~Widget();

private Q_SLOTS:
    void socketReady();
    void on_loadImageButton_clicked();
    void on_writeToMemoryButton_clicked();
    void on_writeToSocketButton_clicked();
    void on_writeToDbusButton_clicked();
    void on_writeToFileButton_clicked();

private:
    Ui::Widget *ui;
    QImage m_sharedImage;
    QSharedMemory m_sharedMemory;
    QTcpSocket *m_socket;
    bool m_socketReady;
#ifdef Q_OS_UNIX
    com::theqtcompany::IpcDemoInterface *m_inageInterface;
#endif
};

#endif // WIDGET_H
