/* Uebungen zu OOP, Aufgabe 2.3
Erstersteller: Jan Binder, Matthias Geckeler, Thomas Günter
E-Mail: jabi00@hs-esslingen.de, matthias.geckeler@stud.hs-esslinge.de, Thomas.Guenter@stud.hs-esslingen.de

Datum: 03.06.2015
Version: 1.0
Zeitaufwand: 0,5h

Aenderungshistorie:
-------------------
Durchgefuehrte Aenderung | Autor | Datum


-------------------------------------------------------
Programmbeschreibung:
---------------------
*/

#pragma once
#include"objectCounter.hpp"

class DrawingObject : public ObjectCounter {
public:
	// Konstruktoren und Destruktor
	DrawingObject();
	~DrawingObject();

	// Instaznmethoden
	virtual void print(bool)const;
	void check(int)const;

	// Interne Klassen
	class GraphException {
	public:	
		// Variablen
		const int id;

		// Konstruktoren
		GraphException(const int);

		//Set und Get
		int getEId();
	};

	class IdTooHigh : public GraphException{
	public:
		// Konstruktoren
		IdTooHigh(int);

		// Instanzmethoden
		int getId();
		void printException();
	};
};