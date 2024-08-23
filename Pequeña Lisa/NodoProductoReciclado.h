#ifndef NODOPRODUCTORECICLADO_H
#define NODOPRODUCTORECICLADO_H

#include "ProductoReciclado.h"

class NodoProductoReciclado{
public:
	ProductoReciclado* getData();
	NodoProductoReciclado* getNext();
	void setNext();

private:
	ProductoReciclado* data;
	NodoProductoReciclado* next;

};

#endif