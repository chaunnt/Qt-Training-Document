/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "keysxmlwriter.h"

#include "keyengine.h"

KeysXmlWriter::KeysXmlWriter(KeyEngine *input)
    : m_input(input)
{
    setAutoFormatting(true);
}

bool KeysXmlWriter::write()
{
    if(!m_input || !device()) {
        return false;
    }
    writeStartDocument();
    writeStartElement("keys");
    writeAttribute("version", "1.0");
    foreach(const QString &key, m_input->keys()) {
        writeItem(key);
    }
    writeEndElement();
    writeEndDocument();
    return true;
}

void KeysXmlWriter::writeItem(const QString &key)
{
    writeStartElement("item");
    writeAttribute("key", key);
    writeCharacters(m_input->value(key));
    writeEndElement();
}
