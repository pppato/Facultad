#ifndef TEXTO_H
#define TEXTO_H
#include "mensaje.h"
struct Txt {
    int nro;
    int tele;
    char text[150];
};
//
class Texto : public Mensaje
{
private:
    int tel;
public:
    Texto();
    std::string getLine();
    void setStruct (Txt t);
    int getTel();
};

#endif // TEXTO_H
