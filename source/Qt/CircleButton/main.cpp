//Circlebutton main.cpp
#include <QtWidgets>
#include "CircleButton.h"
#include "Demo1CircleButton.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    Demo1CircleButton demo1Window;
    demo1Window.move(100, 100);

    demo1Window.show();
    return app.exec();
}
