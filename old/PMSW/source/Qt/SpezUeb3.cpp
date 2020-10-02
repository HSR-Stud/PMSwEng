#include <QtWidgets>

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    QDialog mainWindow;

    mainWindow.setWindowTitle("Signals and Slots");
    QVBoxLayout * layout = new QVBoxLayout(& mainWindow);

    QLabel * label = new QLabel("0");
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);
    QSpinBox * spinBox = new QSpinBox;
    layout->addWidget(spinBox);
    QSlider * slider = new QSlider(Qt::Horizontal);
    layout->addWidget(slider);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), label,
                              SLOT(setNum(int)) );
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider,
                              SLOT(setValue(int)) );
    QObject::connect(slider,  SIGNAL(valueChanged(int)), label,
                              SLOT(setNum(int)) );
    QObject::connect(slider,  SIGNAL(valueChanged(int)), spinBox,
                              SLOT(setValue(int)) );

    mainWindow.show();
    return app.exec();
}
