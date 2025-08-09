#include "cliente.h"
#include <cstring>
#include <iostream>
Cliente::Cliente() {}

Cliente::Cliente(int NumCliente, int servicio, int HorasServicio)
{
    this->NumCliente = NumCliente;
    this->servicio = servicio;
    this->HorasServicio = HorasServicio;
    switch (servicio) {
    case 0:
        this->T = new Horas();
        T->setNombre("Horas");
        T->setMonto(500);
        break;
    case 1:
        this->T = new Mensual();
        T->setNombre("Mensual");
        T->setMonto(15000);
        break;
    case 2:
        this->T = new Solicitud();
        T->setNombre("Solicitud");
        T->setMonto(12000);
        break;
    }
}

int Cliente::getMonto() const
{
    return HorasServicio*T->getMonto();
}

std::ostream& operator<<(std::ostream& os, const Cliente & obj)
{
    os<<obj.T->getNombre()<<" - $"<<obj.T->getMonto()<<" - $"<<obj.getMonto()<<std::endl;
    return os;
}
