#ifndef ELFO
#define ELFO
#include"personaggio.h"
class elfo : public personaggio{
private:
    double bonusEnergia;
public:
    elfo(string, double, double, double, double, int, double);
    virtual~elfo();

    double getAbilitaElfo() const;
    void stampaPersonaggio() const;
};
#endif // ELFO
