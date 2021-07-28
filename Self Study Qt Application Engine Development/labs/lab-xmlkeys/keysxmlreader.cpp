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
    return !error();
}
