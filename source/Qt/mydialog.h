//mydialog.h counter in mehreren Files
#ifndef MYDIALOG_H
#define MYDIALOG_H
#include "counter.h"
#include <QtWidgets>  // fuer Qt5

class MyDialog : public QDialog
{
    Q_OBJECT
private:
    Counter counter;
    QVBoxLayout *layoutTop;
    QPushButton * buDec;
    QPushButton * buInc;
    QLabel *laCount;

public:
    MyDialog(QWidget *parent = 0);
};

#endif // MYDIALOG_H
