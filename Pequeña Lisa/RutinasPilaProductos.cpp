#include "RutinasPilaProductos.h"

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
		}
		aux.pushProducto(actual);
		pila.popProducto();
	}
	restaurarPilaOrdenada(aux);
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
		}
		aux.pushProducto(actual);
		pila.popProducto();
	}
	restaurarPilaOrdenada(aux);
	return encontrado;
}

void RutinasPilaProductos::restaurarPilaOrdenada(PilaProductos& aux)
{
	while (!aux.estaVacio())
	{
		pila.pushProducto(aux.obtenerCima());
		aux.popProducto();
	}
}
