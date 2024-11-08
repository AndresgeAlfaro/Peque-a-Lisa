#ifndef LISTARUTADISTRIBUCION_H
#define LISTARUTADISTRIBUCION_H

#include "RutaDistribucion.h"
#include "NodoRuta.h"

class ListaRutaDistribucion{
public:
	ListaRutaDistribucion();
	~ListaRutaDistribucion();
	NodoRuta* getHead();
	void agregarRutaInicio(RutaDistribucion*);
	void agregarRutaFinal(RutaDistribucion*);
	void eliminarRuta(RutaDistribucion*);
	void ordenarMergeSort();
	void ordenarQuickSort();
	void toStringRutas();

	//implementación proyecto 2
	void mezclarRutas();

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