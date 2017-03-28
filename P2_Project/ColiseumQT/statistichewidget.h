#ifndef STATISTICHEWIDGET_H
#define STATISTICHEWIDGET_H
#include<QMainWindow>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include<QFormLayout>
#include"controller.h"
class statisticheWidget : public QWidget {
    Q_OBJECT
  public:
      explicit statisticheWidget(controller*, QWidget *parent = 0);
      ~statisticheWidget();

  private:
    controller*c1;
    QLayout*layoutPrincipale;
    QLabel*titoloStatistiche;
    QFrame*statisticheFrame;
    QVBoxLayout*vbox;
    QLabel*statistiche;
    QPushButton*bmenu1;

  signals:
    void clickedMenu();
public slots:
    void reloadInformazioni();
};
#endif // STATISTICHEWIDGET_H

