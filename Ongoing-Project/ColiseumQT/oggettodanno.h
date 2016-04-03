#ifndef OGGETTODANNO
#define OGGETTODANNO
#include"oggetto.h"
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
    double getDanno() const;
    double getPrColpire() const;
    double getManovrabilita() const;
    void riassestaArma();


    // Metodi Virtuali
    void stampaCaratteristiche() const;

    double ProbabilitaColpire() const;
    double DannoEffettuato(int=0);             // implementazione
    double ProtezioneOfferta() const;           // implementazione
    bool Parata(double=1) const;                        // implementazione
    double AiutoCaratteristiche(int=0) const;        // implementazione
    double SottrazioneCaratteristiche() const;  // implementazione
    double DeficitProvocato() const;            // implementazione

    // Operatori di uguaglianza e di disuguaglianza virtuali
    bool operator==(const oggettoDanno& ) const;
    bool operator!=(const oggettoDanno& ) const;
};

#endif // OGGETTODANNO

