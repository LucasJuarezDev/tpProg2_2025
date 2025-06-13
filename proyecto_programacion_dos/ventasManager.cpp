/**
#include "VentasManager.h"
#include <iostream>
#include <iomanip>
#include <limits>

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
