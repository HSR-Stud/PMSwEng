/**
 * Klasse 'Keyboard', um abzufragen, ob ein Zeichen eingegeben wurde
 * (Funktion "keypressed()") und um Einzelzeichen (ohne Eingabe von
 * 'Return') einzulesen.
 * Fuer Cygwin und Unix-Umgebungen (Linux etc.).
 * Nur mit Cygwin getestet.
 * Entspricht in etwa 'conio.h' von Microsoft.
 * @file Keyboard.cpp
 * @author H. Pletscher
 * @date  5.4.201
 * @version 1.0
 */
//=================================================================
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>

#include "Keyboard.h"

//=================================================================
static void init_keyboard();
static void close_keyboard();
static int kbhit();
static int readch();
//=================================================================
int Keyboard::_anzObjs;
//-----------------------------------------------------------------
Keyboard::Keyboard()
{
	if (_anzObjs == 0) init_keyboard();
	_anzObjs++;
}
//-----------------------------------------------------------------
Keyboard::~Keyboard()
{
	assert (_anzObjs > 0);
	_anzObjs--;
	if (_anzObjs == 0) close_keyboard();
}
//-----------------------------------------------------------------
bool Keyboard::keypressed()
{
	return kbhit();
}
//-----------------------------------------------------------------
int Keyboard::getch()
{
	return readch();
}
//=================================================================
static struct termios initial_settings, new_settings;
//-----------------------------------------------------------------
static void init_keyboard()
{
    tcgetattr(0, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;   // disable canonical mode
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}
//-----------------------------------------------------------------
static void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}
//-----------------------------------------------------------------
static int kbhit(void)
{
	struct timeval tv;
	fd_set read_fd;

	tv.tv_sec=0; tv.tv_usec=0;
	FD_ZERO(&read_fd);
	FD_SET(0, &read_fd);
	if(select(1, &read_fd,NULL, NULL, &tv) == -1) return 0; // Error

	if(FD_ISSET(0, &read_fd)) return 1;
	return 0;
}
//-----------------------------------------------------------------
static int readch()
{
    char ch;
    read(0, &ch, 1);
    return ch;
}
//-----------------------------------------------------------------
