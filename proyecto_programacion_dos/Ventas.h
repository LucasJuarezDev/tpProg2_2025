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
    Fecha fechaVenta;
    int dniComprador;
    int compradorAsiento;
    int cantidadEntradas;
    int horarioFuncion;
    float totalVenta;

public:

    Venta();
    Venta(int id_venta, int id_pelicula, int id_sala, Fecha fecha_proyeccion, Fecha fecha_venta, int dni, int asiento, int entradas, int horarios, float total);
    // getters
    int getIdVenta();
    int getPelicula();
    int getSalaProyecta();
    Fecha getFechaProyeccion();
    Fecha getFechaVenta();
    int getDniComprador();
    int getAsientoComprador();
    int getCantidadEntradas();
    int getHorarioFuncion();
    float getTotalVenta();

    // setters
    void setIdVenta(int id_venta);
    void setPelicula(int id_pelicula);
    void setSalaProyectada(int id_sala);
    void setFechaProyeccion(Fecha fecha_proyeccion);
    void setFechaVenta(Fecha fecha_venta);
    void setDniComprador(int dni);
    void setCompradorAsiento(int asiento);
    void setCantidadEntradas(int entradas);
    void setHorarioFuncion(int horarios);
    void setTotalVenta(float total);


};



#endif  //VENTAS_H_INCLUDED
