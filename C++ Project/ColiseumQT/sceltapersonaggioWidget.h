#ifndef SCELTAPERSONAGGIO_H
#define SCELTAPERSONAGGIO_H
#include<QWidget>
#include<QGroupBox>
#include<QScrollArea>
#include<QPushButton>
#include<QLCDNumber>
#include<QRadioButton>
#include<QLineEdit>
#include<QFormLayout>
#include"controller.h"
#include"creapersonaggiowidget.h"
#include"completapersonaggioWidget.h"
class sceltaPersonaggioWidget : public QWidget {
    Q_OBJECT
  public:
      explicit sceltaPersonaggioWidget(controller*, QWidget *parent = 0);
      ~sceltaPersonaggioWidget();
 private:
    QLayout *layoutPrincipale;
    controller * c1;
    creaPersonaggioWidget* primaParte;
    completaPersonaggioWidget* secondaParte;
signals:
    void fineCreazione();

public slots:
    void sceltaClasse();
};
#endif // SCELTAPERSONAGGIO_H

