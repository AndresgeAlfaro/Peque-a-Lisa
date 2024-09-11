#include "Camion.h"

Camion::Camion(int _id, std::string _conductor): idCamion(_id), conductor(_conductor){}

Camion::~Camion(){}

int Camion::getId(){
	return idCamion;
}

void Camion::agregarProducto(ProductoReciclado* _producto){

}

void Camion::eliminarProducto(ProductoReciclado* _producto){

}

ListaProductoReciclado Camion::listarProductos()
{
	return ListaProductoReciclado();
}

std::string Camion::toString(){
	std::stringstream s;
	s << "------------------------\n"
		<< "ID: " << idCamion
		<< "\nConductor: " << conductor
		<< "\n-----------------------\n";

	return std::string();
}
