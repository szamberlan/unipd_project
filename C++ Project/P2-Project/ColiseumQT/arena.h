#ifndef ARENA
#define ARENA
#include"scudo.h"
#include"pozione.h"
#include"arma.h"
#include"combattimento.h"
#include"database.h"
#include<QVector>
class arena {
private:
    database * db;
    personaggio* giocatore;
    int livello;
protected:
    personaggio* getGiocatoreProtected() const;
    combattimento* scontro;

public:

    // Costruttore e Distruttore
    arena(database* data, personaggio*p=0, int=0);
    virtual ~arena();

    // Metodi Riguardanti il Ritorno dei Dati
    personaggio* getAvversarioAttuale() const;            //1) restituisce puntatore all'avversario attuale
    const personaggio* getGiocatore() const;              //2) restituisce puntatore al giocatore attuale
    const combattimento* getScontro() const;              //3) restituisce un puntatore allo scontro in conrso
    int getLivello() const;                               //4) restituisce l'intero relativo al livello attuale
    int getNumeroAvversari() const;

    // Meotdi Legati alla Costruzione dell'Arena
    virtual void creaPersonaggio(string,double,double,int,int,int,double);//1) creazione personaggio
    void iniziaScontro();                                                 //2) creazione combattimento
    void aggiungiMercanzia(oggetto *);
    void aggiungiAvversario(personaggio*);

    // Possibilità Offerte dall'Arena
    // Metodi Legati Allo Zaino
    int getSizeZainoPersonaggio() const;
    oggetto*ricercaOggettoNelloZaino(int) const;
    string ricercaNomeOggettoNelloZaino(int) const;

    // Metodi Legati al Combattimento
    virtual void iniziaCombattimento();
    virtual void combatti(int)=0;
    virtual bool vittoria() const;
    virtual bool sconfitta() const;
    virtual void fineCombattimento(int);

    // Metodi Legati al Commercio
    int getSizeMercato() const;
    virtual bool compraOggetto(int);
    oggetto* ricercaOggettoNelMercato(int) const;
    string ricercaNomeOggettoNelMercato(int) const;

    // Metodi Legati allo scambio oggetti tra il giocatore e il suo zaino
    virtual const oggetto* ricercaOggettoNellEquipaggiamento(int) const;
    virtual void opzioniEquipaggiamento(int);
    virtual void opzioniZaino(int, int);
    virtual void vendiOggetto(oggetto*);
    virtual bool vendiOggettobyId(int);

    // Aiuto alle possibilità dell'Arena
    int avversariRimasti() const;
    bool inCombattimento() const;
    virtual void recuperoPostScontro();
    virtual bool vintoArena() =0;
};

#endif // ARENA

