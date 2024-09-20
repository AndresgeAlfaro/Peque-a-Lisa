#include "InterfazUsuario.h"

InterfazUsuario::InterfazUsuario() {}

void InterfazUsuario::menu() {
    std::cout << "*** MENU PRINCIPAL ***\n"
        << "[ 1 ] Ingresar producto\n"
        << "[ 2 ] Buscar producto\n"
        << "[ 3 ] Procesar productos \n"
        << "[ 4 ] Distribuir productos\n"
        << "[ 5 ] Eliminar productos no reciclables\n"
        << "[ 6 ] Vista\n"
        << "[ 7 ] Salir\n";
}

void InterfazUsuario::vista() {
    std::cout << "*** VISTA ***\n"
        << "[ 1 ] Mostrar productos\n"
        << "[ 2 ] Mostrar productos procesados\n"
        << "[ 3 ] Mostrar lista de camiones\n"
        << "[ 4 ] Mostrar lista de rutas\n"
        << "[ 5 ] Salir\n";
}

void InterfazUsuario::manejarOpcion(int opcion) {
    try {
        switch (opcion) {
        case 1: {
            int id;
            std::string tipo, estado, descripcion;

            std::cout << "Ingrese el ID del producto: ";
            std::cin >> id;
            if (std::cin.fail()) throw std::invalid_argument("ID invalido");

            std::cout << "Ingrese el tipo de producto (vidrio, metal, derivados de papel, plastico): ";
            std::cin >> tipo;
            std::cout << "Ingrese el estado del producto (reciclable/no reciclable): ";
            std::cin >> estado;
            std::cout << "Ingrese una descripción del producto: ";
            std::cin >> descripcion;

            Producto* nuevoProducto = new Producto(id, tipo, estado, descripcion);
            gestor.agregarProducto(nuevoProducto);

            std::cout << "PRODUCTO INGRESADO\n";
            break;
        }
        case 2: {
            int id;
            std::cout << "Ingrese el ID del producto que desea buscar: ";
            std::cin >> id;
            if (std::cin.fail()) throw std::invalid_argument("ID invalido");

            Producto* aux = gestor.buscarProductoPorID(id);

            if (aux && aux->getId() != 0) {
                std::cout << "Producto encontrado: " << aux->toString() << std::endl;
            }
            else {
                std::cout << "El producto con el ID " << id << " no fue encontrado\n";
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

                std::string fechaReciclado, descripcionReciclado;
                std::cout << "Ingrese la fecha de reciclado (dd/mm/yyyy): ";
                std::cin >> fechaReciclado;
                std::cout << "Ingrese la descripción del producto reciclado: ";
                std::cin >> descripcionReciclado;

                producto->setDescripcion(descripcionReciclado);
                // pendiente por encolar

                std::cout << "Producto procesado y encolado exitosamente.\n";
            }
            break;
        }
        case 4: {
            int idCamion;
            std::string conductor;

            std::cout << "Ingrese el ID del camion: ";
            std::cin >> idCamion;
            if (std::cin.fail()) throw std::invalid_argument("ID de camion invalido");

            std::cout << "Ingrese el nombre del conductor: ";
            std::cin >> conductor;

            Camion camion(idCamion, conductor);
            // pendiente cargar productos de la cola
            break;
        }
        case 5: {
            std::cout << "Eliminando no reciclables...\n";
            gestor.eliminarProductosNoReciclables();
            std::cout << "PRODUCTOS ELIMINADOS\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            break;
        }
        case 6: {
            int opcionVista = 0;
            while (opcionVista != 5) {
                vista();
                std::cout << "Seleccione la opcion que desea realizar: ";
                std::cin >> opcionVista;
                manejarVista(opcionVista);
            }
            break;
        }
        case 7: {
            std::cout << "Saliendo... \n";
            break;
        }
        default:
            std::cout << "Opcion invalida!\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void InterfazUsuario::manejarVista(int opcionVista) {
    while (true) {
        switch (opcionVista) {
        case 1: {
            std::cout << "*** PRODUCTOS ***\n\n";
            gestor.imprimirTodasLasPilas();
            std::cout << "Cantidad total de productos: " << gestor.contarTotalProductos() << std::endl;
            break;
        }
        case 2: {
            // Implementar mostrar productos procesados
            break;
        }
        case 3: {
            // Implementar mostrar lista de camiones
            break;
        }
        case 4: {
            // Implementar mostrar lista de rutas
            break;
        }
        case 5: {
            std::cout << "Saliendo... \n";
            return;
        }
        default:
            std::cout << "Opcion invalida! Por favor intente de nuevo.\n";
        }

        std::cout << "Seleccione la opcion que desea realizar: ";
        std::cin >> opcionVista;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opcion invalida, por favor ingrese un numero.\n";
            opcionVista = 0;
        }
    }
}


void InterfazUsuario::ejecutar() {
    int opcion = 0;
    while (opcion != 7) {
        menu();
        std::cout << "Seleccione la opcion que desea realizar: ";
        std::cin >> opcion;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Opcion invalida, por favor ingrese un numero.\n";
            continue;
        }
        manejarOpcion(opcion);
    }
}