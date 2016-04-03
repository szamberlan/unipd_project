#include"oggetto.h"
#include<QtGlobal>
using std::cout;
using std::endl;

// Costruttore e Distruttore Virtuale

oggetto::oggetto(string n, double p, double g, int c):
nome(n), peso(p), grandezza(g), costo(c){}

oggetto::~oggetto(){}

// Metodi Protetti
bool oggetto::testProbabilita(double pr) const
{
    double randomValue= qrand()% 100;
    if(randomValue < pr*100)
        return true;
    else
        return false;
}

// Metodi Non Virtuali

string oggetto::getNome() const { return nome; }

double oggetto::getPeso() const { return peso; }

double oggetto::getGrandezza() const { return grandezza; }

int oggetto::getCosto() const { return costo; }

// Metodi Virtuali

void oggetto::stampaCaratteristiche() const
{
    cout<<"Nome : "<<getNome()<<endl;
    cout<<"Peso : "<<getPeso()<<endl;
    cout<<"Costo : "<<getCosto()<<endl;
}

//Operatori di uguaglianza e di disuguaglianza virtuali

bool oggetto::operator==(const oggetto& o) const
{
    return nome==o.getNome() && peso==o.getPeso() && grandezza==o.getGrandezza() && costo==o.getCosto();
}

bool oggetto::operator!=(const oggetto& o) const
{
    return nome!=o.getNome() && peso!=o.getPeso() && grandezza!=o.getGrandezza() && costo!=o.getCosto();
}
