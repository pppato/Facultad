#ifndef EJEMPLAR_H
#define EJEMPLAR_H
#include <string>
struct Ejms{
    int isbn;
    int anio;
    char editorial[50];
};
class Ejemplar
{
private:
    int isbn;
    int anio;
    std::string editorial;
public:
    Ejemplar();

    Ejemplar(int isbn, int anio, std::string editorial);

    int getIsbn() const;
    void setIsbn(int newIsbn);

    int getAnio() const;
    void setAnio(int newAnio);

    std::string getEditorial() const;
    void setEditorial(const std::string &newEditorial);
};

#endif // EJEMPLAR_H
