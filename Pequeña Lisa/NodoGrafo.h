#ifndef NODOGRAFO_H
#define NODOGRAFO_H

#include <sstream>

class NodoGrafo{
public:
    int id;
    std::string nombre;
    std::string ubicacion;

    // Clase interna que representará las aristas/conexiones del nodo
    class Arista {
    public:
        NodoGrafo* destino;
        double peso;
        Arista* siguiente;

        Arista(NodoGrafo* _destino, double _peso) : destino(_destino), peso(_peso), siguiente(nullptr) {}
    };

    Arista* listaAdyacencia;

//public:
    NodoGrafo(int = 0, std::string = "", std::string = "");
    ~NodoGrafo();

    int getId() const;
    std::string getNombre() const;
    std::string getUbicacion() const;

    void agregarConexion(NodoGrafo*, double);
    std::string mostrarConexiones() const;

};

#endif