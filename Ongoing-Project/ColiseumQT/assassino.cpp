#include<iostream>
#include"assassino.h"
using std::cout;
using std::endl;

assassino::assassino(string n, double vm, double em, int s, double bE, double aE, double aDA):
elfo(n,0.50,0.10+aE,vm,em,s,bE), vitaReale(getVitaMax()), energiaReale(getEnergiaMax()), evadere(aE), dannoAumentato(aDA){}

assassino::~assassino(){}

double assassino::getVitaAttuale() const{ return vitaReale; }

double assassino::getEnergiaAttuale() const{ return vitaReale; }

double assassino::getEvadere() const{return evadere;}

double assassino::getDannoAumentato() const{return dannoAumentato;}

double assassino::attacca(int scelta)
{
    if(energiaReale)
    {
        if(equipaggiamento[0]==0)
        {
            energiaReale=energiaReale-1;
            if(energiaReale<0)
                energiaReale=0.0;
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
                return (dannoAumentato*(equipaggiamento[0]->DannoEffettuato(scelta)));
            }
            else
                return 0;
        }
     }
     else
        return 0;
}

void assassino::difendi(double danno)
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

void assassino::recuperoVita()
{
    if(equipaggiamento[3]!=0)
        vitaReale=vitaReale+equipaggiamento[3]->AiutoCaratteristiche(1);
        if(vitaReale>getVitaMax())
            vitaReale=getVitaMax();
}

void assassino::recuperoEnergia()
{
    if(equipaggiamento[4]!=0)
        energiaReale=energiaReale+equipaggiamento[4]->AiutoCaratteristiche(2);
        if(energiaReale>getEnergiaMax())
            energiaReale=getEnergiaMax();
}

bool assassino::sconfitta() const
{
    if(!vitaReale)
        return true;
    else
        return false;
}

void assassino::recuperoCaratteristicheMax()
{
   vitaReale=getVitaMax();
   energiaReale=getEnergiaMax();
}

void assassino::stampaSituazione() const
{
    cout<<"Vita Attuale : "<<vitaReale<<endl;
    cout<<"Energia Attuale : "<<energiaReale<<endl;
}

void assassino::stampaPersonaggio() const
{
    cout<<"Classe : Assassino"<<endl;
    elfo::stampaPersonaggio();
}
