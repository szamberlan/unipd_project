#include"completapersonaggioWidget.h"
#include"QMessageBox"
completaPersonaggioWidget::completaPersonaggioWidget(controller *c, QWidget *parent): QWidget(parent), c1(c)
{
    layoutPrincipale=new QFormLayout();
    gb1 = new QGroupBox();
    gb2 = new QGroupBox();
    gb3 = new QGroupBox();
    h1=new QHBoxLayout();
    h2=new QHBoxLayout();
    h3=new QHBoxLayout();
    gb1->setLayout(h1);
    gb2->setLayout(h2);
    gb3->setLayout(h3);
    l2=new QLabel("<p align = center><h1>Crea Personaggio</h1></p>",this);
    layoutPrincipale->addWidget(l2);
    c1->insertWidget(l2);
    l3=new QLabel("<p><h3>Seleziona la Classe</h3></p>",this);
    l4=new QLabel("<p><h3>Seleziona l'Abilità da attribuire</h3></p>",this);
    layoutPrincipale->addWidget(l3);
    c1->insertWidget(l3);
    layoutPrincipale->addWidget(gb1);
    layoutPrincipale->addWidget(gb2);
    sceltaClasse1= new QRadioButton(c1->getNomeClasse1Disponibile(),this);
    h1->addWidget(sceltaClasse1);
    c1->insertWidget(sceltaClasse1);
    sceltaClasse2= new QRadioButton(c1->getNomeClasse2Disponibile(),this);
    h1->addWidget(sceltaClasse2);
    c1->insertWidget(sceltaClasse2);
    imm1 = new QLabel(this);
    pix1 = new QPixmap(c1->getPathImageClasse1Disponibile());
    imm1->setPixmap(*pix1);
    imm2= new QLabel(this);
    pix2 = new QPixmap(c1->getPathImageClasse2Disponibile());
    imm2->setPixmap(*pix2);
    h2->addWidget(imm1);
    h2->addWidget(imm2);
    c1->insertImmagini(pix1);
    c1->insertImmagini(pix2);
    c1->insertWidget(imm1);
    c1->insertWidget(imm2);
    sceltaAbilita= new QComboBox(this);
    listaAbilitaElfo=new QStringList();
    aE1=new QString("Danno Critico Aumentato");
    aE2=new QString("Risparmio Deficit Armatura ");
    aE3=new QString("Risparimio Deficit Utilizzo Arma");
    aE4=new QString("Capactità Migliorata di Parare");
    aE5=new QString("Migliore Recupero Vita");
    aE6=new QString("Migliore Recupero Energia");
    listaAbilitaElfo->push_back(*aE1);
    listaAbilitaElfo->push_back(*aE2);
    listaAbilitaElfo->push_back(*aE3);
    listaAbilitaElfo->push_back(*aE4);
    listaAbilitaElfo->push_back(*aE5);
    listaAbilitaElfo->push_back(*aE6);
    sceltaAbilita->addItems(*listaAbilitaElfo);
    layoutPrincipale->addWidget(l4);
    c1->insertWidget(l4);
    layoutPrincipale->addWidget(sceltaAbilita);
    c1->insertWidget(sceltaAbilita);
    finalePersonaggio = new QPushButton("Concludi Creazione Personaggio",this);
    layoutPrincipale->addWidget(finalePersonaggio);
    c1->insertWidget(finalePersonaggio);
    connect(sceltaClasse1,SIGNAL(clicked(bool)),this,SLOT(inserimentoClasse1()));
    connect(sceltaClasse2,SIGNAL(clicked(bool)),this,SLOT(inserimentoClasse2()));
    connect(sceltaAbilita,SIGNAL(activated(int)),this,SLOT(inserimentoAbilita(int)));
    connect(finalePersonaggio,SIGNAL(clicked(bool)),this,SLOT(completataCreazione()));
    setLayout(layoutPrincipale);
}

completaPersonaggioWidget::~completaPersonaggioWidget(){
    c1->removeImmagini();
    c1->removeWidget();
}


void completaPersonaggioWidget::inserimentoClasse1()
{
    c1->selezioneClasse(1);
}

void completaPersonaggioWidget::inserimentoClasse2()
{
    c1->selezioneClasse(2);
}

void completaPersonaggioWidget::inserimentoAbilita(int i)
{
    c1->selezioneAbilita(i);
}


void completaPersonaggioWidget::completataCreazione()
{
    if(c1->getClasseSelezionata())
    {
        c1->creaPersonaggio();
        emit(personaggioCompletato());
    }
    else
        QMessageBox::warning(this,"ERRORE SELEZIONE","Seleziona una classe prima di proseguire");
}
