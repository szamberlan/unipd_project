#include<iostream>
#include"elfo.h"
using std::cout;
using std::endl;

elfo::elfo(string n, double a, double d, double vm, double em, int s, double bE):
personaggio(n,a,d,vm,em+bE,15,5,s), bonusEnergia(bE){}

elfo::~elfo(){}

double elfo::getAbilitaElfo() const { return bonusEnergia; }

void elfo::stampaPersonaggio() const
{
    cout<<"Razza : Elfo"<<endl;
    personaggio::stampaPersonaggio();
}
