#ifndef SALASMANAGER_H_INCLUDED
#define SALASMANAGER_H_INCLUDED
#include "salasArchivos.h"
#include "Salas.h"

class salaManager{
private:
    Sala obj;
    salaArchivo archSala;
    void mostrarSala(Sala);
    void cargarCadena(char*, int);
    int configurarButacas();
    int configurarTipoSala();
    void modificarSala(Sala&);
    const char * denominacionXtamanio(int);
public:
    void submenuListarSalas(int menus = 1, bool condicional = false);
    void submenuAnadirSala();
    void submenuBuscarSala();
    void submenuBajaSala(bool alta = false);
    void submenuModificarSala();
    void submenuFiltrarSalaPor();
};

#endif // SALASMANAGER_H_INCLUDED
