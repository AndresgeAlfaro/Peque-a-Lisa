#include "GestosPilaProductos.h"

GestosPilaProductos::GestosPilaProductos() : pilaVidrio(), pilaMetal(), pilaDerivadosPapel(), pilaPlastico() {}


GestosPilaProductos::~GestosPilaProductos()
{
}

void GestosPilaProductos::agregarProducto(Producto* producto)
{

    if (producto->getTipo() == "vidrio")
    {
        pilaVidrio.pushProducto(producto);
    }
    else if (producto->getTipo() == "metal")
    {
        pilaMetal.pushProducto(producto);
    }
    else if (producto->getTipo() == "derivados de papel")
    {
        pilaDerivadosPapel.pushProducto(producto);
    }
    else if (producto->getTipo() == "plastico")
    {
        pilaPlastico.pushProducto(producto);
    }
    else
    {
        std::cout << "Tipo de producto desconocido: " << producto->getTipo() << std::endl;
    }

}

Producto* GestosPilaProductos::buscarProductoPorID(int id)
{
    Producto* producto = pilaVidrio.buscarPorID(id);
    if (producto != nullptr && producto->getId() != 0)
        return producto;

    producto = pilaMetal.buscarPorID(id);
    if (producto != nullptr && producto->getId() != 0)
        return producto;

    producto = pilaDerivadosPapel.buscarPorID(id);
    if (producto != nullptr && producto->getId() != 0)
        return producto;

    producto = pilaPlastico.buscarPorID(id);
    if (producto != nullptr && producto->getId() != 0)
        return producto;

    return nullptr;
}


PilaProductos& GestosPilaProductos::obtenerPilaPorTipo(const std::string& tipo)
{
    if (tipo == "vidrio")
    {
        return pilaVidrio;
    }
    else if (tipo == "metal")
    {
        return pilaMetal;
    }
    else if (tipo == "derivados de papel")
    {
        return pilaDerivadosPapel;
    }
    else if (tipo == "plastico")
    {
        return pilaPlastico;
    }
    else
    {
        std::cout << "Tipo de producto desconocido: " + tipo + "\n";
    }
}

void GestosPilaProductos::eliminarProductosNoReciclables()
{

    pilaVidrio.eliminarProductosNoReciclables();
    pilaMetal.eliminarProductosNoReciclables();
    pilaDerivadosPapel.eliminarProductosNoReciclables();
    pilaPlastico.eliminarProductosNoReciclables();

}

void GestosPilaProductos::contarProductosPorPila() const
{
    std::cout << "Cantidad de productos en la pila de Vidrio: " << pilaVidrio.contarProductos() << std::endl;
    std::cout << "Cantidad de productos en la pila de Metal: " << pilaMetal.contarProductos() << std::endl;
    std::cout << "Cantidad de productos en la pila de Derivados de Papel: " << pilaDerivadosPapel.contarProductos() << std::endl;
    std::cout << "Cantidad de productos en la pila de Plastico: " << pilaPlastico.contarProductos() << std::endl;

}

int GestosPilaProductos::contarTotalProductos() const
{

    return pilaVidrio.contarProductos() + pilaMetal.contarProductos() + pilaDerivadosPapel.contarProductos() + pilaPlastico.contarProductos();;

}

void GestosPilaProductos::imprimirTodasLasPilas() const
{

    std::cout << "Pila de Vidrio:\n" << pilaVidrio.imprimirPila() << std::endl;
    std::cout << "Pila de Metal:\n" << pilaMetal.imprimirPila() << std::endl;
    std::cout << "Pila de Derivados de Papel:\n" << pilaDerivadosPapel.imprimirPila() << std::endl;
    std::cout << "Pila de Plastico:\n" << pilaPlastico.imprimirPila() << std::endl;

}
