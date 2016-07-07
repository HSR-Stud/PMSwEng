#include <QtGui>

int main(int argc, char **argv)
{
	QApplication app(argc, argv); 								// eine neue Instanz von QApplication
	QWidget *window = new QWidget(); 								// eine neue Instanz von QWidget
	QLabel *label = new QLabel("Hello World!");		// Ein Label mit einem Text erzeugen
	app.setMainWidget(window);											// window wird zum Haupfenster der Applikation "app"
	window->show(); 															// Anzeigen des Fensters
	return app.exec(); 															// Ausführen der Applikation
}
