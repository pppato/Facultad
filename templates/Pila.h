#ifndef PILA_H
#define PILA_H
#include "NodoGenerico.h"

template<typename T>
class Pila {
private:
    NodoGenerico<T>* cabeza;
public:
    Pila();
   ~Pila();

    void Agregar(T dato);
    T Sacar();
    bool Preguntar();
};
template<typename T>
Pila<T>::Pila(){
    cabeza = nullptr;
}
template<typename T>
void Pila<T>::Agregar(T dato)
{
    NodoGenerico<T>* Aux = new NodoGenerico(dato);
    Aux->setLink(cabeza);
    cabeza=Aux;
}
template<typename T>
T Pila<T>::Sacar()
{
    T Aux = cabeza->getDato();
    NodoGenerico<T>* AuxNodo = cabeza;
    cabeza = cabeza->GetLinkNodo();
    delete AuxNodo;
    return Aux;
}
template<typename T>
bool Pila<T>::Preguntar()
{
    if (cabeza == nullptr) return true;
    return false;
}
template<typename T>
Pila<T>::~Pila()
{
    delete cabeza;
}
#endif // PILA_H
