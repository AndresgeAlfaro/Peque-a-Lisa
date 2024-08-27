#ifndef PRODUCTORECILADO_H
#define	PRODUCTORECILADO_H
#include "Producto.h"
#include "Date.h"

class ProductoReciclado
{

public:

	ProductoReciclado(Date, std::string);
	~ProductoReciclado();

	Date getFechaReciclaje();
	std::string getDescripcionR();

	void setFechaReciclaje(Date);
	void setDescripcionR(std::string);

	

private:

	Date fechaReciclaje;
	std::string descripcionR;

};


#endif // !PRODUCTORECILADO_H


