#ifndef LANCIA
#define LANCIA
#include"armalunga.h"
class lancia : public armaLunga {
public:
    lancia(string, double, int, double);
    virtual ~lancia();

    // Metodi Non Virtuali
    double AffondoCaricato() const;
    double AffondoRapido() const;
    double AffondoMirato() const;
    double ColpoRovescio() const;

    // Metodi Virtuali
    double DannoEffettuato(int=0);
};
#endif // LANCIA

