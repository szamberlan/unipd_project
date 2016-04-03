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

bool scudo::Parata(double bonus) const
{
    return testParata(pr_parata*bonus);
}

void scudo::stampaCaratteristiche() const
{
    oggettoProtezione::stampaCaratteristiche();
    std::cout<<"Probabilita Parata : "<<getPrParata()*100<<" %"<<std::endl;
}
