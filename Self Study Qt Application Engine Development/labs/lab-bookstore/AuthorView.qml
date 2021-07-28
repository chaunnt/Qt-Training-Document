/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.8
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1

Item {
    signal authorChanged()
    Component {
        id: authorDelegate
        GridLayout {
            property var listView: ListView.view
            width: listView.width
            columns: 2
            rowSpacing: 5

            // First name row
            Label {
                id: firstnameText
                text: qsTr("First Name:")
                Layout.topMargin: 10
            }
            Editor {
                text: qsTr("Author firstname") // Step 4
                Layout.fillWidth: true
                Layout.topMargin: 10

                // Step 6: change model data on text change accepted
            }

            // Last name row
            Label {
                id: lastnameText
                text: qsTr("Last Name:")
                Layout.bottomMargin: 10
            }
            Editor {
                text: qsTr("Author lastname") // Step 4
                Layout.fillWidth: true
                Layout.bottomMargin: 10

                // Step 6: change model data on text change accepted
            }
        }
    }

    ListView {
        model: _bookStore.authorsModel
        delegate: authorDelegate
        highlight: Rectangle { width: parent.width; color: "lightsteelblue"; radius: 5 }

        headerPositioning: ListView.OverlayHeader
        header: Rectangle {
            z: 10
            height: 20
            width: parent.width
            color: "lightblue"
            Text {
                text: qsTr("Author")
                anchors.centerIn: parent
            }
        }

        // Optional Step
        // Add and remove author buttons
        /*
        footerPositioning: ListView.OverlayFooter
        footer: Rectangle {
            property var listView: ListView.view
            z: 10
            width: parent.width
            height: 30

            Rectangle {
                width: parent.width / 3
                height: parent.height
                radius: 5
                color: "lightgray"
                anchors.left: parent.left

                Button {
                    id: addAuthorButton
                    text: qsTr("Add Author")
                    anchors.fill: parent
                    onClicked: {
                        _bookStore.addAuthor();
                        listView.currentIndex = listView.count - 1;
                    }
                }
            }

            Rectangle {
                enabled: listView.currentIndex != -1
                width: parent.width / 3
                height: parent.height
                radius: 5
                color: "lightgray"
                anchors.right: parent.right

                Button {
                    id: removeAuthorButton
                    text: qsTr("Remove Author")
                    anchors.fill: parent
                    onClicked: {
                        _bookStore.removeAuthor(listView.currentIndex);
                    }
                }
            }
        }
        */

        onCurrentIndexChanged: {
            _bookStore.authorChanged(currentIndex);
            authorChanged();
        }

        focus: true
        anchors.fill: parent
        clip: true
    }
}
