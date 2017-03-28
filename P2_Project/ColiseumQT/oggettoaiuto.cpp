#include"oggettoaiuto.h"

using std::cout;
using std::endl;

//Costruttore e Distruttore Virtuale

oggettoAiuto::oggettoAiuto(string n, double p, double g, int c, double a):
oggetto(n,p,g,c), aiuto(a){}

oggettoAiuto::~oggettoAiuto(){}

// Costruttore di Copia e Assegnazione di Default Standard

// Metodi Virtuali

double oggettoAiuto::getAiuto() const { return aiuto; }


// Metodi Virtuali Implementati

double oggettoAiuto::ProbabilitaColpire() const {return 0;}

double oggettoAiuto::DannoEffettuato(int){ return 0; }

double oggettoAiuto::ProtezioneOfferta() const { return 0; }

bool oggettoAiuto::Parata(double, bool) const { return false; }

double oggettoAiuto::AiutoCaratteristiche(int, bool) { return aiuto; }

double oggettoAiuto::SottrazioneCaratteristiche() const { return 0; }

double oggettoAiuto::DeficitProvocato() const { return 0; }

string oggettoAiuto::getNomeUtilita(int) const
{
    return "Aiuto";
}

string oggettoAiuto::getInfoUtilita(int) const
{

    std::ostringstream strs;
    strs<<"Offrire Soccorso "<< getAiuto();
    std::string str = strs.str();
    return str;
}

string oggettoAiuto::getTipologiaOggetto() const
{
    return "Aiuto";
}

// Operatori di uguaglianza e di disuguaglianza virtuali

bool oggettoAiuto::operator==(const oggettoAiuto& oA) const
{
    return oggetto::operator ==(oA) && aiuto == oA.getAiuto();
}

bool oggettoAiuto::operator!=(const oggettoAiuto& oA) const
{
    return oggetto::operator !=(oA) && aiuto != oA.getAiuto();
}

