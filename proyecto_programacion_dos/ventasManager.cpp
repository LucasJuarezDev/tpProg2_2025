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

void ventasManager::mostrarVenta(Venta obj){
    Fecha muestra_fecha;
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
    cout << "| Realizada - ";
    muestra_fecha.MostrarFechaActual(obj.getFechaVenta());
    cout << "+-----------------------------------------+" << endl;
    cout << "| Pelicula:     " << peli.getNombre() << endl;
    cout << "| Director:     " << peli.getDirectorNombre() << " " << peli.getDirectorApellido() << endl;
    cout << "| Duracion:     " << setfill('0') << setw(2) << horas << ":" << setfill('0') << setw(2) << minutos << ":" << setfill('0') << setw(2) << segundos << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "| Fecha de Funcion - ";
    muestra_fecha.MostrarFechaActual(obj.getFechaProyeccion(), true);
    cout << "| Horario de Funcion - ";
    muestra_fecha.mostrarHora(obj.getFechaProyeccion().getHora());
    cout << "| Sala:         " << venta_sala.getNombreSala();
    cout << " - " << venta_sala.getDenominacionSala() << endl;
    cout << "| Asiento N:    " << obj.getAsientoComprador() << endl;
    cout << "+-----------------------------------------+" << endl;
    cout << "| PRECIO:        $" << obj.getTotalVenta() << endl;
    cout << "+=========================================+" << endl;

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
                    venta_sala.setSalaOcupada(true);
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

bool ventasManager::funcionExistente(int id_sala, Fecha fecha_funcion, int id_pelicula){ //ayuda a determinar antes de confirmar venta si la sala esta en uso a esa fecha
    int cantidadVentas = archVenta.cantidadRegistros();

    for(int x = 0 ; x < cantidadVentas ; x ++){
        Venta ventaGuardada = archVenta.leerVenta(x);

        if(ventaGuardada.getSalaProyecta() == id_sala &&
           ventaGuardada.getFechaProyeccion().getDia() == fecha_funcion.getDia() &&
           ventaGuardada.getFechaProyeccion().getMes() == fecha_funcion.getMes() &&
           ventaGuardada.getFechaProyeccion().getHora() == fecha_funcion.getHora()
        ){
            if (ventaGuardada.getPelicula() == id_pelicula) {
                continue; // determinamos que, la venta que coincide el dia/mes/hora con una funcion, es la funcion en efecto haciendo otra venta
            }
            return true; // se intento meter otra pelicula en el mismo dia/mes/hora
        }
    }
    return false;
}

int ventasManager::butacasDisponibles(int id_sala, Fecha fecha_funcion){
    int total = 0;
    int cantidadVentas = archVenta.cantidadRegistros();

    for(int x = 0 ; x < cantidadVentas ; x ++){
        Venta ventaGuardada = archVenta.leerVenta(x);

        if( ventaGuardada.getSalaProyecta() == id_sala &&
           ventaGuardada.getFechaProyeccion().getDia() == fecha_funcion.getDia() &&
           ventaGuardada.getFechaProyeccion().getMes() == fecha_funcion.getMes() &&
           ventaGuardada.getFechaProyeccion().getHora() == fecha_funcion.getHora()
        ){
            total ++;
        }
    }
    return total;
}

//////////////////////////////   SUBMENUS   ///////////////////////////////////////////

void ventasManager::submenuCargarVenta(){
    obj = Venta();
    srand(time(NULL));
    int id_venta, sala, pelicula, asientos_vendidos, asientos_ocupados, finProceso, opcionElegida, dni, capacidadSala = 0;
    Fecha fecha_venta, obj_fecha;
    float total = 0, precio_x_butaca = 400;
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
        obj_fecha = fecha_venta.CargarFecha();
        system("cls");
        cout << "=============================================================="<< endl;
        cout << "                VENTA NRO " << id_venta << endl;
        cout << "--------------------------------------------------------------" << endl;
        cout << "REALIZA EL ";
        obj.getFechaVenta().MostrarFechaActual(fecha_venta);
        obj.setFechaVenta(fecha_venta);
        cout << "--------------------------------------------------------------" << endl;
        cout << "FECHA DE FUNCION ";
        obj.getFechaProyeccion().MostrarFechaActual(obj_fecha);
        obj.setFechaProyeccion(obj_fecha);
        obj.setHorarioFuncion(obj_fecha.getHora());
        cout << "=============================================================="<< endl;
        cout << endl;
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
        venta_sala = archVenta.leerSala(sala - 1);
        strcpy(tipoSala, venta_sala.getDenominacionSala()); //Determino el tamaño de la sala

        if (strcmp(venta_sala.getDenominacionSala(), "SMALL") == 0) capacidadSala = 150;
        else if (strcmp(venta_sala.getDenominacionSala(), "MEDIUM") == 0) capacidadSala = 300;
        else if (strcmp(venta_sala.getDenominacionSala(), "LARGE") == 0) capacidadSala = 500;
        else if (strcmp(venta_sala.getDenominacionSala(), "MEGA") == 0) capacidadSala = 700;

        int puedoProceder = butacasDisponibles(obj.getSalaProyecta(), obj.getFechaProyeccion());

        asientos_ocupados = capacidadSala - (puedoProceder + asientos_vendidos);
        // DIFERENCIA ENTRE LA CAPACIDAD QUE TIENE LA SALA Y LAS ENTRADAS YA VENDIDAS + LAS ENTRADAS DE ESTA VENTA

        if(funcionExistente(obj.getSalaProyecta(), obj.getFechaProyeccion(), obj.getPelicula())){
            //SE ELIGIO EN EL MISMO DIA/MES/HORA , MISMA SALA Y DISTINTA PELICULA -  | FUNCION YA OCUPADA |
            system("cls");
            cout << "                      ERROR" << endl;
            cout << "---------------------------------------------------" << endl;
            cout << "YA EXISTE UNA FUNCION EN ESA SALA, FECHA Y HORARIO." << endl;
            cout << "NO SE PUEDE COMPLETAR LA VENTA." << endl;
            cout << "---------------------------------------------------" << endl;
            system("pause");
            continue;
        }
        else if(asientos_ocupados < 0){//SI ES MENOR A 0, LA VENTA NO PUEDE PROCEDER
            system("cls");
            cout << "                      ERROR" << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << "              NO HAY BUTACAS SUFICIENTES" << endl;
            cout << "            NO SE PUEDE COMPLETAR LA VENTA." << endl;
            cout << "------------------------------------------------------------" << endl;
            system("pause");
            return;
        }

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

        for(int x = 0 ; x < obj.getCantidadEntradas() ; x ++){
            Venta nuevaVenta = obj;
            int asientoAleatorio = (rand() % capacidadSala) + 1;
            nuevaVenta.setCompradorAsiento(asientoAleatorio);
            nuevaVenta.setTotalVenta(precio_x_butaca);
            archVenta.guardarVenta(nuevaVenta);
        }

        system("cls");
        cout << "              VENTA CONFIRMADA!" << endl;
        cout << "---------------------------------------------" << endl;
        cout << endl;
        int posicionInicial = archVenta.cantidadRegistros() - obj.getCantidadEntradas();
        total = 0;

        for (int x = 0; x < obj.getCantidadEntradas(); x++) {
            Venta v = archVenta.leerVenta(posicionInicial + x);
            mostrarVenta(v);
            total += v.getTotalVenta();
        }
        cout << "| TOTAL DE TODA LA OPERACION: $" << total << endl;
        cout << "+=========================================+" << endl << endl;

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
                 system("cls");
                    Fecha _fecha;
                    int dia, mes, anio = 0;
                    bool correcto = false;
                    while(correcto == false)
                        {
                        cout << "Ingrese el anio: " ;
                        cin >> anio;
                        cout << endl << "Ingrese el mes: " ;
                        cin >> mes;
                        cout << endl << "Ingrese el dia: ";
                        cin >> dia;

                        if(anio >= 2020 && anio <= 2030 && mes >=1 && mes <=12 && dia >= 1 && dia <=31)
                            {
                            correcto = true;
                            }
                        else
                            {
                            cout << "La fecha ingresada es incorrecta, por favor ingrese una fecha nuevamente";
                            system ("pause");
                            }
                        }

                    for(int y = 0 ; y < cantidad ; y ++)
                        {
                        obj = archVenta.leerVenta(y);
                        if(obj.getFechaVenta().getAnio() == anio && obj.getFechaVenta().getMes() == mes && obj.getFechaVenta().getDia() == dia)
                            {
                            mostrarVenta(obj);
                            }
                        }

                system("pause");
                }
                break;
            case 3:
                {
                    system("cls");
                    Fecha _fecha;
                    int hora = 0;
                    int acu = 0;
                    bool correcto = false;
                    while(correcto == false)
                        {
                        cout << "Ingrese la hora: " ;
                        cin >> hora;


                        if(hora >= 00 && hora <= 23)
                            {
                            correcto = true;
                            }
                        else
                            {
                            cout << "La hora ingresada es incorrecta, por favor ingrese un horario nuevamente";
                            system ("pause");
                            }
                        }

                    for(int z = 0 ; z < cantidad ; z++)
                        {
                        obj = archVenta.leerVenta(z);
                        if(obj.getFechaProyeccion().getHora() == hora)
                            {
                            mostrarVenta(obj);
                            acu++;
                            }
                        }
                    if (acu == 0)
                        {
                        cout << endl << "=================================================" << "NO HUBO VENTAS EN TAL HORARIO" << endl;
                        }
                    else
                        {
                        cout << endl << "=================================================" << endl << "HUBO UN TOTAL DE " << acu << " VENTAS EN EL HORARIO DE LAS " << hora << ":00 hs. APROX." << endl;
                        }
                }
                system("pause");
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

//////////////////////////////////   ESTADISTICAS   ////////////////////////////////////////////////////////

void ventasManager::estadisticaVentasMes(){
    int selector;
    int cantidad = archVenta.cantidadRegistros();
    bool encontro = false;
    string meses [12] =
    {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};

    do
    {
        system("cls");
        cout << "+-------------------------------------------+" << endl;
        cout << "|               VENTAS X MES                |" << endl;
        cout << "+===========================================+" << endl;
        cout << "|            1   - ENERO                    |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            2   - FEBRERO                  |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            3   - MARZO                    |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            4   - ABRIL                    |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            5   - MAYO                     |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            6   - JUNIO                    |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            7   - JULIO                    |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            8   - AGOSTO                   |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            9   - SEPTIEMBRE               |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            10   - OCTUBRE                 |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            11   - NOVIEMBRE               |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            12   - DICIEMBRE               |" << endl;
        cout << "|                                           |"<< endl;
        cout << "|            0   - ATRAS                    |" << endl;
        cout << "+-------------------------------------------+" << endl;
        cout << "INGRESE: ";
        cin >> selector;

        if (selector >= 1 && selector <= 12) {
            for (int x = 0; x < cantidad; x++) {
                obj = archVenta.leerVenta(x);
                if (obj.getFechaVenta().getMes() == selector) {
                    mostrarVenta(obj);
                    encontro = true;
                }
            }

            if(!encontro){
                system("cls");
                cout << "----------------------------------------" << endl;
                cout << "NO HUBO VENTAS EN EL MES DE " << meses[selector - 1] << "." << endl;
                cout << "----------------------------------------" << endl;
            }
            system("pause");
        }
        else if (selector != 0) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cout << "OPCION INCORRECTA, INGRESE UNA VALIDA." << endl;
            system("pause");
        }

    }while(selector != 0);
}


