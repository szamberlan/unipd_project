#include"creapersonaggiowidget.h"

creaPersonaggioWidget::creaPersonaggioWidget(controller *c, QWidget *parent): QWidget(parent), c1(c)
{
    layoutPrincipale=new QFormLayout();
    l2=new QLabel("<p align = center><h1>Crea Personaggio</h1></p>",this);
    l1a=new QLabel("<p><i>l'era degli uomini è finita </i></p><p><i>il tempo degli orchi</i></p><p><i> è giunto</i></p>",this);
    l1b=new QLabel("<p><i>I guerrieri vittoriosi prima vincono</i></p><p><i>e poi vanno in guerra, </i></p><p><i>mentre i guerrieri sconfitti </i></p><p><i>prima vanno in guerra </i></p><p><i>e poi cercano di vincere</i></p>",this);
    l1c=new QLabel("<p><i>Gli elfi sono l'unico popolo</i></p><p><i>a cui spetta di diritto</i></p><p><i>il governo del pianeta</i></p>",this);
    l1d=new QLabel("<p align = center><h3>Scegli la razza del tuo personaggio</h3></p>",this);
    nomePersonaggio=new QLineEdit("Scrivi qui il nome del tuo personaggio",this);

    gb1 = new QGroupBox();
    gb2 = new QGroupBox();
    gb3 = new QGroupBox();
    gb4 = new QGroupBox();
    h1=new QVBoxLayout();
    h2=new QVBoxLayout();
    h3=new QVBoxLayout();
    h4= new QHBoxLayout();
    gb1->setLayout(h1);
    gb2->setLayout(h2);
    gb3->setLayout(h3);
    gb4->setLayout(h4);

    layoutPrincipale->addWidget(l2);
    layoutPrincipale->addWidget(nomePersonaggio);
    layoutPrincipale->addWidget(l1d);
    layoutPrincipale->addWidget(gb4);
    h4->addWidget(gb1);
    h4->addWidget(gb2);
    h4->addWidget(gb3);

    sceltaOrco= new QPushButton("Orco",this);
    sceltaOrco->setMaximumHeight(30);
    sceltaOrco->setMaximumWidth(50);
    sceltaElfo= new QPushButton("Elfo",this);
    sceltaElfo->setMaximumHeight(30);
    sceltaElfo->setMaximumWidth(50);
    sceltaUmano= new QPushButton("Umano",this);
    sceltaUmano->setMaximumHeight(30);
    sceltaUmano->setMaximumWidth(50);

    immOrc = new QLabel(this);
    pixOrc = new QPixmap(":/img/img/orc_icon.jpg");
    immOrc->setPixmap(*pixOrc);


    immHuman = new QLabel(this);
    pixHuman = new QPixmap(":/img/img/human_icon.jpg");
    immHuman->setPixmap(*pixHuman);


    immElf = new QLabel(this);
    pixElf = new QPixmap(":/img/img/elf_icon.jpg");
    immElf->setPixmap(*pixElf);


    h1->addWidget(immOrc);
    h2->addWidget(immElf);
    h3->addWidget(immHuman);
    h1->addWidget(l1a);
    h2->addWidget(l1c);
    h3->addWidget(l1b);
    h1->addWidget(sceltaOrco);
    h2->addWidget(sceltaElfo);
    h3->addWidget(sceltaUmano);

    c1->insertImmagini(pixElf);
    c1->insertImmagini(pixHuman);
    c1->insertImmagini(pixOrc);

    c1->insertWidget(immElf);
    c1->insertWidget(immHuman);
    c1->insertWidget(immOrc);
    c1->insertWidget(l1a);
    c1->insertWidget(l1b);
    c1->insertWidget(l1c);
    c1->insertWidget(l2);
    c1->insertWidget(nomePersonaggio);
    c1->insertWidget(sceltaUmano);
    c1->insertWidget(sceltaElfo);
    c1->insertWidget(sceltaOrco);
    c1->insertWidget(gb1);
    c1->insertWidget(gb2);
    c1->insertWidget(gb3);
    c1->insertWidget(gb4);
    setLayout(layoutPrincipale);
    connect(nomePersonaggio,SIGNAL(textEdited(QString)),this,SLOT(inserimentoNome(QString)));
    connect(sceltaElfo,SIGNAL(clicked()),this,SLOT(selezionaElfo()));
    connect(sceltaUmano,SIGNAL(clicked()),this,SLOT(selezionaUmano()));
    connect(sceltaOrco,SIGNAL(clicked()),this,SLOT(selezionaOrco()));
}

creaPersonaggioWidget::~creaPersonaggioWidget(){
    c1->removeImmagini();
    c1->removeWidget();
    delete layoutPrincipale;
}

void creaPersonaggioWidget::selezionaElfo()
{
    c1->selezioneRazza(3);
    emit(selezioneRazzaCompletata());
}

void creaPersonaggioWidget::selezionaUmano()
{
    c1->selezioneRazza(2);
    emit(selezioneRazzaCompletata());
}

void creaPersonaggioWidget::selezionaOrco()
{
    c1->selezioneRazza(1);
    emit(selezioneRazzaCompletata());
}

void creaPersonaggioWidget::inserimentoNome(QString n)
{
    c1->inserimentoNome(n);
}
