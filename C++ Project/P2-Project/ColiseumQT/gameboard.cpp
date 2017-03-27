#include"gameboard.h"
#include"QMessageBox"
#include<QtGlobal>
gameBoard::gameBoard(controller*c, QWidget*parent): QWidget(parent), c1(c)
{
    layoutPrincipale=new QFormLayout();
    nomeAvv = new QLabel(this);
    titoloC = new QLabel("<p align = center><h1>Via al Duello</h1></p>",this);
    layoutPrincipale->addWidget(titoloC);
    titolo1 = new QLabel("<p align = center><b>Dati Avversario</b></p>",this);
    ab1a = new QLabel("<p>Vita</p>",this);
    ab2a = new QLabel("<p>Energia</p>",this);
    titolo2 = new QLabel("<p align = center><b>Dati Personaggio</b></p>",this);
    ab1p = new QLabel("<p>Vita</p>",this);
    ab2p = new QLabel("<p>Energia</p>",this);
    SchermataProtagonista = new QFrame(this);
    DatiProtagonista = new QFrame(this);
    DatiProtagonista->setFrameShape(QFrame::Box);
    DatiProtagonista->setFrameShadow(QFrame::Raised);
    Pulsanti1= new QFrame(this);
    Pulsanti1->setFrameShape(QFrame::Box);
    Pulsanti1->setFrameShadow(QFrame::Raised);
    Pulsanti2= new QGroupBox(this);
    Pulsanti3= new QGroupBox(this);
    Pulsanti4= new QGroupBox(this);
    Pulsanti5= new QGroupBox(this);
    SchermataAvversario = new QFrame(this);
    SchermataAvversario->setMaximumSize(800,180);
    DatiAvversario = new QFrame(this);
    DatiAvversario->setFrameShape(QFrame::Box);
    DatiAvversario->setFrameShadow(QFrame::Raised);
    CarAvv = new QFrame(this);
    CarAvv->setFrameShape(QFrame::Box);
    CarAvv->setFrameShadow(QFrame::Raised);
    titoloInfo = new QLabel("Visualizza Info delle mosse",this);
    sceltainfo= new QComboBox(this);
    listaMosse=new QStringList();
    PulsanteAttacco1 = new QPushButton(c1->getNomeMosseArma(1),this);
    PulsanteAttacco2 = new QPushButton(c1->getNomeMosseArma(2),this);
    PulsanteAttacco3 = new QPushButton(c1->getNomeMosseArma(3),this);
    PulsanteAttacco4 = new QPushButton(c1->getNomeMosseArma(4),this);
    PulsanteVisualizzaInfo = new QPushButton("Visualizza",this);
    BeviPozioneV = new QPushButton("Bevi Pozione Vita",this);
    BeviPozioneE = new QPushButton("Bevi Pozione Energia",this);
    layoutPrincipale->addWidget(SchermataAvversario);
    scA = new QHBoxLayout();
    SchermataAvversario->setLayout(scA);
    scA->addWidget(DatiAvversario);
    scA->addWidget(CarAvv);
    layoutAvversario = new QVBoxLayout();
    layoutAvversario2 = new QVBoxLayout();
    DatiAvversario->setLayout(layoutAvversario);
    CarAvv->setLayout(layoutAvversario2);
    layoutAvversario2->addWidget(nomeAvv);
    barraVitaA=new QProgressBar(this);
    barraEnergiaA=new QProgressBar(this);
    layoutAvversario->addWidget(titolo1);
    layoutAvversario->addWidget(ab1a);
    layoutAvversario->addWidget(barraVitaA);
    layoutAvversario->addWidget(ab2a);
    layoutAvversario->addWidget(barraEnergiaA);
    layoutPrincipale->addWidget(SchermataProtagonista);
    scP = new QHBoxLayout();
    SchermataProtagonista->setLayout(scP);
    scP->addWidget(DatiProtagonista);
    scP->addWidget(Pulsanti1);
    layoutProtagonista = new QVBoxLayout();
    DatiProtagonista->setLayout(layoutProtagonista);
    barraVitaP=new QProgressBar(this);
    barraEnergiaP=new QProgressBar(this);
    layoutProtagonista->addWidget(titolo2);
    layoutProtagonista->addWidget(ab1p);
    layoutProtagonista->addWidget(barraVitaP);
    layoutProtagonista->addWidget(ab2p);
    layoutProtagonista->addWidget(barraEnergiaP);
    layoutProtagonista->addWidget(titoloInfo);
    layoutProtagonista->addWidget(Pulsanti5);
    vB1= new QVBoxLayout();
    Pulsanti1->setLayout(vB1);
    titoloM = new QLabel("<p align = center><b>Menù Combattimento</b></p>",this);
    titoloP1 = new QLabel("<p align = left>Mosse</p>",this);
    titoloP2 = new QLabel("<p align = left>Altro</p>",this);
    vB1->addWidget(titoloM);
    vB1->addWidget(titoloP1);
    vB1->addWidget(Pulsanti2);
    vB1->addWidget(Pulsanti3);
    vB1->addWidget(titoloP2);
    vB1->addWidget(Pulsanti4);
    hB1= new QHBoxLayout();
    hB2= new QHBoxLayout();
    hB3= new QHBoxLayout();
    hB4= new QHBoxLayout();
    Pulsanti2->setLayout(hB1);
    Pulsanti3->setLayout(hB2);
    Pulsanti4->setLayout(hB3);
    Pulsanti5->setLayout(hB4);
    hB1->addWidget(PulsanteAttacco1);
    hB1->addWidget(PulsanteAttacco2);
    hB4->addWidget(sceltainfo);
    hB4->addWidget(PulsanteVisualizzaInfo);
    hB2->addWidget(PulsanteAttacco3);
    hB2->addWidget(PulsanteAttacco4);
    hB3->addWidget(BeviPozioneV);
    hB3->addWidget(BeviPozioneE);
    c1->insertWidget(titolo1);
    c1->insertWidget(ab1a);
    c1->insertWidget(ab2a);
    c1->insertWidget(titolo2);
    c1->insertWidget(ab1p);
    c1->insertWidget(ab2p);
    c1->insertWidget(nomeAvv);
    c1->insertWidget(titoloM);
    c1->insertWidget(titoloP1);
    c1->insertWidget(titoloP2);
    c1->insertWidget(PulsanteAttacco1);
    c1->insertWidget(PulsanteAttacco2);
    c1->insertWidget(PulsanteAttacco3);
    c1->insertWidget(PulsanteAttacco4);
    c1->insertWidget(BeviPozioneV);
    c1->insertWidget(BeviPozioneE);
    c1->insertWidget(PulsanteVisualizzaInfo);
    c1->insertWidget(barraEnergiaA);
    c1->insertWidget(barraEnergiaP);
    c1->insertWidget(barraVitaA);
    c1->insertWidget(barraVitaP);
    c1->insertWidget(Pulsanti5);
    c1->insertWidget(Pulsanti4);
    c1->insertWidget(Pulsanti2);
    c1->insertWidget(Pulsanti3);
    c1->insertWidget(Pulsanti1);
    c1->insertWidget(DatiProtagonista);
    c1->insertWidget(CarAvv);
    c1->insertWidget(DatiAvversario);
    c1->insertWidget(titoloC);
    c1->insertWidget(SchermataAvversario);
    c1->insertWidget(SchermataProtagonista);
    barraVitaA->setValue(100);
    barraVitaP->setValue(100);
    barraEnergiaA->setValue(100);
    barraEnergiaP->setValue(100);
    connect(PulsanteAttacco1,SIGNAL(clicked(bool)),this,SLOT(combatti1()));
    connect(PulsanteAttacco2,SIGNAL(clicked(bool)),this,SLOT(combatti2()));
    connect(PulsanteAttacco3,SIGNAL(clicked(bool)),this,SLOT(combatti3()));
    connect(PulsanteAttacco4,SIGNAL(clicked(bool)),this,SLOT(combatti4()));
    connect(BeviPozioneV,SIGNAL(clicked(bool)),this,SLOT(riceviAiuto1()));
    connect(BeviPozioneE,SIGNAL(clicked(bool)),this,SLOT(riceviAiuto2()));
    connect(this,SIGNAL(turno()),this,SLOT(aggiornamentoDanni()));
    connect(PulsanteVisualizzaInfo,SIGNAL(clicked(bool)),this,SLOT(infoAttacco()));
    setLayout(layoutPrincipale);

}

