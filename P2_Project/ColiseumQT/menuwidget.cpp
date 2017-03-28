#include"menuwidget.h"

menuWidget::menuWidget(controller *c, QWidget *parent) : QWidget(parent), c1(c)
{
    layoutPrincipale=new QFormLayout();
    Titolo= new QLabel("<p align = center><h1>MENÙ DI GIOCO</h1></p>",this);
    groupIntro = new QGroupBox(this);
    livello= new QLabel("Avversari Sconfitti : "+QString::number(c1->getLivelloArena()),this);
    nemiciRimasti= new QLabel("Avversari Rimasti : "+QString::number(c1->nemiciRimasti()),this);
    layoutIntro = new QHBoxLayout();
    layoutPrincipale->addWidget(Titolo);
    if(c1->vittoriaArena())
    {
        Vittoria_text = new QLabel("<p color=red><h5>Vittoria</h5>I tuoi avversari sono stati tutti sconfitti</p>",this);
        layoutPrincipale->addWidget(Vittoria_text);
        c1->insertWidget(Vittoria_text);
    }
    layoutPrincipale->addWidget(groupIntro);
    groupIntro->setLayout(layoutIntro);
    layoutIntro->addWidget(livello);
    layoutIntro->addWidget(nemiciRimasti);
    livello->setAlignment(Qt::AlignLeft);
    nemiciRimasti->setAlignment(Qt::AlignRight);
    c1->insertWidget(Titolo);
    c1->insertWidget(nemiciRimasti);
    c1->insertWidget(livello);
    if(!c1->vittoriaArena())
    {
        vediMenu = new QFrame(this);
        layoutMenu = new QVBoxLayout();
        vediMenu->setFrameShape(QFrame::Box);
        vediMenu->setFrameShadow(QFrame::Raised);
        vediMenu->setLayout(layoutMenu);
        layoutPrincipale->addWidget(vediMenu);

        //Combattimento
        pulsanteCombatti = new QPushButton("Combattimento in Arena",this);
        pulsanteCombatti->resize(250,100);
        layoutMenu->addWidget(pulsanteCombatti);
        c1->insertWidget(pulsanteCombatti);
        connect(pulsanteCombatti,SIGNAL(clicked(bool)),this,SIGNAL(clickedCombattimento()));

        //Zaino
        pulsanteZaino= new QPushButton("Zaino",this);
        layoutMenu->addWidget(pulsanteZaino);
        c1->insertWidget(pulsanteZaino);
        connect(pulsanteZaino,SIGNAL(clicked(bool)),this,SIGNAL(clickedZaino()));

        //Mercante
        pulsanteMercante = new QPushButton("Mercante",this);
        layoutMenu->addWidget(pulsanteMercante);
        c1->insertWidget(pulsanteMercante);
        connect(pulsanteMercante,SIGNAL(clicked(bool)),this,SIGNAL(clickedMercante()));

        //Equipaggiamento
        pulsanteEquipaggiamento = new QPushButton("Equipaggiamento",this);
        layoutMenu->addWidget(pulsanteEquipaggiamento);
        c1->insertWidget(pulsanteEquipaggiamento);
        connect(pulsanteEquipaggiamento,SIGNAL(clicked(bool)),this,SIGNAL(clickedEquipaggiamento()));

        //Statistiche
        pulsanteStatistiche = new QPushButton("Statistiche",this);
        layoutMenu->addWidget(pulsanteStatistiche);
        c1->insertWidget(pulsanteStatistiche);
        connect(pulsanteStatistiche,SIGNAL(clicked(bool)),this,SIGNAL(clickedStatistiche()));

        //Risultati
        pulsanteRisultati = new QPushButton("Regole",this);
        layoutMenu->addWidget(pulsanteRisultati);
        c1->insertWidget(pulsanteRisultati);
        connect(pulsanteRisultati,SIGNAL(clicked(bool)),this,SIGNAL(clickedRegole()));

        //Immagine Menù
        immMenu = new QLabel(this);
        pixMenu = new QPixmap(":/img/img/menu_icon.png");
        immMenu->setPixmap(*pixMenu);
        layoutPrincipale->addWidget(immMenu);
        immMenu->setAlignment(Qt::AlignCenter);
        c1->insertWidget(immMenu);
        c1->insertImmagini(pixMenu);
        c1->insertWidget(vediMenu);
    }
    else
    {
        /*Non si tratta di ripetizione di codice in quanto potrebbe creare una arena già vinta*/

        immMenu = new QLabel(this);
        pixMenu = new QPixmap(":/img/img/victory_icon.png");
        immMenu->setPixmap(*pixMenu);
        layoutPrincipale->addWidget(immMenu);
        immMenu->setAlignment(Qt::AlignCenter);
        c1->insertWidget(immMenu);
        c1->insertImmagini(pixMenu);
        pulsanteEsci = new QPushButton("Esci",this);
        layoutPrincipale->addWidget(pulsanteEsci);
        c1->insertWidget(pulsanteEsci);
        connect(pulsanteEsci,SIGNAL(clicked(bool)),this,SIGNAL(endGame()));

    }
    c1->insertWidget(groupIntro);
    setLayout(layoutPrincipale);
}

void menuWidget::ricalcoloInformazioni() // serve per aggiornare le informazioni del menu
{
    livello->setText("Avversari Sconfitti : "+QString::number(c1->getLivelloArena()));
    nemiciRimasti->setText("Avversari Rimasti : "+QString::number(c1->nemiciRimasti()));
    if(c1->vittoriaArena())
    {
        vediMenu->hide();
        immMenu->hide();
        Vittoria_text = new QLabel("<p color=red><h5>Vittoria</h5>I tuoi avversari sono stati tutti sconfitti</p>",this);
        layoutPrincipale->addWidget(Vittoria_text);
        c1->insertWidget(Vittoria_text);
        immMenu = new QLabel(this);
        pixMenu = new QPixmap(":/img/img/victory_icon.png");
        immMenu->setPixmap(*pixMenu);
        layoutPrincipale->addWidget(immMenu);
        immMenu->setAlignment(Qt::AlignCenter);
        c1->insertWidget(immMenu);
        c1->insertImmagini(pixMenu);
        pulsanteEsci = new QPushButton("Esci",this);
        layoutPrincipale->addWidget(pulsanteEsci);
        c1->insertWidget(pulsanteEsci);
        connect(pulsanteEsci,SIGNAL(clicked(bool)),this,SIGNAL(endGame()));
    }
}

menuWidget::~menuWidget(){
    c1->removeImmagini();
    c1->removeWidget();
}
