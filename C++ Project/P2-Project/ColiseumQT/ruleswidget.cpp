#include"ruleswidget.h"

rulesWidget::rulesWidget(controller *c, QWidget *parent) : QWidget(parent), c1(c)
{
    layoutPrincipale=new QFormLayout();
    titolone = new QLabel("<p align = center><h1>REGOLE GIOCO</h1></p>",this);
    regole= new QScrollArea(this);
    scrollW = new QGroupBox(this);
    regole->setWidget(scrollW);
    l = new QVBoxLayout();
    scrollW->setLayout(l);
    scrollW->setObjectName("scrollWidget1");
    scrollW->setAlignment(Qt::AlignCenter);
    regole->setWidgetResizable(true);
    regoleArena=new QLabel("<p><h3>Combattimento : </h3></p><p>Nella schermata di combattimento accessibile tramite pulsante \"Combattimento in arena\"</p><p>si potrà combattere contro l'avversario di livello, se il giocatore ha un'arma</p><p>nel suo equipaggiamento allora avrà la possibilità di eseguire 4 possibili mosse o colpi differenti,</p><p> ognuno dei quali ha caratteristiche diverse, quando si eseguirà un colpo anche l'avversario risponderà.</p><p>C'è'la possibilità che un colpo vada a buon fine oppure no inoltre ogni colpo sferrato</p><p>comporterà una perdita di energia diversa a seconda dell'arma e della mossa eseguita.</p><p><b>LA SCONFITTA O LA VITTORIA </b> si otterrà quando il giocatore o l'avversario rispettivamente</p><p>saranno giunti a 0 o in vita o in energia, anche se la vita ha peso maggiore rispetto all'energia,</p><p> non ci sono casi di pareggio in quanto in quei casi la vittoria è sempre guadagnata dall'avversario.</p>",this);
    regoleArena2= new QLabel("<p><h3>Mercato : </h3></p><p> Nella sezione Mercato si possono acquistare gli oggetti presenti se il giocatore ha i soldi necessari,</p><p> inoltre si potrano verificarne i dati prima dell'acquisto.</p><p>Gli oggetti comprati verranno inviati allo zaino del giocatore</p>",this);
    regoleArena3= new QLabel("<p><h3>Zaino : </h3></p><p> Nella sezione Zaino si potranno visualizzare tutti gli oggetti comprati e non ancora equipaggiati (\"indossati\" ) dal giocatore,</p><p>si potrà visualizzarne le informazioni, venderli al mercante e anche equipaggiarli,</p><p> se è presente già un equipaggiamento di quel tipo esso verrà sostituito con quello presente precedentemente.",this);
    regoleArena4= new QLabel("<p><h3>Equipaggiamento : </h3></p><p>Nella sezione Equipaggiamento si potranno visualizzare gli oggetti equipaggiati dal giocatore,</p><p> essi successivamente potranno essere spostati nello zaino.</p>",this);
    regoleArena5= new QLabel("<p><h3>Statistiche : </h3><p><p>Nella sezione Statistiche si potrà visualizzare l'insieme delle caratteristiche del giocatore.</p>",this);
    regoleArena6= new QLabel("<p><h3>Vittoria Finale : </h3></p><p>La Vittoria finale si ottiene quando si sono sconfitti tutti gli avversari presenti nel gioco.</p>",this);
    pulsanteMenu = new QPushButton("Torna al Menù Principale",this);
    layoutPrincipale->addWidget(titolone);
    layoutPrincipale->addWidget(regole);
    scrollW->layout()->addWidget(regoleArena);
    scrollW->layout()->addWidget(regoleArena2);
    scrollW->layout()->addWidget(regoleArena3);
    scrollW->layout()->addWidget(regoleArena4);
    scrollW->layout()->addWidget(regoleArena5);
    scrollW->layout()->addWidget(regoleArena6);
    layoutPrincipale->addWidget(pulsanteMenu);
    c1->insertWidget(regoleArena);
    c1->insertWidget(regoleArena2);
    c1->insertWidget(regoleArena3);
    c1->insertWidget(regoleArena4);
    c1->insertWidget(regoleArena5);
    c1->insertWidget(regoleArena6);
    c1->insertWidget(scrollW);
    c1->insertWidget(regole);
    c1->insertWidget(titolone);
    c1->insertWidget(pulsanteMenu);
    connect(pulsanteMenu,SIGNAL(clicked(bool)),this,SIGNAL(clickedMenu()));
    setLayout(layoutPrincipale);
}

rulesWidget::~rulesWidget(){
    c1->removeWidget();
}
