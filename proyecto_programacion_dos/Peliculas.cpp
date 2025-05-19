#include "Peliculas.h"
#include <cstring>

Pelicula :: Pelicula()
{
    IdPelicula = 0;
    strcpy(Nombre, "");
    Duracion = 0;
    strcpy(DirectorNombre, "");
    strcpy(DirectorApellido, "");
    Clasificacion = 0;
    strcpy(Genero, "");
    Estreno = Fecha();
    Activa = false;
}

Pelicula :: Pelicula(int id, const char* nombre, int duracion, const char* director_nombre, const char* director_apellido, int clasificacion, const char* genero, Fecha estreno, bool activo)
{
    setIdPelicula(id);
    setNombre(Nombre);
    setDuracion(duracion);
    setDirectorNombre(director_nombre);
    setDirectorApellido(director_apellido);
    setClasificacion(clasificacion);
    setGenero(genero);
    setEstreno(estreno);
    setActivo(activo);
}

//setters

void Pelicula::setIdPelicula(int id){
    IdPelicula = id;
}

void Pelicula::setNombre(const char* nombre){
    strcpy(Nombre, nombre);
}

void Pelicula::setDuracion(int duracion){
    Duracion = duracion;
}

void Pelicula::setDirectorNombre(const char* director_nombre){
    strcpy(DirectorNombre, director_nombre);
}

void Pelicula::setDirectorApellido(const char* director_apellido){
    strcpy(DirectorApellido, director_apellido);
}

void Pelicula::setClasificacion(int clasificacion){
    Clasificacion = clasificacion;
}

void Pelicula::setGenero(const char* genero){
    strcpy(Genero, genero);
}

void Pelicula::setEstreno(Fecha estreno){
    Estreno = estreno;
}

void Pelicula::setActivo(bool activo){
    Activa = activo;
}

//getters

int Pelicula::getIdPelicula(){
    return IdPelicula;
}

const char* Pelicula::getNombre(){
    return Nombre;
}

int Pelicula::getDuracion(){
    return Duracion;
}

const char* Pelicula::getDirectorNombre(){
    return DirectorNombre;
}

const char* Pelicula::getDirectorApellido(){
    return DirectorApellido;
}

int Pelicula::getClasificacion(){
    return Clasificacion;
}

const char* Pelicula::getGenero(){
    return Genero;
}

Fecha Pelicula::getEstreno(){
    return Estreno;
}

bool Pelicula::getActivo(){
    return Activa;
}
