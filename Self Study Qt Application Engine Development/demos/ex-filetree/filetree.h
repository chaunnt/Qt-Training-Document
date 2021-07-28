/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include <QtCore/QVector>
#include <QtXmlPatterns/QSimpleXmlNodeModel>

class FileTree : public QSimpleXmlNodeModel
{
public:
    FileTree(const QXmlNamePool &namePool);

    QXmlNodeModelIndex nodeFor(const QString &fileName) const;

    QXmlNodeModelIndex::DocumentOrder compareOrder(const QXmlNodeModelIndex&, const QXmlNodeModelIndex&) const Q_DECL_OVERRIDE;
    QXmlName name(const QXmlNodeModelIndex &node) const Q_DECL_OVERRIDE;
    QUrl documentUri(const QXmlNodeModelIndex &node) const Q_DECL_OVERRIDE;
    QXmlNodeModelIndex::NodeKind kind(const QXmlNodeModelIndex &node) const Q_DECL_OVERRIDE;
    QXmlNodeModelIndex root(const QXmlNodeModelIndex &node) const Q_DECL_OVERRIDE;
    QVariant typedValue(const QXmlNodeModelIndex &node) const Q_DECL_OVERRIDE;
protected:
    QVector<QXmlNodeModelIndex> attributes(const QXmlNodeModelIndex &element) const Q_DECL_OVERRIDE;
    QXmlNodeModelIndex nextFromSimpleAxis(SimpleAxis, const QXmlNodeModelIndex&) const Q_DECL_OVERRIDE;

private:
    enum Type {
        File,
        Directory,
        AttributeFileName,
        AttributeFilePath,
        AttributeSize,
        AttributeMIMEType,
        AttributeSuffix
    };

    inline QXmlNodeModelIndex nextSibling(const QXmlNodeModelIndex &nodeIndex,
                                          const QFileInfo &from,
                                          qint8 offset) const;
    inline const QFileInfo &toFileInfo(const QXmlNodeModelIndex &index) const;
    inline QXmlNodeModelIndex toNodeIndex(const QFileInfo &index,
                                          Type attributeName) const;
    inline QXmlNodeModelIndex toNodeIndex(const QFileInfo &index) const;

    /*
     One possible improvement is to use a hash, and use the &*&value()
     trick to get a pointer, which would be stored in data() instead
     of the index.
    */
    mutable QVector<QFileInfo>  m_fileInfos;
    const QDir::Filters         m_filterAllowAll;
    const QDir::SortFlags       m_sortFlags;
    QVector<QXmlName>           m_names;
};
