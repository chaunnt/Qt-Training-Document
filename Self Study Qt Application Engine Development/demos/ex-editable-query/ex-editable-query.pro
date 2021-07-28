TEMPLATE = app
SOURCES = main.cpp \
          tabletolistmodel.cpp
HEADERS += \
           tabletolistmodel.h
QT += sql quick

OTHER_FILES += main.qml \
    ListTextItem.qml

RESOURCES += \
    ex-editablequery.qrc

DISTFILES += \
    Button.qml

