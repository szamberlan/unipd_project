#include"statistichewidget.h"
statisticheWidget::statisticheWidget(controller *c, QWidget *parent) : QWidget(parent), c1(c)
{
    layoutPrincipale=new QFormLayout();
    titoloStatistiche = new QLabel("<p align = center><h1>STATISTICHE PERSONAGGIO</h1></p>",this);
    statisticheFrame= new QFrame(this);
    vbox= new QVBoxLayout();
    statisticheFrame->setLayout(vbox);
    statistiche = new QLabel(this);
    layoutPrincipale->addWidget(titoloStatistiche);
    layoutPrincipale->addWidget(statisticheFrame);
    vbox->addWidget(statistiche);
    bmenu1= new QPushButton("Torna al menù principales",this);
    vbox->addWidget(bmenu1);
    c1->insertWidget(bmenu1);
    c1->insertWidget(statistiche);
    c1->insertWidget(titoloStatistiche);
    c1->insertWidget(statisticheFrame);
    connect(bmenu1,SIGNAL(clicked(bool)),this,SIGNAL(clickedMenu()));
    setLayout(layoutPrincipale);
}

statisticheWidget::~statisticheWidget(){
    c1->removeWidget();
    delete layoutPrincipale;
}

void statisticheWidget::reloadInformazioni()
{
    statistiche->setText(c1->stampaCaratteristichePersonaggio());
}
