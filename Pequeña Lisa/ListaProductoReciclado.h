#ifndef LISTAPRODUCTORECICLADO_H
#define LISTAPRODUCTORECICLADO_H

#include "NodoProductoReciclado.h"

class ListaProductoReciclado{
public:
	ListaProductoReciclado();
	~ListaProductoReciclado();
	void agregar(ProductoReciclado*);
	std::string mostrarProductosReciclados() const;

private:
	NodoProductoReciclado* head;

};

#endif