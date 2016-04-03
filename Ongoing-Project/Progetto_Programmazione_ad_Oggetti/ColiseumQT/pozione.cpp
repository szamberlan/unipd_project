#include"pozione.h"

pozione::pozione(string n, int c, double a, int s)
:oggettoAiuto(n,1,1,c,a), scelta(s){}

pozione::~pozione(){}

int pozione::getScelta() const {return scelta;}

double pozione::AiutoCaratteristiche(int sc) const
{
    if(sc==scelta)
        return getAiuto();
    else
        return 0;
}
