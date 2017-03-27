#include"finestragioco.h"

finestraGioco::finestraGioco(QWidget *parent) :
    QWidget(parent), c1(new controller(new arenaSemplice))
{
    layoutPrincipale = new QFormLayout();
    inizioGioco = new playWidget(c1,this);
    creazionePersonaggio=0;
    menuPrincipale=0;
    equipaggiamentoPersonaggio=0;
    combattimentoAvversari=0;
    regoleGioco=0;
    statistichePersonaggio=0;
    mercatoPersonaggio=0;
    zainoPersonaggio=0;
    layoutPrincipale->addWidget(inizioGioco);
    setMinimumHeight(600);
    setMinimumWidth(800);
    setLayout(layoutPrincipale);
    connect(inizioGioco,SIGNAL(clickedGioca()),this,SLOT(creaP()));
    connect(inizioGioco,SIGNAL(clickedClose()),this,SLOT(close()));
}

finestraGioco::~finestraGioco()  // distruttore, distrugge prima tutti i singoli sotto-widget di cui è composta
{
    c1->removeLabel();
    c1->removeImmagini();
    c1->emptiesMercaneWidget();
    c1->emptiesZainoWidget();
    c1->removeWidget();
    if(inizioGioco)
        delete inizioGioco;
    if(creazionePersonaggio)
        delete creazionePersonaggio;
    if(statistichePersonaggio)
        delete statistichePersonaggio;
    if(regoleGioco)
        delete regoleGioco;
    if(menuPrincipale)
        delete menuPrincipale;
    if(combattimentoAvversari)
        delete combattimentoAvversari;
    if(mercatoPersonaggio)
        delete mercatoPersonaggio;
    if(zainoPersonaggio)
        delete zainoPersonaggio;
    if(equipaggiamentoPersonaggio)
        delete equipaggiamentoPersonaggio;
    delete layoutPrincipale;
    delete c1;
}

void finestraGioco::creaP()
{
    delete inizioGioco;    
    inizioGioco=0;
    creazionePersonaggio= new sceltaPersonaggioWidget(c1,this);
    layoutPrincipale->addWidget(creazionePersonaggio);
    connect(creazionePersonaggio,SIGNAL(fineCreazione()),this,SLOT(menu()));
}

void finestraGioco::menu()
{
    delete creazionePersonaggio;
    creazionePersonaggio=0;
    menuPrincipale = new menuWidget(c1,this);
    layoutPrincipale->addWidget(menuPrincipale);
    combattimentoAvversari=new gameBoard(c1,this);
    equipaggiamentoPersonaggio = new equipBoardWidget(c1,this);
    statistichePersonaggio = new statisticheWidget(c1,this);
    regoleGioco = new rulesWidget(c1,this);
    mercatoPersonaggio = new listaMercatoWidget(c1,this);
    zainoPersonaggio = new listaZainoWidget(c1,this);
    //menuPrincipale->ricalcoloInformazioni();

    /* Quelli che seguono sono connect che a prima vista possono sembrare inutimente complessi
     * e lunghi ma in realtà c'è poca condivisione di pulsanti e segnali tra i singoli widget
     * di conseguenza invece che fare una classe base astratta che contenga solamente 2/3 pulsanti
     * e qualke segnale ho preferito gestire tutto nei singoli widget e poi connettere i vari segnali
     * in questo che li contiene. Stesso dicasi per i metodi set precedenti, trovo inutile creare una classe che
     * contiene solamente un metodo come classe base.
    */
    connect(menuPrincipale,SIGNAL(clickedEquipaggiamento()),this,SLOT(equipaggiamento()));
    connect(menuPrincipale,SIGNAL(clickedCombattimento()),this,SLOT(combattimento()));
    connect(menuPrincipale,SIGNAL(clickedZaino()),this,SLOT(zaino()));
    connect(menuPrincipale,SIGNAL(clickedMercante()),this,SLOT(mercato()));
    connect(menuPrincipale,SIGNAL(clickedRegole()),this,SLOT(regole()));
    connect(menuPrincipale,SIGNAL(clickedStatistiche()),this,SLOT(statistiche()));

    connect(regoleGioco,SIGNAL(clickedMenu()),this,SLOT(menuReturn()));
    connect(combattimentoAvversari,SIGNAL(endDuel()),this,SLOT(menuReturn()));
    connect(mercatoPersonaggio,SIGNAL(clickedPulsante3()),this,SLOT(menuReturn()));
    connect(equipaggiamentoPersonaggio,SIGNAL(vaiAMenu()),this,SLOT(menuReturn()));
    connect(statistichePersonaggio,SIGNAL(clickedMenu()),this,SLOT(menuReturn()));
    connect(regoleGioco,SIGNAL(clickedMenu()),this,SLOT(menuReturn()));
    connect(zainoPersonaggio,SIGNAL(clickedPulsante3()),this,SLOT(menuReturn()));

    connect(zainoPersonaggio,SIGNAL(clickedPulsante2()),this,SLOT(mercato()));
    connect(mercatoPersonaggio,SIGNAL(clickedPulsante2()),this,SLOT(zaino()));
    connect(menuPrincipale,SIGNAL(endGame()),this,SLOT(close()));
}

void finestraGioco::equipaggiamento()
{
    hideAll();

    equipaggiamentoPersonaggio->visualizzaEquipaggiamento();// aggiornamento equipaggiamento
    equipaggiamentoPersonaggio->show();
    layoutPrincipale->addWidget(equipaggiamentoPersonaggio);
}

void finestraGioco::combattimento()
{
    hideAll();
    combattimentoAvversari->show();
    combattimentoAvversari->iniziaIlCombattimento(); // inizio combattimento
    layoutPrincipale->addWidget(combattimentoAvversari); 
}

void finestraGioco::statistiche()
{
    hideAll();
    statistichePersonaggio->reloadInformazioni(); // aggiornamento informazioni
    statistichePersonaggio->show();
    layoutPrincipale->addWidget(statistichePersonaggio);
}

void finestraGioco::regole()
{
    hideAll();
    regoleGioco->show();
    layoutPrincipale->addWidget(regoleGioco);
}

void finestraGioco::mercato()
{
    hideAll();
    mercatoPersonaggio->visualizzaElenco();
    mercatoPersonaggio->show();
    layoutPrincipale->addWidget(mercatoPersonaggio);
}

void finestraGioco::zaino()
{
    hideAll();
    zainoPersonaggio->visualizzaElenco();
    zainoPersonaggio->show();
    layoutPrincipale->addWidget(zainoPersonaggio);
}


void finestraGioco::menuReturn()
{
    hideAll();
    menuPrincipale->ricalcoloInformazioni();
    menuPrincipale->show();
}


void finestraGioco::hideAll()
{
    menuPrincipale->hide();
    zainoPersonaggio->hide();
    mercatoPersonaggio->hide();
    regoleGioco->hide();
    statistichePersonaggio->hide();
    equipaggiamentoPersonaggio->hide();
    combattimentoAvversari->hide();
}
