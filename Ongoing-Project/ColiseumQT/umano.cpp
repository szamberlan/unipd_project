#include<iostream>
#include"umano.h"
using std::cout;
using std::endl;

umano::umano(string n, double a, double d, double vm, double em, int s, double bVE):
personaggio(n,a,d,vm+(bVE/2),em+(bVE/2),20,0,s), bonusVitaEnergia(bVE){}

umano::~umano(){}

double umano::getAbilitaUmano() const { return bonusVitaEnergia; }

void umano::stampaPersonaggio() const
{
    cout<<"Razza : Umano"<<endl;
    personaggio::stampaPersonaggio();
}
