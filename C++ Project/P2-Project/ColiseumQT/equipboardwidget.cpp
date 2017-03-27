#include"equipboardwidget.h"
equipBoardWidget::equipBoardWidget(controller*c, QWidget*parent): QWidget(parent), c1(c)
{
    layoutPrincipale=new QFormLayout();
    titoloEquipaggiamento = new QLabel("<p align = center><h1>EQUIPAGGIAMENTO PERSONAGGIO</h1></p>",this);
    equipaggiamentoBox= new QFrame(this);
    equipaggiamentoBox->setFrameShape(QFrame::Box);
    equipaggiamentoBox->setFrameShadow(QFrame::Raised);
    zonaSopra= new QGroupBox(this);
    zonaSotto= new QGroupBox(this);
    vboxEq= new QVBoxLayout();
    hboxEq1= new QHBoxLayout();
    hboxEq2= new QHBoxLayout();
    equipaggiamentoBox->setLayout(vboxEq);
    vboxEq->addWidget(zonaSopra);
    vboxEq->addWidget(zonaSotto);
    zonaSopra->setLayout(hboxEq1);
    zonaSotto->setLayout(hboxEq2);
    layoutPrincipale->addWidget(titoloEquipaggiamento);
    layoutPrincipale->addWidget(equipaggiamentoBox);
    armaBox= new QGroupBox(this);
    armaturaBox= new QGroupBox(this);
    scudoBox= new QGroupBox(this);
    pozione1Box= new QGroupBox(this);
    pozione2Box= new QGroupBox(this);
    pulsantiBox = new QGroupBox(this);
    vboxpb= new QVBoxLayout();
    vboxarma= new QVBoxLayout();
    vboxarmatura= new QVBoxLayout();
    vboxscudo= new QVBoxLayout();
    vboxpozione1= new QVBoxLayout();
    vboxpozione2= new QVBoxLayout();
    armaBox->setLayout(vboxarma);
    armaturaBox->setLayout(vboxarmatura);
    scudoBox->setLayout(vboxscudo);
    pozione1Box->setLayout(vboxpozione1);
    pozione2Box->setLayout(vboxpozione2);
    pulsantiBox->setLayout(vboxpb);
    hboxEq1->addWidget(armaBox);
    hboxEq1->addWidget(armaturaBox);
    hboxEq1->addWidget(scudoBox);
    hboxEq2->addWidget(pozione1Box);
    hboxEq2->addWidget(pulsantiBox);
    hboxEq2->addWidget(pozione2Box);
    titoloArma = new QLabel("<p align = center><b>Arma</b></p>",this);
    titoloArmatura = new QLabel("<p align = center><b>Armatura</b></p>",this);
    titoloScudo = new QLabel("<p align = center><b>Scudo</b></p>",this);
    titoloPozione1 = new QLabel("<p align = center><b>Pozione Vita</b></p>",this);
    titoloPozione2 = new QLabel("<p align = center><b>Pozione Energia</b></p>",this);
    vboxarma->addWidget(titoloArma);
    vboxarmatura->addWidget(titoloArmatura);
    vboxscudo->addWidget(titoloScudo);
    vboxpozione1->addWidget(titoloPozione1);
    vboxpozione2->addWidget(titoloPozione2);
    armaFrame= new QFrame(this);
    armaFrame->setFrameShape(QFrame::Box);
    armaFrame->setFrameShadow(QFrame::Raised);
    armaturaFrame= new QFrame(this);
    armaturaFrame->setFrameShape(QFrame::Box);
    armaturaFrame->setFrameShadow(QFrame::Raised);
    scudoFrame= new QFrame(this);
    scudoFrame->setFrameShape(QFrame::Box);
    scudoFrame->setFrameShadow(QFrame::Raised);
    pozione1Frame= new QFrame(this);
    pozione1Frame->setFrameShape(QFrame::Box);
    pozione1Frame->setFrameShadow(QFrame::Raised);
    pozione2Frame= new QFrame(this);
    pozione2Frame->setFrameShape(QFrame::Box);
    pozione2Frame->setFrameShadow(QFrame::Raised);
    vboxarma->addWidget(armaFrame);
    vboxarmatura->addWidget(armaturaFrame);
    vboxscudo->addWidget(scudoFrame);
    vboxpozione1->addWidget(pozione1Frame);
    vboxpozione2->addWidget(pozione2Frame);
    vframearma= new QVBoxLayout();
    vframearmatura= new QVBoxLayout();
    vframescudo= new QVBoxLayout();
    vframepozione1= new QVBoxLayout();
    vframepozione2= new QVBoxLayout();
    armaFrame->setLayout(vframearma);
    armaturaFrame->setLayout(vframearmatura);
    scudoFrame->setLayout(vframescudo);
    pozione1Frame->setLayout(vframepozione1);
    pozione2Frame->setLayout(vframepozione2);
    informazioniArma = new QLabel(this);
    informazioniArmatura = new QLabel(this);
    informazioniScudo = new QLabel(this);
    informazioniPozione1 = new QLabel(this);
    informazioniPozione2 = new QLabel(this);
    immArma = new QLabel(this);
    immArmatura = new QLabel(this);
    immScudo = new QLabel(this);
    immPozione1 = new QLabel(this);
    immPozione2 = new QLabel(this);
    bArma = new QPushButton("Sposta Nello Zaino",this);
    bArmatura = new QPushButton("Sposta Nello Zaino",this);
    bScudo = new QPushButton("Sposta Nello Zaino",this);
    bPozione1 = new QPushButton("Sposta Nello Zaino",this);
    bPozione2 = new QPushButton("Sposta Nello Zaino",this);
    informazioniArma->setAlignment(Qt::AlignCenter);
    informazioniArmatura->setAlignment(Qt::AlignCenter);
    informazioniScudo->setAlignment(Qt::AlignCenter);
    informazioniPozione1->setAlignment(Qt::AlignCenter);
    informazioniPozione2->setAlignment(Qt::AlignCenter);
    immArma->setAlignment(Qt::AlignCenter);
    immArmatura->setAlignment(Qt::AlignCenter);
    immScudo->setAlignment(Qt::AlignCenter);
    immPozione1->setAlignment(Qt::AlignCenter);
    immPozione2->setAlignment(Qt::AlignCenter);
    vframearma->addWidget(immArma);
    vframearmatura->addWidget(immArmatura);
    vframescudo->addWidget(immScudo);
    vframepozione1->addWidget(immPozione1);
    vframepozione2->addWidget(immPozione2);
    vframearma->addWidget(informazioniArma);
    vframearmatura->addWidget(informazioniArmatura);
    vframescudo->addWidget(informazioniScudo);
    vframepozione1->addWidget(informazioniPozione1);
    vframepozione2->addWidget(informazioniPozione2);
    vframearma->addWidget(bArma);
    vframearmatura->addWidget(bArmatura);
    vframescudo->addWidget(bScudo);
    vframepozione1->addWidget(bPozione1);
    vframepozione2->addWidget(bPozione2);
    pixArma = new QPixmap(":/img/img/weapon_icon.png");
    pixArmatura = new QPixmap(":/img/img/helmet_icon.png");
    pixScudo = new QPixmap(":/img/img/shield_icon.png");
    pixPozione1 = new QPixmap(":/img/img/potion_icon.png");
    pixPozione2 = new QPixmap(":/img/img/flask_icon.png");
    immArma->setPixmap(*pixArma);
    immArmatura->setPixmap(*pixArmatura);
    immScudo->setPixmap(*pixScudo);
    immPozione1->setPixmap(*pixPozione1);
    immPozione2->setPixmap(*pixPozione2);
    bMenu = new QPushButton("Torna al Menù Principale",this);
    vboxpb->addWidget(bMenu);
    c1->insertImmagini(pixArma);
    c1->insertImmagini(pixArmatura);
    c1->insertImmagini(pixScudo);
    c1->insertImmagini(pixPozione1);
    c1->insertImmagini(pixPozione2);
    c1->insertWidget(informazioniArma);
    c1->insertWidget(informazioniScudo);
    c1->insertWidget(informazioniArmatura);
    c1->insertWidget(informazioniPozione1);
    c1->insertWidget(informazioniPozione2);
    c1->insertWidget(immArma);
    c1->insertWidget(immArmatura);
    c1->insertWidget(immScudo);
    c1->insertWidget(immPozione1);
    c1->insertWidget(immPozione2);
    c1->insertWidget(bArma);
    c1->insertWidget(bArmatura);
    c1->insertWidget(bScudo);
    c1->insertWidget(bPozione1);
    c1->insertWidget(bPozione2);
    c1->insertWidget(pozione2Frame);
    c1->insertWidget(pozione1Frame);
    c1->insertWidget(scudoFrame);
    c1->insertWidget(armaturaFrame);
    c1->insertWidget(armaFrame);
    c1->insertWidget(titoloPozione2);
    c1->insertWidget(titoloPozione1);
    c1->insertWidget(titoloScudo);
    c1->insertWidget(titoloArmatura);
    c1->insertWidget(titoloArma);
    c1->insertWidget(pozione2Box);
    c1->insertWidget(pozione1Box);
    c1->insertWidget(scudoBox);
    c1->insertWidget(armaturaBox);
    c1->insertWidget(armaBox);
    c1->insertWidget(bMenu);
    c1->insertWidget(pulsantiBox);
    c1->insertWidget(zonaSopra);
    c1->insertWidget(zonaSotto);
    c1->insertWidget(equipaggiamentoBox);
    c1->insertWidget(titoloEquipaggiamento);
    connect(bMenu,SIGNAL(clicked(bool)),this,SIGNAL(vaiAMenu()));
    connect(bArma,SIGNAL(clicked(bool)),this,SLOT(spostaArma()));
    connect(bArmatura,SIGNAL(clicked(bool)),this,SLOT(spostaArmatura()));
    connect(bScudo,SIGNAL(clicked(bool)),this,SLOT(spostaScudo()));
    connect(bPozione1,SIGNAL(clicked(bool)),this,SLOT(spostaPozione1()));
    connect(bPozione2,SIGNAL(clicked(bool)),this,SLOT(spostaPozione2()));
    connect(bPozione2,SIGNAL(pressed()),this,SLOT(spostaPozione2()));
    connect(this,SIGNAL(spostamento()),this,SLOT(visualizzaEquipaggiamento()));
    setLayout(layoutPrincipale);
}

