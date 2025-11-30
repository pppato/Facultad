#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct Emps {
    int nro;
    char nombre[200];
    double ventas;
    double porcentaje;
    char tipo;
};
struct Relac {
    int nro_jefe;
    int nro_empleado;
};
class Empleado {
private:
    int nro;
    string nombre;
    double ventas;
    double porcentaje;
    char tipo;
public:
    virtual double getMonto() = 0;
    int getNro() const{
        return nro;
    }
    double getVentas() const {
        return ventas;
    }
    double getPorcentaje() const {
        return porcentaje;
    }
    string getNombre() const {
        return nombre;
    }
    void setStruct(Emps& emp){
        this->nro = emp.nro;
        this->nombre = string(emp.nombre);
        this->ventas = emp.ventas;
        this->porcentaje = emp.porcentaje;
        this->tipo = emp.tipo;
    }
    Empleado();
};

class Jefe : private Empleado {
private:
    vector<Empleado*> aCargo;
public:
    double getMonto(){
        double monto = 0;
        for (auto&it : aCargo){
            monto+=it->getMonto();
        }
        return monto;
    }
    size_t cantACargo(){
        return aCargo.size();
    }
    friend std::ostream& operator<<(std::ostream& os, Empleado*& a){
        os<<a->getNro()<<" "<<a->getNombre()<<" "<<a->getMonto()<<endl;
        return os;
    }
    void agregarEmpleado(Empleado*& a){
        aCargo.push_back(a);
    }
    Jefe();
};

class Vendedor : private Empleado {
public:
    double getMonto(){
        return ventas*(porcentaje/100);
    }
    friend std::ostream& operator<<(std::ostream& os, Empleado*& a){
        os<<a->getNro()<<" "<<a->getNombre()<<" "<<a->getMonto()<<endl;
        return os;
    }
    Vendedor();
};

class Gestor {
private:
    vector<Empleado*>empleados;
public:
    bool leerBin(){
        ifstream in("Empleado.dat",ios::binary);
        if (!in.is_open()) return false;
        Emps emp{};
        while (in.read((char*)&emp,sizeof(Emps))){
            Empleado* Nuevo = nullptr;
            if (emp.tipo=="j"){
                Nuevo = new Jefe;
                Nuevo->setStruct(emp);
                empleados.push_back(Nuevo);
            } else if (emp.tipo == 'v'){
                Nuevo = new Vendedor;
                Nuevo->setStruct(emp);
                empleados.push_back(Nuevo);
            }
        }
        in.close();
        return true;
    }
    bool leerRel(){
        ifstream in("Jefe.dat",ios::binary);
        if (!in.is_open()) return false;
        Relac rel{};
        while (in.read((char*)&rel,sizeof(Relac))){
            int nrojefe = rel.nro_jefe;
            auto it = find_if(empleados.begin(),empleados.end(),[nrojefe](Empleado* a){return a->getNro() == nrojefe;});
            if (it != empleados.end()) {
                int nrovend = rel.nro_empleado;
                auto it2 = find_if(empleados.begin(),empleados.end(),[nrovend](Empleado* a){return a->getNro() == nrovend;});
                if (it2 != empleados.end()) {
                    (*it)->agregarEmpleado(*it2);
                }
            }
        }
        in.close();
        return true;
    }
    bool guardarTxt(){
        ofstream out("montos.txt");
        if (!out.is_open()) return false;
        for (int i = 0 ; i<empleados.size(); i++){
            out<<empleados[i];
        }
        out.close();
        return true;
    }
    // los hice con ia porque no me acuerdo como los hice en el examen
    vector<Empleado*> mayorMonto() {
        vector<Empleado*> res;

        if (empleados.empty()) return res;

        double maxMonto = (*max_element(
                               empleados.begin(),
                               empleados.end(),
                               [](Empleado* a, Empleado* b){
                                   return a->getMonto() < b->getMonto();
                               }
                               ))->getMonto();

        copy_if(
            empleados.begin(),
            empleados.end(),
            back_inserter(res),
            [maxMonto](Empleado* e){
                return e->getMonto() == maxMonto;
            }
            );

        return res;
    }

    vector<Jefe*> jefesConMasACargo() {
        vector<Jefe*> soloJefes;

        for (auto e : empleados) {
            if (auto j = dynamic_cast<Jefe*>(e)) {
                soloJefes.push_back(j);
            }
        }

        if (soloJefes.empty()) return {};

        size_t maxCant = (*max_element(
                              soloJefes.begin(),
                              soloJefes.end(),
                              [](Jefe* a, Jefe* b){
                                  return a->cantACargo() < b->cantACargo();
                              }
                              ))->cantACargo();

        vector<Jefe*> res;
        copy_if(
            soloJefes.begin(),
            soloJefes.end(),
            back_inserter(res),
            [maxCant](Jefe* j){
                return j->cantACargo() == maxCant;
            }
            );

        return res;
    }

    vector<string> nombresQueMasSeRepite() {
        unordered_map<string, int> contador;

        for (auto e : empleados) {
            contador[e->getNombre()]++;
        }

        if (contador.empty()) return;

        int maxRep = max_element(contador.begin(), contador.end(),[](auto& a, auto& b){
                             return a.second < b.second;})->second;

        vector<string> res;
        for (auto& par : contador) {
            if (par.second == maxRep) {
                res.push_back(par.first);
            }
        }

        return res;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
