#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H
#include<QMainWindow>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include"controller.h"
class playWidget : public QWidget {
    Q_OBJECT
  public:
      explicit playWidget(controller*, QWidget *parent = 0);
      ~playWidget();

  private :
    controller*c1;
    QLayout*layoutPrincipale;
    QLabel*l1;
    QFrame*riquadroIniziale;
    QVBoxLayout*layoutIniziale;
    QLabel*l2;
    QLabel*l3;
    QPushButton*p1;
    QPushButton*p2;
    QLabel* immIniz;
    QPixmap*pixIniz;


 signals:
    void clickedGioca();
    void clickedClose();
};
#endif // PLAYWIDGET_H

