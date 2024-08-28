
#include "GestosPilaProductos.h"

int main() {
    
    GestosPilaProductos gestor;

    Producto p1(1, "vidrio", "reciclable", "Botella de vidrio");
    Producto p2(2, "metal", "no reciclable", "Lata oxidada");
    Producto p3(3, "plastico", "reciclable", "Envase de plastico");
    Producto p4(4, "derivados de papel", "reciclable", "Caja de carton");
    Producto p5(6, "metal", "reciclable", "Lata de Atun");

    gestor.agregarProducto(p1);
    gestor.agregarProducto(p2);
    gestor.agregarProducto(p3);
    gestor.agregarProducto(p4);
    gestor.agregarProducto(p5);

    gestor.imprimirTodasLasPilas();
    std::cout << "\n";
    gestor.contarProductosPorPila();
    std::cout << "\n";
    std::cout << "Cantidad total de productos: " << gestor.contarTotalProductos()<<std::endl;
    std::cout << "\n";

    std::cout << "Eliminando no reciclables\n";
    gestor.eliminarProductosNoReciclables();
    std::cout << "\n";

    gestor.imprimirTodasLasPilas();
    std::cout << "\n";

    std::cout << "Cantidad total de productos: " << gestor.contarTotalProductos() << std::endl;
    std::cout << "\n";

    return 0;
   
}
