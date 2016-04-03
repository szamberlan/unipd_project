#ifndef PUGNALE
#define PUGNALE
#include"armacorta.h"
class pugnale : public armaCorta {
public:
    pugnale(string, double, int, double);
    virtual ~pugnale();

     // Metodi Non Virtuali
     double Affondo() const;
     double Sfregio() const;
     double TaglioRapido() const;
     double ColpoRavvicinato() const;

     // Metodi Virtuali
     double DannoEffettuato(int=0);
};
#endif // PUGNALE

