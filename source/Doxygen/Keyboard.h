//Klasse 'Keyboard', um abzufragen, ob ein Zeichen eingegeben wurde
// (Funktion "keypressed()") und um Einzelzeichen (ohne Eingabe von
// 'Return') einzulesen.
// Fuer Cygwin und Unix-Umgebungen (Linux etc.).
// Nur mit Cygwin getestet.
// Entspricht in etwa 'conio.h' von Microsoft.

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

class Keyboard
{
private:
	static int _anzObjs;
public:
	Keyboard();
	~Keyboard();
	bool keypressed();
	int getch();
};

#endif /* KEYBOARD_H_ */
