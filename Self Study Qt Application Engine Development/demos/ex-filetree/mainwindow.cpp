/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QFileDialog>
#include <QMessageBox>
#include <QLibraryInfo>
#include <QtXmlPatterns>

#include "mainwindow.h"
#include "xmlsyntaxhighlighter.h"

MainWindow::MainWindow() : m_fileTree(m_namePool)
{
    setupUi(this);

    new XmlSyntaxHighlighter(fileTree->document());

    // Set up the font.
    {
        QFont font("Courier",10);
        font.setFixedPitch(true);

        fileTree->setFont(font);
        queryEdit->setFont(font);
        output->setFont(font);
    }

    const QString dir("../filetree");
    qDebug() << dir;

    if (QDir(dir).exists())
        loadDirectory(dir);
    else
        fileTree->setPlainText(tr("Use the Open menu entry to select a directory."));

    const QStringList queries(QDir(":/queries/", "*.xq").entryList());
    int len = queries.count();

    for (int i = 0; i < len; ++i)
        queryBox->addItem(queries.at(i));

}

void MainWindow::on_queryBox_currentIndexChanged(const QString &currentText)
{
    QFile queryFile(":/queries/" + currentText);
    queryFile.open(QIODevice::ReadOnly);

    queryEdit->setPlainText(QString::fromLatin1(queryFile.readAll()));
    evaluateResult();
}

void MainWindow::evaluateResult()
{
    if (queryBox->currentText().isEmpty() || m_fileNode.isNull())
        return;

    QXmlQuery query(m_namePool);
    query.bindVariable("fileTree", m_fileNode);
    query.setQuery(QUrl("qrc:/queries/" + queryBox->currentText()));

    QByteArray formatterOutput;
    QBuffer buffer(&formatterOutput);
    buffer.open(QIODevice::WriteOnly);

    QXmlFormatter formatter(query, &buffer);
    query.evaluateTo(&formatter);

    output->setText(QString::fromLatin1(formatterOutput.constData()));
}

void MainWindow::on_actionOpenDirectory_triggered()
{
    const QString directoryName = QFileDialog::getExistingDirectory(this);
    if (!directoryName.isEmpty())
        loadDirectory(directoryName);
}

void MainWindow::loadDirectory(const QString &directory)
{
    Q_ASSERT(QDir(directory).exists());

    m_fileNode = m_fileTree.nodeFor(directory);

    QXmlQuery query(m_namePool);
    query.bindVariable("fileTree", m_fileNode);
    query.setQuery(QUrl("qrc:/queries/wholeTree.xq"));

    QByteArray output;
    QBuffer buffer(&output);
    buffer.open(QIODevice::WriteOnly);

    QXmlFormatter formatter(query, &buffer);
    query.evaluateTo(&formatter);

    treeInfo->setText(tr("Model of %1 output as XML.").arg(directory));
    fileTree->setText(QString::fromLatin1(output.constData()));
    evaluateResult();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About File Tree"),
                   tr("<p>Select <b>File->Open Directory</b> and "
                      "choose a directory. The directory is then "
                      "loaded into the model, and the model is "
                      "displayed on the left as XML.</p>"

                      "<p>From the query menu on the right, select "
                      "a query. The query is displayed and then run "
                      "on the model. The results are displayed below "
                      "the query.</p>"));
}


