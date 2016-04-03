#ifndef FURFANTE
#define FURFANTE
#include"umano.h"
class furfante : public umano {
private:
    double vitaReale;
    double energiaReale;
    double evadere;
    double risparmioRecuperoEnergia;
public:
    furfante(string, double, double, int, double, double, double);
    virtual~furfante();
    double getVitaAttuale() const;
    double getEnergiaAttuale() const;

    double getEvadere() const;
    double getRisparmioRecuperoEnergia() const;

    double attacca(int=0);
    void difendi(double);
    void recuperoVita();
    void recuperoEnergia();
    bool sconfitta() const;

    void recuperoCaratteristicheMax();
    void stampaSituazione() const;
    void stampaPersonaggio() const;
};
#endif // FURFANTE

