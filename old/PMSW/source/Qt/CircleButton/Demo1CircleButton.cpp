//Circlebutton Demo1CircleButton.cpp
#include "Demo1CircleButton.h"

Demo1CircleButton::Demo1CircleButton(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Demo 1");
    layout = new QVBoxLayout(this);

    circleButton = new CircleButton("Start");
    layout->addWidget(circleButton);

    QObject::connect(circleButton, SIGNAL(clicked() ),
                     this, SLOT(onClicked() ) );
}
void Demo1CircleButton::onClicked()
{
    if (circleButton->isRotating() )
    {
        circleButton->setRotating(false);
        circleButton->setText("Start");
    }
    else
    {
        circleButton->setRotating(true);
        circleButton->setText("Stop");
    }
}
