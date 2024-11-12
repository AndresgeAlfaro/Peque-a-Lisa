#include "ArbolAVL.h"
#include <algorithm>

ArbolAVL::ArbolAVL() : raiz(nullptr) {}

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

NodoArbol* ArbolAVL::insertarRec(NodoArbol* raiz, NodoGrafo* nuevoNodo) {
    if (raiz == nullptr) {
        return new NodoArbol(nuevoNodo);
    }

    if (nuevoNodo->getId() < raiz->nodo->getId()) {
        raiz->izquierda = insertarRec(raiz->izquierda, nuevoNodo);
    }
    else if (nuevoNodo->getId() > raiz->nodo->getId()) {
        raiz->derecha = insertarRec(raiz->derecha, nuevoNodo);
    }
    else {
        return raiz;
    }

    raiz->altura = 1 + std::max(obtenerAltura(raiz->izquierda), obtenerAltura(raiz->derecha));

    int balance = obtenerBalance(raiz);

    if (balance > 1 && nuevoNodo->getId() < raiz->izquierda->nodo->getId()) {
        return rotarDerecha(raiz);
    }

    if (balance < -1 && nuevoNodo->getId() > raiz->derecha->nodo->getId()) {
        return rotarIzquierda(raiz);
    }

    if (balance > 1 && nuevoNodo->getId() > raiz->izquierda->nodo->getId()) {
        raiz->izquierda = rotarIzquierda(raiz->izquierda);
        return rotarDerecha(raiz);
    }

    if (balance < -1 && nuevoNodo->getId() < raiz->derecha->nodo->getId()) {
        raiz->derecha = rotarDerecha(raiz->derecha);
        return rotarIzquierda(raiz);
    }

    return raiz;
}

int ArbolAVL::obtenerAltura(NodoArbol* nodo) {
    return nodo ? nodo->altura : 0;
}

int ArbolAVL::obtenerBalance(NodoArbol* nodo) {
    return nodo ? obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha) : 0;
}

NodoArbol* ArbolAVL::rotarIzquierda(NodoArbol* raiz) {
    if (raiz == nullptr) {
        std::cout << "Raiz es nullptr, no se puede realizar rotacion izquierda." << std::endl;
        return nullptr;
    }

    NodoArbol* nuevaRaiz = raiz->izquierda;
    if (nuevaRaiz == nullptr) {
        return raiz;
    }

    NodoArbol* temp = nuevaRaiz->derecha;

    nuevaRaiz->derecha = raiz;
    raiz->izquierda = temp;

    raiz->altura = std::max(obtenerAltura(raiz->izquierda), obtenerAltura(raiz->derecha)) + 1;
    nuevaRaiz->altura = std::max(obtenerAltura(nuevaRaiz->izquierda), obtenerAltura(nuevaRaiz->derecha)) + 1;

    return nuevaRaiz;
}

NodoArbol* ArbolAVL::rotarDerecha(NodoArbol* raiz) {
    if (raiz == nullptr || raiz->derecha == nullptr) {
        return raiz;
    }

    NodoArbol* nuevaRaiz = raiz->derecha;
    NodoArbol* temp = nuevaRaiz->izquierda;

    nuevaRaiz->izquierda = raiz;
    raiz->derecha = temp;

    raiz->altura = std::max(obtenerAltura(raiz->izquierda), obtenerAltura(raiz->derecha)) + 1;
    nuevaRaiz->altura = std::max(obtenerAltura(nuevaRaiz->izquierda), obtenerAltura(nuevaRaiz->derecha)) + 1;

    return nuevaRaiz;
}

void ArbolAVL::mostrarRec(NodoArbol* raiz) {
    if (raiz) {
        mostrarRec(raiz->izquierda);
        std::cout << "ID Nodo: " << raiz->nodo->getId() << ", Nombre: " << raiz->nodo->getNombre() << std::endl;
        mostrarRec(raiz->derecha);
    }
}

void ArbolAVL::mostrar() {
    mostrarRec(raiz);
}

void ArbolAVL::mostrarGrafoPorID() {
    mostrarGrafoPorIDRecursivo(raiz);
}

void ArbolAVL::mostrarGrafoPorIDRecursivo(NodoArbol* nodo) {
    if (nodo == nullptr) {
        return;
    }
   
    mostrarGrafoPorIDRecursivo(nodo->izquierda);

    
    NodoGrafo* nodoGrafo = nodo->nodo;
    std::cout << "ID: " << nodoGrafo->getId()
              << ", Nombre: " << nodoGrafo->getNombre()
              << ", Ubicacion: " << nodoGrafo->getUbicacion() << std::endl;

   
    mostrarGrafoPorIDRecursivo(nodo->derecha);
}
