#include "ListaRutaDistribucion.h"

ListaRutaDistribucion::ListaRutaDistribucion(): head(nullptr){}

ListaRutaDistribucion::~ListaRutaDistribucion(){
    while (head != nullptr) {
        NodoRuta* temp = head;
        head = head->getNext();
        delete temp;
    }
}

NodoRuta* ListaRutaDistribucion::getHead(){
    return head;
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

void ListaRutaDistribucion::ordenarMergeSort(){
    head = mergeSort(head);
}

void ListaRutaDistribucion::ordenarQuickSort(){
    NodoRuta* high = head;
    while (high->getNext() != nullptr) {
        high = high->getNext();
    }
    quickSort(head, high);
}

void ListaRutaDistribucion::toStringRutas(){
    NodoRuta* actual = head;
    while (actual != nullptr) {
        std::cout << actual->getData()->toString() << std::endl;
        actual = actual->getNext();
    }
}

NodoRuta* ListaRutaDistribucion::dividirLista(NodoRuta* _head){
    NodoRuta* slow = _head;
    NodoRuta* fast = _head->getNext();

    while (fast != nullptr) {
        fast = fast->getNext();
        if (fast != nullptr) {
            slow = slow->getNext();
            fast = fast->getNext();
        }
    }

    NodoRuta* mid = slow->getNext();
    slow->setNext(nullptr);
    return mid;
}

NodoRuta* ListaRutaDistribucion::fusionarListas(NodoRuta* left, NodoRuta* right){
    if (!left) return right;
    if (!right) return left;

    if (left->getData()->getId() < right->getData()->getId()) {
        left->setNext(fusionarListas(left->getNext(), right));
        left->getNext()->setPrev(left);
        left->setPrev(nullptr);
        return left;
    }
    else {
        right->setNext(fusionarListas(left, right->getNext()));
        right->getNext()->setPrev(right);
        right->setPrev(nullptr);
        return right;
    }
}

NodoRuta* ListaRutaDistribucion::mergeSort(NodoRuta* _head){
    if (!head || !_head->getNext()) 
        return _head;

    NodoRuta* mid = dividirLista(_head);
    NodoRuta* left = mergeSort(_head);
    NodoRuta* right = mergeSort(mid);

    return fusionarListas(left, right);
}

NodoRuta* ListaRutaDistribucion::particionar(NodoRuta* low, NodoRuta* high){
    int pivot = high->getData()->getId();
    NodoRuta* i = low->getPrev();

    for (NodoRuta* j = low; j != high; j = j->getNext()) {
        if (j->getData()->getId() <= pivot) {
            i = (i == nullptr) ? low : i->getNext();
            intercambiar(i, j);
        }
    }
    i = (i == nullptr) ? low : i->getNext();
    intercambiar(i, high);
    return i;
}

void ListaRutaDistribucion::quickSort(NodoRuta* low, NodoRuta* high){
    if (high != nullptr && low != high && low != high->getNext()) {
        NodoRuta* p = particionar(low, high);
        quickSort(low, p->getPrev());
        quickSort(p->getNext(), high);
    }
}

void ListaRutaDistribucion::intercambiar(NodoRuta* a, NodoRuta* b){
    RutaDistribucion* temp = a->getData();
    a->setData(b->getData());
    b->setData(temp);
}

