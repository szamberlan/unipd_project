#ifndef MENUWIDGET_H
#define MENUWIDGET_H
#include <QWidget>
#include<QGroupBox>
#include<QScrollArea>
#include<QPushButton>
#include<QFormLayout>
#include<QLCDNumber>
#include"controller.h"
class menuWidget : public QWidget {
    Q_OBJECT
  public:
      explicit menuWidget(controller*, QWidget *parent = 0);
      ~menuWidget();

  private:
    controller*c1;
    QLayout*layoutPrincipale;
    QLabel*Titolo;
    QGroupBox * groupIntro;
    QLabel*livello;
    QLabel*nemiciRimasti;
    QHBoxLayout *layoutIntro;
    QFrame*vediMenu;
    QVBoxLayout *layoutMenu;
    QLabel*Vittoria_text;

    //Pulsante Sezione Combattimento
    QPushButton*pulsanteCombatti;

    //Pulsante Sezione Zaino
    QPushButton*pulsanteZaino;

    //Pulsante Sezione Mercante
    QPushButton*pulsanteMercante;

    //Pulsante Sezione Equipaggiamento
    QPushButton*pulsanteEquipaggiamento;

    //Pulsante Sezione Statistiche
    QPushButton*pulsanteStatistiche;

    //Pulsante Sezione Risultati
    QPushButton*pulsanteRisultati;

    //Immagine Menù
    QLabel* immMenu;
    QPixmap*pixMenu;

    //Pulsanti Vittoria
    QPushButton*pulsanteEsci;

  signals:
    void clickedCombattimento();
    void clickedZaino();
    void clickedMercante();
    void clickedEquipaggiamento();
    void clickedStatistiche();
    void clickedRegole();
    void endGame();

public slots:
    void ricalcoloInformazioni();
};

#endif // MENUWIDGET_H

