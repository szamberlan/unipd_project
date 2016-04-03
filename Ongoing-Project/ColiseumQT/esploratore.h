#ifndef ESPLORATORE
#define ESPLORATORE
#include"elfo.h"
class esploratore : public elfo {
private:
    double vitaReale;
    double energiaReale;
    double colpire;
    double risparmioRecuperoVita;
public:
    esploratore(string, double, double, int, double, double, double);
    virtual~esploratore();
    double getVitaAttuale() const;
    double getEnergiaAttuale() const;

    double getColpire() const;
    double getRisparmioRecuperoVita() const;

    double attacca(int=0);
    void difendi(double);
    void recuperoVita();
    void recuperoEnergia();
    bool sconfitta() const;

    void recuperoCaratteristicheMax();
    void stampaSituazione() const;
    void stampaPersonaggio() const;
};
#endif // ESPLORATORE

