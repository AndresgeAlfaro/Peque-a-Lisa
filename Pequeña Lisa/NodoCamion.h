#ifndef NODOCAMION_H
#define NODOCAMION_H

#include "Camion.h"

class NodoCamion{
public:
	NodoCamion(Camion*);
	Camion* getData();
	NodoCamion* getNext();
	void setNext(NodoCamion*);
	void setData(Camion*);

private:
	Camion* data;
	NodoCamion* next;

};

#endif