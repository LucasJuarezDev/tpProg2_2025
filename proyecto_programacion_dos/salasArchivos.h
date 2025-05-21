#ifndef SALASARCHIVOS_H_INCLUDED
#define SALASARCHIVOS_H_INCLUDED
#include "Salas.h"

class salaArchivo{
private:
    Sala obj;
public:
    bool guardarSala(Sala);
    Sala leerSala(int);
    int ContarRegistrosSala();
    int generarIdSala();
    bool SobreescribirSala(int, Sala);
    int BuscarCodigoSala(int);
};

#endif // SALASARCHIVOS_H_INCLUDED
