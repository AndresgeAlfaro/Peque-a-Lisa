#ifndef PILAPRODUCTOS_H
#define PILAPRODUCTOS_H

#include "Producto.h"
#include "NodoProducto.h"

class PilaProductos{
public:
	void pushProducto(Producto*);
	Producto popProducto();
	Producto buscarPorId(int);
	int buscarPorTipo();

private:
	NodoProducto* top;
	std::string tipo;

};

#endif