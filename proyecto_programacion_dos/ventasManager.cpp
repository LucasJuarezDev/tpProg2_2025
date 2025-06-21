#include "VentasManager.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//////////////////////////////   METODOS AUXILIARES   ///////////////////////////////////////////

void ventasManager :: cargarCadena(char *Palabra, int Tamanio)
{
    int i=0;
    fflush(stdin);
    for (i=0; i<Tamanio; i++){
        Palabra[i]=cin.get();
        if (Palabra[i]=='\n'){
            break;
        }
    }
    Palabra[i]='\0';
    fflush(stdin);
}

int ventasManager::seleccionHorario(){
    int opcion;
    bool encontro = false;

    do
    {
        cout << "+--------------------------+" << endl;
        cout << "|  SELECCION DE HORARIOS   |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "|                          |" << endl;
        cout << "|     1) 14 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     2) 16 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     3) 17 : 30           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     4) 18 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     5) 19 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     6) 20 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     7) 21 : 30           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     8) 22 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     9) 23 : 15           |" << endl;
        cout << "|                          |" << endl;
        cout << "|    10) 00 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|    11) 00 : 30           |" << endl;
        cout << "|                          |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "INGRESE: ";
        cin >> opcion;

        if(opcion >= 1 && opcion <= 11){
            encontro = true;
        } else {
            cout << "OPCION INVALIDA. INTENTE NUEVAMENTE." << endl;
            system("pause");
        }

    }while(!encontro);

    return opcion;
}

const char * ventasManager::asignarHorario(int opcionElegida){
    switch(opcionElegida) {
        case 1:  return "14:00";
        case 2:  return "16:00";
        case 3:  return "17:30";
        case 4:  return "18:00";
        case 5:  return "19:00";
        case 6:  return "20:00";
        case 7:  return "21:30";
        case 8:  return "22:00";
        case 9:  return "23:15";
        case 10: return "00:00";
        case 11: return "00:30";
    }
}

void ventasManager::mostrarVenta(Venta obj){
    peli = archPelicula.leerPelicula(obj.getPelicula() - 1); //obtengo datos de la peli con su id - LE RESTO UNO AL ID PORQUE LO DEVOLVIA SUMANDOLE 1
    venta_sala = archVenta.leerSala(obj.getSalaProyecta() - 1); // obtengo datos de la sala con el id captado
    int capacidad, horario = 0;

    int horas    = peli.getDuracion() / 60;
    int minutos  = peli.getDuracion() % 60;
    int segundos = 0;

    cout << "+=========================================+" << endl;
    cout << "|         TICKET DE VENTA DE CINE         |" << endl;
    cout << "+=========================================+" << endl;
    cout << "| Operacion N: " << obj.getIdVenta() << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "| Pelicula:     " << peli.getNombre() << endl;
    cout << "| Director:     " << peli.getDirectorNombre() << " " << peli.getDirectorApellido() << endl;
    cout << "| Duracion:     " << setfill('0') << setw(2) << horas << ":" << setfill('0') << setw(2) << minutos << ":" << setfill('0') << setw(2) << segundos << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "| Sala:         " << venta_sala.getNombreSala();
    cout << " - " << venta_sala.getDenominacionSala() << endl;
    cout << "| Asiento N:    " << obj.getAsientoComprador() << endl;
    cout << "| Horario:      " << obj.getHorarioFuncion() << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "| TOTAL:        $" << obj.getTotalVenta() << endl;
    cout << "+=========================================+" << endl;
    cout << endl;

}

