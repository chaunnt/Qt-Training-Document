/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.5
import QtQuick.Window 2.0
import QtQuick.Layouts 1.1

Window {
    width: 640
    height: 480
    visible: true

    ListView {
        anchors.fill: parent
        model: _model
        delegate: bookDelegate
        section.delegate: Rectangle {
            color: "lightgreen"
            height: childrenRect.height
            width: parent.width

            Text {
                text: section
                width: parent.width
                wrapMode: Text.WordWrap
            }
        }
        section.property: "lastName"
    }

    Component {
        id: bookDelegate

        ColumnLayout {
            width: parent.width

            ListTextItem {
                text: title
                Layout.fillWidth: true
            }

            ListTextItem {
                text: price
                Layout.fillWidth: true
            }

            ListTextItem {
                text: notes
                Layout.fillWidth: true
            }
        }
    }
}


