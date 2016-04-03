#include"ascia.h"

ascia::ascia(string n, double p, int c, double d):
armaMedia(n,p,c,d,0.40){}

ascia::~ascia(){}

double ascia::Fendente() const {
     if(testProbabilita(0.85))
        return getDanno()*4.5;
     else
        return getDanno();
}

double ascia::DirittoTondo() const {
    return getDanno()*3;
}

double ascia::DirittoSgualembrato() const {
    if(testProbabilita(0.70))
        return getDanno()*6;
    else
        return getDanno()/2;


}

double ascia::DirittoRidoppio() const {
    if(testProbabilita(0.55))
        return getDanno()*7.5;
    else
        return getDanno()/3;
}


double ascia::DannoEffettuato(int scelta)
{
    if(scelta==1)
    {
        manovrabilita=1.25;
        return DirittoTondo();
    }
    if(scelta==2)
    {
        manovrabilita=1.5;
        return Fendente();
    }
    if(scelta==3)
    {
        manovrabilita=2.0;
        return DirittoSgualembrato();
    }
    if(scelta==4)
    {
        manovrabilita=2.0;
        return DirittoRidoppio();
    }
        manovrabilita=1.0;
        return oggettoDanno::DannoEffettuato();
}
