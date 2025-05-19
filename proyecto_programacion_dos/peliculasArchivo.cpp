#include "peliculasArchivo.h"
#include <iostream>
using namespace std;

bool peliculaArchivo :: guardarPelicula(Pelicula obj)
{
    FILE *p;
    bool Escritura;

    p = fopen("PELICULAS.DAT", "ab");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR GUARDADO" << endl;
        return false;
    }
    Escritura = fwrite(&obj, sizeof(Pelicula), 1, p);
    fclose(p);
    return Escritura;
}

Pelicula peliculaArchivo :: leerPelicula(int indice)
{
    FILE *p;

    p = fopen("PELICULAS.DAT", "rb");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR LECTURA" << endl;
        return obj;
    }

    fseek(p, sizeof(Pelicula) * indice, SEEK_SET);
    fread(&obj, sizeof(Pelicula), 1, p);
    fclose(p);
    return obj;
}

int peliculaArchivo :: ContarRegistrosPelicula()
{
    FILE *p;
    int tam;

    p = fopen("PELICULAS.DAT", "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, SEEK_END);
    tam = ftell(p) / sizeof(Pelicula);
    fclose(p);
    return tam;
}

int peliculaArchivo :: generarIdPelicula()
{
    int cantidad = ContarRegistrosPelicula();

    if(cantidad > 0)
    {
        return leerPelicula(cantidad - 1).getIdPelicula() + 1;
    }else
    {
        return 1;
    }
}
bool peliculaArchivo:: SobreescribirPelicula(int indice, Pelicula obj)
{
    bool Resultado;
    FILE *p;

    p = fopen("PELICULAS.DAT", "rb+");
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
