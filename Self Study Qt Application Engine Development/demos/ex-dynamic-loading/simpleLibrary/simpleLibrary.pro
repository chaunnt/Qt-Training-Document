#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T15:51:02
#
#-------------------------------------------------

QT       -= gui

TARGET = simpleLibrary
TEMPLATE = lib

DEFINES += SIMPLELIBRARY_LIBRARY

SOURCES += \
    simplelibrary.cpp

HEADERS +=\
        simplelibrary_global.h

target.path = $$[QT_INSTALL_LIBS]
INSTALLS += target

