#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
#include "NodoGrafo.h"

struct NodoArbol {
    NodoGrafo* nodo;
    int altura;
    NodoArbol* izquierda;
    NodoArbol* derecha;

    NodoArbol(NodoGrafo* _nodo) : nodo(_nodo), altura(1), izquierda(nullptr), derecha(nullptr) {}
};

class ArbolAVL {
public:
    ArbolAVL();
    ~ArbolAVL();
    void insertar(NodoGrafo* nuevoNodo);
    void mostrar();
    void destruirRec(NodoArbol*);
    void mostrarGrafoPorID();
    void mostrarGrafoPorIDRecursivo(NodoArbol* );

private:
    NodoArbol* raiz;

    NodoArbol* insertarRec(NodoArbol* raiz, NodoGrafo* nuevoNodo);
    int obtenerAltura(NodoArbol* nodo);
    int obtenerBalance(NodoArbol* nodo);
    NodoArbol* rotarIzquierda(NodoArbol* raiz);
    NodoArbol* rotarDerecha(NodoArbol* raiz);
    void mostrarRec(NodoArbol* raiz);
    
};

#endif // ARBOLAVL_H
