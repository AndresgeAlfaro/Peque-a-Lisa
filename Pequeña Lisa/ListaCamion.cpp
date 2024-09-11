#include "ListaCamion.h"

ListaCamion::ListaCamion(): head(nullptr){}

ListaCamion::~ListaCamion(){
    NodoCamion* aux = head;
    while (aux != nullptr) {
        NodoCamion* next = aux->getNext();
        delete aux;
        aux = next;
    }
}

void ListaCamion::agregarCamion(Camion* nuevo){
	NodoCamion* newNodo = new NodoCamion(nuevo); // Nuevo nodo a insertar 
	if (head == nullptr) { // Caso: La lista esta vacia
		head = newNodo; // O(1) (Complejidad Constante)
	}
	else { // Caso: La lista ya tiene elementos
		// primero->getSiguiente()->getSiguiente()->getSiguiente()->getSiguiente.....
		NodoCamion* aux = head; // Copio el primer nodo 
		while (aux->getNext() != nullptr) { // Mientras que el nodo que tenga enfrente no este vacio
			// Metodos que ocupen recorrer la lista //
			aux = aux->getNext(); // Se mueve al siguiente nodo
		}
		aux->setNext(newNodo); // Se asignaba el nuevo nodo al final
	}
}

void ListaCamion::ordenarBubbleSort(){

}

void ListaCamion::ordenarInsertionSort()
{
}

void ListaCamion::ordenarSelectionSort()
{
}

Camion* ListaCamion::buscarPorId(int _id){
	NodoCamion* aux = head; // Copiar el primer nodo
	while (aux != nullptr) { // O(n) Complejidad LINEAL (TIENE UN CICLO)
		if (aux->getData()->getId() == _id) {
			return aux->getData();
		}
		aux = aux->getNext(); // Se mueve al siguiente nodo
	}
	return nullptr; // NO LO ENCONTRE O NO EXISTE
}

bool ListaCamion::eliminarPorId(int _id){
	// Caso 1: Lista Vacia
	if (head == nullptr)return false;

	// Caso 2: Si el nodo a eliminar es el primero 
	if (head->getData()->getId() == _id) {
		NodoCamion* aux = head; // Copio la lista
		head = head->getNext();
		delete aux->getData();
		delete aux;
		return true;
	}
	else { // Caso 3: Es cualquier otro nodo 
		NodoCamion* aux = head;
		while (aux->getNext() != nullptr && aux->getNext()->getData()->getId() == _id) {
			aux = aux->getNext();
		}
		if (aux->getNext() == nullptr)return false;
		NodoCamion* aux2 = aux->getNext();
		aux->setNext(aux->getNext()->getNext());
		delete aux2->getData();
		delete aux2;
		return true;
	}
}

std::string ListaCamion::imprimirLista() const{
	std::stringstream s; 
	s << "----------------- LISTA DE CAMIONES -----------------\n";
	NodoCamion* aux = head; // Copiar el primer nodo
	while (aux != nullptr) { // O(n) Complejidad LINEAL (TIENE UN CICLO)
		s << aux->getData()->toString() << std::endl;
		aux = aux->getNext(); // Se mueve al siguiente nodo
	}
	return s.str();
}
