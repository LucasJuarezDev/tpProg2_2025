#include "peliculasManager.h"
#include "salasManager.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

//////////////////////////////   METODOS AUXILIARES   ///////////////////////////////////////////

void salaManager::cargarCadena(char *Palabra, int Tamanio)
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

int salaManager::configurarButacas()
{
    int selector;
    int butacas;
    bool Error = false;

    do
    {

        cout << "           TAMANIO DE SALA" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1   -       150 ASIENTOS" << endl;
        cout << endl;
        cout << "2   -       300 ASIENTOS" << endl;
        cout << endl;
        cout << "3   -       500 ASIENTOS" << endl;
        cout << endl;
        cout << "4   -       700 ASIENTOS" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> selector;
        switch(selector)
        {
        case 1:
            butacas = 150;
            Error = true;
            break;
        case 2:
            butacas = 300;
            Error = true;
            break;
        case 3:
            butacas = 500;
            Error = true;
            break;
        case 4:
            butacas = 700;
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
    return butacas;
}

int salaManager::configurarTipoSala()
{
    int selector;
    int tipo;
    bool Error = false;

    do
    {

        cout << "           TIPO DE SALA" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "1   -       SALA ESTANDAR" << endl;
        cout << endl;
        cout << "2   -       SALA PREMIUM" << endl;
        cout << endl;
        cout << "3   -       SALA CONFORT PLUS" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> selector;
        switch(selector)
        {
        case 1:
            tipo = 1;
            Error = true;
            break;
        case 2:
            tipo = 2;
            Error = true;
            break;
        case 3:
            tipo = 3;
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
    return tipo;
}

void salaManager::modificarSala(Sala &obj)
{
    int opcion, butacas, tipo_sala;
    char sala[50];

    do
    {
    system("cls");
    cout << "ELIJA QUE DATOS QUIERE MODIFICAR" << endl;
    cout << "===========================================" << endl;
    cout << "SALA A MODIFICAR: " << obj.getIdSala() << "-" << obj.getNombreSala() << endl;
    cout << "---------------------------------------------" << endl;
    cout << "1) MODIFICAR NOMBRE DE SALA" << endl;
    cout << endl;
    cout << "2) MODIFICAR CANTIDAD DE BUTACAS" << endl;
    cout << endl;
    cout << "3) MODIFICAR TIPO DE SALA" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "0) SALIR" << endl;
    cin >> opcion;
    switch(opcion)
    {
    case 1:
        {
            cout << "NUEVO NOMBRE: ";
            cargarCadena(sala, 49);
            obj.setNombreSala(sala);
            cout << endl;
            break;
        }
    case 2:
        {
            butacas = configurarButacas();
            obj.setButacas(butacas);
            cout << endl;
            break;
        }
    case 3:
        {
            tipo_sala = configurarTipoSala();
            obj.setTipoSala(tipo_sala);
            cout << endl;
            break;
        }
    default:
          if(opcion != 0){
            cout << "OPCION INCORRECTA" << endl;
            }
        break;
    }
    system("pause");
    }while(opcion != 0);
}

void salaManager::mostrarSala(Sala obj)
{
    cout << "SALA NRO " << obj.getIdSala() << endl;
    cout << "*****************************" << endl;
    cout << "SALA " << obj.getNombreSala() << endl;
    cout << "CALIDAD : " << (obj.getTipoSala() == 1 ? "ESTANDAR" : (obj.getTipoSala() == 2) ? "PREMIUM" : "CONFORT PLUS")<< endl;
    cout << "CANTIDAD DE ASIENTOS : " << obj.getButacas() << endl;
    cout << "DISPONIBLE: " << (!obj.getSalaOcupada() ? "SI" : "NO")<< endl;
    cout << "EN FUNCIONAMIENTO: " << (obj.getActivo() ? "SI" : "NO")<< endl;
    cout << "*****************************" << endl;
}

//////////////////////////////   SUBMENUS   ///////////////////////////////////////////

void salaManager::submenuListarSalas(int menus, bool condicional)
{
    Sala obj;
    bool encontro = false;
    int cantidad = archSala.ContarRegistrosSala();

    if(cantidad > 0)
    {
        switch(menus)
        {
        case 1:
            {
                for(int x = 0 ; x < cantidad ; x ++){
                    obj = archSala.leerSala(x);

                    cout << "=================================================" << endl;
                    mostrarSala(obj);
                    cout << "=================================================" << endl;
                }
            }
            break;
        case 2:
            {
                for(int x = 0 ; x < cantidad ; x ++){
                    obj = archSala.leerSala(x);

                    if(!obj.getActivo())
                    {
                        cout << "=================================================" << endl;
                        mostrarSala(obj);
                        encontro = true;
                        cout << "=================================================" << endl;
                    }
                }
                if(!encontro)
                {
                    cout << "NO HAY SALAS DADAS DE BAJA ACTUALMENTE.." << endl;
                }
            }
            break;
        }
    }else
    {
        cout << "NO HAY SALAS DISPONIBLES ACTUALMENTE.." << endl;
    }

}

void salaManager::submenuAnadirSala()
{
    Sala obj;
    int id_sala, tipo_sala, butacas, authenticator, finProceso;
    char sala[50];

    system("cls");
    cout << "----------------------------------------------------" << endl;
    cout << "                AÑADIR : SALA " << endl;
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

    do
    {
        system("cls");
        id_sala = archSala.generarIdSala();
        obj.setIdSala(id_sala);
        cout << "=============================================================="<< endl;
        cout << "ID SALA: " << id_sala << endl;
        cout << endl;
        cout << "=============================================================="<< endl;
        cout << "NOMBRE: ";
        cargarCadena(sala, 49);
        obj.setNombreSala(sala);
        cout << endl;
        cout << "=============================================================="<< endl;
        butacas = configurarButacas();
        obj.setButacas(butacas);
        cout << endl;
        cout << "=============================================================="<< endl;
        tipo_sala = configurarTipoSala();
        obj.setTipoSala(tipo_sala);
        cout << endl;
        cout << "=============================================================="<< endl;
        obj.setSalaOcupada(false);
        obj.setActivo(true);

        if(archSala.guardarSala(obj))
        {
          cout << "SALA INCLUIDA CORRECTAMENTE." << endl;
          system("pause");
        }else
        {
          cout << "ALGO SALIO MAL..." << endl;
          system("pause");
        }
        system("cls");
        cout << "DESEA INTRODUCIR OTRA SALA? (0  - NO | 1 - SI)" << endl;
        cout << "INGRESE: ";
        cin >> finProceso;

    }while(finProceso != 0);

}

void salaManager::submenuBuscarSala()
{
    int selector, finProceso, resultado;
    char sala[50];
    int cantidad = archSala.ContarRegistrosSala();
    Sala obj;
    bool encontrada = false, fin = false;

    do
    {
        system("cls");
        cout << "         BUSCADOR DE SALA" << endl;
        cout << "============================================" << endl;
        cout << "DESEA BUSCAR POR NOMBRE O NRO DE SALA?" << endl;
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
                cargarCadena(sala, 49);
                for(int x = 0 ; x < cantidad ; x ++)
                {
                    obj = archSala.leerSala(x);
                    resultado = strcmp(sala, obj.getNombreSala());
                    if(resultado == 0)
                    {
                        system("cls");
                        encontrada = true;
                        cout << "=================================================" << endl;
                        mostrarSala(obj);
                        cout << "=================================================" << endl;
                    }
                }
                if(!encontrada)
                {
                    system("cls");
                    cout << "SALA NO ENCONTRADA" << endl;
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
                    obj = archSala.leerSala(x);
                    if(obj.getIdSala() == selector)
                    {
                        system("cls");
                        encontrada = true;
                        cout << "=================================================" << endl;
                        mostrarSala(obj);
                        cout << "=================================================" << endl;
                    }
                }

                if(!encontrada)
                {
                    system("cls");
                    cout << "SALA NO ENCONTRADA" << endl;
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

void salaManager::submenuBajaSala(bool alta)
{
    Sala obj;
    int finProceso, selector, pos = 0;
    int cantidad = archSala.ContarRegistrosSala();
    bool encontro = false;

    if(!alta)
    {
        do
        {  /////////////////   CERRAR SALA!!    ////////////////////////
            system("cls");
            submenuListarSalas(1);
            cout << endl;
            cout << "(INGRESE '0' EN CASO DE QUERER VOLVER AL MENU PRINCIPAL)" << endl;
            cout << endl;
            cin >> selector;

            if(selector == 0)return;

            pos = archSala.BuscarCodigoSala(selector);
            if (pos != -2){ // Pregunto si se encontró en el archivo

                for (int x = 0; x < cantidad; x++){ // Recorro todo el archivo de prendas

                    obj = archSala.leerSala(x);
                    if (obj.getIdSala() == selector && obj.getActivo()){// Una vez encontrada modifico y guardo en el archivo

                        obj.setActivo(false);
                        archSala.SobreescribirSala(pos, obj);
                        encontro = true;
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

            if(encontro)
            {
                system("cls");
                encontro = false;
                cout << "SALA CERRADA CON EXITO! DESEA SEGUIR BUSCANDO? (0 - NO / 1 - SI)" << endl;
                cout << endl;
                cout << "OPCION: ";
                cin >> finProceso;
            }

        }while(finProceso != 0);
    }else
    {
        do
        {   /////////////////   ABRIR SALA!!  ////////////////////////
            system("cls");
            submenuListarSalas(2);
            cout << endl;
            cout << "(INGRESE '0' EN CASO DE QUERER VOLVER AL MENU PRINCIPAL)" << endl;
            cout << endl;
            cin >> selector;

            if(selector == 0)return;

            pos = archSala.BuscarCodigoSala(selector);
            if (pos != -2){ // Pregunto si se encontró en el archivo

                for (int x = 0; x < cantidad; x++){ // Recorro todo el archivo de prendas

                    obj = archSala.leerSala(x);
                    if (obj.getIdSala() == selector && !obj.getActivo()){// Una vez encontrada modifico y guardo en el archivo

                        obj.setActivo(true);
                        archSala.SobreescribirSala(pos, obj);
                        encontro = true;
                    }
                }
                if(!encontro)
                {
                    system("cls");
                    cout << "SALA NO ENCONTRADA. POR FAVOR, INGRESE UN CODIGO DE PELICULA VALIDO. " << endl;
                    system("pause");
                } // Salir del bucle una vez realizada la modificacion
            }else{
                system("cls");
                cout << "SALA NO ENCONTRADA. POR FAVOR, INGRESE UN ID VALIDO. " << endl;
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
                cout << "SALA REABIERTA CON EXITO! DESEA SEGUIR BUSCANDO? (0 - NO / 1 - SI)" << endl;
                cout << endl;
                cout << "OPCION: ";
                cin >> finProceso;
            }

        }while(finProceso != 0);
    }
}

void salaManager::submenuModificarSala()
{
    int selector, finProceso, pos = 0;
    int cantidad = archSala.ContarRegistrosSala();
    bool encontro = false;
    Sala obj;

    if (cantidad > 0)
    {
        do
        {
            submenuListarSalas(1);
            cout << endl;
            cout << "(INGRESE '0' EN CASO DE QUERER VOLVER AL MENU PRINCIPAL)" << endl;
            cout << endl;
            cin >> selector;

            if(selector == 0)return;

            pos = archSala.BuscarCodigoSala(selector);
            if (pos != -2){ // Pregunto si se encontró en el archivo

                for (int x = 0; x < cantidad; x++){ // Recorro todo el archivo de prendas

                    obj = archSala.leerSala(x);
                    if (obj.getIdSala() == selector){// Una vez encontrada modifico y guardo en el archivo

                        modificarSala(obj);
                        archSala.SobreescribirSala(pos, obj);
                        encontro = true;
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

            if(encontro)
            {
                system("cls");
                encontro = false;
                cout << "SALA MODIFICADA CON EXITO! DESEA SEGUIR BUSCANDO? (0 - NO / 1 - SI)" << endl;
                cout << endl;
                cout << "OPCION: ";
                cin >> finProceso;
            }

        }while(finProceso != 0);
    }else{
        cout << "NO EXISTEN REGISTROS DE SALAS" << endl;
        system("pause");
    }
}

void salaManager::submenuFiltrarSalaPor()
{
    int selector;
    int cantidadRegistros = archSala.ContarRegistrosSala();

    do
    {
        Sala obj;
        system("cls");
        cout << "         SELECTOR DE FILTROS" << endl;
        cout << "============================================" << endl;
        cout << " 1   - POR TIPO DE SALA" << endl;
        cout << endl;
        cout << " 2   - POR TAMANIO DE SALA" << endl;
        cout << endl;
        cout << " 3   - ATRAS" << endl;
        cout << "============================================" << endl;
        cout << "INGRESE: ";
        cin >> selector;
        system("cls");

        switch(selector)
        {
        case 1:
            {
                cout << "           TIPO DE SALA" << endl;
                cout << "----------------------------------------------" << endl;
                cout << "1   -       SALA ESTANDAR" << endl;
                cout << endl;
                cout << "2   -       SALA PREMIUM" << endl;
                cout << endl;
                cout << "3   -       SALA CONFORT PLUS" << endl;
                cout << "----------------------------------------------" << endl;
                cin >> selector;
                switch(selector)
                {
                case 1:
                    {
                        for(int x = 0 ; x < cantidadRegistros ; x ++){
                            obj = archSala.leerSala(x);
                            if(obj.getTipoSala() == 1){
                                cout << "=================================================" << endl;
                                mostrarSala(obj);
                                cout << "=================================================" << endl;
                            }
                        }
                    }
                    system("pause");
                    break;
                case 2:
                    {
                        for(int x = 0 ; x < cantidadRegistros ; x ++){
                            obj = archSala.leerSala(x);
                            if(obj.getTipoSala() == 2){
                                cout << "=================================================" << endl;
                                mostrarSala(obj);
                                cout << "=================================================" << endl;
                            }
                        }
                    }
                    system("pause");
                    break;
                case 3:
                    {
                        for(int x = 0 ; x < cantidadRegistros ; x ++){
                            obj = archSala.leerSala(x);
                            if(obj.getTipoSala() == 3){
                                cout << "=================================================" << endl;
                                mostrarSala(obj);
                                cout << "=================================================" << endl;
                            }
                        }
                    }
                    system("pause");
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
            }
            break;
        case 2:
            {
                cout << "           TAMANIO DE SALA" << endl;
                cout << "----------------------------------------------" << endl;
                cout << "1   -       150 ASIENTOS" << endl;
                cout << endl;
                cout << "2   -       300 ASIENTOS" << endl;
                cout << endl;
                cout << "3   -       500 ASIENTOS" << endl;
                cout << endl;
                cout << "4   -       700 ASIENTOS" << endl;
                cout << "----------------------------------------------" << endl;
                cin >> selector;
                switch(selector)
                {
                case 1:
                    {
                        for(int x = 0 ; x < cantidadRegistros ; x ++){
                            obj = archSala.leerSala(x);
                            if(obj.getButacas() == 150){
                                cout << "=================================================" << endl;
                                mostrarSala(obj);
                                cout << "=================================================" << endl;
                            }
                        }
                    }
                    system("pause");
                    break;
                case 2:
                    {
                        for(int x = 0 ; x < cantidadRegistros ; x ++){
                            obj = archSala.leerSala(x);
                            if(obj.getButacas() == 300){
                                cout << "=================================================" << endl;
                                mostrarSala(obj);
                                cout << "=================================================" << endl;
                            }
                        }
                    }
                    system("pause");
                    break;
                case 3:
                    {
                        for(int x = 0 ; x < cantidadRegistros ; x ++){
                            obj = archSala.leerSala(x);
                            if(obj.getButacas() == 500){
                                cout << "=================================================" << endl;
                                mostrarSala(obj);
                                cout << "=================================================" << endl;
                            }
                        }
                    }
                    system("pause");
                    break;
                case 4:
                    {
                        for(int x = 0 ; x < cantidadRegistros ; x ++){
                            obj = archSala.leerSala(x);
                            if(obj.getButacas() == 700){
                                cout << "=================================================" << endl;
                                mostrarSala(obj);
                                cout << "=================================================" << endl;
                            }
                        }
                    }
                    system("pause");
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
            }
            break;
        case 3:
            {
                return;
            }
            break;
        }

    }while(true);
}


