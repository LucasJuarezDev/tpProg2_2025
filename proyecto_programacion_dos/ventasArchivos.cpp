#include "ventasArchivos.h"
#include <iostream>
using namespace std;
VentaArchivo::VentaArchivo(){
    NombreArchivo = "ventas.dat";
}

VentaArchivo::VentaArchivo(std::string nombreArchivo){
    NombreArchivo = nombreArchivo;
}


bool VentaArchivo::guardarVenta(Venta registro){

    FILE *p;
    bool Escritura;
    p = fopen(NombreArchivo.c_str(), "ab");
    if(p == nullptr){
        cout<<"NO PUDO ABRIR GUARDADO"<<endl;
        return false;
    }

    Escritura = fwrite(&registro, sizeof(Venta), 1, p);
    fclose(p);
    return Escritura;

}

int VentaArchivo::cantidadRegistros(){

    int tamRegistro, total, cantidad;
    FILE *p;
    p = fopen(NombreArchivo.c_str(), "rb");

    if(p == nullptr){
        return 0;
    }

    fseek(p, 0, SEEK_END);

    tamRegistro = sizeof(Venta);
    total = ftell(p);
    cantidad = total/tamRegistro;
    fclose(p);
    return cantidad;

}
