#ifndef CAMION_H
#define CAMION_H

#include <sstream>
#include "ProductoReciclado.h"
#include "ListaProductoReciclado.h"

class Camion{
private:
	int idCamion;
	std::string conductor;
	ListaProductoReciclado productos;

public:
	Camion(int, std::string);
	virtual ~Camion();
	int getId();
	void agregarProducto(ProductoReciclado*);
	void eliminarProducto(ProductoReciclado*);
	ListaProductoReciclado listarProductos();
	std::string toString();

};

#endif