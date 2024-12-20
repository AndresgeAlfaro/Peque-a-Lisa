#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

#include "GestosPilaProductos.h"
#include "Camion.h"
#include "ColaProcesamiento.h"
#include "ListaCamion.h"
#include "ListaRutaDistribucion.h"

#include "GrafoDistribucion.h"
#include "BusquedaRuta.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

#include "ArbolAVL.h"
#include "NodoGrafo.h"

class InterfazUsuario {
public:

    //implementación proyecto 2
    struct Punto {
        int id;
        std::string nombre;
        std::string ubicacion;
    };

    InterfazUsuario();
    void ejecutar();

    //métodos para proyecto 2
    void registrarCamion(int);
    void generarRutaAleatoria(int);
    void menuGestorRutas();

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

    //implementación proyecto 2
    ArbolAVL arbolAVL;
    std::vector<Punto> centrosRecoleccion;
    std::vector<Punto> centrosProcesamiento;
    std::vector<int> camionesGrafo;
    GrafoDistribucion grafo;

};


#endif // !INTERFAZUSUARIO_H

