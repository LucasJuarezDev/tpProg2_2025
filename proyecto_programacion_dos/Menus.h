#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include "peliculasManager.h"
#include "salasManager.h"
#include "ventasManager.h"
using namespace std;


//PrendaManager ManagerPrend; //creamos los objetos que usaremos para llamar a las funciones
peliculaManager Peliculas;
salaManager Salas;

void Menu1()

{
     int opcion;
    while (true){
        system("cls");
        cout << "+--------------------------------------------+" << endl;
        cout << "|                 PELICULAS                  |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << "|                                            |" << endl;
        cout << "| 1)  AGREGAR PELICULA                       |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 2)  AGREGAR A CARTELERA                    |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 3)  DAR DE BAJA EN CARTELERA               |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 4)  LISTAR CARTELERA                       |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 5)  BUSCAR PELICULA                        |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 6)  LISTAR TODAS LAS PELICULAS             |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 7)  ELIMINAR PELICULA                      |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 0)  MENU ANTERIOR                          |" << endl;
        cout << "|                                            |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << "INGRESE: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                {
                    Peliculas.submenuCargarPeliculas();
                }
                break;
            case 2:
                {
                    Peliculas.submenuCartelera(1);
                }
                break;
            case 3:
                {
                    Peliculas.submenuCartelera(2);
                }
                break;
            case 4:
                {
                    Peliculas.submenuListarPeliculas(1);
                    system("pause");
                }
                break;
            case 5:
                {
                    system("cls");
                    Peliculas.submenuBuscarPeliculas();
                }
                break;
            case 6:
                {
                    Peliculas.submenuListarPeliculas(2);
                    system("pause");
                }
                break;
            case 7:
                {
                    Peliculas.submenuBorrarPeliculas();
                }
                break;
            case 0:
                {
                    return;
                }
                break;
            default:
                if(cin.fail())
                {
                cin.clear();
                cin.ignore();
                cout << "OPCION INCORRECTA" << endl;
                system("pause");
                }
            break;
        }

    }
}

//          MENU DE SALA CINE

void Menu2()
{
    int opcion;
    while (true){
        system("cls");
        cout << "+--------------------------------------------+" << endl;
        cout << "|                  SALAS                     |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << "|                                            |" << endl;
        cout << "| 1)  AGREGAR SALA                           |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 2)  LISTAR TODAS LAS SALAS                 |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 3)  BUSCAR SALA                            |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 4)  FILTRAR SALA POR..                     |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 5)  MODIFICAR SALA                         |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 6)  DAR DE BAJA                            |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 7)  DAR DE ALTA                            |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 0)  MENU ANTERIOR                          |" << endl;
        cout << "|                                            |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << "INGRESE: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                {
                    Salas.submenuAnadirSala();
                }
                break;
            case 2:
                {
                    Salas.submenuListarSalas();
                    system("pause");
                }
                break;
            case 3:
                {
                    Salas.submenuBuscarSala();
                }
                break;
            case 4:
                {
                    Salas.submenuFiltrarSalaPor();
                }
                break;
            case 5:
                {
                    Salas.submenuModificarSala();
                }
                break;
            case 6:
                {
                    Salas.submenuBajaSala();
                }
                break;
            case 7:
                {
                    Salas.submenuBajaSala(true);
                }
                break;
            case 0:
                {
                    return;
                }
                break;
            default:
                if(cin.fail())
                {
                cin.clear();
                cin.ignore();
                cout << "OPCION INCORRECTA" << endl;
                system("pause");
                }
            break;
        }

    }
}

//              MENU DE VENTAS

void Menu3()
{
    int opcion;
    while (true){
        system("cls");
        cout << "+--------------------------------------------+" << endl;
        cout << "|                  VENTAS                    |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << "|                                            |" << endl;
        cout << "| 1)  NUEVA VENTA                            |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 2)  LISTAR VENTAS                          |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 3)  BUSCAR VENTAS POR FECHA                |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 4)  INFORME - VENTA POR PELICULA           |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 5)  INFORME - VENTAS EN EL DIA             |" << endl;
        cout << "|                                            |" << endl;
        cout << "| 0)  MENU ANTERIOR                          |" << endl;
        cout << "|                                            |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << "INGRESE: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                {

                    system("pause");
                }
                break;
            case 2:
                {

                    system("pause");
                }
                break;
            case 3:
                {

                    system("pause");
                }
                break;
            case 0:
                {
                    return;
                }
                break;
            default:
                if(cin.fail())
                {
                cin.clear();
                cin.ignore();
                cout << "OPCION INCORRECTA" << endl;
                system("pause");
                }
            break;
        }

    }
}

#endif // TALLER_H_INCLUDED
