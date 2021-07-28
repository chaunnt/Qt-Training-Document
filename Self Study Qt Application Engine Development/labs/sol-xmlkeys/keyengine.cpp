/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "keyengine.h"

KeyEngine::KeyEngine(QObject *parent) :
    QObject(parent)
{
}

void KeyEngine::setValue(const QString &key, const QString &value)
{
    m_data.insert(key, value);
    emit keysChanged(key);
}

QString KeyEngine::value(const QString &key) const
{
    return m_data.value(key);
}

QStringList KeyEngine::keys() const
{
    return m_data.keys();
}

bool KeyEngine::contains(const QString &key) const
{
    return m_data.contains(key);
}

void KeyEngine::remove(const QString &key)
{
    m_data.remove(key);
}

void KeyEngine::clear()
{
    m_data.clear();
    emit keysCleared();
}

void KeyEngine::dump()
{
    qDebug() << "Dump KeyEngine Data";
    qDebug() << keys().count() << " keys";
    qDebug();
    foreach(const QString& key, keys()) {
        qDebug() << key << " : " << value(key);
    }
}


