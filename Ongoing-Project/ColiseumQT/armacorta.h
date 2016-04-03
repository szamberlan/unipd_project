#ifndef ARMACORTA
#define ARMACORTA
#include"oggettodanno.h"
class armaCorta : public oggettoDanno {
public:
    // Costruttore e Distruttore Virtuali
    armaCorta(string, double, int, double, double);
    virtual ~armaCorta();
};
#endif // ARMACORTA
