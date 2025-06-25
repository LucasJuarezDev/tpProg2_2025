#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Fecha
{
private:
    int Dia, Mes, Anio, Hora;
    int seleccionHorario(int, int);
public:
    Fecha(int _Dia, int _Mes, int _Anio, int _Hora);
    Fecha();
    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    void setDia(int _Dia);
    void setMes(int _Mes);
    void setAnio(int _Anio);
    void setHora(int _Hora);
    void MostrarFechaActual(Fecha, bool ticket = false);
    void mostrarHora(int);
    Fecha ReturnFechaActual();
    Fecha CargarFecha();
};


#endif // FECHA_H_INCLUDED
