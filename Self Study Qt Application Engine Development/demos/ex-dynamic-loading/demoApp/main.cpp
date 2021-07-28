/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QLibrary>
#include <QDebug>

int main(int, char *[])
{
    QLibrary library("simpleLibrary"); // Or use absolute path

    typedef double (*PowerFunction)(int, int);

    // Resolves calls load() automatically
    PowerFunction power = (PowerFunction) library.resolve("pow");
    if (power) {
        qDebug() << "Library:" << library.fileName() << "successfully loaded";
        qDebug() << power(5, -3);
        qDebug() << "Library unload" << (library.unload() ? "succeeded" : "failed");
    }
    else
        qDebug() << "Library load failed:" << library.errorString();

    return EXIT_SUCCESS;
}
