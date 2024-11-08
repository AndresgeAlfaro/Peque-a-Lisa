#include "BusquedaRuta.h"

void BusquedaRuta::inicializarDistancias(NodoGrafo* inicio){
    NodoDistancia* actual = listaDistancias;
    while (actual) {
        actual->distancia = (actual->nodo == inicio) ? 0 : std::numeric_limits<double>::infinity();
        actual->visitado = false;
        actual = actual->siguiente;
    }
}

NodoGrafo* BusquedaRuta::nodoConMenorDistanciaNoVisitado(){
    NodoDistancia* actual = listaDistancias;
    NodoDistancia* menor = nullptr;

    while (actual) {
        if (!actual->visitado && (!menor || actual->distancia < menor->distancia)) {
            menor = actual;
        }
        actual = actual->siguiente;
    }

    return menor ? menor->nodo : nullptr;
}

BusquedaRuta::BusquedaRuta() : listaDistancias(nullptr) {
}

BusquedaRuta::~BusquedaRuta(){
    while (listaDistancias) {
        NodoDistancia* temp = listaDistancias;
        listaDistancias = listaDistancias->siguiente;
        delete temp;
    }
}

void BusquedaRuta::buscarRutaOptima(GrafoDistribucion& grafo, int idInicio, int idDestino){
    NodoGrafo* inicio = grafo.buscarNodo(idInicio);
    if (!inicio) {
        std::cerr << "Error: Nodo inicial no encontrado.\n";
        return;
    }

    // Inicializar la lista de distancias
    listaDistancias = nullptr;
    GrafoDistribucion::NodoLista* actual = grafo.head;
    while (actual) {
        NodoDistancia* nuevaDistancia = new NodoDistancia(actual->nodo, std::numeric_limits<double>::infinity());
        nuevaDistancia->siguiente = listaDistancias;
        listaDistancias = nuevaDistancia;
        actual = actual->siguiente;
    }

    inicializarDistancias(inicio);

    NodoGrafo* nodoActual;
    while ((nodoActual = nodoConMenorDistanciaNoVisitado())) {
        NodoDistancia* distActual = listaDistancias;
        while (distActual && distActual->nodo != nodoActual) {
            distActual = distActual->siguiente;
        }

        if (!distActual || distActual->distancia == std::numeric_limits<double>::infinity()) {
            break;
        }

        distActual->visitado = true;

        NodoGrafo::Arista* arista = nodoActual->listaAdyacencia;
        while (arista) {
            NodoDistancia* vecinoDist = listaDistancias;
            while (vecinoDist && vecinoDist->nodo != arista->destino) {
                vecinoDist = vecinoDist->siguiente;
            }

            if (vecinoDist && !vecinoDist->visitado) {
                double nuevaDist = distActual->distancia + arista->peso;
                if (nuevaDist < vecinoDist->distancia) {
                    vecinoDist->distancia = nuevaDist;
                }
            }

            arista = arista->siguiente;
        }
    }

    mostrarRuta(idDestino);
}

void BusquedaRuta::mostrarRuta(int destinoId){
    NodoDistancia* actual = listaDistancias;
    while (actual) {
        if (actual->nodo->getId() == destinoId) {
            if (actual->distancia == std::numeric_limits<double>::infinity()) {
                std::cout << "No se encontró una ruta al nodo destino.\n";
            }
            else {
                std::cout << "La distancia mínima al nodo destino es: " << actual->distancia << "\n";
            }
            return;
        }
        actual = actual->siguiente;
    }
    std::cout << "Nodo destino no encontrado.\n";
}
