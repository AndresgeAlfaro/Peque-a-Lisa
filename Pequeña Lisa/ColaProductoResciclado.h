#ifndef COLAPRODUCTORECICLADO_H
#define COLAPRODUCTORECICLADO_H
#include"ProductoReciclado.h"

struct Nodo {

    ProductoReciclado producto;
    Nodo* siguiente;
    Nodo(ProductoReciclado p) : producto(p), siguiente(nullptr) {}

};

class ColaProductoResciclado
{

public:

    ColaProductoResciclado();
    ~ColaProductoResciclado();

    bool estaVacio();
    void enqueue();
    void dequeue();

    ProductoReciclado frenteProducto() const;
    void buscarPorRangoFecha(const std::string&, const std::string&) const;

    std::string imprimirCola() const;

private:

    Nodo* frente;
    Nodo* final;

};

#endif // !COLAPRODUCTORECICLADO_H


