#include"arena.h"
#include<QtGlobal>
#include<iostream>
using namespace std;

// Costruttore e Distruttore

arena::arena(personaggio*p, int lvl): giocatore(p), livello(lvl), scontro(0){}

arena::~arena(){}

// Metodi Legati al Ritorno dei Dati
// Metodo 1
personaggio* arena::getAvversarioAttuale() const
{
    return avversari[livello];
}

// Metodo 2
personaggio* arena::getGiocatore() const
{
    return giocatore;
}

// Metodo 3
combattimento* arena::getScontro() const
{
    return scontro;
}

// Metodo 4
contenitoreOggetti arena::getMercanzia() const
{
    return mercanzia;
}

// Metodo 5
int arena::getLivello() const
{
    return livello;
}

// Meotdi Legati alla Costruzione dell'Arena
// Metodo 1
void arena::creaPersonaggio(int scelta1, int scelta2, string nome, int bonusRazza, int bonusClasse1, int bonusClasse2)
{
    double bonus1=0;
    double bonus2=0;
    double bonus3=0;

    // definisco il bonus della Razza
    if(bonusRazza==3) bonus1=50;
    if(bonusRazza==2) bonus1=25;
    if(bonusRazza==1) bonus1=10;

    // definisco il primo bonus della Classe
    if(bonusClasse1==3) bonus2=0.15;
    if(bonusClasse1==2) bonus2=0.10;
    if(bonusClasse1==1) bonus2=0.05;

    // definisco il secondo bonus della Classe
    if(bonusClasse2==3) bonus3=0.15;
    if(bonusClasse2==2) bonus3=0.10;
    if(bonusClasse2==1) bonus3=0.05;

    if(scelta1==1)
    {
        if(scelta2==1)
            giocatore=new barbaro(nome,200,200,50,bonus1,bonus2,bonus3);
        if(scelta2==2)
            giocatore=new guerriero(nome,200,200,50,bonus1,bonus2,bonus3);
    }
    if(scelta1==2)
    {
        if(scelta2==1)
            giocatore=new cavaliere(nome,200,200,50,bonus1,bonus2,bonus3);
        if(scelta2==2)
            giocatore=new furfante(nome,200,200,50,bonus1,bonus2,bonus3);
    }
    if(scelta1==3)
    {
        if(scelta2==1)
            giocatore=new assassino(nome,200,200,50,bonus1,bonus2,bonus3);
        if(scelta2==2)
            giocatore=new esploratore(nome,200,200,50,bonus1,bonus2,bonus3);
    }
}

// Metodo 2
void arena::aggiungiMercanzia(oggetto *o)
{
    mercanzia.Aggiungi_Oggetto(o);
}

// Metodo 3
void arena::aggiungiAvversario(personaggio *p)
{
    avversari.push_front(p);
}
// Metodo 4

void arena::iniziaScontro()
{
    if(scontro)
    {
        scontro->cambioGiocatore2(avversari[livello],0);
    }
    else
        scontro=new combattimento(giocatore,avversari[livello]);
}

// Possibilità Offerte dall'Arena

// Metodi Legati al Combattimento
void arena::iniziaCombattimento()
{
    iniziaScontro();
    scontro->inizioCombattimento();
}

void arena::combatti(int azione)
{
    if(inCombattimento())
        scontro->svolgiTurno(azione,1);
}

bool arena::vittoria() const
{
    return scontro->Vittoria1();
}

bool arena::sconfitta() const
{
    return scontro->Vittoria2();
}

void arena::fineCombattimento()
{
    if(!inCombattimento())
        recuperoPostScontro();
    if(vittoria())
        livello++;
}

// Metodi Legati al Commercio
void arena::compraOggetto(int n)
{
    if(!inCombattimento())
        giocatore->compraOggetto(mercanzia[n]);
    mercanzia[n]=0;
    mercanzia.Togli_Oggetto(mercanzia[n]);
}

// Metodi Legati allo scambio oggetti tra il giocatore e il suo zaino
void arena::opzioniEquipaggiamento(int scelta)
{
    if(!inCombattimento())
    {
       if(scelta==1)
       {
           giocatore->spostaArmaNelloZaino();
       }
       if(scelta==2)
       {
           giocatore->spostaScudoNelloZaino();
       }
       if(scelta==3)
       {
           giocatore->spostaArmaturaNelloZaino();
       }
       if(scelta==4)
       {
           giocatore->spostaPozioneVitaNelloZaino();
       }
       if(scelta==5)
       {
           giocatore->spostaPozioneEnergiaNelloZaino();
       }
    }
}

void arena::opzioniZaino(int scelta, int n)
{
    if(!inCombattimento())
    {
        if(scelta==1)
        {
            giocatore->cambiaArma(n);
        }
        if(scelta==2)
        {
            giocatore->cambiaArmatura(n);
        }
        if(scelta==3)
        {
            giocatore->cambiaScudo(n);
        }
        if(scelta==4)
        {
            giocatore->cambiaPozioneVita(n);
        }
        if(scelta==5)
        {
            giocatore->cambiaPozioneEnergia(n);
        }
    }
}

void arena::vendiOggetto(oggetto *o)
{
    if(!inCombattimento())
        mercanzia.Aggiungi_Oggetto(giocatore->vendiOggetto(o));
}

// Metodi Legati alla Stampa
void arena::stampaMercanzia() const
{
    cout<<"Mercanzia"<<endl;
    cout<<"----------------------"<<endl;
    mercanzia.stampaCaratteristicheOggetti();
    cout<<"----------------------"<<endl;
}

void arena::stampaZainoGiocatore() const
{
    cout<<"Zaino Giocatore"<<endl;
    cout<<"----------------------"<<endl;
    giocatore->stampaZaino();
    cout<<"----------------------"<<endl;
}

void arena::stampaCaratteristicheGiocatore() const
{}

void arena::stampaCaratteristicheAvversario() const
{}

void arena::stampaEquipaggiamentoGiocatore() const
{
    cout<<"Equipaggiamento Giocatore"<<endl;
    giocatore->stampaEquipaggiamento();
}

void arena::stampaRisultati() const
{
    cout<<"Avversari Sconfitti : "<<livello<<endl;
}

// Aiuto alle possibilità dell'Arena
int arena::avversariRimasti() const
{
    return avversari.size()-livello;
}

void arena::recuperoPostScontro()
{
    if(inCombattimento())
    {
        giocatore->recuperoCaratteristicheMax();
        avversari[livello]->recuperoCaratteristicheMax();
    }
}

bool arena::inCombattimento() const
{
    if(!scontro)
        return false;
    else
        return scontro->InCombattimento();
}
