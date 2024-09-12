#include <thread>
#include <chrono>
#include "GestosPilaProductos.h"
#include "Camion.h"

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

void menu() {
    std::cout << "*** MENU PRINCIPAL ***\n"
        << "[ 1 ] Ingresar producto\n"
        << "[ 2 ] Buscar producto\n"
        << "[ 3 ] Procesar productos \n"
        << "[ 4 ] Distribuir productos\n"
        << "[ 5 ] Eliminar productos no reciclables\n"
        << "[ 6 ] Vista\n"
        << "[ 7 ] Salir\n";
}

void vista() {
    std::cout << "*** VISTA ***\n"
        << "[ 1 ] Mostrar productos\n"
        << "[ 2 ] Mostrar productos procesados\n"
        << "[ 3 ] Mostrar lista de camiones\n"
        << "[ 4 ] Mostrar lista de rutas\n"
        << "[ 5 ] Salir";
}

int main() {

    GestosPilaProductos gestor;

    int opcion = 0;

    while (opcion != 6) {
        menu();
        std::cout << "Seleccione la opcion que desea realizar: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            int id;
            std::string tipo, estado, descripcion;

            std::cout << "Ingrese el ID del producto: ";
            std::cin >> id;
            std::cout << "Ingrese el tipo de producto (vidrio, metal, derivados de papel, plastico): ";
            std::cin >> tipo;
            std::cout << "Ingrese el estado del producto (reciclable/no reciclable): ";
            std::cin >> estado;
            std::cout << "Ingrese una descripción del producto: ";
            std::cin >> descripcion;

            Producto nuevoProducto(id, tipo, estado, descripcion);
            gestor.agregarProducto(nuevoProducto);

            std::cout << "PRODUCTO INGRESADO\n";
            break;
        }
        case 2: {
            int id;
            std::cout << "Ingrese el ID del producto que desea buscar: ";
            std::cin >> id;
            Producto* aux = gestor.buscarProductoPorID(id);

            if (aux->getId() != 0) {
                std::cout << "Producto encontrado: " << aux->toString() << std::endl;
            }
            else {
                std::cout << "El producto con el ID " << id << "no fue encontrado\n";
            }
            break;
        }
        case 3: {
            std::string tipo;
            std::cout << "Ingrese el tipo de producto a procesar (vidrio, metal, papel, plastico): ";
            std::cin >> tipo;

            PilaProductos& pila = gestor.obtenerPilaPorTipo(tipo);
            
            if (pila.estaVacio()) {
                std::cout << "No hay productos de tipo " << tipo << " por procesar\n";
            }
            else {
                Producto* producto = pila.obtenerCima();
                pila.popProducto();

                std::string fechaReciclado;
                std::string descripcionReciclado;
                std::cout << "Ingrese la fecha de reciclado (dd/mm/yyyy): ";
                std::cin >> fechaReciclado;
                std::cout << "Ingrese la descripción del producto reciclado: ";
                std::cin >> descripcionReciclado;

                producto->setDescripcion(descripcionReciclado);

                //pendiente por encolar

                std::cout << "Producto procesado y encolado exitosamente.\n";
            }
        }
        case 4: {
            int idCamion;
            std::string conductor;

            std::cout << "Ingrese el ID del camion: ";
            std::cin >> idCamion;
            std::cout << "Ingrese el nombre del conductor: ";
            std::cin >> conductor;

            Camion camion(idCamion, conductor);

            //pendiente cargar productos de la cola
        }
        case 5: {
            std::cout << "Eliminando no reciclables...\n";
            gestor.eliminarProductosNoReciclables();
            std::cout << "\n";
            sleep_for(3000ms);
            std::cout << "PRODUCTOS ELIMINADOS\n";
        }
        case 6: {
            int opcionVista = 0;
            while (opcionVista != 5) {
                vista();
                std::cout << "Seleccione la opcion que desea realizar: ";
                std::cin >> opcion;

                switch (opcionVista) {
                case 1: {
                    std::cout << "*** PRODUCTOS ***\n\n";
                    gestor.imprimirTodasLasPilas();
                    std::cout << "\n";
                    gestor.contarProductosPorPila();
                    std::cout << "\n";
                    std::cout << "Cantidad total de productos: " << gestor.contarTotalProductos() << std::endl;
                    std::cout << "\n";
                }
                case 2: {

                }
                case 3: {

                }
                case 4: {

                }
                case 5: {
                    std::cout << "Saliendo... \n";
                    break;
                }
                default:
                    std::cout << "Opcion invalida!\n";
                }

            }
        }
        case 7: {
            std::cout << "Saliendo... \n";
            break;
        }
        default:
            std::cout << "Opcion invalida!\n";
        }

    }

   /* Producto p1(1, "vidrio", "reciclable", "Botella de vidrio");
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
    std::cout << "Cantidad total de productos: " << gestor.contarTotalProductos() << std::endl;
    std::cout << "\n";

    std::cout << "Eliminando no reciclables\n";
    gestor.eliminarProductosNoReciclables();
    std::cout << "\n";

    gestor.imprimirTodasLasPilas();
    std::cout << "\n";

    std::cout << "Cantidad total de productos: " << gestor.contarTotalProductos() << std::endl;
    std::cout << "\n";*/

    return 0;

}
