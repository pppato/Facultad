#ifndef COLA_H
#define COLA_H
#include "NodoGenerico.h"

template<typename T>
class Cola{

private:
    NodoGenerico<T>* cabeza;
    NodoGenerico<T>* fondo;
public:
    Cola();
   ~Cola();

    void Agregar (T dato);
    T Sacar();
    bool Preguntar();
};
template<typename T>
Cola<T>::Cola(){
    cabeza = nullptr;
    fondo = nullptr;
}
template<typename T>
void Cola<T>::Agregar(T dato)
{
    NodoGenerico<T>*Aux = new NodoGenerico(dato);
    Aux->setLink(nullptr);
    if (fondo != nullptr){
        fondo->setLink(Aux);
    }
    fondo = Aux;
    if (cabeza == nullptr){
        cabeza = Aux;
    }
}
template<typename T>
T Cola<T>::Sacar()
{
    T Aux = cabeza->getDato();
    NodoGenerico<T>* AuxNodo = cabeza;
    cabeza = cabeza->GetLinkNodo();
    delete AuxNodo;
    return Aux;
}
template<typename T>
bool Cola<T>::Preguntar()
{
    if (cabeza == nullptr) return true;
    return false;
}
template<typename T>
Cola<T>::~Cola()
{
    delete cabeza;
}
#endif // COLA_H
