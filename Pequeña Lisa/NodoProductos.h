#ifndef NODOPRODUCTOS_H
#define NODOPRODUCTOS_H

#include "Producto.h"

class NodoProductos {

public:

	NodoProductos(Producto*);
	~NodoProductos();

	Producto* getProducto()const;
	void setProducto(Producto*);

	NodoProductos* getSiguiente()const;
	void setSiguiente(NodoProductos*);

	std::string toString()const;

private:

	Producto* producto;
	NodoProductos* siguiente;

};

#endif // !NODOPRODUCTOS_H

