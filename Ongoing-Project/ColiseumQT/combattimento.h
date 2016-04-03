#ifndef COMBATTIMENTO
#define COMBATTIMENTO
#include<iostream>
#include"personaggio.h"
class combattimento {
private:
    // Campi Dati Privati
    personaggio*giocatore1;
    personaggio*giocatore2;
    int turno;
    bool inCombattimento;

    // Metodi Privati
    // Metodi di Ausilio
    virtual void attacco(bool, int=1);
    virtual void recuperoVita(bool);
    virtual void recuperoEnergia(bool);
public:
    // Costruttore e Distruttore
    combattimento(personaggio*, personaggio*, int=0, bool=false);
    virtual~combattimento();

    // Metodi Non Virtuali
    // Metodi Che Restituiscono i Dati
    personaggio*getGiocatore1() const;
    personaggio*getGiocatore2() const;
    int turnoDiCombattimento() const;
    bool InCombattimento() const;

    // Metodi di Cambio Dati
    void cambioGiocatore1(personaggio*, bool=1);
    void cambioGiocatore2(personaggio*, bool=1);

    // Metodi Virtuali
    // Metodi Principali
    virtual void inizioCombattimento();
    virtual void svolgiTurno(int,int);
    virtual void fineCombattimento();

    // Metodi di Ausilio
    virtual bool Vittoria1() const;
    virtual bool Vittoria2() const;
};

std::ostream& operator<<(std::ostream&, combattimento&);

#endif // COMBATTIMENTO

