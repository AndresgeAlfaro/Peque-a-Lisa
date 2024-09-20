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
            std::cout << "Ingrese una descripci�n del producto: ";
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
            try {
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

                    if (!fechaValida(fechaReciclado)) {
                        throw std::invalid_argument("Fecha inv�lida. Debe estar en formato dd/mm/yyyy.");
                    }

                    std::cout << "Ingrese la descripci�n del producto reciclado: ";
                    std::cin >> descripcionReciclado;

                    time_t fechaRecicladoC = convertirFecha(fechaReciclado);

                    ProductoReciclado* preductoReciclado = new ProductoReciclado(producto->getId(), producto->getTipo(), producto->getEstado(), producto->getDescripcion(), fechaRecicladoC, descripcionReciclado);
                    cola.agregar(preductoReciclado);

                    std::cout << "Producto procesado y encolado exitosamente.\n";
                }
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
            catch (...) {
                std::cout << "Error al procesar el producto!\n";
            }
            break;
        }
        case 4: {
            int idCamion;
            std::string conductor;
            Camion* camion = nullptr;

            std::cout << "Ingrese el ID del camion: ";
            std::cin >> idCamion;
            if (std::cin.fail()) throw std::invalid_argument("ID de camion invalido");

            bool flag = false;
            NodoCamion* actual = camiones.getHead();
            while (actual != nullptr) {
                camion = actual->getData();
                if (camion->getId() == idCamion) { //verificar si el camion ya existe
                    flag = true;
                    break;
                }
                actual = actual->getNext();
            }

            std::cout << "Ingrese el nombre del conductor: ";
            std::cin >> conductor;

            if (!flag) {
                camion = new Camion(idCamion, conductor);
                camiones.agregarCamion(camion);
            }

            int cont = 0;
            const int capacidad = 50; //capacidad default de los camiones

            while (!cola.estaVacia() && cont < capacidad) {
                ProductoReciclado* productoR = cola.procesarProducto();
                camion->agregarProducto(productoR);
                cont;
            }

            std::cout << "Se han cargado " << cont << " productos con en el camion con ID " << idCamion << "\n";
            if (cont == capacidad && cola.estaVacia())
                std::cout << "El camion ha alcanzado su capacidad m�xima\n";

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
            std::cout << "*** PRODUCTOS PROCESADOS ***\n\n";
            cola.toString();
            
            break;
        }
        case 3: {
            // Implementar mostrar lista de camiones
            std::cout << "*** CAMIONES ***\n\n";
            camiones.imprimirLista();
            std::cout << "\n\n*** ORDENAMIENTOS ***\n\n"
                << "BUBBLE SORT\n";
            camiones.ordenarBubbleSort();
            camiones.imprimirLista();
            std::cout << "\n\nINSERTION SORT\n";
            camiones.ordenarInsertionSort();
            camiones.imprimirLista();
            std::cout << "\n\nSELECTION SORT\n";
            camiones.ordenarSelectionSort();
            camiones.imprimirLista();

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

bool InterfazUsuario::fechaValida(const std::string& fecha){
    int dia, mes, anio;
    char delimitador1, delimitador2;

    std::istringstream fechaStream(fecha);
    if (!(fechaStream >> dia >> delimitador1 >> mes >> delimitador2 >> anio) ||
        delimitador1 != '/' || delimitador2 != '/' || dia < 1 || mes < 1 || mes > 12) {
        return false;  // Error de formato b�sico
    }

    // Comprobaci�n de d�as v�lidos por mes
    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        diasPorMes[1] = 29;  // A�o bisiesto
    }

    if (dia > diasPorMes[mes - 1]) {
        return false;  // El d�a no coincide con el n�mero de d�as de ese mes
    }

    return true;
}

time_t InterfazUsuario::convertirFecha(const std::string& fecha){
    int dia, mes, anio;
    char delimitador1, delimitador2;

    std::istringstream fechaStream(fecha);
    fechaStream >> dia >> delimitador1 >> mes >> delimitador2 >> anio;

    struct tm tmFecha = {};
    tmFecha.tm_mday = dia;
    tmFecha.tm_mon = mes - 1;  // Los meses en tm est�n en el rango 0-11
    tmFecha.tm_year = anio - 1900;  // Los a�os en tm se cuentan desde 1900

    return mktime(&tmFecha);  // Convertir struct tm a time_t
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