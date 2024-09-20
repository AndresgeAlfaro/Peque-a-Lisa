#ifndef CAMION_H
#define CAMION_H

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
	std::string mostrarProductosCamion();
	std::string toString();

};

#endif