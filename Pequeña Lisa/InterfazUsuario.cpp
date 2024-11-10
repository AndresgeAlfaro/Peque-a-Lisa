#include "InterfazUsuario.h"

InterfazUsuario::InterfazUsuario() {
    // Inicializaci�n de puntos de recolecci�n y procesamiento
    centrosRecoleccion.push_back({ 1, "Punto Limpio Montes de Oca", "San Pedro, San Jose" });
    centrosRecoleccion.push_back({ 2, "Centro de Acopio Curridabat", "Curridabat, San Jose" });
    centrosRecoleccion.push_back({ 3, "Centro de Acopio Santa Ana", "Santa Ana, San Jose" });
    centrosRecoleccion.push_back({ 4, "Centro de Recoleccion y Reciclaje Hatillo", "Hatillo, San Jose" });
    centrosRecoleccion.push_back({ 5, "Centro de Acopio Belen", "Belen, Heredia" });
    centrosRecoleccion.push_back({ 6, "Punto Verde Escaz�", "Escaz�, San Jos�" });

    centrosProcesamiento.push_back({ 7, "Ecolones Centro de Procesamiento de Materiales", "La Uruca, San Jose" });
    centrosProcesamiento.push_back({ 8, "Total Reclaim S.A.", "El Coyol, Alajuela" });
    centrosProcesamiento.push_back({ 9, "Multigestiones Ambientales", "San Rafael de Heredia" });
    centrosProcesamiento.push_back({ 10, "Pedregal Centro de Procesamiento de Reciclaje", "San Antonio de Belen, Heredia" });
    centrosProcesamiento.push_back({ 11, "Recicladora La Virgen", "Sarapiqui, Heredia" });
    centrosProcesamiento.push_back({ 12, "Planta de Compostaje Tilaran", "Tilaran, Guanacaste" });

    // Agregar nodos al grafo y al �rbol AVL
    for (const auto& punto : centrosRecoleccion) {
        NodoGrafo* nodo = new NodoGrafo(punto.id, punto.nombre, punto.ubicacion);
        grafo.agregarNodo(nodo);
        arbolAVL.insertar(nodo); // Insertar en el �rbol AVL
    }

    for (const auto& punto : centrosProcesamiento) {
        NodoGrafo* nodo = new NodoGrafo(punto.id, punto.nombre, punto.ubicacion);
        grafo.agregarNodo(nodo);
        arbolAVL.insertar(nodo); // Insertar en el �rbol AVL
    }
}

    

