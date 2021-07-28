#ifndef PLUGININTERFACE_H_
#define PLUGININTERFACE_H_

#include <QtPlugin>
#include <QtCore/QString>

class PluginInterface
{
public:
    virtual QString getTheString() const = 0;
};

Q_DECLARE_INTERFACE(PluginInterface, "io.qt.SimpleInterface")

#endif

