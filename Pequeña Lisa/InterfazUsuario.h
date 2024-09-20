#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

#include "GestosPilaProductos.h"
#include "Camion.h"

class InterfazUsuario {
public:
    InterfazUsuario();
    void ejecutar();

private:
    void menu();
    void vista();
    void manejarOpcion(int opcion);
    void manejarVista(int opcionVista);

    GestosPilaProductos gestor;
};


#endif // !INTERFAZUSUARIO_H

