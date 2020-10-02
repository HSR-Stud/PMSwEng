//countermain2.cpp counter in mehreren Files
#include <QtWidgets>
#include "mydialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyDialog windowTop(0);

    windowTop.show();
    return app.exec();
}
