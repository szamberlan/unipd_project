#ifndef ARMA_H
#define ARMA_H
#include"oggettodanno.h"
#include"arma.h"
class arma : public oggettoDanno {
private:
    double percentualeSuperficieDanno;
    double dannoCritico;
public:
    // Costruttore e Distruttore Virtuali
    arma(string, double, double, int, double, double, double, double);
    virtual ~arma();

    // Metodi Non Virtuali
    double getSupDanno() const;
    double getDannoCritico() const;

    double Mossa1() const;
    double Mossa2() const;
    double Mossa3() const;
    double Mossa4() const;
    double calcoloDanno(double) const;

    // Metodi Virtuali
    double DannoEffettuato(int=0);
    string getNomeUtilita(int=0) const;
    string getInfoUtilita(int=0) const;
    string getTipologiaOggetto() const;

};
#endif // ARMA_H

