#ifndef GESTORMSJ_H
#define GESTORMSJ_H
#include "mensaje.h"
#include "email.h"
#include "texto.h"
#include <vector>
class GestorMsj
{
private:
    std::vector<Mensaje*>ms;
public:
    GestorMsj();
    void leerMail();
    void leerTxt();
    void escribir();
    std::vector<Mensaje*> repetidos();
};

#endif // GESTORMSJ_H
