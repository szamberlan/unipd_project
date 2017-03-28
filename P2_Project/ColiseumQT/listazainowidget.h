#ifndef LISTAZAINOWIDGET_H
#define LISTAZAINOWIDGET_H
#include"listaobject.h"
class listaZainoWidget : public listaObject {
    Q_OBJECT
  public:
      explicit listaZainoWidget(controller*, QWidget *parent = 0);
      QPushButton* pulsanteEquipaggiamento;
      ~listaZainoWidget();

  public slots:
    void clickedPulsante1();
    void equipaggiaOggetto();
    void mostraInformazioni();
    void visualizzaElenco();
};

#endif // LISTAZAINOWIDGET_H

