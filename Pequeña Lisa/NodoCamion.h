#ifndef NODOCAMION_H
#define NODOCAMION_H

#include "Camion.h"

class NodoCamion{
public:
	Camion* getData();
	NodoCamion* getNext();
	void setSiguiente(NodoCamion*);

private:
	Camion* data;
	NodoCamion* next;

};

#endif