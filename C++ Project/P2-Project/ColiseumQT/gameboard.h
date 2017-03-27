#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include<QMainWindow>
#include<QLabel>
#include<QGroupBox>
#include<QComboBox>
#include<QPushButton>
#include<QVBoxLayout>
#include<QFormLayout>
#include"controller.h"
#include<QProgressBar>
#include<QMessageBox>
class gameBoard : public QWidget {
    Q_OBJECT
  public:
      explicit gameBoard(controller*, QWidget *parent = 0);
      ~gameBoard();
      void fineCombattimento(bool);

  private :
    QLayout * layoutPrincipale;
    controller*c1;
    QLabel*nomeAvv;
    QLabel*titoloC;
    QLabel*titolo1;
    QLabel*ab1a;
    QLabel*ab2a;
    QLabel*titolo2;
    QLabel*ab1p;
    QLabel*ab2p;
    QFrame *SchermataProtagonista;
    QFrame*DatiProtagonista;
    QProgressBar*barraVitaP;
    QProgressBar*barraEnergiaP;
    QProgressBar*barraVitaA;
    QProgressBar*barraEnergiaA;
    QFrame*Pulsanti1;
    QGroupBox*Pulsanti2;
    QGroupBox*Pulsanti3;
    QGroupBox*Pulsanti4;
    QGroupBox*Pulsanti5;
    QFrame *SchermataAvversario;
    QFrame *DatiAvversario;
    QFrame *CarAvv;
    QLabel*titoloInfo;
    QComboBox*sceltainfo;
    QStringList*listaMosse;
    QPushButton*PulsanteAttacco1;
    QPushButton*PulsanteAttacco2;
    QPushButton*PulsanteAttacco3;
    QPushButton*PulsanteAttacco4;
    QPushButton*PulsanteVisualizzaInfo;
    QPushButton*BeviPozioneV;
    QPushButton*BeviPozioneE;
    QHBoxLayout*scA;
    QVBoxLayout*layoutAvversario;
    QVBoxLayout*layoutAvversario2;
    QHBoxLayout*scP;
    QVBoxLayout*layoutProtagonista;
    QVBoxLayout*vB1;
    QLabel * titoloM;
    QLabel * titoloP1;
    QLabel * titoloP2;
    QHBoxLayout*hB1;
    QHBoxLayout*hB2;
    QHBoxLayout*hB3;
    QHBoxLayout*hB4;
    bool inizioIo;

 signals:
    void turno();
    void endDuel();

 public slots:
    void iniziaIlCombattimento();
    void combatti1();
    void combatti2();
    void combatti3();
    void combatti4();
    void riceviAiuto1();
    void riceviAiuto2();
    void infoAttacco();
    void aggiornamentoDanni();
    void aggiornamentoDanniTurno1();
    void aggiornamentoDanniTurno2();
};
#endif // GAMEBOARD_H

