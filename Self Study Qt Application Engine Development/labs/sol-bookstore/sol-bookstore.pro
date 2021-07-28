TEMPLATE = app
HEADERS = bookstore.h bookmodel.h \
          tabletolistmodel.h
SOURCES= main.cpp bookstore.cpp bookmodel.cpp \
         tabletolistmodel.cpp
QT += sql quick

OTHER_FILES += \
    main.qml \
    AuthorView.qml \
    BookView.qml \
    Editor.qml

RESOURCES += \
    bookstore.qrc


