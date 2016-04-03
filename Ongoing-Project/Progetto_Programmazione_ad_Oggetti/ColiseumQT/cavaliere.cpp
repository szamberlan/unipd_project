#include<iostream>
#include"cavaliere.h"
using std::cout;
using std::endl;

cavaliere::cavaliere(string n, double vm, double em, int s, double bVE, double aC, double aBP):
umano(n,0.50+aC,0.10,vm,em,s,bVE), vitaReale(getVitaMax()), energiaReale(getEnergiaMax()), colpire(aC), bonusParata(aBP){}

cavaliere::~cavaliere(){}

double cavaliere::getVitaAttuale() const{ return vitaReale; }

double cavaliere::getEnergiaAttuale() const { return vitaReale; }

double cavaliere::getColpire() const { return colpire; }

double cavaliere::getBonusParata() const { return bonusParata; }

double cavaliere::attacca(int scelta)
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

void cavaliere::difendi(double danno)
{
    {
        if(danno)
        {
            if(equipaggiamento[1]&&equipaggiamento[2])
            {
                if(!(testProbabilita(getDifesa()-(equipaggiamento[1]->DeficitProvocato()+equipaggiamento[2]->DeficitProvocato()))))
                    if(!equipaggiamento[2]->Parata(bonusParata))
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
                            if(!equipaggiamento[2]->Parata(bonusParata))
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
}

void cavaliere::recuperoVita()
{
    if(equipaggiamento[3]!=0)
        vitaReale=vitaReale+equipaggiamento[3]->AiutoCaratteristiche(1);
        if(vitaReale>getVitaMax())
            vitaReale=getVitaMax();
}

void cavaliere::recuperoEnergia()
{
    if(equipaggiamento[4]!=0)
        energiaReale=energiaReale+equipaggiamento[4]->AiutoCaratteristiche(2);
        if(energiaReale>getEnergiaMax())
            energiaReale=getEnergiaMax();
}

bool cavaliere::sconfitta() const
{
    if(!vitaReale)
        return true;
    else
        return false;
}


void cavaliere::recuperoCaratteristicheMax()
{
   vitaReale=getVitaMax();
   energiaReale=getEnergiaMax();
}

void cavaliere::stampaSituazione() const
{
    cout<<"Vita Attuale : "<<vitaReale<<endl;
    cout<<"Energia Attuale : "<<energiaReale<<endl;
}

void cavaliere::stampaPersonaggio() const
{
    cout<<"Classe : Cavaliere"<<endl;
    umano::stampaPersonaggio();
}
