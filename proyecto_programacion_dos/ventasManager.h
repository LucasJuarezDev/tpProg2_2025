#ifndef VENTASMANAGER_H_INCLUDED
#define VENTASMANAGER_H_INCLUDED
#include "Ventas.h"
#include "Salas.h"
#include "Peliculas.h"
#include "peliculasArchivo.h"
#include "peliculasManager.h"
#include "ventasArchivos.h"

class ventasManager
{
    private:
        Venta obj;
        Sala venta_sala;
        Pelicula peli;
        VentaArchivo archVenta;
        peliculaArchivo archPelicula;
        peliculaManager managerPelicula;
        void cargarCadena(char*, int);
        void mostrarVenta(Venta);
        void mostrarSala(int);
        int ocuparSala(int);
        int ocuparPelicula();
    public:
    void submenuCargarVenta();
    void submenuListarVentas();
    //void submenuImporteTotal();
    //void registrarVenta();
    //void cancelarVenta();
    //void buscarVentas();
    //void mostrarVenta();
   //void guardarCambios();
};

#endif // VENTASMANAGER_H_INCLUDED
