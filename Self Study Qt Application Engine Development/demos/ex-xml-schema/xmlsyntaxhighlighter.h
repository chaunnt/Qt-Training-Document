/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef XMLSYNTAXHIGHLIGHTER_H
#define XMLSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegExp>

class XmlSyntaxHighlighter : public QSyntaxHighlighter
{
    public:
        XmlSyntaxHighlighter(QTextDocument *parent = Q_NULLPTR);

    protected:
        void highlightBlock(const QString &text) Q_DECL_OVERRIDE;

    private:
        struct HighlightingRule
        {
            QRegExp pattern;
            QTextCharFormat format;
        };
        QVector<HighlightingRule> highlightingRules;

        QRegExp commentStartExpression;
        QRegExp commentEndExpression;

        QTextCharFormat tagFormat;
        QTextCharFormat attributeFormat;
        QTextCharFormat attributeContentFormat;
        QTextCharFormat commentFormat;
};

#endif
