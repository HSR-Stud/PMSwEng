#ifndef COUNTERWIDGET_H
#define COUNTERWIDGET_H

#include <QWidget>
#include "counter.h"

namespace Ui {
class CounterWidget;
}

class CounterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CounterWidget(QWidget *parent = 0);
    ~CounterWidget();

private:
    Ui::CounterWidget *ui;
    Counter counter;
};

#endif // COUNTERWIDGET_H
