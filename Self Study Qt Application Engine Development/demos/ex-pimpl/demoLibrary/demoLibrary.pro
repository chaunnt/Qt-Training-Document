#-------------------------------------------------
#
# Project created by QtCreator 2016-08-25T15:51:02
#
#-------------------------------------------------

QT       -= gui

TARGET = demoLibrary
TEMPLATE = lib

DEFINES += DEMOLIBRARY_LIBRARY

SOURCES += \
    democlass.cpp

HEADERS +=\
        demolibrary_global.h \
    democlass_p.h \
    democlass.h

installFiles.files += $${HEADERS}
installFiles.path = $$[QT_INSTALL_HEADERS]
target.path = $$[QT_INSTALL_LIBS]
INSTALLS += target installFiles

