#include"mazza.h"

mazza::mazza(string n, double p, int c, double d):
armaMedia(n,p,c,d,0.55){}

mazza::~mazza(){}

double mazza::DirittoSgualembrato() const {
    if(testProbabilita(0.725))
        return getDanno()*4.5;
    else
        return getDanno()/2;
}

double mazza::Fendente() const {
    if(testProbabilita(0.85))
        return getDanno()*3;
    else
        return getDanno();
}

double mazza::RoversoTondo() const {
    return getDanno()*2.25;
}

double mazza::RoversoSgualembrato() const {
    if(testProbabilita(0.60))
        return getDanno()*6;
    else
        return getDanno()/3;
}

double mazza::DannoEffettuato(int scelta)
{
    if(scelta==1)
    {
        manovrabilita=1.25;
        return Fendente();
    }
    if(scelta==2)
    {
        manovrabilita=1.5;
        return RoversoTondo();
    }
    if(scelta==3)
    {
        manovrabilita=2.0;
        return DirittoSgualembrato();
    }
    if(scelta==4)
    {
        manovrabilita=2.0;
        return RoversoSgualembrato();
    }
        manovrabilita=1.0;
        return oggettoDanno::DannoEffettuato();
}

