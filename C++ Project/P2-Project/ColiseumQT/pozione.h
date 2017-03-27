#ifndef POZIONE
#define POZIONE
#include"oggettoaiuto.h"
class pozione: public oggettoAiuto {
private:
    int scelta;
    int durata;
public:
    pozione(string, int, double, int, int=1);
    virtual ~pozione();

    int getCosto() const;
    int getScelta() const;
    int getDurata() const;

    double AiutoCaratteristiche(int=0,bool=true);
    string getNomeUtilita(int) const;
    string getInfoUtilita(int) const;
    string getTipologiaOggetto() const;
};

#endif // POZIONE

