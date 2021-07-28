/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.8
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1

Item {
    function resetItemIndex() {
        bookListId.currentIndex = 0;
    }

    Component {
        id: bookDelegate
        GridLayout {
            property var listView: ListView.view
            columns: 2
            rowSpacing: 5
            width: listView.width

            // Title row
            Label {
                id: titleText
                text: qsTr("Title:")
                Layout.topMargin: 10
            }
            Editor {
                text: qsTr("Title") // Step 4
                Layout.fillWidth: true
                Layout.topMargin: 10

                // Step 6: change model data on text change accepted
            }

            // Price row
            Label {
                text: qsTr("Price:")
            }
            Editor {
                text: qsTr("Price") // Step 4
                Layout.fillWidth: true

                // Step 6: change model data on text change accepted
            }

            // Notes row
            Label {
                id: notesText
                text: qsTr("Notes:")
                Layout.bottomMargin: 10
            }
            Editor {
                text: qsTr("Notes") // Step 4
                Layout.fillWidth: true
                Layout.bottomMargin: 10

                // Step 6: change model data on text change accepted
            }
        }
    }

    ListView {
        id: bookListId
        model: _bookStore.bookModel
        delegate: bookDelegate
        highlight: Rectangle { color: "lightsteelblue"; radius: 5 }

        headerPositioning: ListView.OverlayHeader
        header: Rectangle {
            z: 10
            height: 20
            width: parent.width
            color: "lightblue"

            Text {
                text: qsTr("Book")
                anchors.centerIn: parent
            }
        }

        // Optional Step
        // Add and remove book buttons
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
                    id: addBookButton
                    text: qsTr("Add Book")
                    anchors.fill: parent
                    onClicked: {
                        _bookStore.addBook();
                        listView.currentIndex = listView.count - 1;
                    }
                }
            }

            Rectangle {
                enabled: ListView.currentIndex != -1
                width: parent.width / 3
                height: parent.height
                radius: 5
                color: "lightgray"
                anchors.right: parent.right

                Button {
                    id: removeBookButton
                    text: qsTr("Remove Book")
                    anchors.fill: parent
                    onClicked: {
                        _bookStore.removeBook(listView.currentIndex);
                    }
                }
            }
        }
        */

        anchors.fill: parent
    }
}
