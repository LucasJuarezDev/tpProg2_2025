#ifndef PELICULASARCHIVO_H_INCLUDED
#define PELICULASARCHIVO_H_INCLUDED
#include "Peliculas.h"

class peliculaArchivo{
private:
    Pelicula obj;
public:
    bool guardarPelicula(Pelicula);
    Pelicula leerPelicula(int);
    int ContarRegistrosPelicula();
    int generarIdPelicula();
    bool SobreescribirPelicula(int, Pelicula);
    int BuscarCodigoPelicula(int);
};


#endif // PELICULASARCHIVO_H_INCLUDED
