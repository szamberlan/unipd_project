#ifndef ASCIA
#define ASCIA
#include"armamedia.h"
class ascia : public armaMedia {
public:
    ascia(string, double, int, double);
    virtual ~ascia();

    // Metodi Non Virtuali
    double Fendente() const;
    double DirittoSgualembrato() const;
    double DirittoTondo() const;
    double DirittoRidoppio() const;

    // Metodi Virtuali
    double DannoEffettuato(int=0);
};
#endif // ASCIA

