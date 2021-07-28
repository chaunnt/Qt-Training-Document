QT          += widgets xmlpatterns
FORMS       += schema.ui
HEADERS     = mainwindow.h xmlsyntaxhighlighter.h
RESOURCES   = schema.qrc
SOURCES     = main.cpp mainwindow.cpp xmlsyntaxhighlighter.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/xmlpatterns/schema
INSTALLS += target

CONFIG += c++14

