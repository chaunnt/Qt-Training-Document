QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    pluginloader.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
target.path = .
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    plugininterface.h \
    pluginloader.h
