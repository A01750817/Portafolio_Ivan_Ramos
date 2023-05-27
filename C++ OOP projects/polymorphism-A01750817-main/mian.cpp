#include "Orquesta.h"

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main()
{
    Orquesta orquesta;

    Piano p("Pianote");
    Flauta f("Flautin");
    Piano pe("Pepe");

    orquesta.agregaInstrumento(&p);
    orquesta.agregaInstrumento(&f);
    orquesta.agregaInstrumento(&pe);
    orquesta.tocarTodos();
    orquesta.tocarPianos();
    orquesta.tocarFlautas();
    

    return 0;
}

