#ifndef MIVECTOR_H
#define MIVECTOR_H
template <typename T>
class MiVector
{
private:
    T* Arreglo = nullptr;
    T Elementos = 0;
public:
    MiVector();
    void add(T n);
    bool isIn(T n);
    void eliminate();
    void imprimir();
    ~MiVector();
};

template <typename T>
MiVector<T>::MiVector()
{

}

template <typename T>
MiVector<T>::~MiVector() {
    delete[] Arreglo;
}

template <typename T>
void MiVector<T>::add(T n)
{
    T* Aux = new T [Elementos+1];
    for (int i = 0; i<Elementos; i++){
        Aux[i] = Arreglo[i];
    }
    Aux[Elementos] = n;
    delete[]Arreglo;
    Arreglo = Aux;
    Elementos++;
}

template <typename T>
bool MiVector<T>::isIn(T n)
{
    for (int i = 0 ; i<Elementos; i++){
        if (Arreglo[i] == n){
            return true;
        }
    }
    return false;
}

template <typename T>
void MiVector<T>::eliminate()
{
    T* Aux = new T [Elementos-1];
    for (int i = 0 ; i < Elementos -1 ; i++){
        Aux[i] = Arreglo[i];
    }
    delete[]Arreglo;
    Arreglo = Aux;
    Elementos--;
}

template <typename T>
void MiVector<T>::imprimir(){
    for (int i = 0; i < Elementos; i++){
        std::cout<<Arreglo[i]<<" ";
    }
}
#endif // MIVECTOR_H
