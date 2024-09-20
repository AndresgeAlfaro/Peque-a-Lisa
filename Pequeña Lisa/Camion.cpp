#include "Camion.h"

Camion::Camion(int _id, std::string _conductor): idCamion(_id), conductor(_conductor){}

Camion::~Camion(){}

int Camion::getId(){
	return idCamion;
}

void Camion::agregarProducto(ProductoReciclado* _producto){
	productos.agregar(_producto);
}

std::string Camion::mostrarProductosCamion(){
	return productos.mostrarProductosReciclados();
}


std::string Camion::toString(){
	std::stringstream s;
	s << "------------------------\n"
		<< "ID: " << idCamion
		<< "\nConductor: " << conductor
		<< "\n-----------------------\n";

	return std::string();
}
