#ifndef PERSONAGGIO
#define PERSONAGGIO
#include<iostream>
#include"oggetto.h"
#include"contenitoreoggetti.h"
#include<sstream>
using std::string;
class personaggio {
private:
    string nome;
    double attacco;     // Attacco = Probabilità di Colpire
    double difesa;      // Difesa = Probabilità Di Schivare i Colpi
    double vitaMax;     // Vita Massima che un personaggio ha
    double energiaMax;  // Energia Massima che un personaggio ha
    double danno;       // Danno di Base che un personaggio può fare
    double protezione;  // Protezione di Base che un personaggio ha
    int soldi;
    double vitaReale;
    double energiaReale;
    double bonus;
    int sceltaBonus;

    contenitoreOggetti zaino;
    contenitoreOggetti equipaggiamento;
protected:
    static bool testProbabilita(double);
public:
    //Costruttore e Distruttore Virtuale
    personaggio(string, double, double, double, double, double, double, int, double);
    virtual~personaggio();

    // Assegazione e Costruttore di Copia in Versione Default-Standard

    // Metodi non Virtuali
    string getNome() const;
    double getAttacco() const;
    double getDifesa() const;
    double getDanno() const;
    double getProtezione() const;
    double getVitaMax() const;
    double getEnergiaMax() const;
    int getSoldi() const;
    void aumentaSoldi(int);
    string getInfoMinime() const;

    bool settedBonus() const;

    void setBonusDannoAumentato();
    void setBonusRisparmioDeficitArmature();
    void setBonusParata();
    void setBonusRisparmioEnergia();
    void setBonusUtilizzoPozioneVita();
    void setBounusUtilizzoPozioneEnergia();

    double getBonus(int i) const;

    // Metodi Legati a Zaino e Equipaggiamento

    // Zaino
    bool compraOggetto(oggetto*);
    oggetto*vendiOggetto(oggetto*);
    void inserisciNelloZaino(oggetto*);
    oggetto* ricercaOggetto(int) const;
    string* stampaNomeOggetti() const;
    int getSizeZaino() const;


    // Equipaggiamento
    // Inserimento
    void equipaggiaArma(oggetto*);
    void equipaggiaScudo(oggetto*);
    void equipaggiaArmatura(oggetto*);
    void equipaggiaPozioneVita(oggetto*);
    void equipaggiaPozioneEnergia(oggetto*);

    // Eliminare
    void eliminaArma();
    void eliminaScudo();
    void eliminaArmatura();
    void eliminaPozioneVita();
    void eliminaPozioneEnergia();


    // GetOggetti
    oggetto* getArma() const;
    oggetto* getArmatura() const;
    oggetto* getScudo() const;
    oggetto* getPozione1() const;
    oggetto* getPozione2() const;

    // Scambio Equipaggiamento-Zaino
    void cambiaArma(int);
    void cambiaScudo(int);
    void cambiaArmatura(int);
    void cambiaPozioneVita(int);
    void cambiaPozioneEnergia(int);
    void spostaArmaNelloZaino();
    void spostaScudoNelloZaino();
    void spostaArmaturaNelloZaino();
    void spostaPozioneVitaNelloZaino();
    void spostaPozioneEnergiaNelloZaino();

    // Metodi Virtuali
    virtual double AttaccoAttuale() const;
    virtual double DifesaAttuale() const;
    virtual double DannoAttuale() const;
    virtual double ProtezioneAttuale() const;
    virtual const oggetto* getEquipaggiamento(int i) const;

    virtual double attacca(int=0);
    virtual void difendi(double);
    virtual void recuperoVita();
    virtual void recuperoEnergia();
    virtual bool sconfitta() const;
    virtual void recuperoCaratteristicheMax();
    virtual double getVitaAttuale() const;
    virtual double getEnergiaAttuale() const;
    virtual string getInfoAbilita() const;
};

std::ostream & operator<<(std::ostream&, const personaggio&);

#endif // PERSONAGGIO

