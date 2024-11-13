#ifndef GRAFODISTRIBUCION_H
#define GRAFODISTRIBUCION_H

#include "NodoGrafo.h"
#include <iostream>
#include <string>

class GrafoDistribucion{
public:
    class NodoLista {
    public:
        NodoGrafo* nodo;
        NodoLista* siguiente;

        NodoLista(NodoGrafo* _nodo) : nodo(_nodo), siguiente(nullptr) {}
    };

    NodoLista* head;

    GrafoDistribucion();
    ~GrafoDistribucion();
    void agregarNodo(NodoGrafo*);
    void agregarConexion(int, int, double);
    NodoGrafo* buscarNodo(int);
    bool existeNodo(int);
    std::string mostrarGrafo() const;
    void mostrarGrafoPorCamion(int)const;

};

#endif