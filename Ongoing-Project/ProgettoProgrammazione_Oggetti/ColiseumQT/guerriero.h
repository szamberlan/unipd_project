#ifndef GUERRIERO
#define GUERRIERO
#include"orco.h"
class guerriero : public orco {
private:
    double vitaReale;
    double energiaReale;
    double evadere;
    double risparmioDeficitDifesa;
public:
    guerriero(string, double, double, int, double, double, double);
    virtual~guerriero();
    double getVitaAttuale() const;
    double getEnergiaAttuale() const;

    double getEvadere() const;
    double getRisparmioDeficitDifesa() const;

    double attacca(int=0);
    void difendi(double);
    void recuperoVita();
    void recuperoEnergia();
    bool sconfitta() const;

    void recuperoCaratteristicheMax();
    void stampaSituazione() const;
    void stampaPersonaggio() const;
};
#endif // GUERRIERO

