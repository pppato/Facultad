#include "email.h"

Email::Email() {}

std::string Email::getLine()
{
    std::string msj = 'e ' + " " + this->email + " " + this->body;
    return msj;
}

void Email::setStruct(mail m)
{
    this->body = m.body;
    this->email = m.correo;
    this->nro = m.nro;
}

std::string Email::getEmail() const
{
    return this->email;
}
