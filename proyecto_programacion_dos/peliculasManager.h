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
    void submenuListarPeliculas(bool flag = false);
    void submenuCargarCartelera();
    void submenuBuscarPeliculas();
};

#endif // PELICULASMANAGER_H_INCLUDED
