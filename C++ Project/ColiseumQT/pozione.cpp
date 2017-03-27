#include"pozione.h"

pozione::pozione(string n, int c, double a, int s, int d)
:oggettoAiuto(n,1,1,c,a), scelta(s), durata(d){}

pozione::~pozione(){}

int pozione::getCosto() const
{
    if(durata)
        return oggetto::getCosto();
    else
        return 0;
}

int pozione::getScelta() const {return scelta;}

int pozione::getDurata() const { return durata;}

double pozione::AiutoCaratteristiche(int sc, bool test)
{
    if((sc==scelta)&&(durata))
    {
        if(test)
        {
            durata = durata-1;
            return getAiuto();
        }
        else
            return getAiuto();
    }
    else
        return 0;
}

string pozione::getNomeUtilita(int) const
{
    return "Aiuto";
}

string pozione::getInfoUtilita(int) const
{
    std::ostringstream strs;
    strs<<"Offrire Soccorso di "<< getAiuto()<<std::endl;
    strs<<"Con un durata di utilizzo di "<<getDurata();
    std::string str = strs.str();
    return str;
}

string pozione::getTipologiaOggetto() const
{
    return oggettoAiuto::getTipologiaOggetto() + " Pozione";
}
