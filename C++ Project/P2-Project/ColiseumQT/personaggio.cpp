#include"personaggio.h"
#include<QtGlobal>
#include<iostream>
using namespace std;
// Costruttore e Distruttore
personaggio::personaggio(string n, double a, double d, double vm, double em, double dan, double pro, int s, double b):
nome(n), attacco(a), difesa(d), vitaMax(vm), energiaMax(em), danno(dan), protezione(pro), soldi(s), bonus(b)
{
    for(int i=0; i<5; i++)
        equipaggiamento.Aggiungi_Oggetto(0);

    sceltaBonus=0;
    vitaReale= vitaMax;
    energiaReale=energiaMax;
}

personaggio::~personaggio(){}

// Metodi Protetti

bool personaggio::testProbabilita(double pr)
{
    double randomValue= qrand()% 10000;
    if(randomValue < pr*10000)
        return true;
    else
        return false;
}

// Metodi Non Virtuali

string personaggio::getNome() const{ return nome; }

double personaggio::getAttacco() const { return attacco; }

double personaggio::getDifesa() const { return difesa; }

double personaggio::getDanno() const { return danno; }

double personaggio::getProtezione() const { return protezione; }

int personaggio::getSoldi() const { return soldi; }

double personaggio::getVitaMax()  const { return vitaMax; }

double personaggio::getEnergiaMax() const { return energiaMax; }

void personaggio::aumentaSoldi(int aumento) { soldi=soldi+aumento; }


bool personaggio::settedBonus() const
{
    if(sceltaBonus)
        return true;
    else
        return false;
}

void personaggio::setBonusDannoAumentato(){
    if(!sceltaBonus)
        sceltaBonus=1;
}

void personaggio::setBonusRisparmioDeficitArmature(){
    if(!sceltaBonus)
        sceltaBonus=2;
}

void personaggio::setBonusParata(){
    if(!sceltaBonus)
        sceltaBonus=3;
}

void personaggio::setBonusRisparmioEnergia(){
    if(!sceltaBonus)
        sceltaBonus=4;
}

void personaggio::setBonusUtilizzoPozioneVita(){
    if(!sceltaBonus)
        sceltaBonus=5;
}

void personaggio::setBounusUtilizzoPozioneEnergia(){
    if(!sceltaBonus)
        sceltaBonus=6;
}

double personaggio::getBonus(int i) const
{
    if(i==sceltaBonus)
        return bonus;
    else
        return 1.0;
}

void personaggio::inserisciNelloZaino(oggetto *o)
{
    zaino.Aggiungi_Oggetto(o);
}

bool personaggio::compraOggetto(oggetto *o)
{
    if(o)
    {
        if(soldi>=o->getCosto())
        {
            soldi=soldi-o->getCosto();
            inserisciNelloZaino(o);
            return true;
        }
        else
            return false;
    }else
        return false;
}

oggetto* personaggio::vendiOggetto(oggetto*o)
{
    if(zaino.cercaOggetto(o))
    {
        soldi=soldi+o->getCosto();
        return zaino.ricavoOggetto(o);
    }
    else
        return 0;

}

oggetto *personaggio::ricercaOggetto(int i) const
{
    return zaino[i];
}

void personaggio::cambiaArma(int o)
{
    if(equipaggiamento[0]!=0)
    {
        if(zaino[o])
        {
            if(zaino[o]->getDanno()>0)
            {
                oggetto*aux=zaino[o];
                zaino[o]=equipaggiamento[0];
                equipaggiamento[0]=aux;
            }
        }
    }
    else
    {
        if(zaino[o])
        {
            if(zaino[o]->getDanno()>0)
            {
                equipaggiamento[0]=zaino[o];
                zaino[o]=0;
                zaino.Togli_Oggetto(zaino[o]);
            }
        }
    }
}

void personaggio::cambiaScudo(int o)
{
    if(equipaggiamento[1]!=0)
    {
        if(zaino[o])
        {
            if(zaino[o]->Parata(1,false))
            {
                oggetto*aux=zaino[o];
                zaino[o]=equipaggiamento[1];
                equipaggiamento[1]=aux;
            }
        }
    }
    else
    {
        if(zaino[o])
        {
            if(zaino[o]->Parata(1,false))
            {
                equipaggiamento[1]=zaino[o];
                zaino[o]=0;
                zaino.Togli_Oggetto(zaino[o]);
            }
        }
    }
}

