#ifndef NODOPRODUCTORECICLADO_H
#define NODOPRODUCTORECICLADO_H

#include "ProductoReciclado.h"

class NodoProductoReciclado{
public:

	NodoProductoReciclado(ProductoReciclado*);
	~NodoProductoReciclado();

	ProductoReciclado* getData();
	NodoProductoReciclado* getNext();
	void setNext(NodoProductoReciclado*);

private:
	ProductoReciclado* data;
	NodoProductoReciclado* next;

};

#endif