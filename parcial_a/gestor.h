#ifndef GESTOR_H
#define GESTOR_H
#include "cliente.h"
class Gestor
{
private:
    Cliente* Clientes = nullptr;
    int cantidad = 0;
public:
    Gestor();
    void addClientes(Cliente C);
    void Imprime();
};

#endif // GESTOR_H
