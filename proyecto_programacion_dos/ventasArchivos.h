#ifndef VENTASARCHIVOS_H_INCLUDED
#define VENTASARCHIVOS_H_INCLUDED
#include <string>
#include "Ventas.h"
#include "Salas.h"

class VentaArchivo{

private:
    Venta obj;
    Sala venta_sala;
public:
    bool guardarVenta(Venta);
    Venta leerVenta(int);
    int cantidadRegistros();
    int generarIdVenta();
    int buscarCodigoVenta(int);
    // METODOS RELACIONADOS CON SALA
    Sala leerSala(int);
    int ContarRegistrosSala();
    bool SobreescribirSala(int, Sala);
    int BuscarCodigoSala(int);
};


#endif // VENTASARCHIVOS_H_INCLUDED
