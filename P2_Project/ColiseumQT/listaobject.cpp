#include"listaobject.h"
listaObject::listaObject(controller* c, QWidget *parent ) : QWidget(parent), c1(c)
{
    layoutPrincipale = new QFormLayout();
    titoloPrincip = new QLabel(this);
     areaPrincipale= new QGroupBox(this);
    hboxM= new QHBoxLayout();
    layoutPrincipale->addWidget(titoloPrincip);
    layoutPrincipale->addWidget(areaPrincipale);
     areaPrincipale->setLayout(hboxM);
    parteElenco = new QFrame(this);
    parteElenco->setFrameShape(QFrame::Box);
    parteElenco->setFrameShadow(QFrame::Raised);
    parteElenco->setMinimumSize(320,470);
    vboxM1 = new QVBoxLayout();
    parteElenco->setLayout(vboxM1);
    parteMostraDati = new QFrame(this);
    parteMostraDati->setFrameShape(QFrame::Box);
    parteMostraDati->setFrameShadow(QFrame::Raised);
    vboxM2 = new QVBoxLayout();
    parteMostraDati->setLayout(vboxM2);
    hboxM->addWidget(parteElenco);
    hboxM->addWidget(parteMostraDati);
    sottotitolo = new QLabel(this);
    areaElenco= new QScrollArea(this);
    pulsante1 = new QPushButton(this);
    pulsante3 = new QPushButton(this);
    pulsante2 = new QPushButton(this);
    vboxM1->addWidget(sottotitolo);
    vboxM1->addWidget(areaElenco);
    vboxM1->addWidget(pulsante1);
    vboxM1->addWidget(pulsante2);
    vboxM1->addWidget(pulsante3);
    layoutLista = new QVBoxLayout();
    scrollWidget1 = new QGroupBox(this);
    areaElenco->setWidget(scrollWidget1);
    scrollWidget1->setLayout(layoutLista);
    scrollWidget1->setAlignment(Qt::AlignCenter);
    areaElenco->setWidgetResizable(true);
    titoloDati = new QLabel(this);
    datiOggetto = new QLabel(this);
    titolosoldi = new QLabel(this);
    soldi = new QLCDNumber(10,this);
    soldi->display(c1->getSoldiGiocatore());
    vboxM2->addWidget(titoloDati);
    vboxM2->addWidget(datiOggetto);
    vboxM2->addWidget(titolosoldi);
    vboxM2->addWidget(soldi);

    c1->insertWidget(scrollWidget1);
    c1->insertWidget(areaElenco);
    c1->insertWidget(titoloDati);
    c1->insertWidget(sottotitolo);
    c1->insertWidget(soldi);
    c1->insertWidget(titolosoldi);
    c1->insertWidget(pulsante1);
    c1->insertWidget(pulsante3);
    c1->insertWidget(pulsante2);
    c1->insertWidget(datiOggetto);
    c1->insertWidget(parteMostraDati);
    c1->insertWidget(parteElenco);
    c1->insertWidget(areaPrincipale);
    c1->insertWidget(titoloPrincip);
    connect(pulsante1,SIGNAL(clicked(bool)),this,SLOT(clickedPulsante1()));
    connect(pulsante3,SIGNAL(clicked(bool)),this,SIGNAL(clickedPulsante3()));
    connect(pulsante2,SIGNAL(clicked(bool)),this,SIGNAL(clickedPulsante2()));
    setLayout(layoutPrincipale);
}

listaObject::~listaObject(){
    c1->removeWidget();
    delete layoutPrincipale;
}

void listaObject::setSoldi()
{
    soldi->display(c1->getSoldiGiocatore());
}
