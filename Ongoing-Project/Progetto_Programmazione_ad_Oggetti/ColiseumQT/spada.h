#ifndef SPADA
#define SPADA
#include"armamedia.h"
class spada : public armaMedia {
public:
    spada(string, double, int, double);
    virtual ~spada();

    // Metodi Non Virtuali
    double Fendente() const;
    double Affondo() const;
    double Montante() const;
    double DirittoTondo() const;

    // Metodi Virtuali
    double DannoEffettuato(int=0);
};
#endif // SPADA

