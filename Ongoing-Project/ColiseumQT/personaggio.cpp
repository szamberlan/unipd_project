#include"personaggio.h"
#include<QtGlobal>
#include<iostream>
using namespace std;
// Costruttore e Distruttore
personaggio::personaggio(string n, double a, double d, double vm, double em, double dan, double pro, int s):
nome(n), attacco(a), difesa(d), vitaMax(vm), energiaMax(em), danno(dan), protezione(pro), soldi(s)
{
    for(int i=0; i<5; i++)
        equipaggiamento.Aggiungi_Oggetto(0);
}

personaggio::~personaggio(){}

// Metodi Protetti

bool personaggio::testProbabilita(double pr) const
{
    double randomValue= qrand()% 10000;
    if(randomValue < pr*10000)
        return true;
    else
        return false;
}

// Metodi Non Virtuali

string personaggio::getNome() const{ return nome; }

int personaggio::getSoldi() const { return soldi; }

double personaggio::getVitaMax()  const { return vitaMax; }

double personaggio::getEnergiaMax() const { return energiaMax; }

void personaggio::inserisciNelloZaino(oggetto *o)
{
    zaino.Aggiungi_Oggetto(o);
}

void personaggio::compraOggetto(oggetto *o)
{
    if(soldi>o->getCosto())
    {
        soldi=soldi-o->getCosto();
        inserisciNelloZaino(o);
    }
}

oggetto* personaggio::vendiOggetto(oggetto*o)
{
    if(zaino.cercaOggetto(o))
    {
        soldi=soldi+o->getCosto();
        return zaino.ricavoOggetto(o);
    }
    else
        return 0;

}

void personaggio::cambiaArma(int o)
{
    if(equipaggiamento[0]!=0)
    {
        if(zaino[o])
        {
            oggetto*aux=zaino[o];
            zaino[o]=equipaggiamento[0];
            equipaggiamento[0]=aux;
        }
    }
    else
    {
        if(zaino[o])
        {
            equipaggiamento[0]=zaino[o];
            zaino[o]=0;
            zaino.Togli_Oggetto(zaino[o]);
        }
    }
}

void personaggio::cambiaScudo(int o)
{
    if(equipaggiamento[1]!=0)
    {
        if(zaino[o])
        {
            oggetto*aux=zaino[o];
            zaino[o]=equipaggiamento[1];
            equipaggiamento[1]=aux;
        }
    }
    else
    {
        if(zaino[o])
        {
            equipaggiamento[1]=zaino[o];
            zaino[o]=0;
            zaino.Togli_Oggetto(zaino[o]);
        }
    }
}

void personaggio::cambiaArmatura(int o)
{
    if(equipaggiamento[2]!=0)
    {
        if(zaino[o])
        {
            oggetto*aux=zaino[o];
            zaino[o]=equipaggiamento[2];
            equipaggiamento[2]=aux;
        }
    }
    else
    {
        if(zaino[o])
        {
            equipaggiamento[2]=zaino[o];
            zaino[o]=0;
            zaino.Togli_Oggetto(zaino[o]);
        }
    }
}

void personaggio::cambiaPozioneVita(int o)
{
    if(equipaggiamento[3]!=0)
    {
        if(zaino[o])
        {
            oggetto*aux=zaino[o];
            zaino[o]=equipaggiamento[3];
            equipaggiamento[3]=aux;
        }
    }
    else
    {
        if(zaino[o])
        {
            equipaggiamento[3]=zaino[o];
            zaino[o]=0;
            zaino.Togli_Oggetto(zaino[o]);
        }
    }
}

void personaggio::cambiaPozioneEnergia(int o)
{
    if(equipaggiamento[4]!=0)
    {
        if(zaino[o])
        {
            oggetto*aux=zaino[o];
            zaino[o]=equipaggiamento[4];
            equipaggiamento[4]=aux;
        }
    }
    else
    {
        if(zaino[o])
        {
            equipaggiamento[4]=zaino[o];
            zaino[o]=0;
            zaino.Togli_Oggetto(zaino[o]);
        }
    }
}

void personaggio::spostaArmaNelloZaino()
{
    inserisciNelloZaino(equipaggiamento[0]);
    equipaggiamento[0]=0;
}

