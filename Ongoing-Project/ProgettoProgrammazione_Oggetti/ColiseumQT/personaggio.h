#ifndef PERSONAGGIO
#define PERSONAGGIO
#include<iostream>
#include"oggetto.h"
#include"contenitoreoggetti.h"
using std::string;
class personaggio {
private:
    string nome;
    double attacco;     // Attacco = Probabilità di Colpire
    double difesa;      // Difesa = Probabilità Di Schivare i Colpi
    double vitaMax;
    double energiaMax;
    double danno;       // Danno di Base che un personaggio può fare
    double protezione;  // Protezione di Base che un personaggio ha
    int soldi;
    contenitoreOggetti zaino;
protected:
    contenitoreOggetti equipaggiamento;

    // Metodi Protetti
    bool testProbabilita(double) const;
public:

    //Costruttore e Distruttore Virtuale
    personaggio(string, double, double, double, double, double, double, int);
    virtual~personaggio();

    // Assegazione e Costruttore di Copia in Versione Default-Standard

    // Metodi non Virtuali
    string getNome() const;
    int getSoldi() const;
    double getVitaMax() const;
    double getEnergiaMax() const;

    // Metodi Legati a Zaino e Equipaggiamento

    // Zaino
    void compraOggetto(oggetto*);
    oggetto*vendiOggetto(oggetto*);
    void inserisciNelloZaino(oggetto*);
    void stampaZaino() const;

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
    void eiminaPozioneVita();
    void eliminaPozioneEnergia();

    // Stampa
    void stampaEquipaggiamento() const;

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
    virtual double getProbabilitaColpire() const;
    virtual double getProbabilitaFuggire() const;
    virtual double getAttacco() const;
    virtual double getDifesa() const;
    virtual double getDanno() const;
    virtual double getProtezione() const;
    virtual void stampaPersonaggio()const;
  //virtual void stampaCaratteristichePersonaggio() const;

    // Metodi Virtuali Puri
    virtual double attacca(int=0)=0;
    virtual void difendi(double)=0;
    virtual void recuperoVita()=0;
    virtual void recuperoEnergia()=0;
    virtual bool sconfitta() const =0;
    virtual void recuperoCaratteristicheMax()=0;
    virtual double getVitaAttuale() const=0;
    virtual double getEnergiaAttuale() const=0;
    virtual void stampaSituazione() const =0;
};

#endif // PERSONAGGIO

