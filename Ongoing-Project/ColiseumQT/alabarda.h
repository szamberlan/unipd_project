#ifndef ALABARDA
#define ALABARDA
#include"armalunga.h"
class alabarda : public armaLunga {
public:
    alabarda(string, double, int, double);
    virtual ~alabarda();

    // Metodi Non Virtuali
    double AffondoRapido() const;
    double AffondoCaricato() const;
    double FendenteRapido() const;
    double FendenteCaricato() const;

    // Metodi Virtuali
    double DannoEffettuato(int=0);
};
#endif // ALABARDA
