#include "Salas.h"
#include <cstring>

//constructores

Sala::Sala()
{
    IdSala = 0;
    strcpy(NombreSala, "");
    TipoSala = 0;
    Butacas = 0;
    SalaOcupada = false;
    Activo = false;
}

Sala::Sala(int id, const char* nombre, int tipo, int butacas, bool sala_ocupada, bool activo)
{
    setIdSala(id);
    setNombreSala(nombre);
    setTipoSala(tipo);
    setButacas(butacas);
    setSalaOcupada(sala_ocupada);
    setActivo(activo);
}

//setters

void Sala::setIdSala(int id){
    IdSala = id;
}

void Sala::setNombreSala(const char* nombre){
    strcpy(NombreSala, nombre);
}

void Sala::setTipoSala(int tipo){
    TipoSala = tipo;
}

void Sala::setButacas(int butacas){
    Butacas = butacas;
}

void Sala::setSalaOcupada(bool sala_ocupada){
    SalaOcupada = sala_ocupada;
}

void Sala::setActivo(bool activo){
    Activo = activo;
}
//getters

int Sala::getIdSala(){
    return IdSala;
}

const char* Sala::getNombreSala(){
    return NombreSala;
}

int Sala::getTipoSala(){
    return TipoSala;
}

int Sala::getButacas(){
    return Butacas;
}

bool Sala::getSalaOcupada(){
    return SalaOcupada;
}

bool Sala::getActivo(){
    return Activo;
}
