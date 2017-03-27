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
    static bool testProbabilita(double);
public:
    // Costruttore e Distruttore Virtuale
    oggetto(string, double, double, int);
    virtual ~oggetto();

    //Costruttore di Copia e Operatore di Assegnazione in versione Default-Standard

    // Metodi Non Virtuali
    string getNome() const;
    double getPeso() const;
    double getGrandezza() const;

    // Metodi Virtuali
    virtual int getCosto() const;
    virtual double getDanno() const;
    virtual double getProtezione() const;
    virtual double getAiuto() const;

    // Metodi Virtuali Puri
    virtual double ProbabilitaColpire() const =0;
    virtual double DannoEffettuato(int=0)=0;
    virtual double ProtezioneOfferta() const =0;
    virtual bool Parata(double=1,bool=true) const =0;
    virtual double AiutoCaratteristiche(int=0,bool=true) =0;
    virtual double SottrazioneCaratteristiche() const =0;
    virtual double DeficitProvocato() const =0;
    virtual string getTipologiaOggetto() const =0;
    virtual string getNomeUtilita(int=0) const =0;
    virtual string getInfoUtilita(int=0) const =0;

    // Operatori di uguaglianza e di disuguaglianza virtuali
    virtual bool operator==(const oggetto&) const;
    virtual bool operator!=(const oggetto&) const;
};

std::ostream & operator<<(std::ostream&, const oggetto&);

#endif // OGGETTO
