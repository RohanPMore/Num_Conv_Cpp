#include <QApplication>
#include "converter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Converter converter;
    converter.show();
    return app.exec();
}
