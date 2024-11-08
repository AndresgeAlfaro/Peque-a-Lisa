#include "RutaDistribucion.h"

RutaDistribucion::RutaDistribucion(int _id, std::string _distrito): idUbicacion(_id), nombreDistrito(_distrito), camiones(new ListaCamion()){}

void RutaDistribucion::agregarCamion(Camion* _camion){
	camiones->agregarCamion(_camion);
}

int RutaDistribucion::getId(){
	return idUbicacion;
}

std::string RutaDistribucion::toString(){
	std::stringstream s;
	s << "\n----------------------------\n"
		<< "ID ubicacion: " << idUbicacion
		<< "\nDistrito: " << nombreDistrito
		<< "\nCamiones Asociados:\n"
		<< camiones->imprimirLista()
		<< "\n----------------------------\n";

	return s.str();
}
