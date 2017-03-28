#include"playwidget.h"
playWidget::playWidget(controller*c, QWidget *parent):
    QWidget(parent), c1(c)
{
    layoutPrincipale=new QVBoxLayout();
    l1=new QLabel("<p align= center><h1>Coliseum QT</h1></p>",this);
    riquadroIniziale= new QFrame(this);
    riquadroIniziale->setFrameShape(QFrame::Box);
    riquadroIniziale->setFrameShadow(QFrame::Raised);
    layoutIniziale = new QVBoxLayout();
    riquadroIniziale->setLayout(layoutIniziale);
    l2=new QLabel("<p align= center><i>Crea il tuo personaggio,</i></p><p align= center><i>Combatti e trionfa nell'arena,</i></p><p align= center><i>Compra nuove armi e Scegli le migliori</i></p>",this);
    l3=new QLabel("<p align= right>Un gioco creato da Zamberlan Sebastiano</p>",this);
    p1= new QPushButton("GIOCA",this);
    p2= new QPushButton("ESCI",this);
    immIniz = new QLabel(this);
    pixIniz = new QPixmap(":/img/img/arena.jpg");
    immIniz->setPixmap(*pixIniz);
    layoutIniziale->addWidget(immIniz);
    immIniz->setAlignment(Qt::AlignCenter);
    layoutPrincipale->addWidget(l1);
    layoutPrincipale->addWidget(l2);
    layoutPrincipale->addWidget(riquadroIniziale);
    layoutIniziale->addWidget(p1);
    layoutIniziale->addWidget(p2);
    layoutPrincipale->addWidget(l3);
    c1->insertImmagini(pixIniz);
    c1->insertWidget(immIniz);
    c1->insertWidget(p1);
    c1->insertWidget(p2);
    c1->insertWidget(l1);
    c1->insertWidget(l2);
    c1->insertWidget(riquadroIniziale);
    c1->insertWidget(l3);
    connect(p2,SIGNAL(clicked(bool)),this,SIGNAL(clickedClose()));
    connect(p1,SIGNAL(clicked(bool)),this,SIGNAL(clickedGioca()));
    setLayout(layoutPrincipale);
}


playWidget::~playWidget(){
    c1->removeImmagini();
    c1->removeWidget();
    delete layoutPrincipale;
}