void InterfazUsuario::menu() {
    std::cout << "*** MENU PRINCIPAL ***\n"
        << "[ 1 ] Ingresar producto\n"
        << "[ 2 ] Buscar producto\n"
        << "[ 3 ] Procesar productos\n"
        << "[ 4 ] Distribuir productos\n"
        << "[ 5 ] Eliminar productos no reciclables\n"
        << "[ 6 ] Vista\n"
        << "[ 7 ] Gestionar camiones y rutas\n"
        << "[ 8 ] Mostrar grafo en AVL\n"  // Nueva opci�n para mostrar el �rbol AVL
        << "[ 9 ] Salir\n";
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
            int idCamion, idRuta;
            std::string conductor, ubicacion;
            Camion* camion = nullptr;
            RutaDistribucion* ruta = nullptr;

            std::cout << "Ingrese el ID del camion: ";
            std::cin >> idCamion;
            if (std::cin.fail()) throw std::invalid_argument("ID de camion invalido");

            bool flagC = false;
            NodoCamion* actualC = camiones.getHead();
            while (actualC != nullptr) {
                camion = actualC->getData();
                if (camion->getId() == idCamion) {
                    flagC = true;
                    break;
                }
                actualC = actualC->getNext();
            }
            if (!flagC) {
                std::cout << "Ingrese el nombre del conductor: ";
                std::cin >> conductor;
                camion = new Camion(idCamion, conductor);
                camiones.agregarCamion(camion);
            }

            std::cout << "Ingrese el ID de la ruta: ";
            std::cin >> idRuta;
            if (std::cin.fail()) throw std::invalid_argument("ID de ruta invalido");

            bool flagR = false;
            NodoRuta* actualR = rutas.getHead();
            while (actualR != nullptr) {
                ruta = actualR->getData();
                if (ruta->getId() == idRuta) {
                    flagR = true;
                    break;
                }
                actualR = actualR->getNext();
            }

            if (!flagR) {
                std::cout << "Ingrese la ubicaci�n de la ruta: ";
                std::cin >> ubicacion;
                ruta = new RutaDistribucion(idRuta, ubicacion);
                rutas.agregarRutaFinal(ruta);
            }

            bool flagCRuta = false;
            NodoCamion* actualCamionRuta = camionesRuta.getHead();
            while (actualCamionRuta != nullptr) {
                Camion* camionEnRuta = actualCamionRuta->getData();
                if (camionEnRuta->getId() == idCamion) {
                    flagCRuta = true;
                    break;
                }
                actualCamionRuta = actualCamionRuta->getNext();
            }

            if (!flagCRuta) {
                camionesRuta.agregarCamion(camion);
            }

            int cont = 0;
            const int capacidad = 50;

            while (!cola.estaVacia() && cont < capacidad) {
                ProductoReciclado* productoR = cola.procesarProducto();
                camion->agregarProducto(productoR);
                cont++;
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
            menuGestorRutas();
            break;
        }
        case 8: {
            std::cout << "*** GRAFO EN ARBOL AVL ***\n";
            arbolAVL.mostrar();  // Muestra el �rbol AVL en orden
            break;
        }
            

        case 9: {
            std::cout << "Saliendo...\n";
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
        vista();
        switch (opcionVista) {
        case 1: {
            std::cout << "*** PRODUCTOS ***\n\n";
            gestor.imprimirTodasLasPilas();
            std::cout << "Cantidad total de productos: " << gestor.contarTotalProductos() << std::endl;
            break;
        }
        case 2: {
            std::cout << "*** PRODUCTOS PROCESADOS ***\n\n"
                << cola.toString();
            break;
        }
        case 3: {
            std::cout << "*** CAMIONES ***\n\n"
                << camiones.imprimirLista();
            std::cout << "\n\n*** ORDENAMIENTOS ***\n\n"
                << "BUBBLE SORT\n";
            camiones.ordenarBubbleSort();
            std::cout << camiones.imprimirLista();
            std::cout << "\n\nINSERTION SORT\n";
            camiones.ordenarInsertionSort();
            std::cout << camiones.imprimirLista();
            std::cout << "\n\nSELECTION SORT\n";
            camiones.ordenarSelectionSort();
            std::cout << camiones.imprimirLista();
            break;
        }
        case 4: {
            std::cout << "*** RUTAS ***\n\n";
            rutas.toStringRutas();
            std::cout << "\n\n*** ORDENAMIENTOS ***\n\n"
                << "QUICK SORT\n";
            rutas.ordenarQuickSort();
            rutas.toStringRutas();
            std::cout << "\n\nMERGE SORT\n";
            rutas.ordenarMergeSort();
            rutas.toStringRutas();
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
        return false;
    }

    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        diasPorMes[1] = 29;
    }

    if (dia > diasPorMes[mes - 1]) {
        return false;
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
    tmFecha.tm_mon = mes - 1;
    tmFecha.tm_year = anio - 1900;

    return mktime(&tmFecha);
}


void InterfazUsuario::ejecutar() {
    int opcion = 0;
    while (opcion != 8) {
        menu();
        std::cout << "Seleccione la opci�n que desea realizar: ";
        std::cin >> opcion;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opci�n inv�lida, por favor ingrese un n�mero.\n";
            continue;
        }
        manejarOpcion(opcion);
    }
}

void InterfazUsuario::registrarCamion(int id){
    camionesGrafo.push_back(id);
    std::cout << "Camion con el id " << id << " registrado.\n";
}

void InterfazUsuario::generarRutaAleatoria(int idCamion){
    if (camionesGrafo.empty()) {
        std::cout << "No hay camiones registrados.\n";
        return;
    }

    if (centrosRecoleccion.empty() || centrosProcesamiento.empty()) {
        std::cout << "No hay centros de recolecci�n o procesamiento disponibles.\n";
        return;
    }

    std::random_device rd;
    std::mt19937 g(rd());

    shuffle(centrosRecoleccion.begin(), centrosRecoleccion.end(), g);
    shuffle(centrosProcesamiento.begin(), centrosProcesamiento.end(), g);

    std::vector<Punto> ruta;

    // Selecci�n de 4 centros de recolecci�n aleatorios
    for (int i = 0; i < 4; ++i) {
        ruta.push_back(centrosRecoleccion[i]);
    }

    // Selecci�n de 4 centros de procesamiento aleatorios
    for (int i = 0; i < 4; ++i) {
        ruta.push_back(centrosProcesamiento[i]);
    }

    std::cout << "Ruta generada para el camion " << idCamion << ":\n";
    for (const auto& punto : ruta) {
        std::cout << "ID: " << punto.id << ", Nombre: " << punto.nombre << ", Ubicacion: " << punto.ubicacion << "\n";
    }

    BusquedaRuta algoritmo;
    for (int i = 0; i < ruta.size() - 1; ++i) {
        NodoGrafo* origen = grafo.buscarNodo(ruta[i].id);
        NodoGrafo* destino = grafo.buscarNodo(ruta[i + 1].id);

        if (origen && destino) {
            // Usar buscarRutaOptima para obtener la ruta desde el nodo origen hasta el nodo destino
            algoritmo.buscarRutaOptima(grafo, origen->id, destino->id);

            std::vector<NodoGrafo*> rutaCamion = algoritmo.obtenerRuta(destino->id);

            std::cout << "Ruta de " << origen->nombre
                << " (ID: " << origen->id << ") a "
                << destino->nombre << " (ID: "
                << destino->id << ") (Cami�n "
                << idCamion << "):\n\n"
                << "Recorrido: ";

            for (auto& nodo : rutaCamion) {
                std::cout << nodo->nombre << " (ID: " << nodo->id << ") ";
            }
            std::cout << "\n";
        }
        else {
            std::cout << "Error: Nodo no encontrado en la ruta.\n";
        }
       
    }

}

void InterfazUsuario::menuGestorRutas(){
    int opcion;
    do {
        std::cout << "\n--- Menu Principal ---\n"
            << "1. Registrar camion\n"
            << "2. Generar ruta aleatoria para un cami�n\n"
            << "3. Salir\n"
            << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            int id;
            std::cout << "Ingrese el ID del camion: ";
            std::cin >> id;
            registrarCamion(id);
            break;
        }
        case 2: {
            if (camionesGrafo.empty()) {
                std::cout << "No hay camiones registrados.\n";
            }
            else {
                int id;
                std::cout << "Ingrese el ID del camion para generar una ruta: ";
                std::cin >> id;
                generarRutaAleatoria(id);
            }
            break;
        }
        case 3:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opci�n inv�lida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 3);
}
