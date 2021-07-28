TEMPLATE      = lib
VERSION       = 5.1     # --> firstplugin5.dll
CONFIG       += plugin
INCLUDEPATH  += ..
HEADERS       = secondplugin.h
SOURCES       = secondplugin.cpp

TARGET          = $$qtLibraryTarget(secondplugin)   # windows: firstplugind5.dll

DISTFILES = dummyPlugin.json

target.path = $$[QT_INSTALL_PLUGINS]/generic
json.path = $$[QT_INSTALL_PLUGINS]/generic
json.files = dummyPlugin.json
INSTALLS += target json

OTHER_FILES += \
    dummyPlugin.jsonTEMPLATE      = lib


