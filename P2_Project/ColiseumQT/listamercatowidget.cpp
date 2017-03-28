#include"listamercatowidget.h"

listaMercatoWidget::listaMercatoWidget(controller *c, QWidget *parent): listaObject(c,parent)
{
    titoloPrincip->setText("<p align = center><h1>MERCATO OGGETTI</h1></p>");
    titoloDati->setText("<p align = center><b>Dati</b></p><p>Informazioni sull'oggetto selezionato...</p> ");
    titolosoldi->setText("Soldi : ");
    sottotitolo->setText("<p align = center><b>Mercante</b></p><p>Scegli cosa comprare...</p> ");
    pulsante1->setText("Compra Oggetto");
    pulsante2->setText("Vai allo Zaino");
    pulsante3->setText("Vai al Menu");
    connect(this,SIGNAL(aggiornamento()),this,SLOT(visualizzaElenco()));
}

listaMercatoWidget::~listaMercatoWidget(){
    c1->emptiesMercaneWidget();
}

void listaMercatoWidget::clickedPulsante1()
{
    if(c1->findOggettoMercato())
    {
        if(c1->compraOggetto(c1->getInfoOggettoCercatoMercato()))
        {
            c1->emptiesMercaneWidget();
            datiOggetto->setText("Comprato e inviato allo Zaino");
            emit(aggiornamento());
        }
        else
            QMessageBox::warning(this,"ERRORE ACQUISTO","Hai troppi pochi soldi per poter comprare questo oggetto");
    }
    else
        QMessageBox::warning(this,"ERRORE SELEZIONE","Seleziona l'oggetto da comprare");
}

void listaMercatoWidget::visualizzaElenco()
{
    c1->emptiesMercaneWidget();
    QVector<QString *> m = c1->stampaMercanzia();
    for(int i=0; i<m.size(); i++)
    {
        QRadioButton* aButton= new QRadioButton(*m[i]);
        layoutLista->addWidget(aButton);
        c1->fillMercanteWidget(aButton);
        connect(aButton,SIGNAL(clicked(bool)),this,SLOT(mostraInformazioni()));
    }
    setSoldi();
}

void listaMercatoWidget::mostraInformazioni()
{
    if(c1->findOggettoMercato())
    {
        datiOggetto->setText(c1->stampaCaratteristicheMercanzia(c1->getInfoOggettoCercatoMercato()));
    }
}

