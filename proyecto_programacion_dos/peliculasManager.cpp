#include "peliculasManager.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

//////////////////////////////   METODOS AUXILIARES   ///////////////////////////////////////////

void peliculaManager :: cargarCadena(char *Palabra, int Tamanio)
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

void peliculaManager::mostrarPelicula(Pelicula obj)
{
    int horas    = obj.getDuracion() / 60;
    int minutos  = obj.getDuracion() % 60;
    int segundos = 0;

    cout << "PELICULA NRO " << obj.getIdPelicula() << endl;
    cout << "*******************************************" << endl;
    cout << "TITULO: " << obj.getNombre() << endl;
    cout << "DURACION: " << setfill('0') << setw(2) << horas << ":" << setfill('0') << setw(2) << minutos << ":" << setfill('0') << setw(2) << segundos << endl;
    cout << "   -----------------------    " << endl;
    cout << "DIRIGIDA POR: " << obj.getDirectorNombre();
    cout << " " << obj.getDirectorApellido() << endl;
    cout << "   -----------------------    " << endl;
    cout << "CLASIFICACION: " << (obj.getClasificacion() == 1 ? "APTP" : (obj.getClasificacion() == 2) ? "PARA MAYORES DE 14" : "MAYORES DE 18")<< endl;
    cout << "GENERO: " << obj.getGenero() << endl;
    cout << "DISPONIBLE EN CARTELERA: " << (obj.getEnCartelera() ? "SI" : "NO")<< endl;
}

int peliculaManager::validarDuracion()
{
        int duracion;

    do {
        cin >> duracion;

        if (!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            duracion = -1;
            cout << "  ERROR: Entrada no valida. Intente nuevamente" << endl;
        }
        else if (duracion < 0) {
            cout << "  ERROR: Debe ser un numero no negativo" << endl;
        }

    }while (duracion < 0);
    return duracion;
}

int peliculaManager::switchClasificacion()
{
    int selector;
    int clasificacion;
    bool Error = false;

    do
    {

        cout << "CLASIFICACION DE PELICULA" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1 -    APTA PARA TODO PUBLICO" << endl;
        cout << endl;
        cout << "2 -    MAYORES DE 14 ANIOS" << endl;
        cout << endl;
        cout << "3 -    MAYORES DE 18 ANIOS" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> selector;
        switch(selector)
        {
        case 1:
            clasificacion = 1;
            Error = true;
            break;
        case 2:
            clasificacion = 2;
            Error = true;
            break;
        case 3:
            clasificacion = 3;
            Error = true;
            break;
        default:
            cout << "OPCION INCORRECTA. INDIQUE NUEVAMENTE ALGUNA DE LAS OPCIONES." << endl;
            system("pause");
            system("cls");
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            break;
        }


    }while(Error != true);
    return clasificacion;
}

//////////////////////////////   SUBMENUS   ///////////////////////////////////////////

