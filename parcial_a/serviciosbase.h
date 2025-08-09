#ifndef SERVICIOSBASE_H
#define SERVICIOSBASE_H

class ServiciosBase
{
protected:
    int monto;
    char* nombre = nullptr;

public:
    ServiciosBase();
    virtual void setMonto (int n) = 0;
    virtual void setNombre(const char* nom);
    virtual int getMonto ();
    virtual char* getNombre();
};

#endif // SERVICIOSBASE_H
