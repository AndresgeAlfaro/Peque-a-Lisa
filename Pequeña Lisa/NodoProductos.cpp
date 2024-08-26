#include "NodoProductos.h"

NodoProductos::NodoProductos(Producto producto): /*producto(producto),*/ siguiente{ nullptr }{}

NodoProductos::~NodoProductos()
{
}

Producto NodoProductos::getProducto() const
{
	return/* producto*/;
}

void NodoProductos::setProducto(Producto producto)
{
	this->producto = /*producto*/ 0;
}

NodoProductos* NodoProductos::getSiguiente() const
{
	return siguiente;
}

void NodoProductos::setSiguiente(NodoProductos* siguiente)
{
	this->siguiente = siguiente;
}

std::string NodoProductos::toString() const
{
	return producto->toString();
}
