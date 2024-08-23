#ifndef LISTACAMION_H
#define LISTACAMION_H

#include "Camion.h"
#include "NodoCamion.h"

class ListaCamion{
public:
	void agregarCamion(Camion*);
	void ordenarBubbleSort();
	void ordenarInsertionSort();
	void ordenarSelectionSort();
	Camion* buscarPorId(int);

private:
	NodoCamion head;

};

#endif