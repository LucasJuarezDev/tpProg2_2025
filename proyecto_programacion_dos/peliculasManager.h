#ifndef PELICULASMANAGER_H_INCLUDED
#define PELICULASMANAGER_H_INCLUDED
#include "peliculasArchivo.h"
#include "Peliculas.h"

class peliculaManager{
private:
    Pelicula cine;
    peliculaArchivo archPelicula;
    void mostrarPelicula(Pelicula);
    int validarDuracion();
    int switchClasificacion();
    void cargarCadena(char*, int);
public:
    void submenuCargarPeliculas();
    void submenuListarPeliculas(int menus = 1, bool condicional = false);
    void submenuCartelera(int menus = 1);
    void submenuBuscarPeliculas();
    void submenuBorrarPeliculas();
};

#endif // PELICULASMANAGER_H_INCLUDED
