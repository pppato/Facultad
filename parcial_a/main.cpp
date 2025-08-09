#include <iostream>
#include "horas.h"
#include "serviciosbase.h"
#include "mensual.h"
#include "solicitud.h"
#include "cliente.h"
#include "gestor.h"
using namespace std;

int main()
{

    Cliente C(3,0,5), J(8,1,6), P(3,2,3), A(1,0,2);

    Gestor Gestion;
    Gestion.addClientes(C);
    Gestion.addClientes(J);
    Gestion.addClientes(P);
    Gestion.addClientes(A);
    Gestion.Imprime();


    return 0;
}
