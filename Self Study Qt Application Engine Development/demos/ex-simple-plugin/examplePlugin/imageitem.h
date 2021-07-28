/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef IMAGEITEM_H
#define IMAGEITEM_H

#include <QQuickItem>

QT_FORWARD_DECLARE_CLASS(QSGTexture)

class ImageItem : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(ImageItem)

public:
    ImageItem(QQuickItem *parent = 0);
    ~ImageItem();

protected:
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *);

private:
    QSGTexture *m_texture;
};

#endif // IMAGEITEM_H
