#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "Fecha.h"

class Venta
{

private:
    int idVenta;
    int idPelicula;
    int idSala;
    Fecha fechaProyeccion;
    int dniComprador;
    int cantidadEntradas;


public:

    Venta();
    Venta(int id_venta, int id_pelicula, int id_sala, Fecha fecha_proyeccion, int dni, int entradas);
    // getters
    int getIdVenta();
    int getPelicula();
    int getSalaProyecta();
    Fecha getFechaProyeccion();
    int getDniComprador();
    int getCantidadEntradas();

    // setters
    void setIdVenta(int id_venta);
    void setPelicula(int id_pelicula);
    void setSalaPyoecta(int id_sala);
    void setFechaProyeccion(Fecha fecha_proyeccion);
    void setDniComprador(int dni);
    void setCantidadEntradas(int entradas);



};



#endif  //VENTAS_H_INCLUDED
