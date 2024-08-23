#ifndef LISTARUTADISTRIBUCION_H
#define LISTARUTADISTRIBUCION_H

#include "RutaDistribucion.h"
#include "NodoRuta.h"

class ListaRutaDistribucion{
public:
	void agregarRutaInicio(RutaDistribucion*);
	void agregarRutaFinal(RutaDistribucion*);
	void ordenarMergeSort();
	void ordenarQuickSort();

private:
	NodoRuta head;

};

#endif