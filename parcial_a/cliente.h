#ifndef CLIENTE_H
#define CLIENTE_H
#include "serviciosbase.h"
#include "horas.h"
#include "mensual.h"
#include "solicitud.h"
#include <iostream>
class Cliente
{
private:
    int NumCliente;
    ServiciosBase* T;
    int servicio;
    int HorasServicio;

public:
    Cliente();
    Cliente(int NumCliente, int servicio, int HorasServicio);
    int getMonto() const;
    friend std::ostream& operator<<(std::ostream& os, const Cliente & obj);
};

#endif // CLIENTE_H
