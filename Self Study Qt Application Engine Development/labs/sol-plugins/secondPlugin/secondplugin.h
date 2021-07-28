#ifndef SECONDPLUGIN_H_
#define SECONDPLUGIN_H_

#include "plugininterface.h"

class SecondPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.theqtcompany.QDummyPlugin" FILE "dummyPlugin.json")
    Q_INTERFACES(PluginInterface)

public:
    SecondPlugin();
    QString getTheString(void) const;
};

#endif
