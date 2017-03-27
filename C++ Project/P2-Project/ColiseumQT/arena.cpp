#include"arena.h"
#include<QtGlobal>
#include<iostream>
#include <sstream>
using namespace std;

// Costruttore e Distruttore

arena::arena(database* data, personaggio*p, int lvl): db(data), giocatore(p), livello(lvl),scontro(0){
        db->load();
}

arena::~arena()
{
    if(giocatore)
        delete giocatore;
    if(scontro)
    {
        scontro->cambioGiocatore1(0,0);
        scontro->cambioGiocatore2(0,0);
        delete scontro;
    }
    delete db;
}

// Metodi Legati al Ritorno dei Dati

//Protetto
// Metodo 1
personaggio* arena::getGiocatoreProtected() const
{
    return giocatore;
}

// Pubblico
// Metodo 1
personaggio* arena::getAvversarioAttuale() const
{
    if(db)
        return db->listaAvversari()[livello];
    else
        return 0;
}

// Metodo 2
const personaggio* arena::getGiocatore() const
{
    return giocatore;
}

// Metodo 3
const combattimento* arena::getScontro() const
{
    return scontro;
}
// Metodo 5
int arena::getLivello() const
{
    return livello;
}

// Meotdi Legati alla Costruzione dell'Arena
// Metodo 1
void arena::creaPersonaggio(string nome,double attacco, double difesa, int vita, int energia,int scelta, double bonus)
{
    giocatore=new personaggio(nome,attacco,difesa,vita,energia,15,5,20,bonus);
    if(scelta==1)
    {
        giocatore->setBonusDannoAumentato();
    }
    if(scelta==2)
    {
        giocatore->setBonusRisparmioDeficitArmature();
    }
    if(scelta==3)
    {
        giocatore->setBonusParata();
    }
    if(scelta==4)
    {
        giocatore->setBonusRisparmioEnergia();
    }
    if(scelta==5)
    {
        giocatore->setBonusUtilizzoPozioneVita();
    }
    if(scelta==6)
    {
        giocatore->setBounusUtilizzoPozioneEnergia();
    }
}

// Metodo 2
void arena::aggiungiMercanzia(oggetto *o)
{
    db->aggiungiMercanzia(o);
}

// Metodo 3
void arena::aggiungiAvversario(personaggio *p)
{
    db->aggiungiAvversario(p);
}
// Metodo 4

void arena::iniziaScontro()
{
    if(scontro)
    {
        scontro->cambioGiocatore2(getAvversarioAttuale(),0);
    }
    else
        scontro=new combattimento(giocatore,getAvversarioAttuale());
}

// Possibilità Offerte dall'Arena
// Metodi Legati Allo Zaino
int arena::getSizeZainoPersonaggio() const
{
    return giocatore->getSizeZaino();
}

oggetto* arena::ricercaOggettoNelloZaino(int i) const
{
    if(giocatore)
        return giocatore->ricercaOggetto(i);
    else
        return 0;
}

string arena::ricercaNomeOggettoNelloZaino(int i) const
{
    if(ricercaOggettoNelloZaino(i))
        return ricercaOggettoNelloZaino(i)->getNome();
    else
        return "Oggetto non trovato nello Zaino";
}

// Metodi Legati al Combattimento
void arena::iniziaCombattimento()
{
    if(!vintoArena())
    {
        iniziaScontro();
        scontro->inizioCombattimento();
    }
}

bool arena::vittoria() const
{
    return scontro->Vittoria1();
}

bool arena::sconfitta() const
{
    return scontro->Vittoria2();
}

void arena::fineCombattimento(int soldi)
{

    if(vittoria())
    {
        if(!inCombattimento())
            recuperoPostScontro();
        giocatore->aumentaSoldi(soldi);
        livello++;
    }
    else
    {
        if(!inCombattimento())
            recuperoPostScontro();
    }
}

// Metodi Legati al Commercio
bool arena::compraOggetto(int n)
{
    if(!inCombattimento())
    {
        if(giocatore->compraOggetto(db->ricercaOggettoNelMercato(n)))
        {
            db->rimuoviMercanzia(n);
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

oggetto* arena::ricercaOggettoNelMercato(int i) const
{
    return db->ricercaOggettoNelMercato(i);
}

string arena::ricercaNomeOggettoNelMercato(int i) const
{
    if(db->ricercaOggettoNelMercato(i))
        return db->ricercaOggettoNelMercato(i)->getNome();
    else
        return "Oggetto non trovato nel Mercato";
}

// Metodi Legati allo scambio oggetti tra il giocatore e il suo zaino
const oggetto* arena::ricercaOggettoNellEquipaggiamento(int i) const
{
    return giocatore->getEquipaggiamento(i);
}

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
        db->aggiungiMercanzia(giocatore->vendiOggetto(o));
}

bool arena::vendiOggettobyId(int i)
{
    if(ricercaOggettoNelloZaino(i))
    {
        vendiOggetto(ricercaOggettoNelloZaino(i));
        return true;
    }
    else
        return false;
}

// Aiuto alle possibilità dell'Arena
int arena::avversariRimasti() const
{
    return db->getAvversariSize()-livello;
}

void arena::recuperoPostScontro()
{
    if(!inCombattimento())
    {
        giocatore->recuperoCaratteristicheMax();
        getAvversarioAttuale()->recuperoCaratteristicheMax();
    }
}

bool arena::inCombattimento() const
{
    if(!scontro)
        return false;
    else
        return scontro->InCombattimento();
}


int arena::getSizeMercato() const
{
    return db->getMercanziaSize();
}

int arena::getNumeroAvversari() const
{
    return db->getAvversariSize();
}
