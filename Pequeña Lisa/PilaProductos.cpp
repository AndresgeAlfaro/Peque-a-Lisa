#include "PilaProductos.h"

PilaProductos::PilaProductos() :top(nullptr) {}

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

void PilaProductos::pushProducto(Producto* producto)
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
		std::cout << "LA PILA DE PRODUCTOS ESTA VACIA\n";
	}
	else
	{
		NodoProductos* aux = top;
		top = top->getSiguiente();
		delete aux;
	}
}

Producto* PilaProductos::buscarPorID(int id)
{
	NodoProductos* aux = top;
	while (aux != nullptr) {
		if (aux->getProducto()->getId() == id) {
			return aux->getProducto();
		}
		aux = aux->getSiguiente();
	}
	return nullptr;
}

Producto* PilaProductos::buscarPorTipo(std::string tipo)
{
	NodoProductos* aux = top;
	while (aux != nullptr) {
		if (aux->getProducto()->getTipo() == tipo) {
			return aux->getProducto();
		}
		aux = aux->getSiguiente();
	}
	return nullptr;
}


Producto* PilaProductos::obtenerCima() const
{
	if (!estaVacio())
	{
		return top->getProducto();

	}
	else
	{
		std::cerr << "LA PILA DE PRODUCTOS ESTA VACIA\n";
		return nullptr;
	}
}

int PilaProductos::contarProductos() const
{
	int contador = 0;
	NodoProductos* actual = top;
	while (actual != nullptr)
	{
		contador++;
		actual = actual->getSiguiente();
	}
	return contador;
}

void PilaProductos::eliminarProductosNoReciclables()
{

	NodoProductos* actual = top;
	NodoProductos* anterior = nullptr;

	while (actual != nullptr) {
		if (actual->getProducto()->getEstado() != "reciclable")
		{
			if (actual == top)
			{
				top = top->getSiguiente();
				delete actual;
				actual = top;
			}
			else
			{

				anterior->setSiguiente(actual->getSiguiente());
				delete actual;
				actual = anterior->getSiguiente();
			}
		}
		else
		{
			anterior = actual;
			actual = actual->getSiguiente();
		}
	}

}

std::string PilaProductos::imprimirPila() const
{
	std::string respuesta;
	if (estaVacio())
	{
		respuesta = "LA PILA DE PRODUCTOS ESTA VACIA\n";
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