bool ventasManager::mostrarSala(int asientos_vendidos){ // metodo privador para realizar el muestreo de salas disponibles para la venta
    bool encontro = false;
    int cantidad = archVenta.ContarRegistrosSala();
    int butacasRestantes = 0, butacasActuales = 0;

    if(cantidad > 0){
        for(int x = 0 ; x < cantidad ; x ++){
            venta_sala = archVenta.leerSala(x);
            butacasActuales = venta_sala.getButacas();
            butacasRestantes = butacasActuales - asientos_vendidos; //filtro directamente las salas compatibles con la cantidad de asientos que se vendan

            if(venta_sala.getActivo() && butacasRestantes >= 0) //si la sala no esta ocupada y las butacas restantes son mayor a 0, muestro la sala a elegir
            {
                cout << "=================================================" << endl;
                cout << "SALA NRO " << venta_sala.getIdSala() << endl;
                cout << "*****************************" << endl;
                cout << "SALA " << venta_sala.getNombreSala() << endl;
                cout << "CALIDAD " << (venta_sala.getTipoSala() == 1 ? "ESTANDAR" : (venta_sala.getTipoSala() == 2) ? "PREMIUM" : "CONFORT PLUS")<< endl;
                cout << "TAMANIO " << venta_sala.getDenominacionSala() << endl;
                cout << "CANTIDAD DE ASIENTOS : " << venta_sala.getButacas() << endl;
                cout << "DISPONIBLE: " << (venta_sala.getSalaOcupada() ? "SI" : "NO")<< endl;
                cout << "EN FUNCIONAMIENTO: " << (venta_sala.getActivo() ? "SI" : "NO")<< endl;
                cout << "*****************************" << endl;
                cout << "=================================================" << endl;
                encontro = true;
            }

            butacasRestantes = butacasActuales = 0;
        }
        if(!encontro)
        {
            cout << "SALAS NO DISPONIBLES PARA LA CANTIDAD DE BUTACAS REQUERIDAS." << endl << endl;
            system("pause");
        }


    }else{
        cout << "ERROR" << endl;
        cout << "------------" << endl;
        cout << "CONTACTE CON SOPORTE TECNICO." << endl;
    }
    return encontro;
}

int ventasManager::ocuparSala(int asientos_vendidos){ // metodo interno para sobreescribir los datos (pasar sala = ocupada y asientos disponibles)
    int pos = 0, sala, id_sala;
    int cantidad = archVenta.ContarRegistrosSala();
    int asientos_disponibles = 0;
    bool encontro = false;

    do
    {
        bool salaDisponible = mostrarSala(asientos_vendidos);
        if(!salaDisponible) return -2;
        cout << "SELECCIONE LA SALA CORRESPONDIENTE: ";
        cin >> sala;
        cout << endl;

        pos = archVenta.BuscarCodigoSala(sala);
        if (pos != -2){ // Pregunto si se encontró en el archivo

            for (int x = 0; x < cantidad; x++){ // Recorro todo el archivo de prendas

                venta_sala = archVenta.leerSala(x);
                if (venta_sala.getIdSala() == sala && venta_sala.getActivo() && venta_sala.getButacas() > 0){// Una vez encontrada modifico y guardo en el archivo

                    id_sala = venta_sala.getIdSala(); //me llevo el id de la sala para luego al salir del metodo quedarmelo
                    asientos_disponibles = venta_sala.getButacas() - asientos_vendidos; //si todo esta ok, hago el calculo de asientos actuales

                    venta_sala.setSalaOcupada(true);
                    venta_sala.setButacas(asientos_disponibles);
                    archVenta.SobreescribirSala(pos, venta_sala);
                    encontro = true;
                    break;
                }
            }
            if(!encontro)
            {
                cout << "SALA NO ENCONTRADA. POR FAVOR, INGRESE UN CODIGO DE PELICULA VALIDO. " << endl;
                system("pause");
            } // Salir del bucle una vez realizada la modificacion
        }else{
            cout << "SALA NO ENCONTRADA. POR FAVOR, INGRESE UN ID VALIDO. " << endl;
            if(cin.fail())
            {
            cin.clear();
            cin.ignore();
            }
            system("pause");
        }
    }while(!encontro);
    return id_sala;
}

