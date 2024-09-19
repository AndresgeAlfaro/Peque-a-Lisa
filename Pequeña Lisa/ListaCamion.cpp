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
	if (head == nullptr) return;

	bool swapped;
	NodoCamion* ptr1;
	NodoCamion* lptr = nullptr;

	do {
		swapped = false;
		ptr1 = head;

		while (ptr1->getNext() != lptr) {
			if (ptr1->getData()->getId() > ptr1->getNext()->getData()->getId()) {
				Camion* temp = ptr1->getData();
				ptr1->setData(ptr1->getNext()->getData());
				ptr1->getNext()->setData(temp);
				swapped = true;
			}
			ptr1 = ptr1->getNext();
		}
		lptr = ptr1;
	} while (swapped);
}

void ListaCamion::ordenarInsertionSort(){
	if (head == nullptr) return;

	NodoCamion* sorted = nullptr;

	NodoCamion* current = head;
	while (current != nullptr) {
		NodoCamion* next = current->getNext();

		if (sorted == nullptr || sorted->getData()->getId() >= current->getData()->getId()) {
			current->setNext(sorted);
			sorted = current;
		}
		else {
			NodoCamion* temp = sorted;
			while (temp->getNext() != nullptr && temp->getNext()->getData()->getId() < current->getData()->getId()) {
				temp = temp->getNext();
			}
			current->setNext(temp->getNext());
			temp->setNext(current);
		}
		current = next;
	}
	head = sorted;
}

void ListaCamion::ordenarSelectionSort(){
	if (head == nullptr) return;

	NodoCamion* temp = head;

	while (temp != nullptr) {
		NodoCamion* min = temp;
		NodoCamion* r = temp->getNext();

		while (r != nullptr) {
			if (min->getData()->getId() > r->getData()->getId()) {
				min = r;
			}
			r = r->getNext();
		}

		Camion* x = temp->getData();
		temp->setData(min->getData());
		min->setData(x);
		temp = temp->getNext();
	}
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
