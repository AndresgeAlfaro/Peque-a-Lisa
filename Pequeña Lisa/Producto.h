#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "Includes.h"

class Producto
{
public:

	Producto(int, std::string, std::string, std::string);
	Producto();
	~Producto();

	int getId()const;
	void setID(int);

	std::string getTipo()const;
	void setTipo(std::string);

	std::string getEstado()const;
	void setEstado(std::string);

	std::string getDescripcion()const;
	void setDescripcion(std::string);

	std::string toString()const;

private:
	int id;
	std::string tipo;
	std::string estado;
	std::string descripcion;
};

#endif // PRODUCTO_H



