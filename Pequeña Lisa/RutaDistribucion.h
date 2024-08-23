#ifndef RUTADISTRIBUCION_H
#define RUTADISTRIBUCION_H

#include "Camion.h"
#include "ListaCamion.h"

class RutaDistribucion{
public:
	void agregarCamion(Camion*);
	void ordenarMergeSort();
	void ordenarQuickSort();

private:
	int idUbicacion;
	std::string nombreDistrito;
	ListaCamion camiones;

};

#endif