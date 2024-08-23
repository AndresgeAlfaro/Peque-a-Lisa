#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_h

#include "Producto.h"

class NodoProducto{
public:
	Producto* getData();
	NodoProducto* getNext();
	void setSiguiente(NodoProducto*);

private:
	Producto* data;
	NodoProducto* next;

};

#endif