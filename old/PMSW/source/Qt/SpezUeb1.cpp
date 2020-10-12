#include <QtWidgets>

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    QDialog mainWindow;
    mainWindow.setWindowTitle("-- Test --");
    QGridLayout * layout = new QGridLayout();
    mainWindow.setLayout(layout);

    QPushButton * bu1 = new QPushButton("Button 1");
    layout->addWidget(bu1, 0, 0, 1, 2);
    QLabel * la1 = new QLabel("Label 1");
    la1->setAlignment(Qt::AlignCenter);
    layout->addWidget(la1, 0, 2);
    QPushButton * bu2 = new QPushButton("Button 2");
    layout->addWidget(bu2, 1, 1);

    QVBoxLayout * lout2 = new QVBoxLayout;
    layout->addLayout(lout2, 1, 0);
    QPushButton * bu3 = new QPushButton("Button 3");
    lout2->addWidget(bu3);
    QPushButton * bu4 = new QPushButton("Button 4");
    lout2->addWidget(bu4);

    mainWindow.show();
    return app.exec();
}
