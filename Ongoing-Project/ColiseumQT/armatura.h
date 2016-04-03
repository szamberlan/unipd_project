#ifndef ARMATURA
#define ARMATURA
#include"oggettoprotezione.h"
class armatura : public oggettoProtezione {
public:
     // Costruttore e Distruttore Virtuale
    armatura(string, double, int, double);
    virtual ~armatura();

    // Costruttore di Copia e Assegnazione di Default Standard


};
#endif // ARMATURA