int ventasManager :: ocuparPelicula(){
    int pos = 0, pelicula, id_pelicula;
    int cantidad = archPelicula.ContarRegistrosPelicula();
    bool encontro = false;

    do
    {
        managerPelicula.submenuListarPeliculas(1, false);
        cout << "SELECCIONE LA PELICULA QUE SE EMITIRA: ";
        cin >> pelicula;
        cout << endl;

        pos = archPelicula.BuscarCodigoPelicula(pelicula);
        if (pos != -2){ // Pregunto si se encontró en el archivo

            for (int x = 0; x < cantidad; x++){ // Recorro todo el archivo de prendas

                peli = archPelicula.leerPelicula(x);
                if (peli.getIdPelicula() == pelicula && peli.getEnCartelera()){// Una vez encontrada modifico y guardo en el archivo
                    id_pelicula = peli.getIdPelicula();
                    encontro = true;
                    break;
                }
            }
            if(!encontro)
            {
                cout << "PELICULA NO ENCONTRADA. POR FAVOR, INGRESE UN CODIGO DE PELICULA VALIDO. " << endl;
                system("pause");
            } // Salir del bucle una vez realizada la modificacion
        }else{
            cout << "PELICULA NO ENCONTRADA. POR FAVOR, INGRESE UN CODIGO DE PELICULA VALIDO. " << endl;
            if(cin.fail())
            {
            cin.clear();
            cin.ignore();
            }
            system("pause");
        }
    }while(!encontro);
    return id_pelicula;
}

//////////////////////////////   SUBMENUS   ///////////////////////////////////////////

void ventasManager::submenuCargarVenta(){
    srand(time(NULL));
    int id_venta, sala, pelicula, asientos_vendidos, finProceso, opcionElegida, dni, capacidadSala = 0;
    Fecha fecha_venta;
    float total, precio_x_butaca = 400;
    char horario[10], tipoSala[50];

    system("cls");
    cout << "----------------------------------------------------" << endl;
    cout << "                ALTA - VENTA " << endl;
    cout << "----------------------------------------------------" << endl;

    do
    {
        system("cls");
        id_venta = archVenta.generarIdVenta();
        obj.setIdVenta(id_venta);
        cout << "=============================================================="<< endl;
        cout << "VENTA NRO " << id_venta << endl;
        cout << "--------------------------------" << endl;
        cout << "REALIZADA EL ";
        fecha_venta.MostrarFechaActual();
        cout << endl;
        system("pause");
        cout << "=============================================================="<< endl;
        cout << "SELECCIONE LA CANTIDAD DE BUTACAS: ";
        cout << "(PRECIO ACTUAL X BUTACA : " << precio_x_butaca << ")" << endl;
        cin >> asientos_vendidos;
        obj.setCantidadEntradas(asientos_vendidos);
        cout << endl;
        cout << "=============================================================="<< endl;
        sala = ocuparSala(asientos_vendidos);
        if (sala == -2) {
            cout << "NO SE PUEDE COMPLETAR LA VENTA. VOLVIENDO AL MENU." << endl;
            system("pause");
            return;  // salir de la función si no hay sala valida
        }
        obj.setSalaProyectada(sala);
        cout << endl;
        cout << "=============================================================="<< endl;
        pelicula = ocuparPelicula();
        obj.setPelicula(pelicula);
        cout << endl;
        cout << "=============================================================="<< endl;
        opcionElegida = seleccionHorario();
        strcpy(horario, asignarHorario(opcionElegida));
        obj.setHorarioFuncion(horario);
        cout << endl;
        cout << "=============================================================="<< endl;
        do {
            cout << "CONFIRMACION DE COMPRA - DNI DEL CLIENTE: ";
            cin >> dni;
            if (cin.fail() || dni < 1000000 || dni > 99999999) {
                cout << "DNI invalido. Debe tener entre 7 y 8 digitos." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                system("pause");
            } else {
                obj.setDniComprador(dni);
                break;
            }
        }while(true);
        cout << endl;
        cout << "=============================================================="<< endl;
        total = asientos_vendidos * precio_x_butaca;
        obj.setTotalVenta(total);
        venta_sala = archVenta.leerSala(sala - 1);
        strcpy(tipoSala, venta_sala.getDenominacionSala());

        if (strcmp(venta_sala.getDenominacionSala(), "SMALL") == 0) capacidadSala = 150;
        else if (strcmp(venta_sala.getDenominacionSala(), "MEDIUM") == 0) capacidadSala = 300;
        else if (strcmp(venta_sala.getDenominacionSala(), "LARGE") == 0) capacidadSala = 500;
        else if (strcmp(venta_sala.getDenominacionSala(), "MEGA") == 0) capacidadSala = 700;

        for(int x = 0 ; x < obj.getCantidadEntradas() ; x ++){
            Venta nuevaVenta = obj;
            int asientoAleatorio = (rand() % capacidadSala) + 1;
            nuevaVenta.setCompradorAsiento(asientoAleatorio);
            archVenta.guardarVenta(nuevaVenta);
        }

        system("cls");
        cout << "VENTA CONFIRMADA" << endl;
        int posicionInicial = archVenta.cantidadRegistros() - obj.getCantidadEntradas(); //me pos

        for (int x = 0; x < obj.getCantidadEntradas(); x++) {
            Venta v = archVenta.leerVenta(posicionInicial + x);
            mostrarVenta(v);
        }
        cout << "DESEA REALIZAR OTRA VENTA? (0  - NO | 1 - SI)" << endl;
        cout << "INGRESE: ";
        cin >> finProceso;
    }while(finProceso != 0);
}

