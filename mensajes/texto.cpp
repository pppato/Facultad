#include "texto.h"

Texto::Texto() {}

std::string Texto::getLine()
{
    std::string msj = 't' + " " + this->body + " " + this->tel;
}

void Texto::setStruct(Txt t)
{
    this->nro = t.nro;
    this->tel = t.tele;
    this->body = t.text;
}

int Texto::getTel() const
{
    return this->tel;
}
