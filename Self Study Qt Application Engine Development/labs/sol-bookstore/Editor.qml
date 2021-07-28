/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.8
import QtQuick.Controls 2.0

TextField {
    wrapMode: Text.WordWrap
    onActiveFocusChanged: {
        if (focus) {
            listView.currentIndex = index;
            focus = true;
        }
    }
}
