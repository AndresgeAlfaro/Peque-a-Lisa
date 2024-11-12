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
		<<productos.mostrarProductosReciclados()
		<< "\n" << mostrarRuta()
		<< "\n-----------------------\n";

	return s.str();
}

void Camion::asignarRuta(const std::vector<NodoGrafo*>& _rutaAsignada){
	this->rutaAsignada = _rutaAsignada;
}

std::string Camion::mostrarRuta(){
	std::stringstream s;
	s << "Ruta Asignada:\n";
	for (const auto& nodo : rutaAsignada) {
		s << nodo->getNombre() << " - " << nodo->getUbicacion() << "\n";
	}
	return s.str();
}

void Camion::ejecutarRuta() {
	for (NodoGrafo* nodo : rutaAsignada) {
		std::cout << "Visitando nodo: " << nodo->getNombre() << " - " << nodo->getUbicacion() << std::endl;
		arbolRutas.insertar(nodo);
	}

	arbolRutas.mostrar();
}
