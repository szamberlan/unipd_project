#include"combattimento.h"
using std::ostream;
using std::endl;
// Costruttore e Distruttore
combattimento::combattimento(personaggio*a, personaggio*b, int t, bool c):
giocatore1(a), giocatore2(b), turno(t), inCombattimento(c){}
combattimento::~combattimento()
{
    if(giocatore1){ delete giocatore1; giocatore1=0; }
    if(giocatore2){ delete giocatore2; giocatore2=0; }
}

// Metodi Privati
// Metodi di Ausilio
void combattimento::attacco(bool giocatore, int scelta)
{
    if(!giocatore)
    {
        giocatore2->difendi(giocatore1->attacca(scelta));

    }
    else
    {
        giocatore1->difendi(giocatore2->attacca(scelta));
    }
}

void combattimento::recuperoVita(bool giocatore)
{
    if(!giocatore)
    {
        giocatore1->recuperoVita();
    }
    else
    {
        giocatore2->recuperoVita();
    }
}

void combattimento::recuperoEnergia(bool giocatore)
{
    if(!giocatore)
    {
        giocatore1->recuperoEnergia();
    }
    else
    {
        giocatore2->recuperoEnergia();
    }
}

// Metodi Non Virtuali
// Metodi Che Restituiscono i Dati
personaggio* combattimento::getGiocatore1() const
{
    return giocatore1;
}

personaggio* combattimento::getGiocatore2() const
{
    return giocatore2;
}

int combattimento::turnoDiCombattimento() const
{
    return turno;
}

bool combattimento::InCombattimento() const
{
    return inCombattimento;
}

// Metodi di Cambio Dati
// Metodi di Cambio Dati
void combattimento::cambioGiocatore1(personaggio*p, bool canc)
{
    if(canc)
    {
        delete giocatore1;
        giocatore1=p;
    }
    else
    {
        giocatore1=p;
    }
}

void combattimento::cambioGiocatore2(personaggio*p, bool canc)
{
    if(canc)
    {
        delete giocatore2;
        giocatore2=p;
    }
    else
    {
        giocatore2=p;
    }
}


// Metodi Virtuali
// Metodi Principali
void combattimento::inizioCombattimento()
{
    turno=1;
    inCombattimento=true;
}

void combattimento::svolgiTurno(int azione1, int azione2)
{
    if(turno)
    {
        if(azione1==1)
        {
            attacco(0,1);
        }
        if(azione1==2)
        {
            attacco(0,2);
        }
        if(azione1==3)
        {
            attacco(0,3);
        }
        if(azione1==4)
        {
            attacco(0,4);
        }
        if(azione1==5)
        {
            recuperoVita(0);
        }
        if(azione1==6)
        {
            recuperoEnergia(0);
        }
        if(azione2==1)
        {
            attacco(1,1);
        }
        if(azione2==2)
        {
            attacco(1,2);
        }
        if(azione2==3)
        {
            attacco(1,3);
        }
        if(azione2==4)
        {
            attacco(1,4);
        }
        if(azione2==5)
        {
            recuperoVita(1);
        }
        if(azione2==6)
        {
            recuperoEnergia(1);
        }
        if(Vittoria1())
        {
            fineCombattimento();
        }
        if(Vittoria2())
        {
            fineCombattimento();
        }
        turno++;
    }
}

void combattimento::fineCombattimento()
{
    turno=0;
    inCombattimento=false;
}

// Metodi di Ausilio
bool combattimento::Vittoria1() const
{
    return giocatore2->sconfitta();
}

bool combattimento::Vittoria2() const
{
    return giocatore1->sconfitta();
}

std::ostream& operator<<(std::ostream& os, combattimento& c)
{
    os<<"Combattimento Tra "<<c.getGiocatore1()->getNome()<<" e "<<c.getGiocatore2()->getNome()<<endl;
    os<<"Turno "<<c.turnoDiCombattimento()<<endl;
    os<<"Situazione Giocatore 1"<<endl;
    os<<"Vita Attuale"<<c.getGiocatore1()->getVitaAttuale()<<endl;
    os<<"Energia Attuale"<<c.getGiocatore1()->getEnergiaAttuale()<<endl;
    os<<"Situazione Giocatore 2"<<endl;
    os<<"Vita Attuale"<<c.getGiocatore2()->getVitaAttuale()<<endl;
    os<<"Energia Attuale"<<c.getGiocatore2()->getEnergiaAttuale()<<endl;

      return os;
}
