QT       += quick
HEADERS   = baritem.h chartitem.h
RESOURCES = ex-custom-collection-types.qrc
SOURCES   = baritem.cpp chartitem.cpp main.cpp

# These next three lines makes the QML files show up in a section of their
# own in Qt Creator.
qml.files += $$files(*.qml)
qml.path = "."
INSTALLS += qml
