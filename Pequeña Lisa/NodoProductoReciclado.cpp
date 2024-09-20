#include "NodoProductoReciclado.h"

NodoProductoReciclado::NodoProductoReciclado(ProductoReciclado* data)
    : data(data), next(nullptr) {}

NodoProductoReciclado::~NodoProductoReciclado(){}

ProductoReciclado* NodoProductoReciclado::getData() {
    return data;
}

NodoProductoReciclado* NodoProductoReciclado::getNext() {
    return next;
}

void NodoProductoReciclado::setNext(NodoProductoReciclado* nextNode) {
    next = nextNode;
}
