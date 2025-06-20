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
    char horarioFuncion[10];
    float totalVenta;

public:

    Venta();
    Venta(int id_venta, int id_pelicula, int id_sala, Fecha fecha_proyeccion, int dni, int entradas, const char * horarios, float total);
    // getters
    int getIdVenta();
    int getPelicula();
    int getSalaProyecta();
    Fecha getFechaProyeccion();
    int getDniComprador();
    int getCantidadEntradas();
    const char * getHorarioFuncion();
    float getTotalVenta();

    // setters
    void setIdVenta(int id_venta);
    void setPelicula(int id_pelicula);
    void setSalaProyectada(int id_sala);
    void setFechaProyeccion(Fecha fecha_proyeccion);
    void setDniComprador(int dni);
    void setCantidadEntradas(int entradas);
    void setHorarioFuncion(const char * horarios);
    void setTotalVenta(float total);


};



#endif  //VENTAS_H_INCLUDED
