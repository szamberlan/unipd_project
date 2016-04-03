#include"pugnale.h"

pugnale::pugnale(string n, double p, int c, double d):
armaCorta(n,p,c,d,0.20){}

pugnale::~pugnale(){}

double pugnale::ColpoRavvicinato() const
{
    if(testProbabilita(0.50))
        return getDanno()*10;
    else
        return getDanno();
}

double pugnale::Affondo() const
{
    if(testProbabilita(0.70))
        return getDanno()*8.5;
    else
        return getDanno()/2;
}

double pugnale::TaglioRapido() const
{
    return getDanno()*5;
}

double pugnale::Sfregio() const
{
    if(testProbabilita(0.90))
        return getDanno()*7.5;
    else
        return getDanno();
}

double pugnale::DannoEffettuato(int scelta)
{
    if(scelta==1)
    {
        manovrabilita=1.25;
        return TaglioRapido();
    }
    if(scelta==2)
    {
        manovrabilita=1.5;
        return Sfregio();
    }
    if(scelta==3)
    {
        manovrabilita=2.0;
        return Affondo();
    }
    if(scelta==4)
    {
        manovrabilita=2.0;
        return ColpoRavvicinato();
    }
        manovrabilita=1.0;
        return oggettoDanno::DannoEffettuato();
}
