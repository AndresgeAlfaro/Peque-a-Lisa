#include "Camion.h"

Camion::Camion(int _id, std::string _conductor): idCamion(_id), conductor(_conductor){}

Camion::~Camion(){}

void Camion::agregarProducto(ProductoReciclado* _producto){

}

void Camion::eliminarProducto(ProductoReciclado* _producto){

}

ListaProductoReciclado Camion::listarProductos()
{
	return ListaProductoReciclado();
}
