/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtCore>

#include "keyengine.h"
#include "keysxmlreader.h"
#include "keysxmlwriter.h"


/*
    XML Keys Format

    <?xml version="1.0" encoding="UTF-8"?>
    <keys version="1.0">
        <item key="Key-0">Value-0</item>
        <item key="Key-1">Value-1</item>
        ...
        <item key="Key-9">Value-9</item>
    </keys>

*/

void writeKeys(KeyEngine *engine)
{
    QFile file("keys.xml");
    if(!file.open(QIODevice::WriteOnly)) {
        qDebug() << "error writing files" << file.errorString();
        return;
    }

    KeysXmlWriter writer(engine);
    writer.setDevice(&file);
    if(!writer.write()) {
        qDebug() << "error writing xml";
    }
}

void readKeys(KeyEngine *engine)
{
    QFile file("keys.xml");
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error reading file " << file.errorString();
        return;
    }

    KeysXmlReader reader(engine);
    reader.setDevice(&file);
    if(!reader.read()) {
        qDebug() << "error reading xml: " << reader.errorString();
    }

    file.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    KeyEngine *engine = new KeyEngine(&app);

    for (int i=0; i<10; i++) {
        QString key = QString("Key-%1").arg(i);
        QString value = QString("Value-%1").arg(i);
        engine->setValue(key, value);
    }

    writeKeys(engine);

    // Delete old engine
    delete engine;
    engine = 0;

    // create new engine for testing
    engine = new KeyEngine(QCoreApplication::instance());

    readKeys(engine);

    // Test the Outcome

    if(engine->keys().count() != 10) {
        qDebug() << "Wrong number of keys";
    }
    engine->dump();
//    Outcome should be ...
//
//    Dump KeyEngine Data
//    10  keys

//    "Key-0"  :  "Value-0"
//    "Key-1"  :  "Value-1"
//    ...
//    "Key-9"  :  "Value-9"

    return 0;
}
