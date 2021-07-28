/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "imageitem.h"
#include <QSGSimpleTextureNode>
#include <QQuickWindow>

ImageItem::ImageItem(QQuickItem *parent):
    QQuickItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    setFlag(ItemHasContents, true);
}

ImageItem::~ImageItem()
{
}

QSGNode *ImageItem::updatePaintNode(QSGNode *node, QQuickItem::UpdatePaintNodeData *updateData)
{
    Q_UNUSED(updateData);
    QSGSimpleTextureNode *textureNode = static_cast<QSGSimpleTextureNode *>(node);
    if (!textureNode) {
        textureNode = new QSGSimpleTextureNode();
        QImage image(":/images/lady.png");
        m_texture = window()->createTextureFromImage(image);
        textureNode->setTexture(m_texture);
        textureNode->setFiltering(QSGTexture::Linear);
    }
    textureNode->setRect(boundingRect());

    return textureNode;
}
