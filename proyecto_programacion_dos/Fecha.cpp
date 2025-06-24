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
    cout << obj.getDia() << "/" << obj.getMes() << "/" << 2025 << " - " << obj.getHora() << ":00 hs." << endl;
}


Fecha Fecha:: ReturnFechaActual()
{
    return Fecha();
}


//cargar fecha
Fecha Fecha::CargarFecha() {
    Fecha obj, fecha_retorno;
    int dia, mes, anio, hora;
    bool fechaValida = false;

    do{
        cout << "FECHA DE FUNCION" << endl;
        cout << "-------------------------" << endl;
        cout << "DIA DE LA FUNCION: ";
        cin >> dia;
        cout << "MES DE LA FUNCION: ";
        cin >> mes;
        fecha_retorno.setAnio(2025);

        // validacion de la fecha ingresaa
        if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12) {
            if ((mes > obj.getMes()) || (mes == obj.getMes() && dia >= obj.getDia())) {
                hora = obj.seleccionHorario(dia, mes);
                fecha_retorno.setAnio(anio);
                fecha_retorno.setMes(mes);
                fecha_retorno.setDia(dia);
                fecha_retorno.setHora(hora);
                fechaValida = true;
                return fecha_retorno;
            } else {
                cout << "La fecha ingresada ya paso. Ingrese una fecha futura." << endl;
                system("pause");
            }
        } else {
            cout << "Dia o mes fuera de rango. Intente nuevamente." << endl;
            system("pause");
        }

    }while(!fechaValida);

}

int Fecha::seleccionHorario(int diaIngresado, int mesIngresado){
    Fecha obj;
    int opcion;
    bool encontro = false;

    do
    {
        cout << "+--------------------------+" << endl;
        cout << "|  SELECCION DE HORARIOS   |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "|                          |" << endl;
        cout << "|     1) 14 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     2) 15 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     3) 16 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     4) 17 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     5) 18 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     6) 19 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     7) 20 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     8) 21 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|     9) 22 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "|    10) 23 : 00           |" << endl;
        cout << "|                          |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "INGRESE: ";
        cin >> opcion;

        if(opcion >= 1 && opcion <= 10){
            int horaSeleccionada = 0;
            switch(opcion) {
                case 1:  horaSeleccionada = 14; break;
                case 2:  horaSeleccionada = 15; break;
                case 3:  horaSeleccionada = 16; break;
                case 4:  horaSeleccionada = 17; break;
                case 5:  horaSeleccionada = 18; break;
                case 6:  horaSeleccionada = 19; break;
                case 7:  horaSeleccionada = 20; break;
                case 8:  horaSeleccionada = 21; break;
                case 9:  horaSeleccionada = 22; break;
                case 10: horaSeleccionada = 23; break;
            }
            if (diaIngresado == obj.getDia() && mesIngresado == obj.getMes() && horaSeleccionada <= obj.getHora()) {
                cout << "No puede seleccionar un horario anterior al actual." << endl;
                system("pause");
            }
            else {
                encontro = true;
                return horaSeleccionada;
            }
        } else {
            cout << "OPCION INVALIDA. INTENTE NUEVAMENTE." << endl;
            system("pause");
        }

    }while(!encontro);
}

