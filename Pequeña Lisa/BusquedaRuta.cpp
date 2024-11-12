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
                    vecinoDist->predecesor = nodoActual;
                }
            }

            arista = arista->siguiente;
        }
    }

    mostrarRuta(idDestino);
}

void BusquedaRuta::mostrarRuta(int destinoId){
    NodoDistancia* actual = listaDistancias;
    NodoGrafo* destino = nullptr;
    while (actual) {
        if (actual->nodo->getId() == destinoId) {
            destino = actual->nodo;
            break;
        }
        actual = actual->siguiente;
    }

    if (!destino) {
        std::cout << "Nodo destino no encontrado.\n";
        return;
    }

    std::vector<NodoGrafo*> ruta;
    NodoGrafo* nodoActual = destino;
    while (nodoActual) {
        ruta.push_back(nodoActual);
        nodoActual = listaDistancias ? listaDistancias->predecesor : nullptr;
    }

    std::reverse(ruta.begin(), ruta.end());

    std::cout << "Ruta desde el nodo de inicio hasta el nodo destino: \n";
    for (NodoGrafo* nodo : ruta) {
        std::cout << nodo->getId() << " ";
    }
    std::cout << std::endl;
}

std::vector<NodoGrafo*> BusquedaRuta::obtenerRuta(int destinoId){
    NodoDistancia* actual = listaDistancias;
    NodoGrafo* destino = nullptr;
    while (actual) {
        if (actual->nodo->getId() == destinoId) {
            destino = actual->nodo;
            break;
        }
        actual = actual->siguiente;
    }

    if (!destino) {
        std::cout << "Nodo destino no encontrado.\n";
        return {};
    }

    std::vector<NodoGrafo*> ruta;
    NodoGrafo* nodoActual = destino;
    while (nodoActual) {
        ruta.push_back(nodoActual);
        nodoActual = listaDistancias ? listaDistancias->predecesor : nullptr;
    }

    std::reverse(ruta.begin(), ruta.end());

    return ruta;
}
