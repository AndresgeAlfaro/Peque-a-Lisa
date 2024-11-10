#include "ArbolAVL.h"
#include <algorithm>

// Constructor de la clase ArbolAVL
ArbolAVL::ArbolAVL() : raiz(nullptr) {}

// Función para insertar un nodo en el árbol
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

// Función recursiva para insertar un nodo en el árbol
NodoArbol* ArbolAVL::insertarRec(NodoArbol* raiz, NodoGrafo* nuevoNodo) {
    if (raiz == nullptr) {
        return new NodoArbol(nuevoNodo);
    }

    // Si el ID del nodo es menor que el ID de la raíz, va a la izquierda
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

    // Balancear el árbol si es necesario
    int balance = obtenerBalance(raiz);

    // Si el nodo se desequilibra, hacer las rotaciones necesarias
    if (balance > 1 && nuevoNodo->getId() < raiz->izquierda->nodo->getId()) {
        return rotarDerecha(raiz);  // Rotación a la derecha
    }

    if (balance < -1 && nuevoNodo->getId() > raiz->derecha->nodo->getId()) {
        return rotarIzquierda(raiz);  // Rotación a la izquierda
    }

    if (balance > 1 && nuevoNodo->getId() > raiz->izquierda->nodo->getId()) {
        raiz->izquierda = rotarIzquierda(raiz->izquierda);  // Rotación a la izquierda en el subárbol izquierdo
        return rotarDerecha(raiz);  // Rotación a la derecha
    }

    if (balance < -1 && nuevoNodo->getId() < raiz->derecha->nodo->getId()) {
        raiz->derecha = rotarDerecha(raiz->derecha);  // Rotación a la derecha en el subárbol derecho
        return rotarIzquierda(raiz);  // Rotación a la izquierda
    }

    return raiz;
}

// Función para obtener la altura de un nodo
int ArbolAVL::obtenerAltura(NodoArbol* nodo) {
    return nodo ? nodo->altura : 0;
}

// Función para obtener el factor de balance de un nodo
int ArbolAVL::obtenerBalance(NodoArbol* nodo) {
    return nodo ? obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha) : 0;
}

NodoArbol* ArbolAVL::rotarIzquierda(NodoArbol* raiz) {
    if (raiz == nullptr) {
        std::cout << "Raíz es nullptr, no se puede realizar rotación izquierda." << std::endl;
        return nullptr;
    }

    NodoArbol* nuevaRaiz = raiz->izquierda;
    if (nuevaRaiz == nullptr) {
        std::cout << "Nueva raíz es nullptr, no se puede realizar rotación." << std::endl;
        return raiz; // Si no hay subárbol izquierdo, no se puede rotar.
    }

    NodoArbol* temp = nuevaRaiz->derecha;

    // Realizar la rotación
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

    // Realizar la rotación
    nuevaRaiz->izquierda = raiz;
    raiz->derecha = temp;

    // Actualizar las alturas
    raiz->altura = std::max(obtenerAltura(raiz->izquierda), obtenerAltura(raiz->derecha)) + 1;
    nuevaRaiz->altura = std::max(obtenerAltura(nuevaRaiz->izquierda), obtenerAltura(nuevaRaiz->derecha)) + 1;

    // Retornar la nueva raíz
    return nuevaRaiz;
}

// Función recursiva para mostrar el árbol en orden
void ArbolAVL::mostrarRec(NodoArbol* raiz) {
    if (raiz) {
        mostrarRec(raiz->izquierda);
        std::cout << "ID Nodo: " << raiz->nodo->getId() << ", Nombre: " << raiz->nodo->getNombre() << std::endl;
        mostrarRec(raiz->derecha);
    }
}

// Función pública para mostrar el árbol
void ArbolAVL::mostrar() {
    mostrarRec(raiz);
}
