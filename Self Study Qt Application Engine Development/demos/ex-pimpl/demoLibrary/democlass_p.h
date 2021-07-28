/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef DEMOCLASS_P_H
#define DEMOCLASS_P_H

#include <qglobal.h> // For QT_FORWARD_DECLARE_CLASS

QT_FORWARD_DECLARE_CLASS(DemoClass)

class DemoClassPrivate
{
    // Attributes may be public as they are used by the public class only
    // Or declare the private class as friend of the public class
public: // Attributes
    int m_intMember;

    DemoClass *q; // To access the public class if needed

public:
    DemoClassPrivate(DemoClass *demoClass);
    ~DemoClassPrivate();
};

#endif // DEMOCLASS_P_H
