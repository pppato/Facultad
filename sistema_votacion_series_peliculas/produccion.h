#ifndef PRODUCCION_H
#define PRODUCCION_H
#include <iostream>
#include <vector>
struct Prod{
    int nro;
    char nombre [50];
    char tipo;
};
class Produccion
{
private:
    int nro;
    std::string nombre;
    char tipo;
    std::vector<int>votacion;
    float promedio;
public:
    Produccion();
    void setStruct(Prod p);
    void agregarVoto(int v);
    void promediar();
    float getPromedio() const;
    int getVotosSize();
    int getNro() const;
    std::string getNombre() const;
    int getCantVotos() const;
    char getTipo() const;
};

#endif // PRODUCCION_H
