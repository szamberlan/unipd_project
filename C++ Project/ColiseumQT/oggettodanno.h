#ifndef OGGETTODANNO
#define OGGETTODANNO
#include"oggetto.h"
#include<sstream>
class oggettoDanno : public oggetto {
private :
    double danno;
    double pr_colpire;
protected:
    double manovrabilita;
public:
    // Costruttore e Distruttore Virtuale
    oggettoDanno(string, double, double, int, double, double, double);
    virtual ~oggettoDanno();

    // Costruttore di Copia e Assegnazione di Default Standard

    // Metodi Non Virtuali
    double getPrColpire() const;
    double getManovrabilita() const;
    void riassestaArma();


    // Metodi Virtuali
    double getDanno() const;

    double ProbabilitaColpire() const;          // implementazione
    double DannoEffettuato(int=0);              // implementazione
    double ProtezioneOfferta() const;           // implementazione
    bool Parata(double=1,bool=true) const;      // implementazione
    double AiutoCaratteristiche(int=0, bool=true);// implementazione
    double SottrazioneCaratteristiche() const;  // implementazione
    double DeficitProvocato() const;            // implementazione
    virtual string getNomeUtilita(int=0) const; // implementazione
    virtual string getInfoUtilita(int=0) const; // implementazione
    string getTipologiaOggetto() const;         // implementazione

    // Operatori di uguaglianza e di disuguaglianza virtuali
    bool operator==(const oggettoDanno& ) const;
    bool operator!=(const oggettoDanno& ) const;
};

#endif // OGGETTODANNO

