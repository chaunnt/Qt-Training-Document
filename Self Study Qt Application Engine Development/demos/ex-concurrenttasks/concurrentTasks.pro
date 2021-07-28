#-------------------------------------------------
#
# Project created by QtCreator 2015-04-15T17:47:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConcurrentTasks
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    runnable.cpp

HEADERS  += widget.h \
    runnable.h

FORMS    += widget.ui
