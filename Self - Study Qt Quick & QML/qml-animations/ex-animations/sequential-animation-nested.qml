/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5

Rectangle {
    width: 200; height: 200; color: "#000040"

    Image {
        id: rocket
        anchors.centerIn: parent
        source: "../images/rocket.png"
    }

    SequentialAnimation {
        NumberAnimation {
            target: rocket; properties: "scale"
            from: 1.0; to: 0.5; duration: 1000
        }
        SequentialAnimation {
            NumberAnimation {
                target: rocket; properties: "rotation"
                from: 0.0; to: 360.0; duration: 1000
            }
            NumberAnimation {
                target: rocket; properties: "opacity"
                from: 1.0; to: 0.0; duration: 1000
            }
        }
        running: true
    }
}
