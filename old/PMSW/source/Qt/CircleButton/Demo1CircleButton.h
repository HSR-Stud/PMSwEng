//Circlebutton Demo1CircleButton.h
#ifndef DEMO1CIRCLEBUTTON_H
#define DEMO1CIRCLEBUTTON_H

#include <QWidget>
#include "CircleButton.h"

class Demo1CircleButton : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout * layout;
    CircleButton * circleButton;

public:
    explicit Demo1CircleButton(QWidget *parent = 0);

private slots:
    void onClicked();
};

#endif // DEMO1CIRCLEBUTTON_H
