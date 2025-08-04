#ifndef NODOGENERICO_H
#define NODOGENERICO_H
template <typename T> class NodoGenerico
{
protected:
    T Dato;
    NodoGenerico <T>* link;
public:
    NodoGenerico(T t)
    {
        Dato = t;
        link = 0;
    }
    NodoGenerico(T p, NodoGenerico<T>* n)
    {
        Dato = p;
        link = n;
    }
    NodoGenerico <T>* GetLinkNodo () const
    {
        return link;
    }
    void setLink(NodoGenerico <T>* sgte)
    {
        link = sgte;
    }
    T getDato(){
        return Dato;
    }
};
#endif // NODOGENERICO_H
