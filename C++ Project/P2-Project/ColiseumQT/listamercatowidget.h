#ifndef LISTAMERCATOWIDGET_H
#define LISTAMERCATOWIDGET_H
#include"listaobject.h"
class listaMercatoWidget : public listaObject {
    Q_OBJECT
  public:
      explicit listaMercatoWidget(controller*, QWidget *parent = 0);
      ~listaMercatoWidget();

  public slots:
    void clickedPulsante1();
    void mostraInformazioni();
    void visualizzaElenco();
};

#endif // LISTAMERCATOWIDGET_H

