#ifndef OGGETTOAIUTO
#define OGGETTOAIUTO
#include"oggetto.h"
#include<sstream>
class oggettoAiuto : public oggetto {
private:
    double aiuto;
public:
    oggettoAiuto(string, double, double, int, double);
    virtual ~oggettoAiuto();

    // Metodi Virtuali
    double getAiuto() const;

    double ProbabilitaColpire() const;          // implementazione
    double DannoEffettuato(int=0);              // implementazione
    double ProtezioneOfferta() const;           // implementazione
    bool Parata(double=1,bool=true) const;      // implementazione
    double AiutoCaratteristiche(int =0,bool=true);// implementazione
    double SottrazioneCaratteristiche() const;  // implementazione
    double DeficitProvocato() const;            // implementazione
    string getNomeUtilita(int=0) const;         // implementazione
    string getInfoUtilita(int=0) const;         // implementazione
    string getTipologiaOggetto() const;         // implementazione

    // Operatori di uguaglianza e di disuguaglianza virtuali
    bool operator==(const oggettoAiuto& ) const;
    bool operator!=(const oggettoAiuto& ) const;
};
#endif // OGGETTOAIUTO

