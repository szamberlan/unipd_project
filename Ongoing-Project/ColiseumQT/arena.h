#ifndef ARENA
#define ARENA
#include"armatura.h"
#include"scudo.h"
#include"pozione.h"
#include"lancia.h"
#include"alabarda.h"
#include"ascia.h"
#include"pugnale.h"
#include"spada.h"
#include"mazza.h"
#include"assassino.h"
#include"barbaro.h"
#include"cavaliere.h"
#include"esploratore.h"
#include"furfante.h"
#include"guerriero.h"
#include"combattimento.h"
#include<QVector>
class arena {
private:
    personaggio* giocatore;
    int livello;
protected:
    QVector<personaggio*> avversari;
    combattimento* scontro;
    contenitoreOggetti mercanzia;
public:

    // Costruttore e Distruttore
    arena(personaggio*p=0, int=0);
    virtual ~arena();

    // Metodi Riguardanti il Ritorno dei Dati
    personaggio* getAvversarioAttuale() const;      //1) restituisce puntatore all'avversario attuale
    personaggio* getGiocatore() const;              //2) restituisce puntatore al giocatore attuale
    contenitoreOggetti getMercanzia() const;        //3) restituisce un contenitoreOggetti copiato da mercanzia
    combattimento* getScontro() const;              //4) restituisce un puntatore allo scontro in conrso
    int getLivello() const;                         //5) restituisce l'intero relativo al livello attuale

    // Meotdi Legati alla Costruzione dell'Arena
    virtual void creaPersonaggio(int, int, string, int, int, int);      //1) creazione personaggio
    void aggiungiMercanzia(oggetto*);                                   //2) aggiunta di mercanzia
    void aggiungiAvversario(personaggio*);                              //3) aggiunta avversari
    void iniziaScontro();                                               //4) creazione combattimento

    // Possibilità Offerte dll'Arena

    // Metodi Legati al Combattimento
    virtual void iniziaCombattimento();
    virtual void combatti(int)=0;
    virtual bool vittoria() const;
    virtual bool sconfitta() const;
    virtual void fineCombattimento();

    // Metodi Legati al Commercio
    virtual void compraOggetto(int);

    // Metodi Legati allo scambio oggetti tra il giocatore e il suo zaino
    virtual void opzioniEquipaggiamento(int);
    virtual void opzioniZaino(int, int);
    virtual void vendiOggetto(oggetto*);

    // Metodi Legati alla Stampa
    void stampaMercanzia() const;
    void stampaZainoGiocatore() const;
    void stampaCaratteristicheGiocatore() const;
    void stampaCaratteristicheAvversario() const;
    void stampaEquipaggiamentoGiocatore() const;
    virtual void stampaRisultati() const;

    // Aiuto alle possibilità dell'Arena
    int avversariRimasti() const;
    bool inCombattimento() const;
    virtual void recuperoPostScontro();
};

#endif // ARENA

