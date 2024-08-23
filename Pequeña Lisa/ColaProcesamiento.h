#ifndef COLAPROCESAMIENTO_H
#define COLAPROCESAMIENTO_H

#include <string>
#include "ProductoReciclado.h"
#include "ListaProductoReciclado.h"
#include "NodoProductoReciclado.h"

class ColaProcesamiento{
public:
	void agregar(ProductoReciclado);
	ProductoReciclado procesarProducto();
	ListaProductoReciclado buscarPorFecha(Date, Date);

private:
	NodoProductoReciclado frente;
	NodoProductoReciclado final;
	std::string tipo;

};

#endif