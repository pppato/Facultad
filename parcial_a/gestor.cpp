#include "gestor.h"

Gestor::Gestor() {}

void Gestor::addClientes(Cliente C)
{
    Cliente* Aux = new Cliente [cantidad+1];
    for (int i = 0 ; i< this->cantidad;i++){
        Aux[i] = this->Clientes[i];
    }
    Aux[this->cantidad] = C;
    delete[]Clientes;
    this->Clientes = Aux;
    this->cantidad++;
}

void Gestor::Imprime()
{
    for (int i = 0; i<cantidad;i++)
    {
        std::cout<<i+1<<" "<<Clientes[i];
    }
}