void personaggio::cambiaArmatura(int o)
{
    if(equipaggiamento[2]!=0)
    {
        if(zaino[o])
        {
            if(zaino[o]->getProtezione())
            {
                if(!(zaino[o]->Parata(1,false)))
                {
                    oggetto*aux=zaino[o];
                    zaino[o]=equipaggiamento[2];
                    equipaggiamento[2]=aux;
                }
            }
        }
    }
    else
    {
        if(zaino[o])
        {
            if(zaino[o]->getProtezione())
            {
                if(!(zaino[o]->Parata(1,false)))
                {
                    equipaggiamento[2]=zaino[o];
                    zaino[o]=0;
                    zaino.Togli_Oggetto(zaino[o]);
                }
            }
        }
    }
}

void personaggio::cambiaPozioneVita(int o)
{
    if(equipaggiamento[3]!=0)
    {
        if(zaino[o])
        {
            oggetto*aux=zaino[o];
            zaino[o]=equipaggiamento[3];
            equipaggiamento[3]=aux;
        }
    }
    else
    {
        if(zaino[o])
        {
            if(zaino[o]->AiutoCaratteristiche(1,false))
            {
                equipaggiamento[3]=zaino[o];
                zaino[o]=0;
                zaino.Togli_Oggetto(zaino[o]);
            }
        }
    }
}

void personaggio::cambiaPozioneEnergia(int o)
{
    if(equipaggiamento[4]!=0)
    {
        if(zaino[o])
        {
            if(zaino[o]->AiutoCaratteristiche(2,false))
            {
                oggetto*aux=zaino[o];
                zaino[o]=equipaggiamento[4];
                equipaggiamento[4]=aux;
            }
        }
    }
    else
    {
        if(zaino[o])
        {
            if(zaino[o]->AiutoCaratteristiche(2,false))
            {
                equipaggiamento[4]=zaino[o];
                zaino[o]=0;
                zaino.Togli_Oggetto(zaino[o]);
            }
        }
    }
}

void personaggio::spostaArmaNelloZaino()
{
    if(equipaggiamento[0])
    {
        inserisciNelloZaino(equipaggiamento[0]);
        equipaggiamento[0]=0;
    }
}

void personaggio::spostaScudoNelloZaino()
{
    if(equipaggiamento[1])
    {
        inserisciNelloZaino(equipaggiamento[1]);
        equipaggiamento[1]=0;
    }
}

void personaggio::spostaArmaturaNelloZaino()
{
    if(equipaggiamento[2])
    {
        inserisciNelloZaino(equipaggiamento[2]);
        equipaggiamento[2]=0;
    }
}

void personaggio::spostaPozioneVitaNelloZaino()
{
    if(equipaggiamento[3])
    {
        inserisciNelloZaino(equipaggiamento[3]);
        equipaggiamento[3]=0;
    }
}

void personaggio::spostaPozioneEnergiaNelloZaino()
{
    if(equipaggiamento[4])
    {
        inserisciNelloZaino(equipaggiamento[4]);
        equipaggiamento[4]=0;
    }
}

int personaggio::getSizeZaino() const
{
    return zaino.size();
}

void personaggio::equipaggiaArma(oggetto*arma)
{
    if(arma->getDanno()>0)
    {
        if(equipaggiamento[0])
        {
            zaino.Aggiungi_Oggetto(equipaggiamento[0]);
            equipaggiamento[0]=arma;
        }
        else
        {
            equipaggiamento[0]=arma;
        }
    }
}

void personaggio::equipaggiaScudo(oggetto*scudo)
{
    if(scudo->Parata(1,false)>0)
    {
        if(equipaggiamento[1])
        {
            zaino.Aggiungi_Oggetto(equipaggiamento[1]);
            equipaggiamento[1]=scudo;
        }
        else
        {
            equipaggiamento[1]=scudo;
        }
    }
}

void personaggio::equipaggiaArmatura(oggetto*armatura)
{
    if(armatura->getProtezione()>0)
    {
        if(!(armatura->Parata(1,false)))
        {
            if(equipaggiamento[2])
            {
                zaino.Aggiungi_Oggetto(equipaggiamento[2]);
                equipaggiamento[2]=armatura;
            }
            else
            {
                equipaggiamento[2]=armatura;
            }
        }
    }
}

void personaggio::equipaggiaPozioneVita(oggetto*pozVita)
{
    if(pozVita->AiutoCaratteristiche(1,false)>0)
    {
        if(equipaggiamento[3])
        {
            zaino.Aggiungi_Oggetto(equipaggiamento[3]);
            equipaggiamento[3]=pozVita;
        }
        else
        {
            equipaggiamento[3]=pozVita;
        }
    }

}

void personaggio::equipaggiaPozioneEnergia(oggetto*pozEnergia)
{
    if(pozEnergia->AiutoCaratteristiche(2,false)>0)
    {
        if(equipaggiamento[4])
        {
            zaino.Aggiungi_Oggetto(equipaggiamento[4]);
            equipaggiamento[4]=pozEnergia;
        }
        else
        {
            equipaggiamento[4]=pozEnergia;
        }
    }
}

