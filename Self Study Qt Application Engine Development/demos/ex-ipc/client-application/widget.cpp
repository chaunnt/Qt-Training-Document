/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QBuffer>
#include <QTcpSocket>
#include <QImageReader>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_sharedMemory("SharedMemoryKey"),
    m_socket(new QTcpSocket(this)),
    m_socketReady(false)
{
    ui->setupUi(this);
    ui->label->setText(tr("Select an image file"));

    m_socket->connectToHost("localhost", 4242);
    connect(m_socket, &QTcpSocket::connected, this, &Widget::socketReady);
#ifdef Q_OS_UNIX
    m_inageInterface = new com::theqtcompany::IpcDemoInterface("com.theQtCompany.ImageLoader", "/IpcDemo", QDBusConnection::sessionBus(), this);
#endif
}

Widget::~Widget()
{
    m_sharedImage.detach();
    m_socket->close();
    delete ui;
}

void Widget::socketReady()
{
    m_socketReady = true;
}

void Widget::on_loadImageButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(0, QString(), QString(), tr("Images (*.png *.xpm *.jpg *.jpeg)"));
    if (!m_sharedImage.load(fileName)) {
        ui->label->setText(tr("Selected file is not an image, please select another."));
        return;
    }
    ui->label->setPixmap(QPixmap::fromImage(m_sharedImage));
}

void Widget::on_writeToMemoryButton_clicked()
{
    QBuffer buffer;
    buffer.open(QBuffer::ReadWrite);
    QDataStream out(&buffer);
    out << m_sharedImage;
    int size = buffer.size();

    if (!m_sharedMemory.isAttached()) {
        if (!m_sharedMemory.create(size)) {
            ui->label->setText(tr("Unable to create a shared memory segment."));
            return;
        }
    }

    m_sharedMemory.lock();
    char *to = (char *) m_sharedMemory.data();
    const char *from = buffer.data().data();
    memcpy(to, from, qMin(m_sharedMemory.size(), size));
    m_sharedMemory.unlock();
}

void Widget::on_writeToSocketButton_clicked()
{
    if (m_socketReady) {
        QDataStream out(m_socket);
        // Large images are sent in fragments
        // The data is sent as QByteArray, because QImage de-serialization fails with fragment data
        out << m_sharedImage;
    }
    else
        ui->label->setText(tr("No socket connection yet."));
}

void Widget::on_writeToDbusButton_clicked()
{
#ifdef Q_OS_UNIX
    QBuffer buffer;
    buffer.open(QBuffer::WriteOnly);
    QDataStream out(&buffer);
    out << m_sharedImage;

    QDBusVariant args;
    args.setVariant(QVariant(buffer.data()));
    m_inageInterface->loadImage(args);
#endif
}

void Widget::on_writeToFileButton_clicked()
{
    QFile outFile(QString(QDir::tempPath() + "/imageFile"));
    outFile.open(QFile::WriteOnly);
    QDataStream out(&outFile);
    out << m_sharedImage;
}
