#ifndef ARMAMEDIA
#define ARMAMEDIA
#include"oggettodanno.h"
class armaMedia : public oggettoDanno {
public:
    // Costruttore e Distruttore Virtuali
    armaMedia(string, double, int, double, double);
    virtual ~armaMedia();
};
#endif // ARMAMEDIA

