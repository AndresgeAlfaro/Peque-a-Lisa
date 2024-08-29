#ifndef PRODUCTORECICLADO_H
#include "Producto.h"

class ProductoReciclado:public Producto
{

public:

	ProductoReciclado(int,std::string,std::string,std::string,std::string,std::string);
	~ProductoReciclado();

	std::string getFechaReciclaje()const;
	std::string getDescripcionReciclado() const;

	void setFechaReciclaje(const std::string& );
	void setDescripcionReciclado(const std::string& );
	std::string toString();

private:

	std::string fechaReciclaje;
	std::string descripcionReciclado;

};

#endif // !PRODUCTORECICLADO_H


