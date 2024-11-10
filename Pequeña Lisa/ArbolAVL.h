#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
#include "NodoGrafo.h"  // Suponiendo que esta clase est� definida en este archivo

// Definici�n de la estructura del nodo para el �rbol AVL
struct NodoArbol {
    NodoGrafo* nodo;  // Nodo del grafo
    int altura;       // Altura del nodo en el �rbol
    NodoArbol* izquierda;
    NodoArbol* derecha;

    NodoArbol(NodoGrafo* _nodo) : nodo(_nodo), altura(1), izquierda(nullptr), derecha(nullptr) {}
};

// Clase para el �rbol AVL
class ArbolAVL {
public:
    ArbolAVL();  // Constructor
    ~ArbolAVL();
    void insertar(NodoGrafo* nuevoNodo);  // Funci�n para insertar un nodo
    void mostrar();  // Funci�n para mostrar el �rbol (en orden)
    void destruirRec(NodoArbol*);

private:
    NodoArbol* raiz;  // Ra�z del �rbol AVL

    // Funciones privadas
    NodoArbol* insertarRec(NodoArbol* raiz, NodoGrafo* nuevoNodo);
    int obtenerAltura(NodoArbol* nodo);
    int obtenerBalance(NodoArbol* nodo);
    NodoArbol* rotarIzquierda(NodoArbol* raiz);
    NodoArbol* rotarDerecha(NodoArbol* raiz);
    void mostrarRec(NodoArbol* raiz);
};

#endif // ARBOLAVL_H