void personaggio::spostaScudoNelloZaino()
{
    inserisciNelloZaino(equipaggiamento[1]);
    equipaggiamento[1]=0;
}

void personaggio::spostaArmaturaNelloZaino()
{
    inserisciNelloZaino(equipaggiamento[2]);
    equipaggiamento[2]=0;
}

void personaggio::spostaPozioneVitaNelloZaino()
{
    inserisciNelloZaino(equipaggiamento[3]);
    equipaggiamento[3]=0;
}

void personaggio::spostaPozioneEnergiaNelloZaino()
{
    inserisciNelloZaino(equipaggiamento[4]);
    equipaggiamento[4]=0;
}


void personaggio::equipaggiaArma(oggetto*arma)
{
    if(equipaggiamento[0])
    {
        zaino.Aggiungi_Oggetto(equipaggiamento[0]);
        equipaggiamento[0]=arma;
    }
    else
    {
        equipaggiamento[0]=arma;
    }
}

void personaggio::equipaggiaScudo(oggetto*scudo)
{
    if(equipaggiamento[1])
    {
        zaino.Aggiungi_Oggetto(equipaggiamento[1]);
        equipaggiamento[1]=scudo;
    }
    else
    {
        equipaggiamento[1]=scudo;
    }
}

void personaggio::equipaggiaArmatura(oggetto*armatura)
{
    if(equipaggiamento[2])
    {
        zaino.Aggiungi_Oggetto(equipaggiamento[2]);
        equipaggiamento[2]=armatura;
    }
    else
    {
        equipaggiamento[2]=armatura;
    }
}

void personaggio::equipaggiaPozioneVita(oggetto*pozVita)
{
    if(equipaggiamento[3])
    {
        zaino.Aggiungi_Oggetto(equipaggiamento[3]);
        equipaggiamento[3]=pozVita;
    }
    else
    {
        equipaggiamento[3]=pozVita;
    }

}

void personaggio::equipaggiaPozioneEnergia(oggetto*pozEnergia)
{
    if(equipaggiamento[4])
    {
        zaino.Aggiungi_Oggetto(equipaggiamento[4]);
        equipaggiamento[4]=pozEnergia;
    }
    else
    {
        equipaggiamento[4]=pozEnergia;
    }
}

void personaggio::eliminaArma()
{
    if(equipaggiamento[0])
    {
        delete equipaggiamento[0];
        equipaggiamento[0]=0;
    }
}

void personaggio::eliminaScudo()
{
    if(equipaggiamento[1])
    {
        delete equipaggiamento[1];
        equipaggiamento[1]=0;
    }
}

void personaggio::eliminaArmatura()
{
    if(equipaggiamento[2])
    {
        delete equipaggiamento[2];
        equipaggiamento[2]=0;
    }
}

void personaggio::eiminaPozioneVita()
{
    if(equipaggiamento[3])
    {
        delete equipaggiamento[3];
        equipaggiamento[3]=0;
    }
}

void personaggio::eliminaPozioneEnergia()
{
    if(equipaggiamento[4])
    {
        delete equipaggiamento[4];
        equipaggiamento[4]=0;
    }
}
void personaggio::stampaEquipaggiamento() const { equipaggiamento.stampaCaratteristicheOggetti(); }
void personaggio::stampaZaino() const { zaino.stampaCaratteristicheOggetti(); }
void personaggio::stampaPersonaggio() const
{
    cout<<"Nome : "<<getNome()<<endl;
    cout<<"Attacco : "<<getAttacco()<<endl;
    cout<<"Difesa : "<<getDifesa()<<endl;
    cout<<"Vita : "<<getVitaMax()<<endl;
    cout<<"Energia : "<<getEnergiaMax()<<endl;
    cout<<"Soldi : "<<getSoldi()<<endl;
}

// Metodi Virtuali

double personaggio::getProbabilitaColpire() const { return attacco; }

double personaggio::getProbabilitaFuggire() const { return difesa; }

double personaggio::getAttacco() const { return attacco; }

double personaggio::getDifesa() const { return difesa; }

double personaggio::getDanno() const { return danno; }

double personaggio::getProtezione() const { return protezione; }
