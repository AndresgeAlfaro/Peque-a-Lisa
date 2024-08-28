#ifndef PILAPRODUCTOS_H
#define PILAPRODUCTOS_H

#include "NodoProductos.h"

class PilaProductos
{
public:

	PilaProductos();
	~PilaProductos();

	bool estaVacio()const;
	void pushProducto(Producto);
	void popProducto();

	Producto buscarPorID(int);
	Producto buscarPorTipo(std::string);

	Producto obtenerCima()const;
	int contarProductos()const;

	void eliminarProductosNoReciclables();

	std::string imprimirPila()const;

private:

	NodoProductos* top;

};

#endif // !PILAPRODUCTOS_H

