#include "ventas.h"
#include <cstring>

//constructores
Venta::Venta(){
    idVenta = 0;
    idPelicula = 0;
    idSala = 0;
    fechaProyeccion = Fecha();
    fechaVenta = Fecha();
    dniComprador = 0;
    compradorAsiento = 0;
    cantidadEntradas = 0;
    strcpy(horarioFuncion, "");
    totalVenta = 0.0f;
}

Venta::Venta(int id_venta, int id_pelicula, int id_sala, Fecha fecha_proyeccion, Fecha fecha_venta, int dni, int asiento, int entradas, const char * horarios, float total){
    setIdVenta(id_venta);
    setPelicula(id_pelicula);
    setSalaProyectada(id_sala);
    setFechaProyeccion(fecha_proyeccion);
    setFechaVenta(fecha_venta);
    setDniComprador(dni);
    setCompradorAsiento(asiento);
    setCantidadEntradas(entradas);
    setHorarioFuncion(horarios);
    setTotalVenta(total);

}

//setters
void Venta::setFechaVenta(Fecha fecha_venta){
    fechaVenta = fecha_venta;
}

void Venta::setCompradorAsiento(int asiento){
    compradorAsiento = asiento;
}

void Venta::setHorarioFuncion(const char * horarios){
    strcpy(horarioFuncion, horarios);
}

void Venta::setTotalVenta(float total){
    totalVenta = total;
}

void Venta::setIdVenta(int id_venta){
    idVenta = id_venta;
}

void Venta::setPelicula(int id_pelicula){
    idPelicula = id_pelicula;
}

void Venta::setSalaProyectada(int id_sala){
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
Fecha Venta::getFechaVenta(){
    return fechaVenta;
}

int Venta::getAsientoComprador(){
    return compradorAsiento;
}

const char * Venta::getHorarioFuncion(){
    return horarioFuncion;
}

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
