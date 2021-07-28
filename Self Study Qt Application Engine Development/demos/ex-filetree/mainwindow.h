/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include <QXmlNamePool>

#include "filetree.h"
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, private Ui_MainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void on_actionOpenDirectory_triggered();
    void on_actionAbout_triggered();
    void on_queryBox_currentIndexChanged(const QString &);

private:
    void loadDirectory(const QString &directory);
    void evaluateResult();

    const QXmlNamePool  m_namePool;
    const FileTree      m_fileTree;
    QXmlNodeModelIndex  m_fileNode;
};
#endif
