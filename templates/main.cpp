//1. Realice una clase template que represente un Vector dinámico.
//2. Realice una clase template que represente un Lista.
//3. Realice una clase template que represente un Pila.
//4. Realice una clase template que represente un Cola.
#include <iostream>
#include "MiVector.h"
#include "Lista.h"
#include "Pila.h"
#include "Cola.h"
#include "NodoGenerico.h"
using namespace std;


int main()
{
    MiVector<int> A;
    Lista<char> B;
    Pila<double> C;
    Cola<string> D;

    A.add(3);
    A.imprimir();
    cout<<A.isIn(3)<<endl;
    A.eliminate();

    B.AgregarPrimero('A');
    B.AgregarUltimo('C');
    B.AgregarEntre('A', 'B');
    B.Imprimir();
    cout<<B.Busqueda('D');
    B.Eliminar('A');
    cout<<B.getNodos()<<endl;
    B.Imprimir();
    cout<<endl;

    C.Agregar(1.51);
    C.Agregar(4.37);
    cout<<C.Sacar()<<endl;
    cout<<C.Preguntar()<<endl;

    D.Agregar("Hola");
    D.Agregar("Como andas?");
    cout<<D.Sacar()<<" ";
    cout<<D.Sacar()<<endl;
    cout<<D.Preguntar();


    return 0;
}
