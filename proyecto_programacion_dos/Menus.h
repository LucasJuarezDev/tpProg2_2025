#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include "peliculasManager.h"
using namespace std;


//PrendaManager ManagerPrend; //creamos los objetos que usaremos para llamar a las funciones
peliculaManager Peliculas;

void Menu1()

{
     int opcion;
    while (true){
        system("cls");
        cout << "         PELICULAS" << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        cout << "1)    AGREGAR PELICULA" << endl;
        cout << endl;
        cout << "2)    AGREGAR A CARTELERA" << endl;
        cout << endl;
        cout << "3)    DAR DE BAJA EN CARTELERA" << endl;
        cout << endl;
        cout << "4)    LISTAR CARTELERA" << endl;
        cout << endl;
        cout << "5)    BUSCAR PELICULA"<< endl;
        cout << endl;
        cout << "6)    LISTAR TODAS LAS PELICULAS"<< endl;
        cout << endl;
        cout << "7)    ELIMINAR PELICULA"<< endl;
        cout << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        cout << "0)   MENU ANTERIOR" << endl << endl;
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
        cout << "       SALAS" << endl;
        cout << "--------------------------" << endl;
        cout << endl;
        cout << "1)    VER INVENTARIO" << endl;
        cout << endl;
        cout << "2)   DETALLES DE PRENDA" << endl;
        cout << endl;
        cout << "3)   DETALLES DE PRENDA" << endl;
        cout << endl;
        cout << "4)   DETALLES DE PRENDA" << endl;
        cout << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        cout << "0)   MENU ANTERIOR" << endl << endl;
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
        cout << "      VENTAS" << endl;
        cout << "-------------------------" << endl;
        cout << endl;
        cout << "1)  NUEVA VENTA" << endl;
        cout << endl;
        cout << "2)   LISTAR VENTAS" << endl;
        cout << endl;
        cout << "3)  INFORME - VENTA POR PELICULA" << endl;
        cout << endl;
        cout << "3)  INFORME - VENTAS EN EL DIA" << endl;
        cout << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        cout << "0)   MENU ANTERIOR" << endl << endl;
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
