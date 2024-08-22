#ifndef Producto
#include <iostream>
#include <sstream>

class Producto
{
public:

	Producto();
	~Producto();

	int getId();
	std::string getTipo();
	std::string getEstado();
	std::string getDescripcion();

private:
	int id;
	std::string tipo;
	std::string estado;
	std::string descripcion;
};

#endif // !Producto



