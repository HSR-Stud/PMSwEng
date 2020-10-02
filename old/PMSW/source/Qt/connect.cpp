//****  Qt4 Notation
QObject::connect( buDec, SIGNAL(clicked()), &counter, SLOT(decValue()));
QObject::connect( &counter, SIGNAL(valueChanged(int)), laCount, SLOT(setNum(int)) );

//****  Funktionspointer ab Qt5
connect( button, &QPushButton::clicked count, &Counter::incValue );

//****  Globaler Funktion ab Qt5
connect( button, &QPushButton::clicked, &printValue );