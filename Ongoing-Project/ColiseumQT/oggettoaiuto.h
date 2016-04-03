#ifndef OGGETTOAIUTO
#define OGGETTOAIUTO
#include"oggetto.h"
class oggettoAiuto : public oggetto {
private:
    double aiuto;
public:
    oggettoAiuto(string, double, double, int, double);
    virtual ~oggettoAiuto();

    double getAiuto() const;

    // Metodi Virtuali
    void stampaCaratteristiche() const;

    double ProbabilitaColpire() const;
    double DannoEffettuato(int=0);           // implementazione
    double ProtezioneOfferta() const;           // implementazione
    bool Parata(double=1) const;                        // implementazione
    double AiutoCaratteristiche(int =0) const;        // implementazione
    double SottrazioneCaratteristiche() const;  // implementazione
    double DeficitProvocato() const;            // implementazione

    // Operatori di uguaglianza e di disuguaglianza virtuali
    bool operator==(const oggettoAiuto& ) const;
    bool operator!=(const oggettoAiuto& ) const;
};
#endif // OGGETTOAIUTO

