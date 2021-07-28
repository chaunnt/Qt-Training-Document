#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T15:44:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demoApp
TEMPLATE = app

SOURCES += main.cpp

HEADERS  +=

unix {
    target.path = .
    INSTALLS += target
}




