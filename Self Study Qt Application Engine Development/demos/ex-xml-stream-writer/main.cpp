/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include <QtXml>

int main(int, char *[])
{
    QFile file("animals.xml");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qFatal("Unable to open file animals.xml: %s", qPrintable(file.errorString()));

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("animals");
    writer.writeStartElement("mammals");
    writer.writeStartElement("monkeys");
    writer.writeEmptyElement("gorilla");
    writer.writeEmptyElement("orang-utan");
    writer.writeEndElement(); // end monkeys
    writer.writeEndElement(); // end mammals
    writer.writeStartElement("birds");
    writer.writeEmptyElement("pigion");
    writer.writeEmptyElement("penguin");
    writer.writeEndDocument(); // Closes all open elements.
}
