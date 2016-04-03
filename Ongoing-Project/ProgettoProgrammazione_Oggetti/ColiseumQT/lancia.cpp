#include"lancia.h"

lancia::lancia(string n, double p, int c, double d):
armaLunga(n,p,c,d,0.70){}

lancia::~lancia(){}

double lancia::AffondoCaricato() const {
    if(testProbabilita(0.55))
        return getDanno()*4.5;
    else
        return getDanno()/3;

}

double lancia::AffondoMirato() const {
    if(testProbabilita(0.70))
        return getDanno()*3;
    else
        return getDanno()/2;
}

double lancia::AffondoRapido() const {
    if(testProbabilita(0.85))
        return getDanno()*2.5;
    else
        return getDanno();

}

double lancia::ColpoRovescio() const {
    return getDanno()*1.75;
}

double lancia::DannoEffettuato(int scelta)
{
    if(scelta==1)
    {
        manovrabilita=1.25;
        return ColpoRovescio();
    }
    if(scelta==2)
    {
        manovrabilita=1.5;
        return AffondoRapido();
    }
    if(scelta==3)
    {
        manovrabilita=2.0;
        return AffondoMirato();
    }
    if(scelta==4)
    {
        manovrabilita=2.0;
        return AffondoCaricato();
    }
        manovrabilita=1.0;
        return oggettoDanno::DannoEffettuato();
}

