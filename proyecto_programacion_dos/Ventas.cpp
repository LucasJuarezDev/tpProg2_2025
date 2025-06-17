#include "ventas.h"
#include <cstring>

//constructores
Venta::Venta(){
    idVenta = 0;
    idPelicula = 0;
    idSala = 0;
    fechaProyeccion = Fecha();
    dniComprador = 0;
    cantidadEntradas = 0;
    totalVenta = 0.0f;
}

Venta::Venta(int id_venta, int id_pelicula, int id_sala, Fecha fecha_proyeccion, int dni, int entradas, float total){
    setIdVenta(id_venta);
    setPelicula(id_pelicula);
    setSalaPyoecta(id_sala);
    setFechaProyeccion(fecha_proyeccion);
    setDniComprador(dni);
    setCantidadEntradas(entradas);
    setTotalVenta(total);

}

//setters
void Venta::setTotalVenta(float total){
    totalVenta = total;
}

void Venta::setIdVenta(int id_venta){
    idVenta = id_venta;
}

void Venta::setPelicula(int id_pelicula){
    idPelicula = id_pelicula;
}

void Venta::setSalaPyoecta(int id_sala){
    idSala = id_sala;
}

void Venta::setFechaProyeccion(Fecha fecha_proyeccion){
    fechaProyeccion = fecha_proyeccion;
}

void Venta::setDniComprador(int dni){
    dniComprador = dni;
}

void Venta::setCantidadEntradas(int entradas){
    cantidadEntradas = entradas;
}

//getters
float Venta::getTotalVenta(){
    return totalVenta;
}

int Venta::getIdVenta(){
    return idVenta;
}

int Venta::getPelicula(){
    return idPelicula;
}

int Venta::getSalaProyecta(){
    return idSala;
}

Fecha Venta::getFechaProyeccion(){
    return fechaProyeccion;
}

int Venta::getDniComprador(){
    return dniComprador;
}

int Venta::getCantidadEntradas(){
    return cantidadEntradas;
}
