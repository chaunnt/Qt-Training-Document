#-------------------------------------------------
#
# Project created by QtCreator 2017-01-04T10:07:29
#
#-------------------------------------------------

QT       += core gui network

unix {
    QT += dbus
    DBUS_INTERFACES += com.theqtcompany.IpcDemoInterface.xml
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IPCApplication
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
