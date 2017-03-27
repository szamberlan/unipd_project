#ifndef SCUDO
#define SCUDO
#include"oggettoprotezione.h"
class scudo : public oggettoProtezione {
private:
    double pr_parata;
protected:
    bool testParata(double) const;
public:
     // Costruttore e Distruttore Virtuale
    scudo(string, double, double, int, double, double);
    virtual ~scudo();

    // Costruttore di Copia e Assegnazione di Default Standard

    //Metodi Non Virtuali
    double getPrParata() const;

    // Metodi Virtuali
    bool Parata(double=1,bool=true) const;
    string getNomeUtilita(int=0) const;
    string getInfoUtilita(int=0) const;
    string getTipologiaOggetto() const;
};
#endif // SCUDO

