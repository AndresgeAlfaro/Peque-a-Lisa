#include "GrafoDistribucion.h"

GrafoDistribucion::GrafoDistribucion() : head(nullptr){
}

GrafoDistribucion::~GrafoDistribucion(){
    while (head) {
        NodoLista* temp = head;
        head = head->siguiente;
        delete temp->nodo;
        delete temp;
    }
}

void GrafoDistribucion::agregarNodo(NodoGrafo* nuevoNodo){
    NodoLista* nuevo = new NodoLista(nuevoNodo);
    nuevo->siguiente = head;
    head = nuevo;
}

void GrafoDistribucion::agregarConexion(int idOrigen, int idDestino, double peso){
    NodoGrafo* origen = buscarNodo(idOrigen);
    NodoGrafo* destino = buscarNodo(idDestino);

    if (origen && destino) {
        origen->agregarConexion(destino, peso);
    }
    else {
        std::cerr << "Error: No se encontró el nodo de origen o destino para agregar la conexión.\n";
    }
}

NodoGrafo* GrafoDistribucion::buscarNodo(int id){
    GrafoDistribucion::NodoLista* actual = head; 
    while (actual) {
        if (actual->nodo->getId() == id) {
            return actual->nodo;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

std::string GrafoDistribucion::mostrarGrafo() const{
    std::stringstream s;
    NodoLista* actual = head;
    while (actual) {
        s << actual->nodo->mostrarConexiones() << "\n";
        actual = actual->siguiente;
    }
    return s.str();
}
