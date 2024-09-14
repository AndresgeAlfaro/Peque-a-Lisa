#ifndef PRODUCTORECICLADO_H
#include "Includes.h"
#define _CRT_SECURE_NO_WARNINGS //por si hay errores

class ProductoReciclado{

public:

    ProductoReciclado(int id, const std::string& tipo, const std::string& descripcion, std::time_t fechaReciclaje);

    int getId() const;
    std::string getTipo() const;
    std::string getDescripcion() const;
    std::time_t getFechaReciclaje() const;

    std::string toString() const;


private:

    int id;
    std::string tipo;
    std::string descripcion;
    std::time_t fechaReciclaje;

    std::string convertirFecha(std::time_t fecha)const{
        char buffer[20];
        struct tm timeinfo;

        localtime_s(&timeinfo, &fecha);

        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeinfo);
        return std::string(buffer);
    }

};

#endif // !PRODUCTORECICLADO_H


