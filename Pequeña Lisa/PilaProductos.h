#ifndef PilaProductos
#include "Producto.h"

struct Nodo {

};

class PilaProductos
{
public:

	void pushProducto(Producto);
	Producto popProducto();
	Producto serchProductoID(int);
	int serchProductoporTipo();

private:
	std::string producto;

};

#endif // !PilaProductos

