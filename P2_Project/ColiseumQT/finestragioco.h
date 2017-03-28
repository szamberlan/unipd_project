#ifndef FINESTRAGIOCO_H
#define FINESTRAGIOCO_H
#include<QMainWindow>
#include<QLabel>
#include<QPushButton>
#include<QLayout>
#include<QVBoxLayout>
#include<QFormLayout>
#include"controller.h"
#include"playwidget.h"
#include"sceltapersonaggioWidget.h"
#include"menuwidget.h"
#include"equipboardwidget.h"
#include"statistichewidget.h"
#include"ruleswidget.h"
#include"gameboard.h"
#include"listamercatowidget.h"
#include"listazainowidget.h"
class finestraGioco : public QWidget {
    Q_OBJECT
  public:
      explicit finestraGioco(QWidget *parent = 0);
      ~finestraGioco();
  private :
    QLayout*layoutPrincipale;
    controller*c1;
    playWidget* inizioGioco;
    sceltaPersonaggioWidget* creazionePersonaggio;
    menuWidget* menuPrincipale;
    equipBoardWidget* equipaggiamentoPersonaggio;
    gameBoard* combattimentoAvversari;
    rulesWidget *regoleGioco;
    statisticheWidget* statistichePersonaggio;
    listaObject*mercatoPersonaggio;
    listaObject* zainoPersonaggio;

public slots:
    void creaP();
    void menu();
    void equipaggiamento();
    void combattimento();
    void statistiche();
    void regole();
    void zaino();
    void mercato();
    void hideAll();
    void menuReturn();
};
#endif // FINESTRAGIOCO_H

