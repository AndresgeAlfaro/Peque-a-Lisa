#include "Producto.h"

Producto::Producto(int _id, std::string _tipo, std::string _estado, std::string _descripcion): id(_id), estado(_estado), descripcion(_descripcion){}

Producto::~Producto(){}

int Producto::getId(){
	return this->id;
}

std::string Producto::getTipo(){
	return this->tipo;
}

std::string Producto::getEstado(){
	return this->estado;
}

std::string Producto::getDescripcion(){
	return this->descripcion;
}

std::string Producto::toString() {
	std::stringstream s;

	s << "***INFORMACION DEL PRODUCTO***"
		<< "\nID: " << id
		<< "\nTipo: " << tipo
		<< "\nEstado: " << estado
		<< "Descripcion: " << descripcion;
	return s.str();
}
