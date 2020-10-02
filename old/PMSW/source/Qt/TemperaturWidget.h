//TemperaturWidget TemperaturWidget.h
#ifndef TEMPERATURWIDGET_H
#define TEMPERATURWIDGET_H
#include <QtWidgets>
class TemperaturWidget : public QWidget
{
private:
    Q_OBJECT
private:    // **** GUI-Stuff:
    QGridLayout * mainLayout;
    QLabel *label1, *label2, *label3;
    QLineEdit *eingabeLineEdit, *resultLineEdit;
    QGroupBox *groupBox;

    QHBoxLayout * boxLayout;
    QRadioButton * tCelsiusButton, * tFahrenheitButton;

    QPushButton * rechneButton;
public:
    TemperaturWidget(QWidget * parent = 0);
private slots:
    void rechne();
};
#endif // MYDIALOG_H
