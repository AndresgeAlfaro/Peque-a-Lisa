#ifndef COLAPRODUCTORECICLADO_H
#define COLAPRODUCTORECICLADO_H
#include"NodoCola.h"

class ColaProductoResciclado
{

public:

    ColaProductoResciclado();
    ~ColaProductoResciclado();

    bool estaVacio()const;
    void encolar(const ProductoReciclado&);
    void desencolar();

    void buscarPorFecha(const std::string&, const std::string&) const;

    std::string imprimirCola() const;

private:

    NodoCola* frente;
    NodoCola* final;

};

#endif // !COLAPRODUCTORECICLADO_H