gameBoard::~gameBoard()
{
    c1->removeWidget();
    delete layoutPrincipale;
}


void gameBoard::infoAttacco()
{
    QMessageBox::information(this,"INFORMAZIONI",c1->getInfoMosseArma(sceltainfo->currentIndex()+1));
}

void gameBoard::iniziaIlCombattimento()
{
    sceltainfo->clear();
    c1->iniziaCombattimento();
    barraVitaA->setValue(100);
    barraVitaP->setValue(100);
    barraEnergiaA->setValue(100);
    barraEnergiaP->setValue(100);
    nomeAvv->setText(c1->stampaCaratteristicheAvversario());
    PulsanteAttacco1->setText(c1->getNomeMosseArma(1));
    PulsanteAttacco2->setText(c1->getNomeMosseArma(2));
    PulsanteAttacco3->setText(c1->getNomeMosseArma(3));
    PulsanteAttacco4->setText(c1->getNomeMosseArma(4));
    c1->aggiornaMosse(listaMosse);
    sceltainfo->addItems(*listaMosse);
}
void gameBoard::combatti1()
{
    c1->combatti(1);
    emit(turno());
}

void gameBoard::combatti2()
{
    c1->combatti(2);
    emit(turno());
}

void gameBoard::combatti3()
{
    c1->combatti(3);
    emit(turno());

}

