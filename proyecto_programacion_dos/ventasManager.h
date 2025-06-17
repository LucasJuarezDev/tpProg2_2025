#ifndef VENTASMANAGER_H_INCLUDED
#define VENTASMANAGER_H_INCLUDED
#include "Ventas.h"
#include "ventasArchivos.h"

class ventasManager
{
    private:
        Venta obj;
        VentaArchivo archVenta;
    public:
    void submenuListarVentas();
    void submenuImporteTotal();
    void registrarVenta();
    void cancelarVenta();
    void buscarVentas();
    void mostrarVenta();
    void guardarCambios();
};

#endif // VENTASMANAGER_H_INCLUDED
