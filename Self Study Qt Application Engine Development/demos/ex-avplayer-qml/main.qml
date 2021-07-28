/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.8
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
import QtMultimedia 5.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Media player")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: {
                    filedialog.open();
                }
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

FileDialog {
        id: filedialog
        title: qsTr("Please choose a media file")
        folder: shortcuts.home
        onAccepted: {
            mediaplayer.source = filedialog.fileUrls[0];
        }
    }

    Loader {
        id: loader
        anchors { top: parent.top; bottom: toolbar.top }
        width: parent.width
    }

    Component {
        id: videooutputcamera
        VideoOutput {
            property alias camera: reccamera
            visible: !videooutputvideo.visible

            source: Camera {
                id: reccamera
            }
        }
    }

    VideoOutput {
        id: videooutputvideo
        anchors.top: parent.top
        anchors.bottom: toolbar.top
        width: parent.width

        source: mediaplayer
    }

    MediaPlayer {
        id: mediaplayer
    }

    ToolBar {
        id: toolbar
        anchors.bottom: parent.bottom
        style: ToolBarStyle {
            background: Rectangle {
                gradient: Gradient {
                    GradientStop {
                        position: 0.00;
                        color: "#d7d4d4";
                    }
                    GradientStop {
                        position: 1.00;
                        color: "#050404";
                    }
                }
            }
        }

        RowLayout {
            spacing: playButton.width
            anchors.horizontalCenter: parent.horizontalCenter
            ToolButton {
                id: playButton
                iconSource: "qrc:/buttonimages/play.png"
                onClicked: {
                    mediaplayer.play();
                }
            }
            ToolButton {
                iconSource: "qrc:/buttonimages/pause.png"
                onClicked: {
                    (mediaplayer.playbackState === MediaPlayer.PausedState) ? mediaplayer.play() : mediaplayer.pause();
                }
            }
            ToolButton {
                iconSource: "qrc:/buttonimages/stop.png"
                onClicked: {
                    mediaplayer.stop();
                }
            }
            ToolButton {
                iconSource: "qrc:/buttonimages/upload.png"
                onClicked: {
                    if (videooutputvideo.visible) {
                        videooutputvideo.visible = false;
                        if (loader.status === Loader.Ready) {
                            loader.item.camera.start();
                        }
                        else {
                            loader.sourceComponent = videooutputcamera;
                        }
                    }
                    else {
                        videooutputvideo.visible = true;
                        loader.item.camera.stop();
                    }
                }
            }
        }
    }
}
