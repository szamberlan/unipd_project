#include<iostream>
#include"orco.h"
using std::cout;
using std::endl;

orco::orco(string n, double a, double d, double vm, double em, int s, double bV):
personaggio(n,a,d,vm+bV,em,10,10,s), bonusVita(bV){}

orco::~orco(){}

double orco::getAbilitaOrco() const { return bonusVita; }

void orco::stampaPersonaggio() const
{
    cout<<"Razza : Orco"<<endl;
    personaggio::stampaPersonaggio();
}
