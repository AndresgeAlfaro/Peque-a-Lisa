#include "NodoGrafo.h"

NodoGrafo::NodoGrafo(int _id, std::string _nombre, std::string _ubicacion) : id(_id), nombre(_nombre), ubicacion(_ubicacion), listaAdyacencia(nullptr) {
}

NodoGrafo::~NodoGrafo(){
	Arista* actual = listaAdyacencia;
	while (actual) {
		Arista* temp = actual;
		actual = actual->siguiente;
		delete temp;
	}
}

int NodoGrafo::getId() const{
	return this->id;
}

std::string NodoGrafo::getNombre() const{
	return this->nombre;
}

std::string NodoGrafo::getUbicacion() const{
	return this->ubicacion;
}

void NodoGrafo::agregarConexion(NodoGrafo* destino, double peso){
	Arista* nuevaArista = new Arista(destino, peso);
	nuevaArista->siguiente = listaAdyacencia;
	listaAdyacencia = nuevaArista;
}

std::string NodoGrafo::mostrarConexiones() const{
	std::stringstream s;
	s << "Conexiones desde " << nombre << " (" << ubicacion << "):\n";
	Arista* actual = listaAdyacencia;
	while (actual) {
		s << "  - " << actual->destino->getNombre() << " (Peso: " << actual->peso << ")\n";
		actual = actual->siguiente;
	}
	return s.str();
}
