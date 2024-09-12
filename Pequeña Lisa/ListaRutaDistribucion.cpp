#include "ListaRutaDistribucion.h"

ListaRutaDistribucion::ListaRutaDistribucion(): head(nullptr){}

ListaRutaDistribucion::~ListaRutaDistribucion(){
    while (head != nullptr) {
        NodoRuta* temp = head;
        head = head->getNext();
        delete temp;
    }
}

void ListaRutaDistribucion::agregarRutaInicio(RutaDistribucion* nuevo){
    NodoRuta* nuevoNodo = new NodoRuta(nuevo);
    if (head == nullptr) {
        head = nuevoNodo;
    }
    else {
        nuevoNodo->setNext(head);
        head->setPrev(nuevoNodo);
        head = nuevoNodo;
    }
}

void ListaRutaDistribucion::agregarRutaFinal(RutaDistribucion* nuevo){
    NodoRuta* nuevoNodo = new NodoRuta(nuevo);
    if (head == nullptr) {
        head = nuevoNodo;
    }
    else {
        NodoRuta* aux = head;
        while (aux->getNext() != nullptr) {
            aux = aux->getNext();
        }
        aux->setNext(nuevoNodo);
        nuevoNodo->setPrev(aux);
    }
}

void ListaRutaDistribucion::eliminarRuta(RutaDistribucion* ruta){
    NodoRuta* actual = head;
    while (actual != nullptr) {
        if (actual->getData() == ruta) {
            if (actual == head) { // Si es el primero
                head = head->getNext(); // Ajusta el primero al que le sigue
                if (head != nullptr) {
                    head->setPrev(nullptr);
                }
            }
            else {
                actual->getPrev()->setNext(actual->getNext());
                if (actual->getNext() != nullptr) {
                    actual->getNext()->setPrev(actual->getPrev());
                }
            }
            delete actual;
            return;
        }
        actual = actual->getNext();
    }
}

void ListaRutaDistribucion::ordenarMergeSort()
{
}

void ListaRutaDistribucion::ordenarQuickSort()
{
}

void ListaRutaDistribucion::toStringRutas(){
    NodoRuta* actual = head;
    while (actual != nullptr) {
        std::cout << actual->getData()->toString() << std::endl;
        actual = actual->getNext();
    }
}
