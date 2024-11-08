#ifndef LISTACAMION_H
#define LISTACAMION_H

#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include "Camion.h"
#include "NodoCamion.h"

class ListaCamion{
public:
	ListaCamion();
	~ListaCamion();
	NodoCamion* getHead();
	void agregarCamion(Camion*);
	void ordenarBubbleSort();
	void ordenarInsertionSort();
	void ordenarSelectionSort();
	Camion* buscarPorId(int);
	bool eliminarPorId(int);
	std::string imprimirLista() const;

	//implementación proyecto 2
	void mezclarLista();

private:
	NodoCamion* head;

};

#endif