void ventasManager::submenuListarVentas(){
    int selector, finProceso, resultado;
    int cantidad = archVenta.cantidadRegistros();
    bool encontrada = false, fin = false;

    do
    {
        system("cls");
        cout << "+-------------------------------------------+" << endl;
        cout << "|            DASHBOARD DE VENTAS            |" << endl;
        cout << "+===========================================+" << endl;
        cout << "|            TIPOS DE LISTADOS              |" << endl;
        cout << "+*******************************************+" << endl;
        cout << "|            1   - TODAS                    |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            2   - POR FECHA                |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            3   - POR HORARIO              |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            4   - ATRAS                    |" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << "INGRESE: ";
        cin >> selector;

        switch(selector){
            case 1:
                {
                    system("cls");
                    for(int x = 0 ; x < cantidad ; x ++){
                        obj = archVenta.leerVenta(x);
                        mostrarVenta(obj);
                    }
                }
                system("pause");
                break;
            case 2:
                {

                }
                break;
            case 3:
                {

                }
                break;
            case 4:
                {
                    return;
                }
                break;
            default:
                {
                    if(cin.fail())
                    {
                    cin.clear();
                    cin.ignore();
                    cout << "OPCION INCORRECTA, INGRESE UNA VALIDA." << endl;
                    system("pause");
                    }
                }
                break;
        }

    }while(finProceso != 0);
}

/*
void VentasManager::submenuListarVentas() {
    if (listaVentas.empty()) {
        cout << "No hay ventas registradas." << endl;
        return;
    }

    cout << "Listado de Ventas:" << endl;
    for (const auto& venta : listaVentas) {
        cout << venta.mostrarInformacion() << endl;
    }
}

void VentasManager::submenuImporteTotal() {
    double total = 0.0;
    for (const auto& venta : listaVentas) {
        total += venta.getPrecioTotal();
    }
    cout << "El importe total de las ventas es: $" << total << endl;
}

void VentasManager::registrarVenta() {
    int idSala, idPelicula, cantidadAsientos;
    int asientosVendidos[] = {};
    double precioTotal;
    string fechaHora;

    cout << "Ingrese el ID de la sala: ";
    cin >> idSala;

    cout << "Ingrese el ID de la película: ";
    cin >> idPelicula;

    cout << "Ingrese la cantidad de asientos vendidos: ";
    cin >> cantidadAsientos;

    for (int i = 0; i < cantidadAsientos; i++) {
        int asiento;
        cout << "Ingrese el número del asiento vendido: ";
        cin >> asiento;
        asientosVendidos.guardarventa();
    }

    cout << "Ingrese el precio total de la venta: ";
    cin >> precioTotal;

    cout << "Ingrese la fecha y hora de la venta (ej: 2024-01-26 19:30): ";
    cin.ignore();
    getline(std::cin, fechaHora);

    // Crear el objeto venta
}

void VentasManager::cancelarVenta() {
    int idVenta;
    cout << "Ingrese el ID de la venta a cancelar: ";
    cin >> idVenta;

    // Buscar la venta por ID

}

void VentasManager::buscarVentas() {
    int idVenta;
    cout << "Ingrese el ID de la venta a buscar: ";
    cin >> idVenta;

}

void VentasManager::mostrarVenta() {
    int idVenta;
    cout << "Ingrese el ID de la venta a mostrar: ";
    cin >> idVenta;

}

void VentasManager::guardarCambios() {
    for (const auto& venta : listaVentas) {
        ventasArchivo.guardarVenta(venta);
    }
    std::cout << "Cambios guardados exitosamente en el archivo." << std::endl;
}
*/
