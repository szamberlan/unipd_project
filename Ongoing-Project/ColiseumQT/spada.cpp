#include"spada.h"

spada::spada(string n, double p, int c, double d):
armaMedia(n,p,c,d,0.50){}

spada::~spada(){}

double spada::Affondo() const {
    return getDanno()*2.5;
}

double spada::Fendente() const {
    if(testProbabilita(0.90))
        return getDanno()*4;
    else
        return getDanno();
}

double spada::DirittoTondo() const {
    if(testProbabilita(0.75))
        return getDanno()*5.5;
    else
        return getDanno()/2;
}

double spada::Montante() const {
    if(testProbabilita(0.60))
        return getDanno()*7;
    else
        return getDanno()/3;
}

double spada::DannoEffettuato(int scelta)
{
    if(scelta==1)
    {
        manovrabilita=1.25;
        return Affondo();
    }
    if(scelta==2)
    {
        manovrabilita=1.5;
        return Fendente();
    }
    if(scelta==3)
    {
        manovrabilita=2.0;
        return DirittoTondo();
    }
    if(scelta==4)
    {
        manovrabilita=2.0;
        return Montante();
    }
        manovrabilita=1.0;
        return oggettoDanno::DannoEffettuato();
}
