#include "NodoRuta.h"

NodoRuta::NodoRuta(RutaDistribucion* _data):data(_data), next(nullptr), prev(nullptr){}

RutaDistribucion* NodoRuta::getData(){
    return data;
}

NodoRuta* NodoRuta::getNext(){
    return next;
}

NodoRuta* NodoRuta::getPrev(){
    return prev;
}

void NodoRuta::setNext(NodoRuta* _next){
    this->next = _next;
}

void NodoRuta::setPrev(NodoRuta* _prev){
    this->prev = prev;
}
