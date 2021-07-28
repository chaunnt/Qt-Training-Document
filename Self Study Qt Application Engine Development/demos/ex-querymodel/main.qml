/*************************************************************************
 *
 * Copyright (c) 2016 Qt Group Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.3

Rectangle {
    width: 300
    height: 300

    Component {
        id: bookDelegate

        Column {
            height: 90
            Text {
                text: title
            }

            Text {
                text: lastName + ", " + firstName
            }

            Text {
                text: price
            }

            Text {
                text: notes
            }
        }
    }

    ListView {
        model: _model
        delegate: bookDelegate
        section.delegate: Rectangle {
            color: "red"
            height: 20
            width: parent.width

            Text {
                text: section
            }
        }
        section.property: "lastName"

        anchors.fill: parent
    }
}
