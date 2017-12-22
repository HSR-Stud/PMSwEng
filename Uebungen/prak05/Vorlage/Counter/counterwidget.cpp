#include "counterwidget.h"
#include "ui_counterwidget.h"

CounterWidget::CounterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CounterWidget)
{
    ui->setupUi(this);

    // **** Interaktives Verhalten initialisieren:
    connect(ui->incButton, &QPushButton::clicked, &counter, &Counter::incValue);
    connect(ui->decButton, &QPushButton::clicked, &counter, &Counter::decValue);
    connect(ui->resetButton, &QPushButton::clicked, &counter, &Counter::clearValue);

    connect(&counter, &Counter::valueChanged ,ui->countLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
}

CounterWidget::~CounterWidget()
{
    delete ui;
}
