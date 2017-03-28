#ifndef CREAPERSONAGGIOWIDGET
#define CREAPERSONAGGIOWIDGET
#include<QWidget>
#include<QGroupBox>
#include<QScrollArea>
#include<QPushButton>
#include<QLCDNumber>
#include<QRadioButton>
#include<QLineEdit>
#include<QFormLayout>
#include"controller.h"
class creaPersonaggioWidget : public QWidget {
    Q_OBJECT
  public:
      explicit creaPersonaggioWidget(controller*, QWidget *parent = 0);
      ~creaPersonaggioWidget();
 private:
    QLayout *layoutPrincipale;
    controller * c1;
    QGroupBox *gb1;
    QGroupBox *gb2;
    QGroupBox *gb3;
    QGroupBox* gb4;
    QLayout*h1;
    QLayout*h2;
    QLayout*h3;
    QLayout*h4;
    QLabel*l2;
    QLabel*l1a;
    QLabel*l1b;
    QLabel*l1c;
    QLabel*l1d;
    QLineEdit*nomePersonaggio;
    QPushButton*sceltaOrco;
    QPushButton*sceltaElfo;
    QPushButton*sceltaUmano;
    QLabel* immOrc;
    QPixmap*pixOrc;
    QLabel* immHuman;
    QPixmap*pixHuman;
    QLabel* immElf;
    QPixmap*pixElf;

 signals:
    void selezioneRazzaCompletata();

 public slots:
    void inserimentoNome(QString);
    void selezionaElfo();
    void selezionaOrco();
    void selezionaUmano();

};

#endif // CREAPERSONAGGIOWIDGET

