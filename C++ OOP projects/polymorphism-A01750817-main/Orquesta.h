#include "InstrumentoMusical.h"
#include "Piano.h"
#include "Flauta.h"

#include <vector>
using std::vector;

#ifndef ORQUESTA_H
#define ORQUESTA_H
class Orquesta{
    private:
        vector <InstrumentoMusical*> listaInstrumento;
    public:
        void tocaInstrumento(InstrumentoMusical* instru);
        void agregaInstrumento(InstrumentoMusical* instru);
        void tocarTodos();
        void tocarPianos();
        void tocarFlautas();
        void afinarInstrumento(InstrumentoMusical* instru);
};
#endif