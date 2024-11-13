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
    if (existeNodo(nuevoNodo->getId())) {
        std::cerr << "Nodo con ID " << nuevoNodo->getId() << " ya existe y no sera agregado nuevamente.\n";
        return;
    }

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
        std::cerr << "Error: No se encontro el nodo de origen o destino para agregar la conexion.\n";
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

bool GrafoDistribucion::existeNodo(int id){
    NodoLista* actual = head;
    while (actual) {
        if (actual->nodo->getId() == id) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
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

void GrafoDistribucion::mostrarGrafoPorCamion(int idCamion) const {
    std::stringstream s;
    NodoLista* actual = head;

    while (actual) {
        
        if (actual->nodo->getId() == idCamion) {
            s << actual->nodo->mostrarConexiones() << "\n";
        }
        actual = actual->siguiente;
    }
    if (s.str().empty()) {
        s << "No se encontro ningun nodo para el camion con ID " << idCamion << ".\n";
    }

    std::cout << s.str();
}