equipBoardWidget::~equipBoardWidget(){
    c1->removeImmagini();
    c1->removeWidget();
    delete layoutPrincipale;
}

void equipBoardWidget::visualizzaEquipaggiamento()
{
    informazioniArma->clear();
    informazioniArmatura->clear();
    informazioniScudo->clear();
    informazioniPozione1->clear();
    informazioniPozione2->clear();
    if(c1->ricercaEquipaggiamento(0))
    {
        informazioniArma->setText(c1->stampaCaratteristicheEquipaggiamento(0));
        informazioniArma->adjustSize();
    }
    else
        informazioniArma->setText("VUOTO");
    if(c1->ricercaEquipaggiamento(1))
    {
        informazioniScudo->setText(c1->stampaCaratteristicheEquipaggiamento(1));
        informazioniScudo->adjustSize();
    }
    else
        informazioniScudo->setText("VUOTO");
    if(c1->ricercaEquipaggiamento(2))
    {
        informazioniArmatura->setText(c1->stampaCaratteristicheEquipaggiamento(2));
        informazioniArmatura->adjustSize();
    }
    else
        informazioniArmatura->setText("VUOTO");
    if(c1->ricercaEquipaggiamento(3))
    {
        informazioniPozione1->setText(c1->stampaCaratteristicheEquipaggiamento(3));
        informazioniPozione1->adjustSize();
    }
    else
        informazioniPozione1->setText("VUOTO");
    if(c1->ricercaEquipaggiamento(4))
    {
        informazioniPozione2->setText(c1->stampaCaratteristicheEquipaggiamento(4));
        informazioniPozione2->adjustSize();
    }
    else
        informazioniPozione2->setText("VUOTO");
}

void equipBoardWidget::spostaArma()
{
    c1->spostaOggetto(1);
    emit(spostamento());
}

void equipBoardWidget::spostaArmatura()
{
    c1->spostaOggetto(3);
    emit(spostamento());
}

void equipBoardWidget::spostaPozione2()
{
    c1->spostaOggetto(5);
    emit(spostamento());
}

void equipBoardWidget::spostaPozione1()
{
    c1->spostaOggetto(4);
    emit(spostamento());
}

void equipBoardWidget::spostaScudo()
{
    c1->spostaOggetto(2);
    emit(spostamento());
}
