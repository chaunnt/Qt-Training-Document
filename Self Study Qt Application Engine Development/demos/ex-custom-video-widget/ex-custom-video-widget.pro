TEMPLATE = app
TARGET = customvideowidget

QT += multimedia widgets multimediawidgets

HEADERS = \
    videoplayer.h \
    videowidget.h \
    videowidgetsurface.h

SOURCES = \
    main.cpp \
    videoplayer.cpp \
    videowidget.cpp \
    videowidgetsurface.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/customvideosurface/customvideowidget
INSTALLS += target
