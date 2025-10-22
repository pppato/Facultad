#ifndef EMAIL_H
#define EMAIL_H
#include "mensaje.h"
#include <iostream>
struct mail{
    int nro;
    char correo [150];
    char body [500];
};
//
class Email : public Mensaje
{
private:
    std::string email;
public:
    Email();
    std::string getLine();
    void setStruct(mail m);
    std::string getEmail() const;
};

#endif // EMAIL_H