void peliculaManager::submenuListarPeliculas(int menus, bool condicional)
{
        Pelicula obj;

    int cantidad = archPelicula.ContarRegistrosPelicula();
    int peliculasEnCartelera = 0;

    system("cls");
    if(cantidad > 0)
    {
        switch(menus)
        {
        case 1:
            {  // LISTA SOLO LAS PELICULAS EN CARTELERA
                for(int x = 0 ; x < cantidad ; x ++)
                {
                    obj = archPelicula.leerPelicula(x);
                    if(obj.getEnCartelera() && !obj.getBorrar())
                    {
                        cout << "=================================================" << endl;
                        mostrarPelicula(obj);
                        peliculasEnCartelera ++;
                        cout << "=================================================" << endl;
                    }
                }
                if(peliculasEnCartelera == 0)
                {
                    cout << "NO HAY PELICULAS EN CARTELERA." << endl;
                }
            }
            break;
        case 2:
            {   //LISTA TODAS LAS PELICULAS
                for(int x = 0 ; x < cantidad ; x ++)
                {
                    obj = archPelicula.leerPelicula(x);
                    if(!obj.getBorrar())
                    {
                        cout << "=================================================" << endl;
                        mostrarPelicula(obj);
                        cout << "=================================================" << endl;
                    }
                }
            }
            break;
        case 3:
            {   //LISTA LAS PELICULAS DISPONIBLES A SELECCIONAR EN CARTELERA
                if(condicional)
                {
                    cout << "          BORRAR PELICULA EN CARTELERA" << endl << endl;
                    cout << "Seleccione una pelicula para dar de baja a la cartelera de hoy" << endl;
                    for(int x = 0 ; x < cantidad ; x ++)
                    {
                        obj = archPelicula.leerPelicula(x);
                        if(obj.getEnCartelera() && !obj.getBorrar())
                        {
                            cout << "=================================================" << endl;
                            mostrarPelicula(obj);
                            peliculasEnCartelera ++;
                            cout << "=================================================" << endl;
                        }
                    }
                    if(peliculasEnCartelera == 0)
                    {
                        cout << "NO HAY PELICULAS DISPONIBLES A ELEGIR." << endl;
                    }
                }else
                {
                    cout << "          AGREGAR PELICULA A CARTELERA" << endl << endl;
                    cout << "Seleccione una pelicula para agregar a la cartelera de hoy" << endl;
                    for(int x = 0 ; x < cantidad ; x ++)
                    {
                        obj = archPelicula.leerPelicula(x);
                        if(!obj.getEnCartelera() && !obj.getBorrar())
                        {
                            cout << "=================================================" << endl;
                            mostrarPelicula(obj);
                            peliculasEnCartelera ++;
                            cout << "=================================================" << endl;
                        }
                    }
                    if(peliculasEnCartelera == 0)
                    {
                        cout << "NO HAY PELICULAS DISPONIBLES A ELEGIR." << endl;
                    }
                }

            }
            break;
        }
    }else
    {
        cout << "NO HAY PELICULAS CARGADAS ACTUALMENTE" << endl;
        return;
    }
}

void peliculaManager::submenuCargarPeliculas()
{
    Pelicula obj;
    int id_pelicula, duracion, clasificacion, finProceso, authenticator;
    char pelicula[100], direc_name[50], direc_surname[50], genero[50];
    Fecha estreno;

    system("cls");
    cout << "----------------------------------------------------" << endl;
    cout << "                ALTA : PELICULA " << endl;
    cout << "(ADVERTENCIA - REQUIERE AUTORIZACION DE SUPERVISOR) " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "INTRODUZCA ID SUPERVISOR : ";
    cin >> authenticator;
    if(authenticator != 12)
    {
        system("cls");
        cout << "USTED NO TIENE AUTORIZACION PARA ESTA ACCION." << endl;
        system("pause");
        return;
    }

    do{
        system("cls");
        id_pelicula = archPelicula.generarIdPelicula();
        obj.setIdPelicula(id_pelicula);
        cout << "=============================================================="<< endl;
        cout << "ID PELICULA: " << id_pelicula << endl;
        cout << endl;
        cout << "=============================================================="<< endl;
        cout << "TITULO: ";
        cargarCadena(pelicula, 99);
        obj.setNombre(pelicula);
        cout << endl;
        cout << "=============================================================="<< endl;
        cout << "DURACION (EN MINUTOS): ";
        duracion = validarDuracion();
        obj.setDuracion(duracion);
        cout << endl;
        cout << "=============================================================="<< endl;
        cout << "DIRECTOR" << endl;
        cout << "**********" << endl;
        cout << "NOMBRE: ";
        cargarCadena(direc_name, 49);
        obj.setDirectorNombre(direc_name);
        cout << endl;
        cout << "**********" << endl;
        cout << "APELLIDO: ";
        cargarCadena(direc_surname, 49);
        obj.setDirectorApellido(direc_surname);
        cout << endl;
        cout << "=============================================================="<< endl;
        cout << "CLASIFICACION: ";
        clasificacion = switchClasificacion();
        obj.setClasificacion(clasificacion);
        cout << endl;
        cout << "=============================================================="<< endl;
        cout << "GENERO: ";
        cargarCadena(genero, 49);
        obj.setGenero(genero);
        obj.setEnCartelera(false);
        obj.setBorrar(false);
        cout << endl;
        cout << "=============================================================="<< endl;
        if(archPelicula.guardarPelicula(obj))
        {
          cout << "PELICULA CARGADA CORRECTAMENTE." << endl;
          system("pause");
        }else
        {
          cout << "ALGO SALIO MAL..." << endl;
          system("pause");
        }
        system("cls");
        cout << "DESEA INGRESAR OTRA PELICULA? (0  - NO | 1 - SI)" << endl;
        cout << "INGRESE: ";
        cin >> finProceso;

    }while(finProceso != 0);
}

