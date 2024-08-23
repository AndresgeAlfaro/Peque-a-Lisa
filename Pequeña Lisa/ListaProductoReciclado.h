#ifndef LISTAPRODUCTORECICLADO_H
#define LISTAPRODUCTORECICLADO_H

#include "NodoProductoReciclado.h"

class ListaProductoReciclado{
public:
	void agregar(ProductoReciclado*);
	void obtenerProducto(int);
	void eliminar(int);

private:
	NodoProductoReciclado* head;

};

#endif