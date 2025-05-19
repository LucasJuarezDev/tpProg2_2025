#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#include "Fecha.h"

class Pelicula{
private:
    int IdPelicula;
    char Nombre[100];
    int Duracion;
    char DirectorNombre[50];
    char DirectorApellido[50];
    int Clasificacion;
    char Genero[50];
    Fecha Estreno;
    bool Activa;
public:
    //constructores
    Pelicula(int id, const char* nombre, int duracion, const char* director_nombre, const char* director_apellido, int clasificacion, const char* genero, Fecha estreno, bool activo);
    Pelicula();
    //getters
    int getIdPelicula();
    const char *getNombre();
    int getDuracion();
    const char *getDirectorNombre();
    const char *getDirectorApellido();
    int getClasificacion();
    const char *getGenero();
    bool getActivo();
    Fecha getEstreno();
    //setters
    void setIdPelicula(int id);
    void setNombre(const char* nombre);
    void setDuracion(int duracion);
    void setDirectorNombre(const char* director_nombre);
    void setDirectorApellido(const char* director_apellido);
    void setClasificacion(int clasificacion);
    void setGenero(const char* genero);
    void setEstreno(Fecha estreno);
    void setActivo(bool activo);
    //others
    /* algun otro metodo necesario */
};

#endif // PELICULAS_H_INCLUDED
