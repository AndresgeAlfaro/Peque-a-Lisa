#ifndef PRODUCTORECICLADO_H
#define PRODUCTORECICLADO_H

#include <ctime>
#include "Producto.h"

class ProductoReciclado: public Producto{
public:
	ProductoReciclado(int, std::string, std::string, std::string, time_t, std::string);
	virtual ~ProductoReciclado();
	time_t getFechaReciclaje();
	std::string getDescripcion();
	std::string toString();

private:
	time_t fechaReciclaje;
	std::string DescripcionR;

};


#endif // !ProductoRecilado


