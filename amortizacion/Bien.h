#ifndef BIEN_H
#define BIEN_H
struct bienes {
    int cod;
    char tipo;
    double valor;
};
class Bien{
private:
    int cod;
    char tipo;
    double valor;
public:
    virtual void actualizarValor()= 0;
    virtual void setStruct(bienes b);

    int getCod() const;
    char getTipo() const;
    double getValor() const;
    void setValor(double newValor);
};
#endif // BIEN_H
