	#ifndef RUTINASPILAPRODUCTOS_H
#define  RUTINASPILAPRODUCTOS_H
#include "PilaProductos.h"

class RutinasPilaProductos {

public:

	RutinasPilaProductos();
	~RutinasPilaProductos();

	void agregarProducto(Producto);
	bool busquedaPorId(int);
	bool busquedaPorTipo(std::string);
	bool cantidadDeProductos();
	void EliminarProducto(int);

	void imprimirPilaProductos()const;


private:

	PilaProductos pila;

	void restaurarPilaOrdenada(PilaProductos&);

};

#endif // ! RUTINASPILAPRODUCTOS_H


