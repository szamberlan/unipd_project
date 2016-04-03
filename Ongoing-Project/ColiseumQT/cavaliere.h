#ifndef CAVALIERE
#define CAVALIERE
#include"umano.h"
class cavaliere : public umano {
private:
    double vitaReale;
    double energiaReale;
    double colpire;
    double bonusParata;
public:
    cavaliere(string, double, double, int, double, double, double);
    virtual~cavaliere();
    double getVitaAttuale() const;
    double getEnergiaAttuale() const;

    double getColpire() const;
    double getBonusParata() const;

    double attacca(int=0);
    void difendi(double);
    void recuperoVita();
    void recuperoEnergia();
    bool sconfitta() const;

    void recuperoCaratteristicheMax();
    void stampaSituazione() const;
    void stampaPersonaggio() const;
};
#endif // CAVALIERE

