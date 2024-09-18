#include "converter.h"
#include <QIntValidator>
#include <QMessageBox>

Converter::Converter(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Input field
    inputField = new QLineEdit(this);
    layout->addWidget(new QLabel("Enter Number:"));
    layout->addWidget(inputField);

    // Input type combo box
    inputType = new QComboBox(this);
    inputType->addItem("Decimal");
    inputType->addItem("Binary");
    inputType->addItem("Octal");
    inputType->addItem("Hexadecimal");
    layout->addWidget(new QLabel("Input Type:"));
    layout->addWidget(inputType);

    // Output type combo box
    outputType = new QComboBox(this);
    outputType->addItem("Decimal");
    outputType->addItem("Binary");
    outputType->addItem("Octal");
    outputType->addItem("Hexadecimal");
    layout->addWidget(new QLabel("Output Type:"));
    layout->addWidget(outputType);

    // Convert button
    QPushButton *convertButton = new QPushButton("Convert", this);
    layout->addWidget(convertButton);

    // Result label
    resultLabel = new QLabel(this);
    layout->addWidget(resultLabel);

    connect(convertButton, &QPushButton::clicked, this, &Converter::convert);
}

QString Converter::convertFromBase(const QString &input, int baseFrom, int baseTo)
{
    bool ok;
    long long number = input.toLongLong(&ok, baseFrom);
    if (!ok)
    {
        return "Invalid Input";
    }

    switch (baseTo)
    {
    case 10:
        return QString::number(number, 10);
    case 2:
        return QString::number(number, 2);
    case 8:
        return QString::number(number, 8);
    case 16:
        return QString::number(number, 16).toUpper();
    default:
        return "Invalid Output Base";
    }
}

bool Converter::validateInput(const QString &input, int base)
{
    bool ok;
    input.toLongLong(&ok, base);
    return ok;
}

void Converter::convert()
{
    QString input = inputField->text();
    int baseFrom = 10, baseTo = 10;

    switch (inputType->currentIndex())
    {
    case 0:
        baseFrom = 10; // Decimal
        break;
    case 1:
        baseFrom = 2; // Binary
        break;
    case 2:
        baseFrom = 8; // Octal
        break;
    case 3:
        baseFrom = 16; // Hexadecimal
        break;
    }

    switch (outputType->currentIndex())
    {
    case 0:
        baseTo = 10; // Decimal
        break;
    case 1:
        baseTo = 2; // Binary
        break;
    case 2:
        baseTo = 8; // Octal
        break;
    case 3:
        baseTo = 16; // Hexadecimal
        break;
    }

    if (validateInput(input, baseFrom))
    {
        QString result = convertFromBase(input, baseFrom, baseTo);
        resultLabel->setText("Result: " + result);
    }
    else
    {
        resultLabel->setText("Invalid input for the selected format.");
    }
}
