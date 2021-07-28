/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "exampleplugin_plugin.h"
#include "imageitem.h"

#include <qqml.h>

void ExamplePluginPlugin::registerTypes(const char *uri)
{
    // @uri com.theqtcompany.demoItems
    qmlRegisterType<ImageItem>(uri, 1, 0, "ImageItem");
}