void personaggio::eliminaArma()
{
    if(equipaggiamento[0])
    {
        delete equipaggiamento[0];
        equipaggiamento[0]=0;
    }
}

void personaggio::eliminaScudo()
{
    if(equipaggiamento[1])
    {
        delete equipaggiamento[1];
        equipaggiamento[1]=0;
    }
}

void personaggio::eliminaArmatura()
{
    if(equipaggiamento[2])
    {
        delete equipaggiamento[2];
        equipaggiamento[2]=0;
    }
}

void personaggio::eliminaPozioneVita()
{
    if(equipaggiamento[3])
    {
        delete equipaggiamento[3];
        equipaggiamento[3]=0;
    }
}

void personaggio::eliminaPozioneEnergia()
{
    if(equipaggiamento[4])
    {
        delete equipaggiamento[4];
        equipaggiamento[4]=0;
    }
}

const oggetto*personaggio::getEquipaggiamento(int i) const
{
    if(i>4)
        return 0;
    else
        return equipaggiamento[i];
}

oggetto* personaggio::getArma() const
{
    return equipaggiamento[0];
}

oggetto* personaggio::getArmatura() const
{
    return equipaggiamento[2];
}

oggetto* personaggio::getScudo() const
{
    return equipaggiamento[1];
}

oggetto* personaggio::getPozione1() const
{
    return equipaggiamento[3];
}

oggetto* personaggio::getPozione2() const
{
    return equipaggiamento[4];
}

// Metodi Virtuali

double personaggio::AttaccoAttuale() const
{
    if(getArma())
        return getArma()->ProbabilitaColpire()*getAttacco();
    else
        return getAttacco();
}

double personaggio::DifesaAttuale() const
{
    if(getArmatura())
    {
        if(getScudo())
        {
            if((getDifesa()-getArmatura()->DeficitProvocato()-getScudo()->DeficitProvocato())<0)
                return 0.0;
            else
                return getDifesa()-getArmatura()->DeficitProvocato()-getScudo()->DeficitProvocato();
        }
        else
        {
            if((getDifesa()-getArmatura()->DeficitProvocato())<0)
                return 0.0;
            else
                return getDifesa()-getArmatura()->DeficitProvocato();
        }
    }
    else
    {
        if(getScudo())
        {
            if((getDifesa()-getScudo()->DeficitProvocato())<0)
                return 0.0;
            else
                return getDifesa()-getScudo()->DeficitProvocato();
        }
        else
        {
            return getDifesa();
        }
    }
}

double personaggio::DannoAttuale() const
{
    if(getArma())
        return getArma()->getDanno();
    else
        return getDanno();
}


double personaggio::ProtezioneAttuale() const
{
    if(getArmatura())
    {
        if(getScudo())
            return getProtezione()+getArmatura()->getProtezione()+getScudo()->getProtezione();
        else
            return getProtezione()+getArmatura()->getProtezione();
    }
    else
    {
        if(getScudo())
            return getProtezione()+getScudo()->getProtezione();
        else
            return getProtezione();
    }
}


double personaggio::attacca(int scelta)
{
    if(energiaReale)
    {
        if(getArma()==0)
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
            energiaReale=energiaReale-(getBonus(4)*getArma()->SottrazioneCaratteristiche());
            if(energiaReale<0)
                energiaReale=0.0;
            if(testProbabilita(getAttacco()*(1+getArma()->ProbabilitaColpire())))
            {
                if(sceltaBonus==1)
                    return ((1+getBonus(1))*(getArma()->DannoEffettuato(scelta)));
                else
                    return (getBonus(1)*(getArma()->DannoEffettuato(scelta)));

            }
            else
                return 0;
        }
    }
    else
        return 0;
}

