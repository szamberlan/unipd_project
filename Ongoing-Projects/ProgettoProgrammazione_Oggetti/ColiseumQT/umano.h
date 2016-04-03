#ifndef UMANO
#define UMANO
#include"personaggio.h"
class umano : public personaggio{
    double bonusVitaEnergia;
public:
    umano(string, double, double, double, double, int, double);
    virtual ~umano();

    double getAbilitaUmano() const;
    void stampaPersonaggio() const;
};
#endif // UMANO

