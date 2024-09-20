#ifndef RUTADISTRIBUCION_H
#define RUTADISTRIBUCION_H

#include "Camion.h"
#include "ListaCamion.h"

class RutaDistribucion{
public:
	RutaDistribucion(int, std::string);
	void agregarCamion(Camion*);
	int getId();
	std::string toString();

private:
	int idUbicacion;
	std::string nombreDistrito;
	ListaCamion* camiones;

};

#endif