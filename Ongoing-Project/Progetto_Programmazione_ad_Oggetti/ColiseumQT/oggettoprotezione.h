#ifndef OGGETTOPROTEZIONE
#define OGGETTOPROTEZIONE
#include"oggetto.h"
class oggettoProtezione : public oggetto {
private:
    double protezione;
public:
    // Costruttore e Distruttore Virtuale
    oggettoProtezione(string, double, double, int, double);
    virtual ~oggettoProtezione();

    // Assegnazione e Costruttore di Copia di Default-Standard

    // Metodi Non Virtuali
    double getProtezione() const;

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
    bool operator==( const oggettoProtezione& ) const;
    bool operator!=( const oggettoProtezione& ) const;
};
#endif // OGGETTOPROTEZIONE

