#ifndef ARENASEMPLICE
#define ARENASEMPLICE
#include"arena.h"
class arenaSemplice : public arena {
private:
    bool vittoriaArena;
    bool pozioneVita;
    bool pozioneEnergia;
    int testProbabilita() const;
public:
    // Costruttore e Distruttore Virtuale
    arenaSemplice(personaggio*p=0, int=0);
    virtual ~arenaSemplice();

    // Metodi di Ritorno Dati
    bool getVittoriaArena() const;

    // Metodi di Modifica Dati
    void VittoriaArena();

    // Metodi Implementati da Arena
    void combatti(int);
    void creaPersonaggio(string,double,double,int,int,int,double);
    bool vintoArena();
};
#endif // ARENASEMPLICE

