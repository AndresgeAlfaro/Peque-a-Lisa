#include "RutaDistribucion.h"

void RutaDistribucion::agregarCamion(Camion*)
{
}

void RutaDistribucion::ordenarMergeSort()
{
}

void RutaDistribucion::ordenarQuickSort()
{
}

std::string RutaDistribucion::toString(){
	std::stringstream s;
	s << "----------------------------\n"
		<< "ID ubicacion: " << idUbicacion
		<< "\nDistrito: " << nombreDistrito
		<< "\n----------------------------\n";

	return s.str();
}
