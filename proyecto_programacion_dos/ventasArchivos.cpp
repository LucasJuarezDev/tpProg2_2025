#include "ventasArchivos.h"
#include <iostream>
using namespace std;

bool VentaArchivo::guardarVenta(Venta registro){

    FILE *p;
    bool Escritura;
    p = fopen("VENTAS.DAT", "ab");
    if(p == nullptr){
        cout<<"NO PUDO ABRIR GUARDADO"<<endl;
        return false;
    }

    Escritura = fwrite(&registro, sizeof(Venta), 1, p);
    fclose(p);
    return Escritura;

}

Venta VentaArchivo::leerVenta(int indice){
    FILE *p;

    p = fopen("VENTAS.DAT", "rb");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR LECTURA" << endl;
        return obj;
    }

    fseek(p, sizeof(Venta) * indice, SEEK_SET);
    fread(&obj, sizeof(Venta), 1, p);
    fclose(p);
    return obj;
}

int VentaArchivo::cantidadRegistros(){

    int tamRegistro, total, cantidad;
    FILE *p;
    p = fopen("VENTAS.DAT", "rb");

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

int VentaArchivo::generarIdVenta(){
    int cantidad = cantidadRegistros();

    if(cantidad > 0)
    {
        return leerVenta(cantidad - 1).getIdVenta() + 1;
    }else
    {
        return 1;
    }
}

int VentaArchivo::buscarCodigoVenta(int Cod){
    FILE *p;
    int pos = 0;

    p = fopen("VENTAS.DAT", "rb");
    if(p == nullptr)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        return -1; //retorna -1 en caso de error
    }

    while(fread(&obj, sizeof(Venta), 1, p) == 1) //el ciclo itera hasta encontrar el objeto
    {
        if(obj.getIdVenta() == Cod)
        {
            fclose(p);
            return pos; //una vez encontrado retorna la posicion
        }
        pos ++;
    }
    fclose(p);
    return -2;// retorna -2 en caso de no encontrarlo en el archivo
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////        ARCHIVOS RELACIONADOS CON SALA          ////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

Sala VentaArchivo::leerSala(int indice){
    FILE *p;

    p = fopen("SALAS.DAT", "rb");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR LECTURA" << endl;
        return venta_sala;
    }

    fseek(p, sizeof(Sala) * indice, SEEK_SET);
    fread(&venta_sala, sizeof(Sala), 1, p);
    fclose(p);
    return venta_sala;
}

int VentaArchivo::ContarRegistrosSala(){
    FILE *p;
    int tam;

    p = fopen("SALAS.DAT", "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, SEEK_END);
    tam = ftell(p) / sizeof(Sala);
    fclose(p);
    return tam;
}

bool VentaArchivo:: SobreescribirSala(int indice, Sala obj)
{
    bool Resultado;
    FILE *p;

    p = fopen("SALAS.DAT", "rb+");
    if(p == nullptr)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        return false;
    }
    fseek(p, sizeof obj * indice, SEEK_SET);//te posiciona en el obj
    Resultado = fwrite(&obj, sizeof obj, 1, p); //sobre escribis
    fclose(p);
    return Resultado;
}

int VentaArchivo :: BuscarCodigoSala(int Cod) //(te posiciona en la pelicula segun el codigo que le pases)
{
    FILE *p;
    int pos = 0;

    p = fopen("SALAS.DAT", "rb");
    if(p == nullptr)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        return -1; //retorna -1 en caso de error
    }

    while(fread(&venta_sala, sizeof(Sala), 1, p) == 1) //el ciclo itera hasta encontrar el objeto
    {
        if(venta_sala.getIdSala() == Cod)
        {
            fclose(p);
            return pos; //una vez encontrado retorna la posicion
        }
        pos ++;
    }
    fclose(p);
    return -2;// retorna -2 en caso de no encontrarlo en el archivo
}

