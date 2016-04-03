#ifndef ASSASSINO
#define ASSASSINO
#include"elfo.h"
class assassino : public elfo {
private:
    double vitaReale;
    double energiaReale;
    double evadere;
    double dannoAumentato;
public:
    assassino(string, double, double, int, double, double, double);
    virtual~assassino();
    double getVitaAttuale() const;
    double getEnergiaAttuale() const;

    double getEvadere() const;
    double getDannoAumentato() const;

    double attacca(int=0);
    void difendi(double);
    void recuperoVita();
    void recuperoEnergia();
    bool sconfitta() const;

    void recuperoCaratteristicheMax();
    void stampaSituazione() const;
    void stampaPersonaggio() const;
};
#endif // ASSASSINO

