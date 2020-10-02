/**
 * @class Keyboard
 * @brief Verfügbarkeit von Eingaben prüfen und Zeichen lesen
 *
 * Erlaubt es abzufragen, ob ein Zeichen eingegeben wurde
 * (Funktion "keypressed()") und um Einzelzeichen (ohne Eingabe von
 * 'Return') einzulesen.
 *
 * Für Cygwin und Unix-Umgebungen (Linux etc.).
 *
 * Nur mit Cygwin getestet.
 *
 * Entspricht in etwa 'conio.h' von Microsoft.
 * @file Keyboard.h
 * @author H. Pletscher
 * @date  5.4.2010
 * @version 1.0
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

class Keyboard
{
private:
	static int _anzObjs;
public:
	/**
	* Pseudo-Constructor: Kapselt die Tastatur, so dass mit Objektmethoden
	* darauf zugegriffen werden kann.
	*
	* Die Tastatur ist eine Ressource, die nicht angelegt werden kann.
	* Der erste Konstruktor-Aufruf initialisiert die Tastatur, alle weiteren
	* werden nur registriert (Keyboard-Usage-Zähler, für die korrekte Funktion
	* des Destruktors).
	*/
	Keyboard();

	/**
	* Destructor: Der Keyboard-Usage-Zähler wird reduziert, und wenn die
	* Tastatur nicht mehr gebraucht wird, wird die Tastatur "geschlossen".
	*/
	~Keyboard();

	/**
	* Prüft, ob eine Taste gedruckt wurde, so dass getch() ohne zu blocken
	* aufgerufen werden kann.
	* @return 1 wenn Zeichen verfügbar, 0 wenn keine Taste gedrückt wurde,
	* -1 bei Fehler.
	*/
	bool keypressed();

	/**
	* Liest das nächste zeichen.
	* @return Code des Zeichen.
	*/
	int getch();
};

#endif /* KEYBOARD_H_ */
