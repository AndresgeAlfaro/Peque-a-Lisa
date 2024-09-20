#include "ColaProcesamiento.h"

ColaProcesamiento::ColaProcesamiento() : frente(nullptr), final(nullptr), tipo("") {}
ColaProcesamiento::~ColaProcesamiento() {};

void ColaProcesamiento::agregar(ProductoReciclado* producto) {
    NodoProductoReciclado* nuevoNodo = new NodoProductoReciclado(producto);
    if (final) {
        final->setNext(nuevoNodo);
    }
    else {
        frente = nuevoNodo;
    }
    final = nuevoNodo;
}

ProductoReciclado* ColaProcesamiento::procesarProducto() {
    if (!frente) {
        return nullptr;
    }
    NodoProductoReciclado* nodoAProcesar = frente;
    frente = frente->getNext();
    if (!frente) {
        final = nullptr;
    }
    ProductoReciclado* producto = nodoAProcesar->getData();
    delete nodoAProcesar;
    return producto;
}

ListaProductoReciclado ColaProcesamiento::buscarPorFecha(time_t inicio, time_t fin) {
    ListaProductoReciclado listaResultados;
    NodoProductoReciclado* actual = frente;

    while (actual) {
        ProductoReciclado* producto = actual->getData();
        if (producto->getFechaReciclaje() >= inicio && producto->getFechaReciclaje() <= fin) {
            listaResultados.agregar(producto);
        }
        actual = actual->getNext();
    }

    return listaResultados;
}

