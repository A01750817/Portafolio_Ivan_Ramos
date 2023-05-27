#include "Flauta.h"
#include <iostream>

using std::cout;
using std::endl;

void Flauta::tocar(){
    cout<<"Soy la flauta "<< nombre <<" y me estan tocando"<<endl;
}

void Flauta::afinar(){
    cout<<"Soy la flauta " <<nombre<< " y me estan afinando" <<endl;
}

Flauta::Flauta(string nom){
    nombre= nom;

}