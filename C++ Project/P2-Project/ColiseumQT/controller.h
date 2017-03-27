#ifndef CONTROLLER
#define CONTROLLER
#include"arenasemplice.h"
#include"personaggio.h"
#include"contenitoreoggetti.h"
#include<QVector>
#include<QWidget>
#include<QAbstractButton>
#include<QLabel>
#include<QBoxLayout>
#include<QStringList>
#include"database.h"
class controller {
private:
    arena*a1;
    QVector<QWidget*> contenitorQWidget;
    QVector<QAbstractButton*> mercanteQWidget;
    QVector<QAbstractButton*> zainoQWidget;
    QVector<QPaintDevice*>contenitorImmagini;
    QVector<QLabel*> contenitoreQLabel;
    QString sceltaNome;

    int sceltaRazza;
    int sceltaClasse;
    int sceltaAbilita;
public:
    controller(arena*);
    virtual ~controller();

    void insertWidget(QWidget*);
    void insertFrontWidget(QWidget*);
    void removeWidget();
    void removeLastWidget();

    QWidget* ricercaContenitorWidget(int) const;
    QWidget *ricercaContenitorWidgetByName(QString)const;
    int ricercaIndexContenitorWidgetByName(QString)const;
    void sostituisciWidget(QWidget*, int);

    void insertLabel(QLabel*);
    QLabel*ricercaContenitorQLabel(int)const;
    void removeLabel();

    void fillZainoWidget(QAbstractButton*);
    void emptiesZainoWidget();
    QAbstractButton* ricercaZainoWidget(int) const;

    void fillMercanteWidget(QAbstractButton*);
    void emptiesMercaneWidget();
    QAbstractButton* ricercaMercanteWidget(int) const;

    void insertImmagini(QPaintDevice*);
    void removeImmagini();

    void creaPersonaggio();
    void selezioneRazza(int);
    void selezioneClasse(int);
    void selezioneAbilita(int);
    void inserimentoNome(QString);
    void aggiornaMosse(QStringList*);
    string getNomeSelezionato() const;
    QString getNomeClasse1Disponibile() const;
    QString getNomeClasse2Disponibile() const;
    QString getPathImageClasse1Disponibile() const;
    QString getPathImageClasse2Disponibile() const;
    oggetto* ricercaMercato(int)const;
    oggetto* ricercaZaino(int)const;

    bool findOggettoZaino()const;
    int getInfoOggettoCercatoZaino()const;

    bool findOggettoMercato()const;
    int getInfoOggettoCercatoMercato()const;

    const oggetto*ricercaEquipaggiamento(int) const;

    int getRazzaSelezionata() const;
    int getClasseSelezionata() const;
    int getAbilitaSelezionata() const;
    int getSoldiGiocatore() const;

    QString stampaRobe() const;
    QVector<QString*> stampaMercanzia() const;
    QVector<QString*> stampaZaino() const;
    QString stampaCaratteristicheMercanzia(int) const;
    QString stampaCaratteristicheZaino(int) const;
    QString stampaCaratteristicheEquipaggiamento(int) const;
    QString stampaCaratteristicheAvversario() const;
    QString stampaCaratteristichePersonaggio()const;
    QString stampaAbilitaPersonaggio()const;
    bool presenzaArma() const;

    void iniziaCombattimento();
    void combatti(int);
    bool vittoria() const;
    bool sconfitta() const;
    void fineCombattimento(int);
    double getVita(bool) const;
    double getEnergia(bool) const;
    QString getNomeMosseArma(int) const;
    QString getInfoMosseArma(int) const;
    bool inCombattimento() const;

    bool compraOggetto(int);
    bool vendiOggetto(int);
    bool equipaggiaOggettto(int);
    void spostaOggetto(int);

    int getLivelloArena() const;
    int nemiciRimasti() const;
    bool vittoriaArena() const;

};

#endif // CONTROLLER

