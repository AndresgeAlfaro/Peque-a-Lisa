#include "ProductoReciclado.h"
//hola
ProductoReciclado::ProductoReciclado(int id, const std::string& tipo, const std::string& descripcion, std::time_t fechaReciclaje): id(id), tipo(tipo), descripcion(descripcion), fechaReciclaje(fechaReciclaje) {}

int ProductoReciclado::getId() const
{
	return id;
}

std::string ProductoReciclado::getTipo() const
{
	return tipo;
}

std::string ProductoReciclado::getDescripcion() const
{
	return descripcion;
}

std::time_t ProductoReciclado::getFechaReciclaje() const
{
	return fechaReciclaje;
}

std::string ProductoReciclado::toString() const
{
	return "ProductoReciclado{" + std::to_string(id) + ", " + tipo + ", " + descripcion + ", " + convertirFecha(fechaReciclaje) + "}";
}


