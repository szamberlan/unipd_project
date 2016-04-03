#ifndef POZIONE
#define POZIONE
#include"oggettoaiuto.h"
class pozione: public oggettoAiuto {
private:
    int scelta;
public:
    pozione(string, int, double, int);
    virtual ~pozione();

    int getScelta() const;

    double AiutoCaratteristiche(int=0) const;
};

#endif // POZIONE

