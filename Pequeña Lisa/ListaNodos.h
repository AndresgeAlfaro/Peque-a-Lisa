#ifndef LISTANODOS_H
#define LISTANODOS_H

#include "NodoGrafo.h"
#include <iostream>
#include <string>
#include <functional>

class ListaNodos {
private:
    struct Nodo {
        NodoGrafo* dato;
        Nodo* siguiente;

        Nodo(NodoGrafo* _dato, Nodo* _siguiente = nullptr) : dato(_dato), siguiente(_siguiente) {}
    };

    Nodo* cabeza;

public:
    ListaNodos() : cabeza(nullptr) {}
    ~ListaNodos() { limpiar(); }

    void agregar(NodoGrafo* nodo) {
        if (!cabeza) {
            cabeza = new Nodo(nodo);
        }
        else {
            Nodo* actual = cabeza;
            while (actual->siguiente) {
                actual = actual->siguiente;
            }
            actual->siguiente = new Nodo(nodo);
        }
    }

    std::string mostrar() const {
        std::stringstream s;
        Nodo* actual = cabeza;
        while (actual) {
            s << actual->dato->getNombre() << " - " << actual->dato->getUbicacion() << "\n";
            actual = actual->siguiente;
        }
        return s.str();
    }

    void recorrer(const std::function<void(NodoGrafo*)>& accion) const {
        Nodo* actual = cabeza;
        while (actual) {
            accion(actual->dato);
            actual = actual->siguiente;
        }
    }

    void limpiar() {
        while (cabeza) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

#endif
