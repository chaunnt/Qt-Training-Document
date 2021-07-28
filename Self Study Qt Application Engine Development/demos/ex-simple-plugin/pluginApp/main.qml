/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.3
import QtQuick.Window 2.2
import io.qt.demoItems 1.0

Window {
    visible: true
    width: 640
    height: 480

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    ImageItem {
        id: texture
        anchors.fill: parent
        transformOrigin: Item.Center
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: {
                if (mouse.button === Qt.LeftButton)
                    texture.rotation += 10;
                else
                    texture.rotation -= 10;
            }
        }
    }
}
