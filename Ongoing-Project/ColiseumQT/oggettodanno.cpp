#include"oggettodanno.h"
using std::cout;
using std::endl;

//Costruttore e Distruttore Virtuale

oggettoDanno::oggettoDanno(string n, double p, double g, int c, double d, double pd, double m):
oggetto(n,p,g,c), danno(d), pr_colpire(pd), manovrabilita(m){}

oggettoDanno::~oggettoDanno(){}

// Costruttore di Copia e Assegnazione di Default Standard

// Metodi Non Virtuali

double oggettoDanno::getDanno() const { return danno; }

double oggettoDanno::getPrColpire() const { return pr_colpire; }

double oggettoDanno::getManovrabilita() const {return manovrabilita;}

void oggettoDanno::riassestaArma(){manovrabilita=1.0;}

// Metodi Virtuali

void oggettoDanno::stampaCaratteristiche() const
{
    oggetto::stampaCaratteristiche();
    cout<<"Danno Base dell'Arma :"<<getDanno()<<std::endl;
    cout<<"Probabilità di Colpire : "<<getPrColpire()<<"%"<<std::endl;
}

// Metodi Virtuali Implementati

double oggettoDanno::ProbabilitaColpire() const {return pr_colpire;}

double oggettoDanno::DannoEffettuato(int) { return danno; }

double oggettoDanno::ProtezioneOfferta() const { return 0; }

bool oggettoDanno::Parata(double) const { return false; }

double oggettoDanno::AiutoCaratteristiche(int) const { return 0; }

double oggettoDanno::SottrazioneCaratteristiche() const { return getGrandezza()*getPeso()*getManovrabilita(); }

double oggettoDanno::DeficitProvocato() const { return 0; }

// Operatori di uguaglianza e di disuguaglianza virtuali

bool oggettoDanno::operator==(const oggettoDanno& oD) const
{
    return oggetto::operator ==(oD) && danno == oD.getDanno() && pr_colpire == oD.pr_colpire && manovrabilita == oD.getManovrabilita();
}

bool oggettoDanno::operator!=(const oggettoDanno& oD) const
{
    return oggetto::operator !=(oD) && danno != oD.getDanno() && pr_colpire != oD.pr_colpire &&  manovrabilita != oD.getManovrabilita();
}
