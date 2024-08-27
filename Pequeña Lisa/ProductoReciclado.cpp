#include "ProductoReciclado.h"

ProductoReciclado::ProductoReciclado(Date fechaReciclaje, std::string descripcionR): fechaReciclaje(fechaReciclaje), descripcionR(descripcionR){}

Date ProductoReciclado::getFechaReciclaje()
{
	return fechaReciclaje;
}

std::string ProductoReciclado::getDescripcionR()
{
	return std::string();
}

void ProductoReciclado::setFechaReciclaje(Date fechaReciclaje)
{
	this->fechaReciclaje = fechaReciclaje;
}

void ProductoReciclado::setDescripcionR(std::string descripcionR)
{
	this->descripcionR = descripcionR;
}



