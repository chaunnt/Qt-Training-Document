#-------------------------------------------------
#
# Project created by QtCreator 2017-01-04T10:03:39
#
#-------------------------------------------------

QT       += core gui network

unix {
    QT += dbus
    DBUS_ADAPTORS += com.theqtcompany.IpcDemoInterface.xml
    SOURCES += dbusloader.cpp
    HEADERS += dbusloader.h
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IPCServer
TEMPLATE = app

SOURCES += main.cpp \
    sharedmemoryloader.cpp \
    socketloader.cpp \
    fileloader.cpp

HEADERS  += \
    sharedmemoryloader.h \
    socketloader.h \
    fileloader.h
