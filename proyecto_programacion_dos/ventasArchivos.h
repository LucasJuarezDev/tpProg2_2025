#ifndef VENTASARCHIVOS_H_INCLUDED
#define VENTASARCHIVOS_H_INCLUDED
#include <string>
#include "Ventas.h"

class VentaArchivo{

private:
    Venta obj;
    std::string NombreArchivo;

public:
    //constructores
    VentaArchivo();
    VentaArchivo(std::string nombreArchivo);
    bool guardarVenta(Venta registro);
    int cantidadRegistros();




};


#endif // VENTASARCHIVOS_H_INCLUDED
