#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <sstream>

class Producto
{
public:

	Producto(int, std::string, std::string, std::string);
	virtual ~Producto();

	int getId();
	std::string getTipo();
	std::string getEstado();
	std::string getDescripcion();
	std::string toString();

protected:
	int id;
	std::string tipo;
	std::string estado;
	std::string descripcion;
};

#endif // !Producto



