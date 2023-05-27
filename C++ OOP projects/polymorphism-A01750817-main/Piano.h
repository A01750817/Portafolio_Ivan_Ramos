#include "InstrumentoMusical.h"
#include <string>

using std::string;

#ifndef PIANO_H
#define PIANO_H

class Piano:public InstrumentoMusical{
    private:
        string nombre;
    public:
        void tocar();
        void afinar();
        Piano(string nom);
};

#endif
