#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

class Sala{
private:
    int IdSala;
    char NombreSala[50];
    int TipoSala;
    char DenominacionSala[50];
    int Butacas;
    bool SalaOcupada;
    bool Activo;
public:
    // constructores
    Sala();
    Sala(int id, const char* nombre, int tipo, const char *denominacion_sala, int butacas, bool sala_ocupada, bool activo);
    // getters
    int getIdSala();
    const char* getNombreSala();
    int getTipoSala();
    const char * getDenominacionSala();
    int getButacas();
    bool getSalaOcupada();
    bool getActivo();
    // setters
    void setIdSala(int id);
    void setNombreSala(const char* nombre);
    void setTipoSala(int tipo);
    void setDenominacionSala(const char *denominacion_sala);
    void setButacas(int butacas);
    void setSalaOcupada(bool sala_ocupada);
    void setActivo(bool activo);
};

#endif // SALAS_H_INCLUDED
