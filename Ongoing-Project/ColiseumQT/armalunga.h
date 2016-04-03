#ifndef ARMALUNGA
#define ARMALUNGA
#include"oggettodanno.h"
class armaLunga : public oggettoDanno {
public:
    // Costruttore e Distruttore Virtuali
    armaLunga(string, double, int, double, double);
    virtual ~armaLunga();
};
#endif // ARMALUNGA

