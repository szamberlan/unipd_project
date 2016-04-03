#include"oggettoprotezione.h"
using std::cout;
using std::endl;

//Costruttore e Distruttore Virtuale

oggettoProtezione::oggettoProtezione(string n, double p, double g, int c, double r):
oggetto(n,p,g,c), protezione(r){}

oggettoProtezione::~oggettoProtezione(){}

// Costruttore di Copia e Assegnazione di Default Standard

// Metodi Non Virtuali

double oggettoProtezione::getProtezione() const { return protezione; }

// Metodi Virtuali

void oggettoProtezione::stampaCaratteristiche() const
{
    oggetto::stampaCaratteristiche();
    cout<<"Protezione Disponibile : "<<getProtezione()<<std::endl;
    cout<<"Deficit Difesa  :  -"<<DeficitProvocato()*100<<"%"<<std::endl;
}

// Metodi Virtuali Implementati

double oggettoProtezione::ProbabilitaColpire() const {return 0;}

double oggettoProtezione::DannoEffettuato(int) { return 0; }

double oggettoProtezione::ProtezioneOfferta() const { return protezione; }

bool oggettoProtezione::Parata(double) const { return false; }

double oggettoProtezione::AiutoCaratteristiche(int) const { return 0; }

double oggettoProtezione::SottrazioneCaratteristiche() const { return 0; }

double oggettoProtezione::DeficitProvocato() const { return (getPeso()*getGrandezza())/1000; }

// Operatori di uguaglianza e di disuguaglianza virtuali

bool oggettoProtezione::operator==(const oggettoProtezione& oP) const
{
    return oggetto::operator ==(oP) && protezione == oP.getProtezione();
}

bool oggettoProtezione::operator!=(const oggettoProtezione& oP) const
{
    return oggetto::operator !=(oP) && protezione != oP.getProtezione();
}
