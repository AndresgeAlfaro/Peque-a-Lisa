#include "PilaProductos.h"

PilaProductos::PilaProductos():top(nullptr){}

PilaProductos::~PilaProductos()
{
	while (!estaVacio()) {
		popProducto();
	}
}

bool PilaProductos::estaVacio()const
{
	return top == nullptr;
}

void PilaProductos::pushProducto(Producto producto)
{
	NodoProductos* nuevo = new NodoProductos(producto);
	if (estaVacio()) 
	{
		top = nuevo;
	}
	else
	{
		nuevo->setSiguiente(top);
		top = nuevo;
	}
}

void PilaProductos::popProducto()
{
	if (estaVacio())
	{
		std::cout << "LA PILA DE PRODUCTOS ESTA VACIA" << std::endl;
	}
	else
	{
		NodoProductos* aux = top;
		top = top->getSiguiente();
		delete aux;
	}
}

Producto PilaProductos::obtenerCima() const
{
	if (!estaVacio())
	{
		return top->getProducto();
		
	}
	else
	{
		std::cerr << "LA PILA DE PRODUCTOS ESTA VACIA" << std::endl;
		return Producto(-1, "", "", "");
	}
}

std::string PilaProductos::imprimirPila() const
{
	std::string respuesta;
	if (estaVacio())
	{
		respuesta = "LA PILA DE PRODUCTOS ESTA VACIA";
	}
	else
	{
		NodoProductos* aux = top;
		while (aux != nullptr)
		{
			respuesta += aux->toString() + "\n";
			aux = aux->getSiguiente();
		}
	}
	return respuesta;
}
