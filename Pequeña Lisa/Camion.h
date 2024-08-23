#ifndef CAMION_H
#define CAMION_H

#include <string>
#include "ProductoReciclado.h"
#include "ListaProductoReciclado.h"

class Camion{
public:
	int idCamion;
	std::string conductor;
	ListaProductoReciclado productos;

private:
	Camion(int, std::string);
	virtual ~Camion();
	void agregarProducto(ProductoReciclado*);
	void eliminarProducto(ProductoReciclado*);
	ListaProductoReciclado listarProductos();

};

#endif