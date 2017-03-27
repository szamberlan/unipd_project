#ifndef LISTAOBJECT_H
#define LISTAOBJECT_H
#include <QWidget>
#include<QGroupBox>
#include<QScrollArea>
#include<QRadioButton>
#include<QMessageBox>
#include<QPushButton>
#include<QLCDNumber>
#include<QFormLayout>
#include"controller.h"
class listaObject : public QWidget {
    Q_OBJECT
  public:
      explicit listaObject(controller*c, QWidget *parent = 0);
      virtual ~listaObject();

  protected:
      controller * c1;
      QLayout* layoutPrincipale;
      QLabel * titoloPrincip;
      QGroupBox *  areaPrincipale;
      QHBoxLayout * hboxM;
      QFrame * parteElenco;
      QVBoxLayout * vboxM1;
      QFrame * parteMostraDati;
      QVBoxLayout * vboxM2;
      QLabel * sottotitolo;
      QScrollArea * areaElenco;
      QPushButton* pulsante1;
      QPushButton* pulsante3;
      QPushButton* pulsante2;
      QVBoxLayout*  layoutLista;
      QGroupBox *scrollWidget1;
      QLabel* titoloDati;
      QLabel* datiOggetto;
      QLabel* titolosoldi;
      QLCDNumber *soldi;

signals:
    void clickedPulsante2();
    void clickedPulsante3();
    void aggiornamento();


public slots:
    virtual void clickedPulsante1() =0;
    virtual void visualizzaElenco()=0;
    virtual void mostraInformazioni()=0;
    void setSoldi();

};

#endif // LISTAOBJECT_H

