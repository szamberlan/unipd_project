#include"alabarda.h"

alabarda::alabarda(string n, double p, int c, double d):
armaLunga(n,p,c,d,0.725){}

alabarda::~alabarda(){}

double alabarda::AffondoCaricato() const {
    if(testProbabilita(0.50))
        return getDanno()*4.25;
    else
        return getDanno()/3;
}

double alabarda::AffondoRapido() const {
    if(testProbabilita(0.80))
        return getDanno()*2.5;
    else
        return getDanno();
}

double alabarda::FendenteCaricato() const {
    if(testProbabilita(0.70))
        return getDanno()*3;
    else
        return getDanno()/2;
}

double alabarda::FendenteRapido() const {
    return getDanno()*1.725;
}


double alabarda::DannoEffettuato(int scelta)
{
    if(scelta==1)
    {
        manovrabilita=1.25;
        return FendenteRapido();
    }
    if(scelta==2)
    {
        manovrabilita=1.5;
        return AffondoRapido();
    }
    if(scelta==3)
    {
        manovrabilita=2.0;
        return FendenteCaricato();
    }
    if(scelta==4)
    {
        manovrabilita=2.0;
        return AffondoCaricato();
    }
        manovrabilita=1.0;
        return oggettoDanno::DannoEffettuato();
}

