#include "ventas.h"
#include <cstring>

//constructores
Venta::Venta(){

    strcpy(Pelicula, "");
    SalaProyecta = 0;
    FechaProyeccion = 0;
    DniComprador = 0;
    CantidadEntradas = 0;

}

Venta::Venta(const char* pelicula, int sala_proyecta, int fecha_proyeccion, int dni_comprador, int cantidad_entradas){

    setPelicula(pelicula);
    setSalaPyoecta(sala_proyecta);
    setFechaProyeccion(fecha_proyeccion);
    setDniComprador(dni_comprador);
    setCantidadEntradas(cantidad_entradas);


}

//setters
void Venta::setPelicula(const char* pelicula){
    strcpy(Pelicula, pelicula);
}

void Venta::setSalaPyoecta(int sala_proyecta){
    SalaProyecta = sala_proyecta;
}

void Venta::setFechaProyeccion(int fecha_proyeccion){
    FechaProyeccion = fecha_proyeccion;
}

void Venta::setDniComprador(int dni_comprador){
    DniComprador = dni_comprador;
}

void Venta::setCantidadEntradas(int cantidad_entradas){
    CantidadEntradas = cantidad_entradas;
}
