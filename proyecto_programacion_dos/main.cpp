#include <iostream>
#include <windows.h>
#include "Menus.h"

using namespace std;

void SetColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main()
{
    SetColor(10);
    int opcion;
    while (true){
        system("cls");
        cout << "+--------------------------------------------+" << endl;
        cout << "|              GESTION DE CINE               |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << "|               MENU PRINCIPAL               |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << "|                                            |" << endl;
        cout << "|     1) PELICULAS                           |" << endl;
        cout << "|     2) SALAS                               |" << endl;
        cout << "|     3) VENTAS                              |" << endl;
        cout << "|     4) ESTADISTICAS                        |" << endl;
        cout << "|                                            |" << endl;
        cout << "|     0) SALIR                               |" << endl;
        cout << "|                                            |" << endl;
        cout << "+--------------------------------------------+" << endl;
        cout << "INGRESE: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                {
                    Menu1();
                }
                break;
            case 2:
                {
                    Menu2();
                }
                break;
            case 3:
                {
                    Menu3();
                }
                break;
            case 4:
                {
                    Menu4();
                }
                break;
            case 0:
                {
                    return 0;
                }
                break;
            default:
                cout << "OPCION INCORRECTA" << endl;
                system("pause");
            break;
        }

    }
}
