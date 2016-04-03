#include "finestraprincipale.h"
#include "ui_finestraprincipale.h"
#include<QLabel>
#include<QPushButton>

finestraPrincipale::finestraPrincipale(QWidget *parent) :
    QMainWindow(parent), c1(new controller(new arenaSemplice)),
    ui(new Ui::finestraPrincipale)
{
    ui->setupUi(this);
    //ui->scrollArea->setStyleSheet("background-color:trasparent;");
    layoutPrincipale = new QVBoxLayout();
    ui->centralwidget->setLayout(layoutPrincipale);
    PaginaInziale();
}

finestraPrincipale::~finestraPrincipale()
{
    delete ui;
}

void finestraPrincipale::premiGioca()
{
    c1->removeWidget();
    CreaPersonaggio();
}


void finestraPrincipale::PaginaInziale()
{
    QLabel*l1=new QLabel("Coliseum QT",this);
    QPushButton*p1= new QPushButton("GIOCA",this);
    QPushButton*p2= new QPushButton("ESCI",this);
    connect(p2,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(p1,SIGNAL(clicked(bool)),this,SLOT(premiGioca()));
    layoutPrincipale->addWidget(l1);
    layoutPrincipale->addWidget(p1);
    layoutPrincipale->addWidget(p2);
    c1->insertWidget(l1);
    c1->insertWidget(p1);
    c1->insertWidget(p2);
}

void finestraPrincipale::CreaPersonaggio()
{
    QLabel*l2=new QLabel("Crea Personaggio",this);
    layoutPrincipale->addWidget(l2);
    c1->insertWidget(l2);
}
