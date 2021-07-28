SOURCES += main.cpp filetree.cpp mainwindow.cpp xmlsyntaxhighlighter.cpp
HEADERS += filetree.h  mainwindow.h xmlsyntaxhighlighter.h
FORMS += forms/mainwindow.ui
QT += widgets xmlpatterns
RESOURCES += queries.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/xmlpatterns/filetree
INSTALLS += target

