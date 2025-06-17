#include "VentasManager.h"
#include <iostream>
#include <cstring>
#include <iomanip>
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

}



//////////////////////////////   SUBMENUS   ///////////////////////////////////////////

void ventasManager::submenuCargarVenta(){
    int id_venta, sala, pelicula, asientos_vendidos, finProceso;
    Fecha fecha_venta;
    float total, precio_x_butaca = 400;

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
        cout << endl;
        cout << "=============================================================="<< endl;
        cout << "SELECCIONE LA SALA CORRESPONDIENTE: ";
        cin >> sala;
        cout << endl;
        cout << "=============================================================="<< endl;
        cout << "SELECCIONE LA PELICULA QUE SE EMITIRA: ";
        cin >> pelicula;
        cout << endl;
        cout << "=============================================================="<< endl;
        cout << "SELECCIONE LA CANTIDAD DE BUTACAS: ";
        cout << "(PRECIO ACTUAL X BUTACA : " << precio_x_butaca << ")" << endl;
        cin >> asientos_vendidos;
        cout << endl;
        cout << "=============================================================="<< endl;


        system("cls");
        cout << "DESEA INTRODUCIR OTRA SALA? (0  - NO | 1 - SI)" << endl;
        cout << "INGRESE: ";
        cin >> finProceso;
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