void personaggio::difendi(double danno)
{
    if(danno)
    {
        if(getScudo()&&getArmatura())
        {
            if(!(testProbabilita(getDifesa()-getBonus(2)*(getScudo()->DeficitProvocato()+getArmatura()->DeficitProvocato()))))
                if(!getScudo()->Parata(getBonus(3)))
                    if((getScudo()->ProtezioneOfferta()+getArmatura()->ProtezioneOfferta())<danno)
                        vitaReale=vitaReale-(danno-(getScudo()->ProtezioneOfferta()+getArmatura()->ProtezioneOfferta()));
                if(vitaReale<0)
                    vitaReale=0;
        }
        else
        {
            if(getScudo())
            {
                if(!(testProbabilita(getDifesa()-getBonus(2)*(getScudo()->DeficitProvocato()))))
                    if(!getScudo()->Parata(getBonus(3)))
                        if(getScudo()->ProtezioneOfferta()<danno)
                            vitaReale=vitaReale-(danno-getScudo()->ProtezioneOfferta());
                if(vitaReale<0)
                    vitaReale=0.0;
            }
            else
            {
                if(getArmatura())
                {
                    if(!(testProbabilita(getDifesa()-getBonus(2)*getArmatura()->DeficitProvocato())))
                        if(getArmatura()->ProtezioneOfferta()<danno)
                                vitaReale=vitaReale-(danno-getArmatura()->ProtezioneOfferta());
                        if(vitaReale<0)
                            vitaReale=0.0;
                }
                else
                {
                    if(!(testProbabilita(getDifesa())))
                        vitaReale=vitaReale-danno;
                    if(vitaReale<0)
                        vitaReale=0.0;
                }
            }
        }
    }
}

void personaggio::recuperoVita()
{
    if(getPozione1()!=0)
    {
        if(getPozione1()->AiutoCaratteristiche(1))
            vitaReale=vitaReale+(getPozione1()->AiutoCaratteristiche(1)*(1+getBonus(5)));
        else
            eliminaPozioneVita();
    }
    if(vitaReale>getVitaMax())
            vitaReale=getVitaMax();
}

void personaggio::recuperoEnergia()
{
    if(getPozione2()!=0)
    {
        if(getPozione2()->AiutoCaratteristiche(2))
            energiaReale=energiaReale+(getPozione2()->AiutoCaratteristiche(2)*(1+getBonus(6)));
        else
            eliminaPozioneEnergia();
    }
    if(energiaReale>getEnergiaMax())
        energiaReale=getEnergiaMax();
}

bool personaggio::sconfitta() const
{
    if((!vitaReale)||(!energiaReale))
        return true;
    else
        return false;
}
void personaggio::recuperoCaratteristicheMax()
{
    vitaReale=getVitaMax();
    energiaReale=getEnergiaMax();
}

double personaggio::getVitaAttuale() const
{
    return vitaReale;
}

double personaggio::getEnergiaAttuale() const
{
    return energiaReale;
}

string personaggio::getInfoAbilita() const
{
    std::ostringstream strs;
    strs<<"Abilita Classe : "<<std::endl;
    if(sceltaBonus==1)
        strs<<"Danno Aumentato : Danno x"<<1+(getBonus(1))<<std::endl;
    if(sceltaBonus==2)
        strs<<"Risparmio nel Deficit Armatura : "<<getBonus(2)*100<<"%"<<std::endl;
    if(sceltaBonus==3)
        strs<<"Bonus Parata : Bonus di +"<<getBonus(3)*100<<"%"<<std::endl;
    if(sceltaBonus==4)
        strs<<"Risparmio Energia : Risparmio di "<<getBonus(4)*100<<"%"<<std::endl;
    if(sceltaBonus==5)
        strs<<"Risparmio nel Recupero Vita : "<<(getBonus(5)*100)<<"%"<<std::endl;
    if(sceltaBonus==6)
        strs<<"Risparmio nel Recupero Energia : "<<(getBonus(6)*100)<<"%"<<std::endl;
    if(sceltaBonus==0)
        strs<<"Abilita non ancora Decisa"<<std::endl;

    string str = strs.str();
    return str;
}

string personaggio::getInfoMinime() const
{
    std::ostringstream strs;
    strs<<"Nome : "<<getNome()<<endl;
    strs<<"Probabilità di Colpire : "<<AttaccoAttuale()*100<<"%"<<endl;
    strs<<"Probabilità di Subire Colpi :"<<100-DifesaAttuale()*100<<"%"<<endl;
    strs<<"Vita Max : "<<getVitaMax()<<endl;
    strs<<"Energia Max : "<<getEnergiaMax()<<endl;

    string str = strs.str();
    return str;
}
std::ostream & operator<<(std::ostream& os, const personaggio& p)
{
    os<<p.getInfoMinime()<<endl;
    os<<p.getInfoAbilita()<<endl;
    if(p.getArma())
        os<<"Danno Base con Arma : ";
    else
        os<<"Danno di Base senza Armi : ";
    os<<p.DannoAttuale()<<endl;
    if(p.getArmatura())
    {
        if(p.getScudo())
            os<<"Protezione Totale : ";
        else
            os<<"Protezione Solo Armatura : ";
    }
    else
    {
        if(p.getScudo())
            os<<"Protezione Solo Scudo : ";
        else
            os<<"Protezione Base : ";
    }
    os<<p.ProtezioneAttuale()<<endl;
    os<<"Soldi : "<<p.getSoldi()<<endl;
    return os;
}
