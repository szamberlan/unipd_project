#include<iostream>
#include"esploratore.h"
using std::cout;
using std::endl;

esploratore::esploratore(string n, double vm, double em, int s, double bE, double aC, double aRRV):
elfo(n,0.50+aC,0.10,vm,em,s,bE), vitaReale(getVitaMax()), energiaReale(getEnergiaMax()), colpire(aC), risparmioRecuperoVita(aRRV){}

esploratore::~esploratore(){}

double esploratore::getVitaAttuale() const{ return vitaReale; }

double esploratore::getEnergiaAttuale() const { return vitaReale; }

double esploratore::getColpire() const { return colpire; }

double esploratore::getRisparmioRecuperoVita() const { return risparmioRecuperoVita; }

double esploratore::attacca(int scelta)
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

void esploratore::difendi(double danno)
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

void esploratore::recuperoVita()
{
    if(equipaggiamento[3]!=0)
        vitaReale=vitaReale+(equipaggiamento[3]->AiutoCaratteristiche(1)*(1+risparmioRecuperoVita));
        if(vitaReale>getVitaMax())
            vitaReale=getVitaMax();
}

void esploratore::recuperoEnergia()
{
    if(equipaggiamento[4]!=0)
        energiaReale=energiaReale+equipaggiamento[4]->AiutoCaratteristiche(2);
        if(energiaReale>getEnergiaMax())
            energiaReale=getEnergiaMax();
}

bool esploratore::sconfitta() const
{
    if(!vitaReale)
        return true;
    else
        return false;
}

void esploratore::recuperoCaratteristicheMax()
{
   vitaReale=getVitaMax();
   energiaReale=getEnergiaMax();
}

void esploratore::stampaSituazione() const
{
    cout<<"Vita Attuale : "<<vitaReale<<endl;
    cout<<"Energia Attuale : "<<energiaReale<<endl;
}

void esploratore::stampaPersonaggio() const
{
    cout<<"Classe : Esploratore"<<endl;
    elfo::stampaPersonaggio();
}
