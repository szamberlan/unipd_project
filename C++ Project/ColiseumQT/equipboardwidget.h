#ifndef EQUIPBOARDWIDGET_H
#define EQUIPBOARDWIDGET_H
#include <QWidget>
#include<QGroupBox>
#include<QScrollArea>
#include<QPushButton>
#include<QLCDNumber>
#include<QFormLayout>
#include"controller.h"
class equipBoardWidget : public QWidget {
    Q_OBJECT
  public:
      explicit equipBoardWidget(controller*,QWidget *parent = 0);
      ~equipBoardWidget();

  private:
      controller * c1;
      QLayout* layoutPrincipale;
      QLabel*titoloEquipaggiamento;
      QFrame*equipaggiamentoBox;
      QGroupBox*zonaSopra;
      QGroupBox*zonaSotto;
      QVBoxLayout*vboxEq;
      QHBoxLayout*hboxEq1;
      QHBoxLayout*hboxEq2;
      QGroupBox*armaBox;
      QGroupBox*armaturaBox;
      QGroupBox*scudoBox;
      QGroupBox*pozione1Box;
      QGroupBox*pozione2Box;
      QGroupBox*pulsantiBox;
      QVBoxLayout*vboxpb;
      QVBoxLayout*vboxarma;
      QVBoxLayout*vboxarmatura;
      QVBoxLayout*vboxscudo;
      QVBoxLayout*vboxpozione1;
      QVBoxLayout*vboxpozione2;
      QLabel*titoloArma;
      QLabel*titoloArmatura;
      QLabel*titoloScudo;
      QLabel*titoloPozione1;
      QLabel*titoloPozione2;
      QFrame*armaFrame;
      QFrame*armaturaFrame;
      QFrame*scudoFrame;
      QFrame*pozione1Frame;
      QFrame*pozione2Frame;
      QVBoxLayout*vframearma;
      QVBoxLayout*vframearmatura;
      QVBoxLayout*vframescudo;
      QVBoxLayout*vframepozione1;
      QVBoxLayout*vframepozione2;
      QLabel*informazioniArma;
      QLabel*informazioniArmatura;
      QLabel*informazioniScudo;
      QLabel*informazioniPozione1;
      QLabel*informazioniPozione2;
      QLabel*immArma;
      QLabel*immArmatura;
      QLabel*immScudo;
      QLabel*immPozione1;
      QLabel*immPozione2;
      QPushButton*bArma;
      QPushButton*bArmatura;
      QPushButton*bScudo;
      QPushButton*bPozione1;
      QPushButton*bPozione2;
      QPixmap*pixArma;
      QPixmap*pixArmatura;
      QPixmap*pixScudo;
      QPixmap*pixPozione1;
      QPixmap*pixPozione2;
      QPushButton*bMenu;
signals:
    void vaiAMenu();
    void spostamento();

  public slots:
      void visualizzaEquipaggiamento();
      void spostaArma();
      void spostaArmatura();
      void spostaScudo();
      void spostaPozione1();
      void spostaPozione2();
};
#endif // EQUIPBOARDWIDGET_H

