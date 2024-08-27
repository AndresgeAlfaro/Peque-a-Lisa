
#include "RutinasPilaProductos.h"


int main()
{
 
	RutinasPilaProductos rutinas;

	rutinas.agregarProducto(Producto(1, "Vidrio", "Limpio", "Buen estado"));
	rutinas.agregarProducto(Producto(2, "Papel", "Libro", "Buen estado"));
	rutinas.agregarProducto(Producto(3, "Metal", "Anillo", "Buen estado"));
	rutinas.agregarProducto(Producto(4, "Plastico", "Botella", "Mal estado"));

	std::cout << "***IMPRIMIENDO PILA***" << std::endl;
	rutinas.imprimirPilaProductos();
	
	int idBuscar= 2;
	rutinas.busquedaPorId(idBuscar);
	std::string stringBuscar = "Vidrio";
	rutinas.busquedaPorTipo(stringBuscar);

	int eliminar = 2;
	rutinas.EliminarProducto(eliminar);
	std::cout<<"\n";
	rutinas.imprimirPilaProductos();
}
