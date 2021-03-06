// main.cpp zur Demonstration der vorhersehbaren Fehler

#include <iostream>
#include "Polygonline.hpp"
using namespace std;

bool debugConstructor = false;

// unsigned int ObjectCounter::maxId = 0;
// unsigned int ObjectCounter::number = 0;

int main() {
	// Punkt erstellen und Infos ausgeben
	Point p;  // Const weggeschummelt ;-)
	cout << "maxId = " << ObjectCounter::getMaxId() << endl;
	cout << "ID von p = " << p.getId() << endl;
	// ID von p unerlaubt �ndern
	*(((int*)(&p))+1) = ObjectCounter::getMaxId() + 10;
	// Punkt ausgeben
	try {
		cout << "ID von p = " << p.getId() << endl;
		p.print();
	}
	catch (DrawingObject::IdTooHigh &e){
		e.printException();

	}
	// Polygonline erstellen und ausgeben
	Polygonline pl;
	pl.addPoint(Point(1, 1));
	pl.addPoint(Point(2, 2));
	pl.addPoint(Point(3, 3));
	pl.addPoint(Point(4, 4));
	pl.print();
	// Polygonline unerlaubt �ndern
	PlgElement * first = (PlgElement *)(*((int*)(&pl) + 2));
	PlgElement * last = (PlgElement *)(*((int*)(&pl) + 3));
	last->setNext(first);
	// Polygonline ausgeben
	try {
		pl.print();
	}
	catch (Polygonline::LoopInLine &e){
		e.printException();
	}

	catch (DrawingObject::GraphException& e){
		// Meldung ausgeben
	}

	cin.get();
	return 0;
}
