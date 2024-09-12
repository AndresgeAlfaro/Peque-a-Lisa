#ifndef GESTORPILAPRODUCTOS_H
#define GESTORPILAPRODUCTOS_H

#include"PilaProductos.h"

class GestosPilaProductos
{

public:

    GestosPilaProductos();
    ~GestosPilaProductos();

    void agregarProducto(Producto);
    Producto* buscarProductoPorID(int);
    PilaProductos& obtenerPilaPorTipo(const std::string&);
    void eliminarProductosNoReciclables();
    void contarProductosPorPila() const;
    int contarTotalProductos() const;

    void imprimirTodasLasPilas() const;

private:

    PilaProductos pilaVidrio;
    PilaProductos pilaMetal;
    PilaProductos pilaDerivadosPapel;
    PilaProductos pilaPlastico;

};

#endif // !GESTORPILAPRODUCTOS_H