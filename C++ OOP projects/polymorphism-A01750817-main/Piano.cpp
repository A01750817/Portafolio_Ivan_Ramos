#include "Piano.h"
#include <iostream>
using std::cout;
using std::endl;

void Piano::tocar(){
    cout<<"Soy el piano "<< nombre <<" Y me estan tocando"<<endl; 
}

void Piano::afinar(){
    cout<<"Soy el piano "<< nombre <<" Y me estan afinando"<<endl;   
}

Piano::Piano(string nom){
    nombre = nom;
}