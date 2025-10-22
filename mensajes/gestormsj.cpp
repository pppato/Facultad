#include "gestormsj.h"
#include <fstream>
#include <algorithm>
#include <map>
GestorMsj::GestorMsj() {}

void GestorMsj::leerMail()
{
    mail m;
    Email* var;
    std::ifstream archi("email.dat",std::ios::binary);
    while (archi.read((char*)&m, sizeof(mail))){
        var->setStruct(m);
        ms.push_back(var);
    }
    archi.close();
}

void GestorMsj::leerTxt()
{
    Txt t;
    Texto* var;
    std::ifstream archi("texto.dat",std::ios::binary);
    while (archi.read((char*)&t, sizeof(Txt))){
        var->setStruct(t);
        ms.push_back(var);
    }
    archi.close();
}

void GestorMsj::escribir()
{
    std::ofstream Archi("salida.txt");
    std::sort(ms.begin(),ms.end(),[](Mensaje* VarA, Mensaje*VarB)
              ->bool{return VarA->getNumero()>VarB->getNumero();});
    for (auto m : ms){
        Archi<<m->getLine()<<endl;
    }
    Archi.close();
}

std::vector<Mensaje *> GestorMsj::repetidos()
{
    std::map<std::string,int>contadorMails;
    std::map<int,int>contadorTels;
    std::vector<Mensaje*> repe;

    for (auto it : ms){
        if (auto e = dynamic_cast<Email*>(it)){
            contadorMails[e->getEmail()]++;
        } else if (auto t = dynamic_cast<Texto*>(it)){
            contadorTels[t->getTel()]++;
        }
    }

    for (auto it : ms){
        if (auto e = dynamic_cast<Email*>(it)){
            if (contadorMails[e->getEmail()] > 1){
                repe.push_back(it);
            }
        } else if (auto t = dynamic_cast<Texto*>(it)){
            if (contadorTels[t->getTel()] > 1){
                repe.push_back(it);
            }
        }
    }
    return repe;
}
