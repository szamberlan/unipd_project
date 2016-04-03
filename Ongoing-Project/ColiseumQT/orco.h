#ifndef ORCO
#define ORCO
#include"personaggio.h"
class orco : public personaggio {
private:
    double bonusVita;
public:
    orco(string, double, double, double, double, int, double);
    virtual ~orco();

    double getAbilitaOrco() const;
    void stampaPersonaggio() const;
};
#endif // ORCO

