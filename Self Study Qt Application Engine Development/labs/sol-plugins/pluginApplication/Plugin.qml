/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.4
import io.qt.pluginobject 1.0

PluginForm {
    resetButton.onClicked: {
        statusLabel.text = qsTr("--Ready--");
    }
    plugin1Button.onClicked: {
        statusLabel.text = PluginLoader.loadPlugin1();
    }
    plugin2Button.onClicked: {
        statusLabel.text = PluginLoader.loadPlugin2();
    }
}
