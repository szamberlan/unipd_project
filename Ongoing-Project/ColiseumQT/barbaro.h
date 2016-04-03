#ifndef BARBARO
#define BARBARO
#include"orco.h"
class barbaro : public orco {
private:
    double vitaReale;
    double energiaReale;
    double colpire;
    double risparmioEnergia;
public:
    barbaro(string, double, double, int, double, double, double);
    virtual~barbaro();
    double getVitaAttuale() const;
    double getEnergiaAttuale() const;

    double getColpire() const;
    double getRisparmioEnergia() const;

    double attacca(int=0);
    void difendi(double);
    void recuperoVita();
    void recuperoEnergia();
    bool sconfitta() const;

    void recuperoCaratteristicheMax();
    void stampaSituazione() const;
    void stampaPersonaggio() const;
};
#endif // BARBARO