void gameBoard::combatti4()
{
    c1->combatti(4);
    emit(turno());
}
void gameBoard::riceviAiuto1()
{
    c1->combatti(5);
    emit(turno());

}

void gameBoard::riceviAiuto2()
{
    c1->combatti(6);
    emit(turno());
}

void gameBoard::aggiornamentoDanni()
{
    double randomValue= qrand()% 100;
    if(randomValue < 50)
    {
        inizioIo = true;
        aggiornamentoDanniTurno1();
    }
    else
    {
        inizioIo = false;
        aggiornamentoDanniTurno2();
    }

}

void gameBoard::aggiornamentoDanniTurno1()
{
    barraVitaA->setValue(c1->getVita(0));
    barraEnergiaP->setValue(c1->getEnergia(1));
    if(!inizioIo)
    {
        if(c1->vittoria()||c1->sconfitta())
        {
            if(c1->vittoria())
            {
                c1->fineCombattimento(10);
                QMessageBox::warning(this,"FINE DUELLO","Complimenti per la VITTORIA","Torna al Menù");
            }
            else
            {
                c1->fineCombattimento(10);
                QMessageBox::warning(this,"FINE DUELLO","Ritenta, questa SCONFITTA non deve fermarti","Torna al Menù");

            }
            emit(endDuel());
        }
    }
    else
    {
        QMessageBox::warning(this,"Fine Turno Giocatore","Il giocatore ha attaccato per primo ora tocca all'Avversario");
        aggiornamentoDanniTurno2();
    }
}

void gameBoard::aggiornamentoDanniTurno2()
{
    barraVitaP->setValue(c1->getVita(1));
    barraEnergiaA->setValue(c1->getEnergia(0));
    if(inizioIo)
    {
        if(c1->vittoria()||c1->sconfitta())
        {
            if(c1->vittoria())
            {
                c1->fineCombattimento(10);
                QMessageBox::warning(this,"FINE DUELLO","Complimenti per la VITTORIA","Torna al Menù");
            }
            else
            {
                c1->fineCombattimento(10);
                QMessageBox::warning(this,"FINE DUELLO","Ritenta, questa SCONFITTA non deve fermarti","Torna al Menù");

            }
            emit(endDuel());
        }
    }
    else
    {
        QMessageBox::warning(this,"Fine Turno Avversario","L'avversario ha cominciato per primo ora tocca al Giocatore");
        aggiornamentoDanniTurno1();
    }
}
