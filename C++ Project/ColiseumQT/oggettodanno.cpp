#include"oggettodanno.h"
using std::cout;
using std::endl;

//Costruttore e Distruttore Virtuale

oggettoDanno::oggettoDanno(string n, double p, double g, int c, double d, double pd, double m):
oggetto(n,p,g,c), danno(d), pr_colpire(pd), manovrabilita(m){}

oggettoDanno::~oggettoDanno(){}

// Costruttore di Copia e Assegnazione di Default Standard

// Metodi Non Virtuali

double oggettoDanno::getPrColpire() const { return pr_colpire; }

double oggettoDanno::getManovrabilita() const {return manovrabilita;}

void oggettoDanno::riassestaArma(){manovrabilita=1.0;}

// Metodi Virtuali

double oggettoDanno::getDanno() const { return danno; }

// Metodi Virtuali Implementati

double oggettoDanno::ProbabilitaColpire() const {return pr_colpire;}

double oggettoDanno::DannoEffettuato(int) { return danno; }

double oggettoDanno::ProtezioneOfferta() const { return 0; }

bool oggettoDanno::Parata(double, bool) const { return false; }

double oggettoDanno::AiutoCaratteristiche(int,bool) { return 0; }

double oggettoDanno::SottrazioneCaratteristiche() const { return (getGrandezza()*getPeso()*getManovrabilita())/2; }

double oggettoDanno::DeficitProvocato() const { return 0; }

string oggettoDanno::getNomeUtilita(int) const
{
    return "Danno Base";
}

string oggettoDanno::getInfoUtilita(int) const
{
    std::ostringstream strs;
    strs<<"Effettuare Danno : "<<getDanno()<<std::endl;
    strs <<"Colpire con la probabilità : "<<getPrColpire()*100<<" %"<<std::endl;
    std::string str = strs.str();
    return str;
}
string oggettoDanno::getTipologiaOggetto() const
{
    return "Danno";
}
// Operatori di uguaglianza e di disuguaglianza virtuali

bool oggettoDanno::operator==(const oggettoDanno& oD) const
{
    return oggetto::operator ==(oD) && danno == oD.getDanno() && pr_colpire == oD.pr_colpire && manovrabilita == oD.getManovrabilita();
}

bool oggettoDanno::operator!=(const oggettoDanno& oD) const
{
    return oggetto::operator !=(oD) && danno != oD.getDanno() && pr_colpire != oD.pr_colpire &&  manovrabilita != oD.getManovrabilita();
}
