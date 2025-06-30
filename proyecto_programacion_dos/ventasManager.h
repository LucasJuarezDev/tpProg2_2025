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
        //atributos
        Venta obj;
        Sala venta_sala;
        Pelicula peli;
        VentaArchivo archVenta;
        peliculaArchivo archPelicula;
        peliculaManager managerPelicula;
        //metodos
        void cargarCadena(char*, int);
        void mostrarVenta(Venta);
        bool mostrarSala(int);
        int ocuparSala(int);
        int ocuparPelicula();
        bool funcionExistente(int, Fecha, int);
        int butacasDisponibles(int, Fecha);
    public:
    ///////////////SUBMENU VENTAS///////////////////
    void submenuCargarVenta();
    void submenuListarVentas();
    ///////////////ESTADISTICAS///////////////////
    void estadisticaVentasMes();
};

#endif // VENTASMANAGER_H_INCLUDED
