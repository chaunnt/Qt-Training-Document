===========
Plugins Lab
===========

Define a custom plugin interface.

Implement the interface in custom plugins.

Complete the skeleton application to load the plugins.

Step 1:
=======

Create a new header file, defining an interface. The skeleton program assumes you interface has a function, which returns QString.
Define also the interface identifier.

Step 2:
=======

Add one or more plugin subprojects to the project using Qt Creator.
Rather than using any existing interface, derive you plugin from QObject and your own interface.
Implement the pure virtual function(s) of your interface.
Pay attention to DESTDIR and INSTALLS variables in the plugin .pro file.

Step 3:
=======

In pluginApplication, add a library path to the folder, into which you installed the plugin in Step 2.
In the PluginLoader class, implement loadPlugin1(), loadPlugin2(), and loadPlugin() functions. Two former
functions should just set the plugin file name and the last one should load the plugin and call the interface
function to return a QString, shown in Qt Quick Button item.

