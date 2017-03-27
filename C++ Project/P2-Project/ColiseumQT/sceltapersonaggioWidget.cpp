#include"sceltapersonaggioWidget.h"
sceltaPersonaggioWidget::sceltaPersonaggioWidget(controller *c, QWidget *parent): QWidget(parent), c1(c)
{
    layoutPrincipale= new QVBoxLayout();
    primaParte= new creaPersonaggioWidget(c1,this);
    secondaParte=0;
    layoutPrincipale->addWidget(primaParte);
    connect(primaParte,SIGNAL(selezioneRazzaCompletata()),this,SLOT(sceltaClasse()));
    setLayout(layoutPrincipale);
}

sceltaPersonaggioWidget::~sceltaPersonaggioWidget(){
    if(primaParte)
        delete primaParte;
    if(secondaParte)
        delete secondaParte;
    delete layoutPrincipale;
}

void sceltaPersonaggioWidget::sceltaClasse()
{
    delete primaParte;
    primaParte=0;
    secondaParte=new completaPersonaggioWidget(c1,this);
    layoutPrincipale->addWidget(secondaParte);
    connect(secondaParte,SIGNAL(personaggioCompletato()),this,SIGNAL(fineCreazione()));
}
