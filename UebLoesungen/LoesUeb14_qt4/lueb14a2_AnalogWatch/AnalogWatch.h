#ifndef ANALOGWATCH_H
#define ANALOGWATCH_H

#include <QWidget>
#include <QTimer>

class AnalogWatch : public QWidget
{
    Q_OBJECT
private:
    QTimer *_timer;

public:
    AnalogWatch(QWidget *parent = 0, Qt::WindowFlags f = 0);

protected:
    void paintEvent(QPaintEvent *event);
};
#endif
