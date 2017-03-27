#ifndef COMPLETAPERSONAGGIO_H
#define COMPLETAPERSONAGGIO_H
#include<QWidget>
#include<QGroupBox>
#include<QScrollArea>
#include<QPushButton>
#include<QLCDNumber>
#include<QRadioButton>
#include<QLineEdit>
#include<QFormLayout>
#include<QComboBox>
#include"controller.h"
class completaPersonaggioWidget : public QWidget {
    Q_OBJECT
  public:
      explicit completaPersonaggioWidget(controller*, QWidget *parent = 0);
      ~completaPersonaggioWidget();
 private:
    controller* c1;
    QLayout *layoutPrincipale;
    QLabel*l2;
    QLabel*l3;
    QLabel*l4;
    QGroupBox *gb1;
    QGroupBox *gb2;
    QGroupBox *gb3;
    QLayout*h1;
    QLayout*h2;
    QLayout*h3;
    QRadioButton*sceltaClasse1;
    QRadioButton*sceltaClasse2;
    QLabel* imm1;
    QPixmap*pix1;
    QLabel* imm2;
    QPixmap*pix2;
    QComboBox*sceltaAbilita;
    QStringList*listaAbilitaElfo;
    QString *aE1;
    QString *aE2;
    QString *aE3;
    QString *aE4;
    QString *aE5;
    QString *aE6;
    QString *aE7;
    QPushButton*finalePersonaggio;

 signals:
    void personaggioCompletato();

 public slots:
    void inserimentoClasse1();
    void inserimentoClasse2();
    void inserimentoAbilita(int);
    void completataCreazione();

};
#endif // COMPLETAPERSONAGGIO_H

