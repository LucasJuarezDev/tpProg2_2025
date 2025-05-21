#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

class Sala{
private:
    int IdSala;
    char NombreSala[50];
    int TipoSala;
    int Butacas;
    bool SalaOcupada;
    bool Activo;
public:
    // constructores
    Sala();
    Sala(int id, const char* nombre, int tipo, int butacas, bool sala_ocupada, bool activo);
    // getters
    int getIdSala();
    const char* getNombreSala();
    int getTipoSala();
    int getButacas();
    bool getSalaOcupada();
    bool getActivo();
    // setters
    void setIdSala(int id);
    void setNombreSala(const char* nombre);
    void setTipoSala(int tipo);
    void setButacas(int butacas);
    void setSalaOcupada(bool sala_ocupada);
    void setActivo(bool activo);
};

#endif // SALAS_H_INCLUDED
