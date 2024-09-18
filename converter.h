#ifndef CONVERTER_H
#define CONVERTER_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class Converter : public QWidget
{
    Q_OBJECT

public:
    Converter(QWidget *parent = nullptr);

private slots:
    void convert();

private:
    QLineEdit *inputField;
    QComboBox *inputType;
    QComboBox *outputType;
    QLabel *resultLabel;

    QString convertFromBase(const QString &input, int baseFrom, int baseTo);
    bool validateInput(const QString &input, int base);
};

#endif // CONVERTER_H
