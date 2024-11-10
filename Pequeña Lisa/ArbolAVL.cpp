#include "ArbolAVL.h"
#include <algorithm>

// Constructor de la clase ArbolAVL
ArbolAVL::ArbolAVL() : raiz(nullptr) {}

// Funci�n para insertar un nodo en el �rbol
void ArbolAVL::insertar(NodoGrafo* nuevoNodo) {
    raiz = insertarRec(raiz, nuevoNodo);
}

ArbolAVL::~ArbolAVL() {
    destruirRec(raiz);
}

void ArbolAVL::destruirRec(NodoArbol* nodo) {
    if (nodo) {
        destruirRec(nodo->izquierda);
        destruirRec(nodo->derecha);
        delete nodo;
    }
}

// Funci�n recursiva para insertar un nodo en el �rbol
NodoArbol* ArbolAVL::insertarRec(NodoArbol* raiz, NodoGrafo* nuevoNodo) {
    if (raiz == nullptr) {
        return new NodoArbol(nuevoNodo);
    }

    // Si el ID del nodo es menor que el ID de la ra�z, va a la izquierda
    if (nuevoNodo->getId() < raiz->nodo->getId()) {
        raiz->izquierda = insertarRec(raiz->izquierda, nuevoNodo);
    }
    // Si el ID del nodo es mayor, va a la derecha
    else if (nuevoNodo->getId() > raiz->nodo->getId()) {
        raiz->derecha = insertarRec(raiz->derecha, nuevoNodo);
    }
    else {
        return raiz;  // El nodo con el mismo ID ya existe
    }

    // Actualizar la altura del nodo
    raiz->altura = 1 + std::max(obtenerAltura(raiz->izquierda), obtenerAltura(raiz->derecha));

    // Balancear el �rbol si es necesario
    int balance = obtenerBalance(raiz);

    // Si el nodo se desequilibra, hacer las rotaciones necesarias
    if (balance > 1 && nuevoNodo->getId() < raiz->izquierda->nodo->getId()) {
        return rotarDerecha(raiz);  // Rotaci�n a la derecha
    }

    if (balance < -1 && nuevoNodo->getId() > raiz->derecha->nodo->getId()) {
        return rotarIzquierda(raiz);  // Rotaci�n a la izquierda
    }

    if (balance > 1 && nuevoNodo->getId() > raiz->izquierda->nodo->getId()) {
        raiz->izquierda = rotarIzquierda(raiz->izquierda);  // Rotaci�n a la izquierda en el sub�rbol izquierdo
        return rotarDerecha(raiz);  // Rotaci�n a la derecha
    }

    if (balance < -1 && nuevoNodo->getId() < raiz->derecha->nodo->getId()) {
        raiz->derecha = rotarDerecha(raiz->derecha);  // Rotaci�n a la derecha en el sub�rbol derecho
        return rotarIzquierda(raiz);  // Rotaci�n a la izquierda
    }

    return raiz;
}

// Funci�n para obtener la altura de un nodo
int ArbolAVL::obtenerAltura(NodoArbol* nodo) {
    return nodo ? nodo->altura : 0;
}

// Funci�n para obtener el factor de balance de un nodo
int ArbolAVL::obtenerBalance(NodoArbol* nodo) {
    return nodo ? obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha) : 0;
}

NodoArbol* ArbolAVL::rotarIzquierda(NodoArbol* raiz) {
    if (raiz == nullptr) {
        std::cout << "Ra�z es nullptr, no se puede realizar rotaci�n izquierda." << std::endl;
        return nullptr;
    }

    NodoArbol* nuevaRaiz = raiz->izquierda;
    if (nuevaRaiz == nullptr) {
        std::cout << "Nueva ra�z es nullptr, no se puede realizar rotaci�n." << std::endl;
        return raiz; // Si no hay sub�rbol izquierdo, no se puede rotar.
    }

    NodoArbol* temp = nuevaRaiz->derecha;

    // Realizar la rotaci�n
    nuevaRaiz->derecha = raiz;
    raiz->izquierda = temp;

    // Actualizar las alturas
    raiz->altura = std::max(obtenerAltura(raiz->izquierda), obtenerAltura(raiz->derecha)) + 1;
    nuevaRaiz->altura = std::max(obtenerAltura(nuevaRaiz->izquierda), obtenerAltura(nuevaRaiz->derecha)) + 1;

    return nuevaRaiz;
}

NodoArbol* ArbolAVL::rotarDerecha(NodoArbol* raiz) {
    if (raiz == nullptr || raiz->derecha == nullptr) {
        return raiz;  // Si no se puede rotar, retorna el nodo original
    }

    NodoArbol* nuevaRaiz = raiz->derecha;
    NodoArbol* temp = nuevaRaiz->izquierda;

    // Realizar la rotaci�n
    nuevaRaiz->izquierda = raiz;
    raiz->derecha = temp;

    // Actualizar las alturas
    raiz->altura = std::max(obtenerAltura(raiz->izquierda), obtenerAltura(raiz->derecha)) + 1;
    nuevaRaiz->altura = std::max(obtenerAltura(nuevaRaiz->izquierda), obtenerAltura(nuevaRaiz->derecha)) + 1;

    // Retornar la nueva ra�z
    return nuevaRaiz;
}

// Funci�n recursiva para mostrar el �rbol en orden
void ArbolAVL::mostrarRec(NodoArbol* raiz) {
    if (raiz) {
        mostrarRec(raiz->izquierda);
        std::cout << "ID Nodo: " << raiz->nodo->getId() << ", Nombre: " << raiz->nodo->getNombre() << std::endl;
        mostrarRec(raiz->derecha);
    }
}

// Funci�n p�blica para mostrar el �rbol
void ArbolAVL::mostrar() {
    mostrarRec(raiz);
}
