#include<iostream>
#include"guerriero.h"
using std::cout;
using std::endl;

guerriero::guerriero(string n, double vm, double em, int s, double bV, double aE, double aRDD):
orco(n,0.50,0.10+aE,vm,em,s,bV), vitaReale(getVitaMax()), energiaReale(getEnergiaMax()), evadere(aE), risparmioDeficitDifesa(aRDD){}

guerriero::~guerriero(){}

double guerriero::getVitaAttuale() const{ return vitaReale; }

double guerriero::getEnergiaAttuale() const { return vitaReale; }

double guerriero::getEvadere() const { return evadere; }

double guerriero::getRisparmioDeficitDifesa() const { return risparmioDeficitDifesa; }

double guerriero::attacca(int scelta)
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

void guerriero::difendi(double danno)
{
    if(danno)
    {
        if(equipaggiamento[1]&&equipaggiamento[2])
        {
            if(!(testProbabilita(getDifesa()-risparmioDeficitDifesa*(equipaggiamento[1]->DeficitProvocato()+equipaggiamento[2]->DeficitProvocato()))))
                if(!equipaggiamento[2]->Parata())
                    vitaReale=vitaReale-(danno-(equipaggiamento[1]->ProtezioneOfferta()+equipaggiamento[2]->ProtezioneOfferta()));
                if(vitaReale<0)
                    vitaReale=0;
        }
        else
        {
            if(equipaggiamento[1])
            {
                if(!(testProbabilita(getDifesa()-risparmioDeficitDifesa*(equipaggiamento[1]->DeficitProvocato()))))
                    vitaReale=vitaReale-(danno-equipaggiamento[1]->ProtezioneOfferta());
                if(vitaReale<0)
                    vitaReale=0;
            }
            else
            {
                if(equipaggiamento[2])
                {
                    if(!(testProbabilita(getDifesa()-risparmioDeficitDifesa*equipaggiamento[2]->DeficitProvocato())))
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

void guerriero::recuperoVita()
{
    if(equipaggiamento[3]!=0)
        vitaReale=vitaReale+equipaggiamento[3]->AiutoCaratteristiche(1);
        if(vitaReale>getVitaMax())
            vitaReale=getVitaMax();
}
void guerriero::recuperoEnergia()
{
    if(equipaggiamento[4]!=0)
        energiaReale=energiaReale+equipaggiamento[4]->AiutoCaratteristiche(2);
        if(energiaReale>getEnergiaMax())
            energiaReale=getEnergiaMax();
}

bool guerriero::sconfitta() const
{
    if(!vitaReale)
        return true;
    else
        return false;
}


void guerriero::recuperoCaratteristicheMax()
{
   vitaReale=getVitaMax();
   energiaReale=getEnergiaMax();
}

void guerriero::stampaSituazione() const
{
    cout<<"Vita Attuale : "<<vitaReale<<endl;
    cout<<"Energia Attuale : "<<energiaReale<<endl;
}

void guerriero::stampaPersonaggio() const
{
    cout<<"Classe : Guerriero"<<endl;
    orco::stampaPersonaggio();
}
