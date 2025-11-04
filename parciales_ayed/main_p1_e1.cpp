#include <iostream>

using namespace std;
struct NodoListaDE{
    int dato;
    struct NodoListaDE* Anterior = NULL;
    struct NodoListaDE* Siguiente = NULL;
};
void Add(NodoListaDE*& Head, int dato){
    NodoListaDE* NuevoNodo = new (NodoListaDE);
    NuevoNodo->dato = dato;
    if (Head==NULL){
        Head = NuevoNodo;
    } else {
        NodoListaDE* Aux = Head;
        while (Aux->Siguiente != NULL){
            Aux = Aux->Siguiente;
        }
        Aux->Siguiente = NuevoNodo;
        NuevoNodo->Anterior = Aux;
    }
}
void WriteLDE(NodoListaDE* Head){
    NodoListaDE* Aux = Head;
    while (Aux!=NULL){
        cout<<Aux->dato<<" ";
        Aux = Aux->Siguiente;
    }
}
int contarnodos(NodoListaDE*Head){
    NodoListaDE* Aux = Head;
    int cont = 0;
    while (Aux!=NULL){
        Aux = Aux->Siguiente;
        cont++;
    }
    return cont;
}
void eliminar(NodoListaDE* &Head){
    int nodos = contarnodos(Head);

    NodoListaDE* Aux = Head;

    if (nodos%2==0){

        int mitad = nodos/2;
        int cont = 1;

        while (cont!=mitad){
            Aux = Aux->Siguiente;
            cont++;
        }

        NodoListaDE* AuxMitad = Aux;
        NodoListaDE* SigMitad = Aux->Siguiente;

        Aux->Anterior->Siguiente=SigMitad->Siguiente;
        SigMitad->Siguiente->Anterior = Aux->Anterior;

        delete AuxMitad;
        delete SigMitad;

    } else if (nodos%2!=0){

        int mitad = (nodos/2);
        int cont = 0;

        while (cont!=mitad){
            Aux = Aux->Siguiente;
            cont++;
        }

        NodoListaDE* AntAux = Aux->Anterior;
        NodoListaDE* SigAux = Aux->Siguiente;

        AntAux->Siguiente = SigAux;
        SigAux->Anterior = AntAux;

        delete Aux;
    }
}

int main()
{
    NodoListaDE* ListaPar = NULL;
    for (int i = 0; i < 6; i++){
        Add(ListaPar,((i+1)*2));
    }
    NodoListaDE* ListaImpar = NULL;
    for (int i = 0; i < 7; i++){
        Add(ListaImpar,(i+1));
    }
    WriteLDE(ListaPar);
    cout<<endl;
    WriteLDE(ListaImpar);
    cout<<endl;
    cout<<endl;
    eliminar(ListaPar);
    WriteLDE(ListaPar);
    cout<<endl;
    eliminar(ListaImpar);
    WriteLDE(ListaImpar);
    cout<<endl;

    return 0;
}
