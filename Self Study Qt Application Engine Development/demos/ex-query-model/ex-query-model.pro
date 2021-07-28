HEADERS= \ 
         tabletolistmodel.h
SOURCES= main.cpp \
         tabletolistmodel.cpp
QT += sql quick

OTHER_FILES += \
    main.qml \
    ListTextItem.qml

RESOURCES += \
    ex-querymodel.qrc
