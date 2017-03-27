#ifndef OGGETTOPROTEZIONE
#define OGGETTOPROTEZIONE
#include"oggetto.h"
#include<sstream>
class oggettoProtezione : public oggetto {
private:
    double protezione;
public:
    // Costruttore e Distruttore Virtuale
    oggettoProtezione(string, double, double, int, double);
    virtual ~oggettoProtezione();

    // Assegnazione e Costruttore di Copia di Default-Standard

    // Metodi Virtuali
    double getProtezione() const;

    double ProbabilitaColpire() const;          // implementazione
    double DannoEffettuato(int=0);              // implementazione
    double ProtezioneOfferta() const;           // implementazione
    bool Parata(double=1,bool=true)const;       // implementazione
    double AiutoCaratteristiche(int=0, bool=true);// implementazione
    double SottrazioneCaratteristiche() const;  // implementazione
    double DeficitProvocato() const;            // implementazione
    virtual string getNomeUtilita(int=0) const; // implementazione
    virtual string getInfoUtilita(int=0) const; // implementazione
    string getTipologiaOggetto() const;         // implementazione

    // Operatori di uguaglianza e di disuguaglianza virtuali
    bool operator==( const oggettoProtezione& ) const;
    bool operator!=( const oggettoProtezione& ) const;
};
#endif // OGGETTOPROTEZIONE

