#include"oggettoaiuto.h"

using std::cout;
using std::endl;

//Costruttore e Distruttore Virtuale

oggettoAiuto::oggettoAiuto(string n, double p, double g, int c, double a):
oggetto(n,p,g,c), aiuto(a){}

oggettoAiuto::~oggettoAiuto(){}

// Costruttore di Copia e Assegnazione di Default Standard

// Metodi Non Virtuali

double oggettoAiuto::getAiuto() const { return aiuto; }

// Metodi Virtuali

void oggettoAiuto::stampaCaratteristiche() const
{
    oggetto::stampaCaratteristiche();
    cout<<"Aiuto :"<<getAiuto()<<std::endl;
}

// Metodi Virtuali Implementati

double oggettoAiuto::ProbabilitaColpire() const {return 0;}

double oggettoAiuto::DannoEffettuato(int){ return 0; }

double oggettoAiuto::ProtezioneOfferta() const { return 0; }

bool oggettoAiuto::Parata(double) const { return false; }

double oggettoAiuto::AiutoCaratteristiche(int) const { return aiuto; }

double oggettoAiuto::SottrazioneCaratteristiche() const { return 0; }

double oggettoAiuto::DeficitProvocato() const { return 0; }

// Operatori di uguaglianza e di disuguaglianza virtuali

bool oggettoAiuto::operator==(const oggettoAiuto& oA) const
{
    return oggetto::operator ==(oA) && aiuto == oA.getAiuto();
}

bool oggettoAiuto::operator!=(const oggettoAiuto& oA) const
{
    return oggetto::operator !=(oA) && aiuto != oA.getAiuto();
}

