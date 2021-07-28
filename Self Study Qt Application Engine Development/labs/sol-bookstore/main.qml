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

Window {
    width: 640
    height: 640
    minimumWidth: 200
    visible: true

    AuthorView {
        id: authorView
        anchors.top: parent.top
        height: parent.height / 2
        width: parent.width
        onAuthorChanged: {
            bookView.resetItemIndex();
        }
    }

    BookView {
        id: bookView
        width: parent.width
        anchors.top: authorView.bottom
        anchors.bottom: parent.bottom
        clip: true
    }
}
