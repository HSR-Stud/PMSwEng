#include <QtWidgets>

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    QDialog mainWindow;

    mainWindow.setWindowTitle("Quiz");
    QGridLayout * layout = new QGridLayout(& mainWindow);

    QLabel * label1 = new QLabel("Wer wurde 2010 <br>Fussball-Weltmeister?");
    layout->addWidget(label1, 0, 0, 1, 2);

    QRadioButton * rbSchweiz = new QRadioButton("Schweiz");
    layout->addWidget(rbSchweiz, 1, 0);
    QRadioButton * rbSpanien = new QRadioButton("Spanien");
    layout->addWidget(rbSpanien, 1, 1);
    QRadioButton * rbItalien = new QRadioButton("Italien");
    layout->addWidget(rbItalien, 2, 0);
    QRadioButton * rbHolland = new QRadioButton("Holland");
    layout->addWidget(rbHolland, 2, 1);

    QPushButton * button = new QPushButton ("Absenden");
    layout->addWidget(button, 3, 0, 1, 2);

    QObject::connect(button, SIGNAL(clicked()),
                       qApp, SLOT( quit() ) );

    mainWindow.show();
return app.exec();
}