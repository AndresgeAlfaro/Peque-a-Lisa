#ifndef LISTACAMION_H
#define LISTACAMION_H

#include "Camion.h"
#include "NodoCamion.h"
#include <sstream>

class ListaCamion{
public:
	ListaCamion();
	~ListaCamion();
	void agregarCamion(Camion*);
	void ordenarBubbleSort();
	void ordenarInsertionSort();
	void ordenarSelectionSort();
	Camion* buscarPorId(int);
	bool eliminarPorId(int);
	std::string imprimirLista() const;

private:
	NodoCamion* head;

};

#endif