#include"oggettoprotezione.h"
#include<sstream>
using std::cout;
using std::endl;

//Costruttore e Distruttore Virtuale

oggettoProtezione::oggettoProtezione(string n, double p, double g, int c, double r):
oggetto(n,p,g,c), protezione(r){}

oggettoProtezione::~oggettoProtezione(){}

// Costruttore di Copia e Assegnazione di Default Standard

// Metodi Virtuali
double oggettoProtezione::getProtezione() const { return protezione; }

// Metodi Virtuali Implementati

double oggettoProtezione::ProbabilitaColpire() const {return 0;}

double oggettoProtezione::DannoEffettuato(int) { return 0; }

double oggettoProtezione::ProtezioneOfferta() const { return protezione; }

bool oggettoProtezione::Parata(double, bool) const{ return false; }

double oggettoProtezione::AiutoCaratteristiche(int,bool)  { return 0; }

double oggettoProtezione::SottrazioneCaratteristiche() const { return 0; }

double oggettoProtezione::DeficitProvocato() const { return (getPeso()*getGrandezza())/1000; }

string oggettoProtezione::getNomeUtilita(int) const
{
    return "Protezione Base";
}

string oggettoProtezione::getInfoUtilita(int) const
{
    std::ostringstream strs;
    strs<<"Protezione Offerta : "<< getProtezione()<<std::endl;
    strs<<"Con un deficit Provocato di : "<<DeficitProvocato();
    std::string str = strs.str();
    return str;
}

string oggettoProtezione::getTipologiaOggetto() const
{
    return "Protezione";
}

// Operatori di uguaglianza e di disuguaglianza virtuali

bool oggettoProtezione::operator==(const oggettoProtezione& oP) const
{
    return oggetto::operator ==(oP) && protezione == oP.getProtezione();
}

bool oggettoProtezione::operator!=(const oggettoProtezione& oP) const
{
    return oggetto::operator !=(oP) && protezione != oP.getProtezione();
}
