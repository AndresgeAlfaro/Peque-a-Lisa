#include "RutinasPilaProductos.h"

RutinasPilaProductos::RutinasPilaProductos()
{
}

RutinasPilaProductos::~RutinasPilaProductos()
{
}

void RutinasPilaProductos::agregarProducto(Producto producto)
{
	pila.pushProducto(producto);
}

bool RutinasPilaProductos::busquedaPorId(int id)
{
	PilaProductos aux;
	bool encontrado = false;
	while (!pila.estaVacio())
	{
		Producto actual = pila.obtenerCima();
		if (actual.getId() == id)
		{
			encontrado = true;
		
			std::cout << "El Producto: " << id << " , se encontro en la Pila" << std::endl;
			
		}
		aux.pushProducto(actual);
		pila.popProducto();
	}
	restaurarPilaOrdenada(aux);

	if (!encontrado) {
		std::cout << "El Producto: " << id << " ,no se encontro en la Pila" << std::endl;
	}

	return encontrado;
}

bool RutinasPilaProductos::busquedaPorTipo(std::string tipo)
{
	PilaProductos aux;
	bool encontrado = false;
	while (!pila.estaVacio())
	{
		Producto actual = pila.obtenerCima();
		if (actual.getTipo() == tipo)
		{
			encontrado = true;
			std::cout << "El Producto: " << tipo << " , se encontro en la Pila" << std::endl;
		}
		aux.pushProducto(actual);
		pila.popProducto();
	}
	restaurarPilaOrdenada(aux);

	if (!encontrado) {
		std::cout << "El Producto: " << tipo << " ,no se encontro en la Pila" << std::endl;
	}

	return encontrado;
}

void RutinasPilaProductos::EliminarProducto(int id)
{
	PilaProductos aux;
	bool encontrado = false;
	while (!pila.estaVacio())
	{
		Producto actual = pila.obtenerCima();
		if (actual.getId() != id)
		{
			aux.pushProducto(actual);
		}
		else
		{
			encontrado = true;
			std::cout << "El Producto: " << id << " ,se elimino de la Pila" << std::endl;
		}
		pila.popProducto();
	}
	restaurarPilaOrdenada(aux);

	if (!encontrado) {
		std::cout << "El Producto: " << id << " ,no se encontro en la Pila" << std::endl;
	}
}

void RutinasPilaProductos::imprimirPilaProductos() const
{
	std::cout << pila.imprimirPila() << std::endl;
}

void RutinasPilaProductos::restaurarPilaOrdenada(PilaProductos& aux)
{
	while (!aux.estaVacio())
	{
		pila.pushProducto(aux.obtenerCima());
		aux.popProducto();
	}
}
