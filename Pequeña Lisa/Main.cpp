
#include "GestosPilaProductos.h"

int main() {
    
    GestosPilaProductos gestor;

    Producto p1(1, "vidrio", "reciclable", "Botella de vidrio");
    Producto p2(2, "metal", "no reciclable", "Lata oxidada");
    Producto p3(3, "plastico", "reciclable", "Envase de plastico");
    Producto p4(4, "derivados de papel", "reciclable", "Caja de carton");

    gestor.agregarProducto(p1);
    gestor.agregarProducto(p2);
    gestor.agregarProducto(p3);
    gestor.agregarProducto(p4);

    gestor.imprimirTodasLasPilas();

    gestor.eliminarProductosNoReciclables();

    gestor.imprimirTodasLasPilas();

    return 0;
   
}
