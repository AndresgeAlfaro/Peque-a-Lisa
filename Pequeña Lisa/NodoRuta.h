#ifndef NODORUTA_H
#define NODORUTA_H

#include "RutaDistribucion.h"

class NodoRuta{
public:
	RutaDistribucion* getData();
	NodoRuta* getNext();
	void setSiguiente(NodoRuta*);

private:
	RutaDistribucion* data;
	NodoRuta* next;
};

#endif