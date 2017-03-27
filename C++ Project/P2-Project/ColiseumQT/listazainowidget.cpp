#include"listazainowidget.h"

listaZainoWidget::listaZainoWidget(controller *c, QWidget *parent): listaObject(c,parent)
{
    titoloPrincip->setText("<p align = center><h1>ZAINO PERSONAGGIO</h1></p>");
    titoloDati->setText("<p align = center><b>Dati</b></p><p>Informazioni sull'oggetto selezionato...</p> ");
    titolosoldi->setText("Soldi : ");
    sottotitolo->setText("<p align = center><b>Zaino</b></p><p>Scegli cosa equipaggiare...o cosa vendere</p> ");
    pulsante1->setText("Vendi Oggetto");
    pulsante2->setText("Vai al Mercato");
    pulsante3->setText("Vai al Menu");
    pulsanteEquipaggiamento = new QPushButton("Equipaggia Oggetto",this);
    vboxM1->addWidget(pulsanteEquipaggiamento);
    c1->insertFrontWidget(pulsanteEquipaggiamento);
    connect(pulsanteEquipaggiamento,SIGNAL(clicked(bool)),this,SLOT(equipaggiaOggetto()));
    connect(this,SIGNAL(aggiornamento()),this,SLOT(visualizzaElenco()));
}

listaZainoWidget::~listaZainoWidget(){
    c1->emptiesZainoWidget();
}

void listaZainoWidget::equipaggiaOggetto()
{
    if(c1->findOggettoZaino())
    {

        if(c1->equipaggiaOggettto(c1->getInfoOggettoCercatoZaino()))
        {
            c1->emptiesZainoWidget();
            datiOggetto->setText("Equipaggiato");
            emit(aggiornamento());
        }
    }
    else
        QMessageBox::warning(this,"ERRORE SELEZIONE","Seleziona l'oggetto da equipaggiare");
}

void listaZainoWidget::visualizzaElenco()
{
    c1->emptiesZainoWidget();
    QVector<QString *> m = c1->stampaZaino();
    for(int i=0; i<m.size(); i++)
    {
        QRadioButton* kButton= new QRadioButton(*m[i]);
        layoutLista->addWidget(kButton);
        c1->fillZainoWidget(kButton);
        connect(kButton,SIGNAL(clicked(bool)),this,SLOT(mostraInformazioni()));
    }
    setSoldi();
}


void listaZainoWidget::clickedPulsante1()
{
    if(c1->findOggettoZaino())
    {
        if(c1->vendiOggetto(c1->getInfoOggettoCercatoZaino()))
        {
            c1->emptiesZainoWidget();
            datiOggetto->setText("Venduto al Mercante");
            emit(aggiornamento());
        }
    }
    else
        QMessageBox::warning(this,"ERRORE SELEZIONE","Seleziona l'oggetto da vendere");
}

void listaZainoWidget::mostraInformazioni()
{
    if(c1->findOggettoZaino())
    {
        datiOggetto->setText(c1->stampaCaratteristicheZaino(c1->getInfoOggettoCercatoZaino()));
    }
}
