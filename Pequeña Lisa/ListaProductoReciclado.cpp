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
	NodoProductoReciclado* newNodo = new NodoProductoReciclado(nuevo); // Nuevo nodo a insertar 
	if (head == nullptr) { // Caso: La lista esta vacia
		head = newNodo; // O(1) (Complejidad Constante)
	}
	else { // Caso: La lista ya tiene elementos
		// primero->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente.....
		NodoProductoReciclado* aux = head; // Copio el primer nodo 
		while (aux->getNext() != nullptr) { // Mientras que el nodo que tenga enfrente no este vacio
			// Metodos que ocupen recorrer la lista //
			aux = aux->getNext(); // Se mueve al siguiente nodo
		}
		aux->setNext(newNodo); // Se asignaba el nuevo nodo al final
	}
}

std::string ListaProductoReciclado::mostrarProductosReciclados() const{
	std::stringstream s;
	s << "----------------- LISTA DE CAMIONES -----------------\n";
	NodoProductoReciclado* aux = head; // Copiar el primer nodo
	while (aux != nullptr) { // O(n) Complejidad LINEAL (TIENE UN CICLO)
		s << aux->getData()->toString() << std::endl;
		aux = aux->getNext(); // Se mueve al siguiente nodo
	}
	return s.str();
}

