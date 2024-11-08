#ifndef BUSQUEDARUTA_H
#define BUSQUEDARUTA_H

#include "GrafoDistribucion.h"
#include <iostream>
#include <limits>

class BusquedaRuta{
protected:
    struct NodoDistancia {
        NodoGrafo* nodo;
        double distancia;
        bool visitado;
        NodoDistancia* siguiente;

        NodoDistancia(NodoGrafo* _nodo, double _distancia)
            : nodo(_nodo), distancia(_distancia), visitado(false), siguiente(nullptr) {}
    };

    NodoDistancia* listaDistancias;

    void inicializarDistancias(NodoGrafo*);
    NodoGrafo* nodoConMenorDistanciaNoVisitado();

public:
    BusquedaRuta();
    ~BusquedaRuta();

    void buscarRutaOptima(GrafoDistribucion&, int, int);
    void mostrarRuta(int);

};

#endif