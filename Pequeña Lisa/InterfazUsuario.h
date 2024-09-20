#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

#include "GestosPilaProductos.h"
#include "Camion.h"
#include "ColaProcesamiento.h"
#include <stdexcept>
#include <ctime> 
#include "ListaCamion.h"
#include "ListaRutaDistribucion.h"

class InterfazUsuario {
public:
    InterfazUsuario();
    void ejecutar();

private:
    void menu();
    void vista();
    void manejarOpcion(int opcion);
    void manejarVista(int opcionVista);
    bool fechaValida(const std::string&);
    time_t convertirFecha(const std::string&);

    GestosPilaProductos gestor;
    ColaProcesamiento cola;
    ListaCamion camiones;
    ListaRutaDistribucion rutas;
    ListaCamion camionesRuta;
};


#endif // !INTERFAZUSUARIO_H

