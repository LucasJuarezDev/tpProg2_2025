#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Fecha
{
private:
    int Dia, Mes, Anio;
public:
    Fecha(int _Dia, int _Mes, int _Anio);
    Fecha();
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int _Dia);
    void setMes(int _Mes);
    void setAnio(int _Anio);
    void MostrarFechaActual();
    Fecha ReturnFechaActual();
    //void CargarFecha();
};


#endif // FECHA_H_INCLUDED
