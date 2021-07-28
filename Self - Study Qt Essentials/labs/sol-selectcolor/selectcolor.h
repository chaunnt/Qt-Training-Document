/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef SELECTCOLOR_H
#define SELECTCOLOR_H

#include <QtWidgets>

class QLabel;

class SelectColor : public QWidget
{
public:
    SelectColor(QWidget *parent = 0);

private:
    void showColorSelector();

    QLabel *m_label;
};

#endif // SELECTCOLOR_H
