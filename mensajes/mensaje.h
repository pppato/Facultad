#ifndef MENSAJE_H
#define MENSAJE_H
#include <iostream>

class Mensaje
{
private:
    int nro;
    std::string body;
public:
    Mensaje();
    virtual std::string getLine() = 0;
    virtual int getNumero(){
        return nro;
    }
};

#endif // MENSAJE_H
