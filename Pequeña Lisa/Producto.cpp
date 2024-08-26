#include "Producto.h"

Producto::Producto(int id, std::string tipo, std::string estado, std::string descripcion)
    : id( id ), tipo( tipo ), estado( estado ), descripcion( descripcion ) {}

Producto::~Producto()
{
}

int Producto::getId()const
{
    return id;
}

void Producto::setID(int id)
{
    this->id = id;
}

std::string Producto::getTipo()const
{
    return tipo;
}

void Producto::setTipo(std::string tipo)
{
    this->tipo = tipo;
}

std::string Producto::getEstado()const
{
    return estado;
}

void Producto::setEstado(std::string estado)
{
    this->estado = estado;
}

std::string Producto::getDescripcion()const
{
    return descripcion;
}

void Producto::setDescripcion(std::string descripcion)
{
    this->descripcion = descripcion;
}

std::string Producto::toString() const
{
    return "PRODUCTO{" + std::to_string(id) + ", " + tipo + ", " + estado + ", " + descripcion + " }";
}
