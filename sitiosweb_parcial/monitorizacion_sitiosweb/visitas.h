#ifndef VISITAS_H
#define VISITAS_H
struct strVisitas{
    char URL [20];
    int tiempoPermanencia;
    char origen;
};
class Visitas
{
private:
    char URL [20];
    int tiempoPermanencia;
    char origen;
public:
    Visitas();
    Visitas(char* URL, int tiempoPermanencia, char origen);
    char getOrigen() const;
    int getTiempoPermanencia() const;
};

#endif // VISITAS_H
