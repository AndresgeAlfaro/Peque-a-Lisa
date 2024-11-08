#ifndef GRAFODISTRIBUCION_H
#define GRAFODISTRIBUCION_H

#include "NodoGrafo.h"
#include <iostream>
#include <string>
#include <sstream>

class GrafoDistribucion{
public:
    class NodoLista {
    public:
        NodoGrafo* nodo;
        NodoLista* siguiente;

        NodoLista(NodoGrafo* _nodo) : nodo(_nodo), siguiente(nullptr) {}
    };

    NodoLista* head;

//public: 
    GrafoDistribucion();
    ~GrafoDistribucion();
    void agregarNodo(NodoGrafo*);
    void agregarConexion(int, int, double);
    NodoGrafo* buscarNodo(int);
    std::string mostrarGrafo() const;

};

#endif