#include "ColaProductoResciclado.h"

ColaProductoResciclado::ColaProductoResciclado() : frente(nullptr), final(nullptr) {}

ColaProductoResciclado::~ColaProductoResciclado()
{
    while (frente != nullptr) {
        NodoCola* aux = frente;
        frente = frente->siguiente;
        delete aux;
    }

}

bool ColaProductoResciclado::estaVacio() const
{
    return frente == nullptr;
}

void ColaProductoResciclado::encolar(const ProductoReciclado& producto)
{
    NodoCola* nuevo = new NodoCola(producto);
    if (estaVacio()) {
        frente = final = nuevo;
    }
    else {
        final->siguiente = nuevo;
        final = nuevo;
    }
}

void ColaProductoResciclado::desencolar()
{
}

void ColaProductoResciclado::buscarPorFecha(const std::string& fechaInicio, const std::string& fechaFin) const
{
}

std::string ColaProductoResciclado::imprimirCola() const
{
    std::string respuesta;
    NodoCola* aux = frente;
    while (aux != nullptr) {
        respuesta += aux->producto.toString() + "\n";
        aux = aux->siguiente;
    }
    return respuesta;

}
