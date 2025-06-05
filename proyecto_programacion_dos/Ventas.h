#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class Venta
{

private:

    char Pelicula[50];
    int SalaProyecta;
    int FechaProyeccion;
    int DniComprador;
    int CantidadEntradas;


public:

    Venta();
    Venta(const char* pelicula, int sala_proyecta, int fecha_proyeccion, int dni_comprador, int cantidad_entradas);
    // getters
    const char* getPelicula();
    int getSalaProyecta();
    int getFechaProyeccion();
    int getDniComprador();
    int getCantidadEntradas();

    // setters
    void setPelicula(const char* pelicula);
    void setSalaPyoecta(int sala_proyecta);
    void setFechaProyeccion(int fecha_proyeccion);
    void setDniComprador(int dni_comprador);
    void setCantidadEntradas(int cantidad_entradas);



};



#endif  //VENTAS_H_INCLUDED
