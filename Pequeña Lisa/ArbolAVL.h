#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
#include "NodoGrafo.h"  // Suponiendo que esta clase está definida en este archivo

// Definición de la estructura del nodo para el árbol AVL
struct NodoArbol {
    NodoGrafo* nodo;  // Nodo del grafo
    int altura;       // Altura del nodo en el árbol
    NodoArbol* izquierda;
    NodoArbol* derecha;

    NodoArbol(NodoGrafo* _nodo) : nodo(_nodo), altura(1), izquierda(nullptr), derecha(nullptr) {}
};

// Clase para el Árbol AVL
class ArbolAVL {
public:
    ArbolAVL();  // Constructor
    ~ArbolAVL();
    void insertar(NodoGrafo* nuevoNodo);  // Función para insertar un nodo
    void mostrar();  // Función para mostrar el árbol (en orden)
    void destruirRec(NodoArbol*);

private:
    NodoArbol* raiz;  // Raíz del árbol AVL

    // Funciones privadas
    NodoArbol* insertarRec(NodoArbol* raiz, NodoGrafo* nuevoNodo);
    int obtenerAltura(NodoArbol* nodo);
    int obtenerBalance(NodoArbol* nodo);
    NodoArbol* rotarIzquierda(NodoArbol* raiz);
    NodoArbol* rotarDerecha(NodoArbol* raiz);
    void mostrarRec(NodoArbol* raiz);
};

#endif // ARBOLAVL_H