void peliculaManager::submenuBuscarPeliculas()
{
    int selector, finProceso, resultado;
    char pelicula[50];
    int cantidad = archPelicula.ContarRegistrosPelicula();
    Pelicula obj;
    bool encontrada = false;

    do
    {
        system("cls");
        cout << "         BUSCADOR DE PELICULA" << endl;
        cout << "============================================" << endl;
        cout << "DESEA BUSCAR POR NOMBRE O NRO DE PELICULA?" << endl;
        cout << "*************************************" << endl;
        cout << " 1   - POR NOMBRE" << endl;
        cout << endl;
        cout << " 2   - POR NUMERO" << endl;
        cout << endl;
        cout << " 3   - ATRAS" << endl;
        cout << "============================================" << endl;
        cout << "INGRESE: ";
        cin >> selector;

        switch(selector)
        {
        case 1:
            {
                system("cls");
                cout << "===========================" << endl;
                cout << endl;
                cout << "INGRESE EL NOMBRE A BUSCAR" << endl;
                cout << endl;
                cout << "===========================" << endl;
                cout << "INGRESE AQUI: ";
                cargarCadena(pelicula, 49);
                for(int x = 0 ; x < cantidad ; x ++)
                {
                    obj = archPelicula.leerPelicula(x);
                    resultado = strcmp(pelicula, obj.getNombre());
                    if(resultado == 0)
                    {
                        system("cls");
                        encontrada = true;
                        cout << "=================================================" << endl;
                        mostrarPelicula(obj);
                        cout << "=================================================" << endl;
                    }
                }
                if(!encontrada)
                {
                    system("cls");
                    cout << "PELICULA NO ENCONTRADA" << endl;
                }
                system("pause");
                system("cls");
                cout << "DESEA SEGUIR BUSCANDO? (0 - NO / 1 - SI)" << endl;
                cin >> finProceso;
            }
            break;
        case 2:
            {
                selector = 0;
                encontrada = false;
                system("cls");
                cout << "===========================" << endl;
                cout << endl;
                cout << "INGRESE EL NUMERO A BUSCAR" << endl;
                cout << endl;
                cout << "===========================" << endl;
                cout << "INGRESE AQUI: ";
                cin >> selector;

                for(int x = 0 ; x < cantidad ; x ++)
                {
                    obj = archPelicula.leerPelicula(x);
                    if(obj.getIdPelicula() == selector)
                    {
                        system("cls");
                        encontrada = true;
                        cout << "=================================================" << endl;
                        mostrarPelicula(obj);
                        cout << "=================================================" << endl;
                    }
                }

                if(!encontrada)
                {
                    system("cls");
                    cout << "PELICULA NO ENCONTRADA" << endl;
                }
                system("pause");
                system("cls");
                cout << "DESEA SEGUIR BUSCANDO? (0 - NO / 1 - SI)" << endl;
                cin >> finProceso;
            }
            break;
        case 3:
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

void peliculaManager::submenuCartelera(int menus)
{
    int finProceso, selector, pos = 0;
    int cantidad = archPelicula.ContarRegistrosPelicula();
    bool encontro = false;

    switch(menus)
    {
    case 1:
        {
            do
            {
                submenuListarPeliculas(3);
                cout << endl;
                cout << "(INGRESE '0' EN CASO DE QUERER VOLVER AL MENU PRINCIPAL)" << endl;
                cout << endl;
                cin >> selector;

                if(selector == 0)return;

                pos = archPelicula.BuscarCodigoPelicula(selector);
                if (pos != -2){ // Pregunto si se encontró en el archivo

                    for (int x = 0; x < cantidad; x++){ // Recorro todo el archivo de prendas

                        cine = archPelicula.leerPelicula(x);
                        if (cine.getIdPelicula() == selector && !cine.getEnCartelera()){// Una vez encontrada modifico y guardo en el archivo

                            cine.setEnCartelera(true);
                            archPelicula.SobreescribirPelicula(pos, cine);
                            encontro = true;
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

                if(encontro)
                {
                    encontro = false;
                    cout << "PELICULA ENCONTRADA! DESEA SEGUIR BUSCANDO? (0 - NO / 1 - SI)" << endl;
                    cout << endl;
                    cout << "OPCION: ";
                    cin >> finProceso;
                }
            }while(finProceso != 0);
        }
        break;
    case 2:
        {
            do
            {
                submenuListarPeliculas(3, true);
                cout << endl;
                cout << "(INGRESE '0' EN CASO DE QUERER VOLVER AL MENU PRINCIPAL)" << endl;
                cout << endl;
                cin >> selector;

                if(selector == 0)return;

                pos = archPelicula.BuscarCodigoPelicula(selector);
                if (pos != -2){ // Pregunto si se encontró en el archivo

                    for (int x = 0; x < cantidad; x++){ // Recorro todo el archivo de prendas

                        cine = archPelicula.leerPelicula(x);
                        if (cine.getIdPelicula() == selector && cine.getEnCartelera()){// Una vez encontrada modifico y guardo en el archivo

                            cine.setEnCartelera(false);
                            archPelicula.SobreescribirPelicula(pos, cine);
                            encontro = true;
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

                if(encontro)
                {
                    encontro = false;
                    cout << "PELICULA ENCONTRADA! DESEA SEGUIR BUSCANDO? (0 - NO / 1 - SI)" << endl;
                    cout << endl;
                    cout << "OPCION: ";
                    cin >> finProceso;
                }
            }while(finProceso != 0);
        }
        break;
    }
}

void peliculaManager::submenuBorrarPeliculas()
{
    int finProceso, selector, pos = 0;
    int cantidad = archPelicula.ContarRegistrosPelicula();
    bool encontro = false;

    do
    {
        submenuListarPeliculas(2);
        cout << endl;
        cout << "(INGRESE '0' EN CASO DE QUERER VOLVER AL MENU PRINCIPAL)" << endl;
        cout << endl;
        cin >> selector;

        if(selector == 0)return;

        pos = archPelicula.BuscarCodigoPelicula(selector);
        if (pos != -2){ // Pregunto si se encontró en el archivo

            for (int x = 0; x < cantidad; x++){ // Recorro todo el archivo de prendas

                cine = archPelicula.leerPelicula(x);
                if (cine.getIdPelicula() == selector && !cine.getBorrar()){// Una vez encontrada modifico y guardo en el archivo

                    cine.setBorrar(true);
                    archPelicula.SobreescribirPelicula(pos, cine);
                    encontro = true;
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

        if(encontro)
        {
            system("cls");
            encontro = false;
            cout << "PELICULA BORRADA! DESEA SEGUIR BUSCANDO? (0 - NO / 1 - SI)" << endl;
            cout << endl;
            cout << "OPCION: ";
            cin >> finProceso;
        }

    }while(finProceso != 0);
}

