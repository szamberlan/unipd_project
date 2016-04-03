#ifndef OGGETTO
#define OGGETTO
#include<iostream>
using std::string;
class oggetto {
private:
    string nome;
    double peso;
    double grandezza;
    int costo;
protected:
    // Metodi Protetti
    bool testProbabilita(double) const;
public:
    // Costruttore e Distruttore Virtuale
    oggetto(string, double, double, int);
    virtual ~oggetto();

    //Costruttore di Copia e Operatore di Assegnazione in versione Default-Standard

    // Metodi Non Virtuali
    string getNome() const;
    double getPeso() const;
    double getGrandezza() const;
    int getCosto() const;

    // Metodi Virtuali
    virtual void stampaCaratteristiche() const;

    // Metodi Virtuali Puri
    virtual double ProbabilitaColpire() const =0;
    virtual double DannoEffettuato(int=0)=0;
    virtual double ProtezioneOfferta() const =0;
    virtual bool Parata(double=1) const =0;
    virtual double AiutoCaratteristiche(int=0) const =0;
    virtual double SottrazioneCaratteristiche() const =0;
    virtual double DeficitProvocato() const =0;

    // Operatori di uguaglianza e di disuguaglianza virtuali
    virtual bool operator==(const oggetto&) const;
    virtual bool operator!=(const oggetto&) const;
};
#endif // OGGETTO
