#include"oggetto.h"
#include<QtGlobal>
using std::cout;
using std::endl;

// Costruttore e Distruttore Virtuale

oggetto::oggetto(string n, double p, double g, int c):
nome(n), peso(p), grandezza(g), costo(c){}

oggetto::~oggetto(){}

// Metodi Protetti
bool oggetto::testProbabilita(double pr)
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


// Metodi Virtuali

int oggetto::getCosto() const { return costo; }

double oggetto::getDanno() const
{
    return 0.0;
}

double oggetto::getProtezione() const
{
    return 0.0;
}

double oggetto::getAiuto() const
{
    return 0.0;
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

std::ostream & operator<<(std::ostream& os, const oggetto& ogg)
{
    os<<"Nome : "<<ogg.getNome()<<endl;
    os<<"Costo : "<<ogg.getCosto()<<endl;
    os<<"Peso : "<<ogg.getPeso()<<endl;
    os<<"Tipologia : "<<ogg.getTipologiaOggetto()<<endl;
    os<<"Abilità Principale :"<<ogg.getNomeUtilita()<<endl;
    os<<"Descrizione Abilità Principale"<<endl;
    os<<ogg.getInfoUtilita();
    return os;
}
