#include"scudo.h"
#include<QtGlobal>

scudo::scudo(string n, double p, double g, int c, double r, double pp):
oggettoProtezione(n,p,g,c,r), pr_parata(pp){}

scudo::~scudo(){}

bool scudo::testParata(double prob) const {
    double randomValue= qrand()% 100;
    if(randomValue < prob*100)
        return true;
    else
        return false;
}

double scudo::getPrParata() const
{
    return pr_parata;
}

bool scudo::Parata(double bonus, bool test) const
{
    if(test)
        return testParata(pr_parata*bonus);
    else
        return true;
}

string scudo::getTipologiaOggetto() const
{
    return oggettoProtezione::getTipologiaOggetto() + " Scudo";
}

string scudo::getNomeUtilita(int scelta) const
{
    if(scelta==1)
        return "Probabilità di Parata";
    else
        return oggettoProtezione::getNomeUtilita(scelta);
}


string scudo::getInfoUtilita(int scelta) const
{
    if(scelta==1)
    {
        string ab ="Parare con Probabilità : ";
        std::ostringstream strs;
        strs << getPrParata();
        std::string str = strs.str();
        ab=ab+str;
        return ab;
    }
    else
        return oggettoProtezione::getInfoUtilita(scelta);
}
