#ifndef LISTARUTADISTRIBUCION_H
#define LISTARUTADISTRIBUCION_H

#include "RutaDistribucion.h"
#include "NodoRuta.h"
#include <sstream>

class ListaRutaDistribucion{
public:
	ListaRutaDistribucion();
	~ListaRutaDistribucion();
	void agregarRutaInicio(RutaDistribucion*);
	void agregarRutaFinal(RutaDistribucion*);
	void eliminarRuta(RutaDistribucion*);
	void ordenarMergeSort();
	void ordenarQuickSort();
	void toStringRutas();

private:
	NodoRuta* head;

	NodoRuta* dividirLista(NodoRuta*);
	NodoRuta* fusionarListas(NodoRuta*, NodoRuta*);
	NodoRuta* mergeSort(NodoRuta*);

	NodoRuta* particionar(NodoRuta*, NodoRuta*);
	void quickSort(NodoRuta*, NodoRuta*);
	void intercambiar(NodoRuta*, NodoRuta*);

};

#endif