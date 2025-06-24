#include "Fecha.h"
#include <ctime>

// Constructor
Fecha::Fecha(){
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);
    Dia = f->tm_mday;
    Mes = f->tm_mon+1;
    Anio = f->tm_year+1900;
    Hora = f->tm_hour;
}
Fecha::Fecha(int _Dia,int _Mes, int _Anio, int _Hora){
    setDia(_Dia);
    setMes(_Mes);
    setAnio(_Anio);
    setHora(_Hora);
}


//getters
int Fecha::getDia(){
    return Dia;
}

int Fecha::getMes(){
    return Mes;
}

int Fecha::getAnio(){
    return Anio;
}

int Fecha::getHora(){
    return Hora;
}

//setters
void Fecha::setDia(int _Dia){
    Dia = _Dia;
}

void Fecha::setMes(int _Mes){
    Mes = _Mes;
}

void Fecha::setAnio(int _Anio){
    Anio = _Anio;
}

void Fecha::setHora(int _Hora){
    Hora = _Hora;
}

//mostrar fecha
void Fecha ::MostrarFechaActual(Fecha obj)
{
    cout << obj.getDia() << "/" << obj.getMes() << "/" << obj.getAnio() << " - " << obj.getHora() << ":00 hs." << endl;
}


Fecha Fecha:: ReturnFechaActual()
{
    return Fecha();
}


//cargar fecha
Fecha Fecha::CargarFecha() {
    Fecha obj, fecha_retorno;
    int dia, mes, anio;
    bool fechaValida = false;

    do{
        cout << "FECHA DE FUNCION" << endl;
        cout << "-------------------------" << endl;
        cout << "DIA DE LA FUNCION: ";
        cin >> dia;
        cout << "MES DE LA FUNCION: ";
        cin >> mes;
        fecha_retorno.setAnio(obj.getAnio());

        // validacion de la fecha ingresaa
        if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && dia >= obj.getDia() || mes >= obj.getMes()) {//el año lo hice entre 2020 y 2030
            fecha_retorno.setDia(dia);
            fecha_retorno.setMes(mes);
            fechaValida = true;
            cout << "Fecha guardada correctamente."<< endl;
            system("pause");
            return fecha_retorno;
        } else {
            cout << "Fecha no valida. Por favor, ingrese nuevamente.\n";
        }
    }while(!fechaValida);

}

