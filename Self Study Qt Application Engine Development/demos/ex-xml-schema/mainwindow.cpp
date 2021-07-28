/*************************************************************************
 *
 * Copyright (c) 2016 The Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtXmlPatterns>

#include "mainwindow.h"
#include "xmlsyntaxhighlighter.h"

class MessageHandler : public QAbstractMessageHandler
{
public:
    MessageHandler()
        : QAbstractMessageHandler(0)
    {
    }

    QString statusMessage() const
    {
        return m_description;
    }

    int line() const
    {
        return m_sourceLocation.line();
    }

    int column() const
    {
        return m_sourceLocation.column();
    }

protected:
    void handleMessage(QtMsgType type, const QString &description,
                               const QUrl &identifier, const QSourceLocation &sourceLocation) Q_DECL_OVERRIDE
    {
        Q_UNUSED(type);
        Q_UNUSED(identifier);

        m_messageType = type;
        m_description = description;
        m_sourceLocation = sourceLocation;
    }

private:
    QtMsgType m_messageType;
    QString m_description;
    QSourceLocation m_sourceLocation;
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    new XmlSyntaxHighlighter(schemaView->document());
    new XmlSyntaxHighlighter(instanceEdit->document());

    schemaSelection->addItem(tr("Contact Schema"));
    schemaSelection->addItem(tr("Recipe Schema"));
    schemaSelection->addItem(tr("Order Schema"));

    instanceSelection->addItem(tr("Valid Contact Instance"));
    instanceSelection->addItem(tr("Invalid Contact Instance"));

    connect(schemaSelection, qOverload<int>(&QComboBox::currentIndexChanged), this, &MainWindow::schemaSelected);
    connect(instanceSelection, qOverload<int>(&QComboBox::currentIndexChanged), this, &MainWindow::instanceSelected);
    connect(validateButton, &QPushButton::clicked, this, &MainWindow::validate);
    connect(instanceEdit, &QTextEdit::textChanged, this, &MainWindow::textChanged);

    validationStatus->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    schemaSelected(0);
    instanceSelected(0);
}

void MainWindow::schemaSelected(int index)
{
    instanceSelection->clear();
    if (index == 0) {
        instanceSelection->addItem(tr("Valid Contact Instance"));
        instanceSelection->addItem(tr("Invalid Contact Instance"));
    } else if (index == 1) {
        instanceSelection->addItem(tr("Valid Recipe Instance"));
        instanceSelection->addItem(tr("Invalid Recipe Instance"));
    } else if (index == 2) {
        instanceSelection->addItem(tr("Valid Order Instance"));
        instanceSelection->addItem(tr("Invalid Order Instance"));
    }
    textChanged();

    QFile schemaFile(QString(":/schema_%1.xsd").arg(index));
    schemaFile.open(QIODevice::ReadOnly);
    const QString schemaText(QString::fromUtf8(schemaFile.readAll()));
    schemaView->setPlainText(schemaText);

    validate();
}

void MainWindow::instanceSelected(int index)
{
    if (index < 0)
        return;
    QFile instanceFile(QString(":/instance_%1.xml").arg((2*schemaSelection->currentIndex()) + index));
    instanceFile.open(QIODevice::ReadOnly);
    const QString instanceText(QString::fromUtf8(instanceFile.readAll()));
    instanceEdit->setPlainText(instanceText);

    validate();
}

void MainWindow::validate()
{
    const QByteArray schemaData = schemaView->toPlainText().toUtf8();
    const QByteArray instanceData = instanceEdit->toPlainText().toUtf8();

    MessageHandler messageHandler;

    QXmlSchema schema;
    schema.setMessageHandler(&messageHandler);

    schema.load(schemaData);

    bool errorOccurred = false;
    if (!schema.isValid()) {
        errorOccurred = true;
    } else {
        QXmlSchemaValidator validator(schema);
        if (!validator.validate(instanceData))
            errorOccurred = true;
    }

    if (errorOccurred) {
        validationStatus->setText(messageHandler.statusMessage());
        moveCursor(messageHandler.line(), messageHandler.column());
    } else {
        validationStatus->setText(tr("validation successful"));
    }

    const QString styleSheet = QString("QLabel {background: %1; padding: 3px}")
                                      .arg(errorOccurred ? QColor(Qt::red).lighter(160).name() :
                                                           QColor(Qt::green).lighter(160).name());
    validationStatus->setStyleSheet(styleSheet);
}

void MainWindow::textChanged()
{
    instanceEdit->setExtraSelections(QList<QTextEdit::ExtraSelection>());
}

void MainWindow::moveCursor(int line, int column)
{
    instanceEdit->moveCursor(QTextCursor::Start);
    for (int i = 1; i < line; ++i)
        instanceEdit->moveCursor(QTextCursor::Down);

    for (int i = 1; i < column; ++i)
        instanceEdit->moveCursor(QTextCursor::Right);

    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;

    const QColor lineColor = QColor(Qt::red).lighter(160);
    selection.format.setBackground(lineColor);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = instanceEdit->textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);

    instanceEdit->setExtraSelections(extraSelections);

    instanceEdit->setFocus();
}
