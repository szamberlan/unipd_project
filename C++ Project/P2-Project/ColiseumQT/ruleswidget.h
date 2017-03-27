#ifndef RULESWIDGET_H
#define RULESWIDGET_H
#include<QMainWindow>
#include<QLabel>
#include<QPushButton>
#include<QGroupBox>
#include<QVBoxLayout>
#include<QScrollArea>
#include<QFormLayout>
#include"controller.h"
class rulesWidget : public QWidget {
    Q_OBJECT
  public:
      explicit rulesWidget(controller*, QWidget *parent = 0);
      ~rulesWidget();

  private:
    controller*c1;
    QLayout*layoutPrincipale;
    QLabel*titolone;
    QScrollArea *regole;
    QGroupBox *scrollW;
    QVBoxLayout *l;
    QLabel*regoleArena;
    QLabel*regoleArena2;
    QLabel*regoleArena3;
    QLabel*regoleArena4;
    QLabel*regoleArena5;
    QLabel*regoleArena6;
    QPushButton* pulsanteMenu;

  signals:
    void clickedMenu();
};
#endif // RULESWIDGET_H

