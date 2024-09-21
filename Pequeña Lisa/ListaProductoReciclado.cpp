#include "ListaProductoReciclado.h"

ListaProductoReciclado::ListaProductoReciclado(): head(nullptr){}

ListaProductoReciclado::~ListaProductoReciclado(){
    while (head != nullptr) {
        NodoProductoReciclado* temp = head;
        head = head->getNext();
        delete temp;
    }
}

void ListaProductoReciclado::agregar(ProductoReciclado* nuevo){
	NodoProductoReciclado* newNodo = new NodoProductoReciclado(nuevo);
	if (head == nullptr) {
		head = newNodo;
	}
	else { 
		NodoProductoReciclado* aux = head;
		while (aux->getNext() != nullptr) {
			aux = aux->getNext();
		}
		aux->setNext(newNodo);
	}
}

std::string ListaProductoReciclado::mostrarProductosReciclados() const{
	std::stringstream s;
	s << "----------------- LISTA DE CAMIONES -----------------\n";
	NodoProductoReciclado* aux = head;
	while (aux != nullptr) {
		s << aux->getData()->toString() << std::endl;
		aux = aux->getNext();
	}
	return s.str();
}

