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
#include "DrawingObject.hpp"
#include <iostream>

// Konstruktor, Destruktor
DrawingObject::DrawingObject() : ObjectCounter(){
	// std::cout << std::endl << "Konstruktor der Klasse DrawingObject, ObjectID: " << getId() << std::endl;

}
DrawingObject::~DrawingObject(){
	// std::cout << std::endl << "Destruktor der Klasse DrawingObject, ObjectID: " << getId() << std::endl;
}

void DrawingObject::print(bool = false)const{

};

// Aufruf über this->check(this->gehtId());
void DrawingObject::check(int oId)const{

	if (oId > ObjectCounter::getMaxId()){
		// Ausnahme typ IdTooHigh werfen
		throw IdTooHigh(oId);
	}
};

// Konstruktor GraphException
DrawingObject::GraphException::GraphException(const int oId) : id(oId){};

// Konstruktor IdTooHighException
DrawingObject::IdTooHigh::IdTooHigh(int oId): GraphException(oId){};

// Mthoden der IdTooHighException
int DrawingObject::IdTooHigh::getId(){ return this->getId(); };
void DrawingObject::IdTooHigh::printException(){
	std::cout << "Die ID " << this->getEId() << " ist zu hoch! (MaxId ist " << DrawingObject::getMaxId() << ")" << std::endl;
};

// Methoden der GraphException Methoden
int DrawingObject::GraphException::getEId(){ return this->id; };



