#ifndef NODORUTA_H
#define NODORUTA_H

#include "RutaDistribucion.h"

class NodoRuta{
public:
	NodoRuta(RutaDistribucion*);
	RutaDistribucion* getData();
	NodoRuta* getNext();
	NodoRuta* getPrev();
	void setNext(NodoRuta*);
	void setPrev(NodoRuta*);
	void setData(RutaDistribucion*);

private:
	RutaDistribucion* data;
	NodoRuta* next;
	NodoRuta* prev;
};

#endif