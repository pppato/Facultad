#ifndef LISTA_H
#define LISTA_H

#include "NodoGenerico.h"

template <typename T>
class Lista {
private:
    NodoGenerico<T>* cabeza;
    int Nodos = 0;
public:
    Lista();
    ~Lista();

    void AgregarPrimero(T dato);
    void AgregarUltimo(T dato);
    bool Busqueda(T dato);
    NodoGenerico<T>* nUltimo();
    void Imprimir();
    void AgregarEntre(T Testigo, T dato);
    void Eliminar(T dato);
    int getNodos();
};
template <typename T>
Lista<T>::Lista(){
    cabeza = nullptr;
}
template <typename T>
void Lista<T>::AgregarPrimero(T dato)
{
    NodoGenerico<T>* Nuevo = new NodoGenerico(dato);
    Nuevo->setLink(cabeza);
    cabeza = Nuevo;
    Nodos++;
}
template <typename T>
void Lista<T>::AgregarUltimo(T dato)
{
    NodoGenerico<T>* Ultimo = nUltimo();
    Ultimo->setLink(new NodoGenerico(dato));
    Nodos++;
}
template <typename T>
Lista<T>::~Lista(){
    delete cabeza;
}
template <typename T>
NodoGenerico<T>* Lista<T>::nUltimo()
{
    NodoGenerico<T>* p = cabeza;
    if (p==nullptr) throw "Lista Vacia";
    while (p->GetLinkNodo()!=nullptr) p = p->GetLinkNodo();
    return p;
}
template <typename T>
void Lista<T>::Imprimir()
{
    NodoGenerico<T>* Aux = cabeza;
    while (Aux!=nullptr){
        std::cout<<Aux->getDato()<<" ";
        Aux = Aux->GetLinkNodo();
    }
}
template <typename T>
void Lista<T>::AgregarEntre(T Testigo, T dato)
{
    NodoGenerico<T>* Aux = cabeza;

    while (Aux != nullptr && Aux->getDato() != Testigo) {
        Aux = Aux->GetLinkNodo();
    }

    if (Aux == nullptr) return;

    NodoGenerico<T>* siguiente = Aux->GetLinkNodo();
    NodoGenerico<T>* Nuevo = new NodoGenerico<T>(dato);
    Nuevo->setLink(siguiente);
    Aux->setLink(Nuevo);
    Nodos++;
}
template <typename T>
void Lista<T>::Eliminar(T dato)
{
    NodoGenerico<T>* Anterior, *Actual;
    Anterior = nullptr;
    Actual = cabeza;

    while ((Actual != nullptr) && (Actual->getDato() != dato)){
        Anterior = Actual;
        Actual = Actual->GetLinkNodo();
    }

    if ((Anterior == nullptr) && (Actual != nullptr)){
        cabeza = Actual->GetLinkNodo();
        delete Actual;
    } else if ((Anterior != nullptr) && (Actual != nullptr)) {
        Anterior->setLink(Actual->GetLinkNodo());
        delete Actual;
    } else  return;
    Nodos--;
}
template <typename T>
int Lista<T>::getNodos(){
    return Nodos;
}
template <typename T>
bool Lista<T>::Busqueda(T dato)
{
    NodoGenerico<T>* Aux = cabeza;
    while (Aux != nullptr && Aux->getDato() != dato)
    {
        Aux = Aux->GetLinkNodo();
    }

    return Aux!=nullptr;

}
#endif // LISTA_H

