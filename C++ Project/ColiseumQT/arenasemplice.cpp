#include"arenasemplice.h"

arenaSemplice::arenaSemplice(personaggio *p, int lvl):
arena(new database(),p,lvl), vittoriaArena(false), pozioneVita(false), pozioneEnergia(false){
}

void arenaSemplice::creaPersonaggio(string nome,double attacco, double difesa, int vita, int energia,int scelta, double bonus){
    arena::creaPersonaggio(nome,attacco,difesa,vita,energia,scelta,bonus);
    getGiocatoreProtected()->equipaggiaArmatura(new oggettoProtezione("Cotta di Maglia",15,10,3.5,15));
    getGiocatoreProtected()->equipaggiaArma(new arma("Alabarda di Ferro",7,2.5,13,20,0.725,0.50,1.10));
    getGiocatoreProtected()->equipaggiaPozioneVita(new pozione("Pozione Vita +2",4,2,1));
    getGiocatoreProtected()->equipaggiaPozioneEnergia(new pozione("Pozione Energia +2",4,2,2));
}

arenaSemplice::~arenaSemplice(){}

int arenaSemplice::testProbabilita() const
{
    double randomValue= qrand()% 100;
    if(randomValue <25)
        return 1;
    else
        if(randomValue<50)
            return 2;
        else
            if(randomValue<75)
                return 3;
            else
                return 4;
}

// Metodi di Ritorno Dati
bool arenaSemplice::getVittoriaArena() const{ return vittoriaArena; }

// Metodi di Modifica Dati
void arenaSemplice::VittoriaArena()
{
    if(getLivello()==getNumeroAvversari())
        vittoriaArena=true;
}

// Metodi Implementati da Arena
void arenaSemplice::combatti(int scelta)
{
    if(inCombattimento())
    {
        if(((getAvversarioAttuale()->getVitaMax()/3)>getAvversarioAttuale()->getVitaAttuale())&&!pozioneVita)
        {
            scontro->svolgiTurno(scelta,5);
            pozioneVita=true;
        }
        else
        {
            if((getAvversarioAttuale()->getEnergiaMax()/3)>getAvversarioAttuale()->getEnergiaAttuale()&&!pozioneEnergia)
            {
                scontro->svolgiTurno(scelta,6);
                pozioneEnergia=true;
            }
            else
            {
                scontro->svolgiTurno(scelta,testProbabilita());
            }
        }
    }
}

bool arenaSemplice::vintoArena()
{
    VittoriaArena();
    return vittoriaArena;
}
