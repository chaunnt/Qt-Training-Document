/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef KEYSXMLWRITER_H
#define KEYSXMLWRITER_H

#include <QtCore>

class KeyEngine;

class KeysXmlWriter : public QXmlStreamWriter
{
public:
    KeysXmlWriter(KeyEngine *engine);
    bool write();
private:
    KeyEngine *m_input;
};

#endif // KEYSXMLWRITER_H
