#ifndef NODOCOLA_H
#define NODOCOLA_H

#include "ProductoReciclado.h"

class NodoCola {
public:
    ProductoReciclado producto;
    NodoCola* siguiente;

    NodoCola(const ProductoReciclado& producto) : producto(producto), siguiente(nullptr) {}
};


#endif // !NODOCOLA_H


