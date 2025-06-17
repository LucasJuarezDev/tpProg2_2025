#ifndef VENTASARCHIVOS_H_INCLUDED
#define VENTASARCHIVOS_H_INCLUDED
#include <string>
#include "Ventas.h"

class VentaArchivo{

private:
    Venta obj;

public:
    bool guardarVenta(Venta);
    Venta leerVenta(int);
    int cantidadRegistros();
    int generarIdVenta();
    int buscarCodigoVenta(int);
};


#endif // VENTASARCHIVOS_H_INCLUDED
