#ifndef MAZZA
#define MAZZA
#include"armamedia.h"
class mazza : public armaMedia {
public:
    mazza(string, double, int, double);
    virtual ~mazza();

    // Metodi Non Virtuali
    double Fendente() const;
    double DirittoSgualembrato() const;
    double RoversoSgualembrato() const;
    double RoversoTondo() const;

    // Metodi Virtuali
    double DannoEffettuato(int=0);
};
#endif // MAZZA

