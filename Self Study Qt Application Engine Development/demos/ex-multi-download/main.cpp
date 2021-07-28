/*************************************************************************
 *
 * Copyright (c) 2016 Qt Group Plc.
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QFormLayout>
#include <qapplication.h>
#include "DownLoader.h"


int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QStringList list;
    list << "http://www.qt.io" << "http://www.thinkgeek.com/"
         << "http//broken.com/" << "http://slashdot.org/";

    DownLoader *downLoader = new DownLoader;
    Q_FOREACH(const QString &url, list)
        downLoader->load(url);

    downLoader->show();

    return app.exec();
}
