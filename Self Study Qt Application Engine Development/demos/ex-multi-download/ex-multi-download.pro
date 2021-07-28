HEADERS= DownLoader.h
SOURCES= main.cpp DownLoader.cpp
QT+=network
CONFIG+=c++14
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

