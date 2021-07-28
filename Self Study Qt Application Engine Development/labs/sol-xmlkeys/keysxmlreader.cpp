/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "keysxmlreader.h"
#include "keyengine.h"

KeysXmlReader::KeysXmlReader(KeyEngine *input)
    : m_input(input)
{
}

bool KeysXmlReader::read()
{
    if(!m_input || !device()) {
        raiseError("No input object set");
    }
    if(readNextStartElement()) {
        if(name() == "keys" && attributes().value("version") == "1.0") {
            readKeys();
        } else {
            raiseError("This file is not a KEYS version 1.0 file");
        }
    }
    return !error();
}

void KeysXmlReader::readKeys()
{
    Q_ASSERT(isStartElement() && name() == "keys");
    while(readNextStartElement()) {
        if(name() == "item") {
            readItem();
        } else {
            skipCurrentElement();
        }

    }
}

void KeysXmlReader::readItem()
{
    Q_ASSERT(isStartElement() && name() == "item");
    QString key = attributes().value("key").toString();
    QString value = readElementText();
    if(key.isEmpty() || value.isEmpty()) {
        qDebug() << "item skipped. Ignoring item if key or value is empty";
        return;
    }
    m_input->setValue(key, value);
}

