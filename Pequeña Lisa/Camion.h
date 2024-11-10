#ifndef CAMION_H
#define CAMION_H

#include <vector>
#include "ProductoReciclado.h"
#include "ListaProductoReciclado.h"
#include "NodoGrafo.h"
#include "ArbolAVL.h"

class Camion{
private:
	int idCamion;
	std::string conductor;
	ListaProductoReciclado productos;

	//implementación proyecto 2
	std::vector<NodoGrafo*> rutaAsignada;
	ArbolAVL arbolRutas;

public:
	Camion(int, std::string);
	virtual ~Camion();
	int getId();
	void agregarProducto(ProductoReciclado*);
	std::string mostrarProductosCamion();
	std::string toString();

	//implementación proyecto 2
	void asignarRuta(const std::vector<NodoGrafo*>&);
	std::string mostrarRuta();
	void ejecutarRuta();

};

#endif