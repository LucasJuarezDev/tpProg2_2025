#include "salasArchivos.h"
#include <iostream>
using namespace std;

bool salaArchivo :: guardarSala(Sala obj)
{
    FILE *p;
    bool Escritura;

    p = fopen("SALAS.DAT", "ab");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR GUARDADO" << endl;
        return false;
    }
    Escritura = fwrite(&obj, sizeof(Sala), 1, p);
    fclose(p);
    return Escritura;
}

Sala salaArchivo :: leerSala(int indice)
{
    FILE *p;

    p = fopen("SALAS.DAT", "rb");
    if(p == nullptr)
    {
        cout << "NO PUDO ABRIR LECTURA" << endl;
        return obj;
    }

    fseek(p, sizeof(Sala) * indice, SEEK_SET);
    fread(&obj, sizeof(Sala), 1, p);
    fclose(p);
    return obj;
}

int salaArchivo :: ContarRegistrosSala()
{
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

int salaArchivo :: generarIdSala()
{
    int cantidad = ContarRegistrosSala();

    if(cantidad > 0)
    {
        return leerSala(cantidad - 1).getIdSala() + 1;
    }else
    {
        return 1;
    }
}
bool salaArchivo:: SobreescribirSala(int indice, Sala obj)
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

int salaArchivo :: BuscarCodigoSala(int Cod) //(te posiciona en la pelicula segun el codigo que le pases)
{
    FILE *p;
    int pos = 0;

    p = fopen("SALAS.DAT", "rb");
    if(p == nullptr)
    {
        cout << "ERROR DE ARCHIVO" << endl;
        return -1; //retorna -1 en caso de error
    }

    while(fread(&obj, sizeof(Sala), 1, p) == 1) //el ciclo itera hasta encontrar el objeto
    {
        if(obj.getIdSala() == Cod)
        {
            fclose(p);
            return pos; //una vez encontrado retorna la posicion
        }
        pos ++;
    }
    fclose(p);
    return -2;// retorna -2 en caso de no encontrarlo en el archivo
}
