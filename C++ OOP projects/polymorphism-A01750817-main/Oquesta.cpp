//#include "InstrumentoMusical.h"

#include "Orquesta.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void Orquesta::tocaInstrumento(InstrumentoMusical* instru) {
    instru->tocar();
}

void Orquesta::agregaInstrumento(InstrumentoMusical* instru) {
    instru->afinar();
    listaInstrumento.push_back(instru);
}

void Orquesta::afinarInstrumento(InstrumentoMusical* instru) {
    instru->afinar();
}

void Orquesta::tocarTodos() {
    cout << "Tocar todos los instrumentos:" << endl;
    for (InstrumentoMusical* instru : listaInstrumento) {
        instru->tocar();
    }
     cout << endl;
}

void Orquesta::tocarPianos() {
    cout << "Tocar solo pianos:" << endl;
    for (int i=0; i < listaInstrumento.size(); i++) {
        Piano* piano2 = dynamic_cast<Piano *>(listaInstrumento[i]);
        if (piano2 != 0) {
            piano2->tocar();
        }
    }
        cout << endl;

}

void Orquesta::tocarFlautas() {
    cout << "Tocar solo flautas:" << endl;
    for (InstrumentoMusical* instru : listaInstrumento) {
        Flauta* flauta = dynamic_cast<Flauta*>(instru);
        if (flauta != nullptr) {
            flauta->tocar();
        }
    }
    cout << endl;
}