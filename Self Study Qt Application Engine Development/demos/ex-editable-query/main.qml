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
    minimumWidth: 250
    height: 480
    visible: true

    Row {
        id: rootRow
        anchors.fill: parent
        spacing: 10

        ListView {
            id: listView
            height: parent.height
            width: parent.width / 2
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
            highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
            section.property: "lastName"

            focus: true
        }

        Column {
            height: parent.height
            width: parent.width / 2

            Row {
                height: childrenRect.height
                width: parent.width

                ListTextItem {
                    id: titleTextId
                    text: qsTr("Title: ")
                }

                TextInput {
                    id: titleInput
                    wrapMode: TextInput.WordWrap
                    width: parent.width - titleTextId.implicitWidth
                    text: _model.data(listView.currentIndex, "title")
                }
            }
            Row {
                height: childrenRect.height
                width: parent.width

                ListTextItem {
                    id: priceTextId
                    text: qsTr("Price: ")
                }

                TextInput {
                    id: priceInput
                    wrapMode: TextInput.WordWrap
                    width: parent.width - priceTextId.implicitWidth
                    text: _model.data(listView.currentIndex, "price")
                }
            }
            Row {
                height: childrenRect.height
                width: parent.width

                ListTextItem {
                    id: notesTextId
                    text: qsTr("Notes: ")
                }

                TextInput {
                    id: notesInput
                    wrapMode: TextInput.WordWrap
                    width: parent.width - notesTextId.implicitWidth
                    text: _model.data(listView.currentIndex, "notes")
                }
            }

            Rectangle {
                height: 30
                width: parent.width - rootRow.spacing
                color: "lightgray"
                radius: 5

                Button {
                    id: submitButton
                    buttonText: qsTr("Submit")
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        _model.setData(listView.currentIndex, "title", titleInput.text);
                        _model.setData(listView.currentIndex, "price", priceInput.text);
                        _model.setData(listView.currentIndex, "notes", notesInput.text);
                        listView.focus = true;
                        submitButton.notify();
                    }
                }
            }
        }
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
                text: lastName + ", " + firstName
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




