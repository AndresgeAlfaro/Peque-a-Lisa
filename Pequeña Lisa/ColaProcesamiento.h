#ifndef COLAPROCESAMIENTO_H
#define COLAPROCESAMIENTO_H

#include "ProductoReciclado.h"
#include "ListaProductoReciclado.h"
#include "NodoProductoReciclado.h"

class ColaProcesamiento{
public:

	ColaProcesamiento();
	~ColaProcesamiento();

	void agregar(ProductoReciclado*);
	ProductoReciclado* procesarProducto();
	ListaProductoReciclado buscarPorFecha(time_t, time_t);
	bool estaVacia();
	std::string toString();

private:
	NodoProductoReciclado* frente;
	NodoProductoReciclado* final;
	std::string tipo;

};

#endif
