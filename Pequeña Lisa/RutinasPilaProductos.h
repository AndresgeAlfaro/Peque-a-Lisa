#ifndef RUTINASPILAPRODUCTOS_H
#define  RUTINASPILAPRODUCTOS_H
#include "PilaProductos.h"

class RutinasPilaProductos {

public:

	RutinasPilaProductos();
	~RutinasPilaProductos();

	bool busquedaPorId(int);
	bool busquedaPorTipo(std::string);


private:

	PilaProductos pila;

	void restaurarPilaOrdenada(PilaProductos&);

};

#endif // ! RUTINASPILAPRODUCTOS_H


