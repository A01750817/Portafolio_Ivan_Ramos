#include "InstrumentoMusical.h"
#include <string>
using std::string;

#ifndef FLAUTA_H
#define FLAUTA_H
class Flauta: public InstrumentoMusical{
    private:
        string nombre;
    public:
        void tocar();
        void afinar();
        Flauta(string nom);
};
#endif
