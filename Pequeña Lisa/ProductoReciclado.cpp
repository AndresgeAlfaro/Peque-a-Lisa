#include "ProductoReciclado.h"

ProductoReciclado::ProductoReciclado(int _id, std::string _tipo, std::string _estado, std::string _descripcion, time_t _fecha, std::string _descripcionR): Producto(_id, _tipo, _estado, _descripcion), fechaReciclaje(_fecha), DescripcionR(_descripcionR){}

ProductoReciclado::~ProductoReciclado(){}

time_t ProductoReciclado::getFechaReciclaje(){
    return this->fechaReciclaje;
}

std::string ProductoReciclado::getDescripcion(){
    return this->DescripcionR;
}

std::string ProductoReciclado::toString() {
    std::stringstream ss;
    char buffer[26];

    ctime_s(buffer, sizeof(buffer), &fechaReciclaje);

    ss << "***PRODUCTO RECICLADO***"
        << "\nFecha de reciclaje: " << buffer
        << "\nDescripcion: " << DescripcionR;
    return ss.str();
}

