#include<iostream>
#include"furfante.h"
using std::cout;
using std::endl;

furfante::furfante(string n, double vm, double em, int s, double bVE, double aE, double aRRE):
umano(n,0.50,0.10+aE,vm,em,s,bVE), vitaReale(getVitaMax()), energiaReale(getEnergiaMax()), evadere(aE), risparmioRecuperoEnergia(aRRE){}

furfante::~furfante(){}

double furfante::getVitaAttuale() const{ return vitaReale; }

double furfante::getEnergiaAttuale() const { return vitaReale; }

double furfante::getEvadere() const { return evadere; }

double furfante::getRisparmioRecuperoEnergia() const { return risparmioRecuperoEnergia; }

double furfante::attacca(int scelta)
{
    if(energiaReale)
    {
        if(equipaggiamento[0]==0)
        {
            energiaReale=energiaReale-1;
            if(energiaReale<0)
                energiaReale=0;
            if(testProbabilita(getAttacco()))
                return getDanno();
            else
                return 0;
        }
        else
        {
            energiaReale=energiaReale-(equipaggiamento[0]->SottrazioneCaratteristiche());
            if(energiaReale<0)
                energiaReale=0.0;
            if(testProbabilita(getAttacco()*(1+equipaggiamento[0]->ProbabilitaColpire())))
            {
                return equipaggiamento[0]->DannoEffettuato(scelta);
            }
            else
                return 0;
        }

    }
    else
        return 0;
}

void furfante::difendi(double danno)
{
    if(danno)
    {
        if(equipaggiamento[1]&&equipaggiamento[2])
        {
            if(!(testProbabilita(getDifesa()-(equipaggiamento[1]->DeficitProvocato()+equipaggiamento[2]->DeficitProvocato()))))
                if(!equipaggiamento[2]->Parata())
                    vitaReale=vitaReale-(danno-(equipaggiamento[1]->ProtezioneOfferta()+equipaggiamento[2]->ProtezioneOfferta()));
                if(vitaReale<0)
                    vitaReale=0;
        }
        else
        {
            if(equipaggiamento[1])
            {
                if(!(testProbabilita(getDifesa()-(equipaggiamento[1]->DeficitProvocato()))))
                    vitaReale=vitaReale-(danno-equipaggiamento[1]->ProtezioneOfferta());
                if(vitaReale<0)
                    vitaReale=0;
            }
            else
            {
                if(equipaggiamento[2])
                {
                    if(!(testProbabilita(getDifesa()-equipaggiamento[2]->DeficitProvocato())))
                        if(!equipaggiamento[2]->Parata())
                            vitaReale=vitaReale-(danno-equipaggiamento[2]->ProtezioneOfferta());
                        if(vitaReale<0)
                            vitaReale=0;
                }
                else
                {
                    if(!(testProbabilita(getDifesa())))
                        vitaReale=vitaReale-danno;
                    if(vitaReale<0)
                        vitaReale=0;
                }
            }
        }
    }
}

void furfante::recuperoVita()
{
    if(equipaggiamento[3]!=0)
        vitaReale=vitaReale+equipaggiamento[3]->AiutoCaratteristiche(1);
        if(vitaReale>getVitaMax())
            vitaReale=getVitaMax();
}

void furfante::recuperoEnergia()
{
    if(equipaggiamento[4]!=0)
        energiaReale=energiaReale+(equipaggiamento[4]->AiutoCaratteristiche(2)*(1+risparmioRecuperoEnergia));
        if(energiaReale>getEnergiaMax())
            energiaReale=getEnergiaMax();
}

bool furfante::sconfitta() const
{
    if(!vitaReale)
        return true;
    else
        return false;
}


void furfante::recuperoCaratteristicheMax()
{
   vitaReale=getVitaMax();
   energiaReale=getEnergiaMax();
}

void furfante::stampaSituazione() const
{
    cout<<"Vita Attuale : "<<vitaReale<<endl;
    cout<<"Energia Attuale : "<<energiaReale<<endl;
}

void furfante::stampaPersonaggio() const
{
    cout<<"Classe : Furfante"<<endl;
    umano::stampaPersonaggio();
}
