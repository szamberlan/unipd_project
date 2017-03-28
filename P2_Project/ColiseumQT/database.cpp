#include"database.h"
#include <iostream>
using namespace std;

database::database(){}

database::~database()
{
    for(int i=0; i<avversari.size(); ++i)
    {
        delete avversari[i];
    }
}

void database::load()
{
    QFile fileDatabase;
    fileDatabase.setFileName(":/db/database.txt");
    fileDatabase.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&fileDatabase);
    QString x;
        x = stream.readLine();
        while(!stream.atEnd())
        {
            if(x=="Avversario")
            {
                string nomeAvversario = stream.readLine().toStdString();
                double attacco = stream.readLine().toDouble();
                double difesa = stream.readLine().toDouble();
                double vita = stream.readLine().toDouble();
                double energia = stream.readLine().toDouble();
                double danno = stream.readLine().toDouble();
                double protezione = stream.readLine().toDouble();
                int soldi = stream.readLine().toInt();
                double bonus = stream.readLine().toDouble();
                personaggio* p= new personaggio(nomeAvversario,attacco,difesa,vita,energia,danno,protezione,soldi,bonus);
                avversari.push_back(p);
                string nome;
                double peso;
                double altezza;
                int costo;
                x = stream.readLine();
                while(x!="Avversario"&&x!="Mercato"&&!stream.atEnd()&&x!="end")
                {
                    if(x=="Arma")
                    {
                        nome = stream.readLine().toStdString();
                        peso = stream.readLine().toDouble();
                        altezza = stream.readLine().toDouble();
                        costo = stream.readLine().toInt();
                        double danno = stream.readLine().toDouble();
                        double prDanno = stream.readLine().toDouble();
                        double sDanno = stream.readLine().toDouble();
                        double dCritico = stream.readLine().toDouble();
                        arma* a1 = new arma(nome,peso,altezza,costo,danno,prDanno,sDanno,dCritico);
                        p->equipaggiaArma(a1);
                    }
                    else
                    if(x=="Armatura")
                    {
                        nome = stream.readLine().toStdString();
                        peso = stream.readLine().toDouble();
                        altezza = stream.readLine().toDouble();
                        costo = stream.readLine().toInt();
                        double protezione = stream.readLine().toDouble();
                        oggettoProtezione* oP = new oggettoProtezione(nome,peso,altezza, costo, protezione);
                        p->equipaggiaArmatura(oP);

                    }
                    else
                    if(x=="Scudo")
                    {
                        nome = stream.readLine().toStdString();
                        peso = stream.readLine().toDouble();
                        altezza = stream.readLine().toDouble();
                        costo = stream.readLine().toInt();
                        double protezione = stream.readLine().toDouble();
                        double prParata = stream.readLine().toDouble();
                        scudo* sc = new scudo(nome,peso,altezza, costo, protezione, prParata);
                        p->equipaggiaScudo(sc);

                    }
                    else
                    if(x=="Pozione")
                    {
                        nome = stream.readLine().toStdString();
                        costo = stream.readLine().toDouble();
                        double aiuto = stream.readLine().toDouble();
                        int scelta = stream.readLine().toInt();
                        pozione* po = new pozione(nome,costo,aiuto,scelta);
                        if(po->getScelta()==1)
                            p->equipaggiaPozioneVita(po);
                        if(po->getScelta()==2)
                            p->equipaggiaPozioneEnergia(po);

                    }
                    x = stream.readLine();
                }
            }else
            if(x=="Mercato")
            {
                x= stream.readLine();
                while(x!="end")
                {
                    string nome;
                    double peso;
                    double altezza;
                    int costo;
                    if(x=="Arma")
                    {

                        nome = stream.readLine().toStdString();
                        peso = stream.readLine().toDouble();
                        altezza = stream.readLine().toDouble();
                        costo = stream.readLine().toInt();
                        double danno = stream.readLine().toDouble();
                        double prDanno = stream.readLine().toDouble();
                        double sDanno = stream.readLine().toDouble();
                        double dCritico = stream.readLine().toDouble();
                        arma* a1 = new arma(nome,peso,altezza,costo,danno,prDanno,sDanno,dCritico);
                        mercato.Aggiungi_Oggetto(a1);
                    }
                    else
                    if(x=="Armatura")
                    {
                        nome = stream.readLine().toStdString();
                        peso = stream.readLine().toDouble();
                        altezza = stream.readLine().toDouble();
                        costo = stream.readLine().toInt();
                        double protezione = stream.readLine().toDouble();
                        oggettoProtezione* oP = new oggettoProtezione(nome,peso,altezza, costo, protezione);
                        mercato.Aggiungi_Oggetto(oP);

                    }
                    else
                    if(x=="Scudo")
                    {
                        nome = stream.readLine().toStdString();
                        peso = stream.readLine().toDouble();
                        altezza = stream.readLine().toDouble();
                        costo = stream.readLine().toInt();
                        double protezione = stream.readLine().toDouble();
                        double prParata = stream.readLine().toDouble();
                        scudo* sc = new scudo(nome,peso,altezza, costo, protezione, prParata);
                        mercato.Aggiungi_Oggetto(sc);
                    }else
                    if(x=="Pozione")
                    {
                        nome = stream.readLine().toStdString();
                        costo = stream.readLine().toDouble();
                        double aiuto = stream.readLine().toDouble();
                        int scelta = stream.readLine().toInt();
                        pozione* po = new pozione(nome,costo,aiuto,scelta);
                        mercato.Aggiungi_Oggetto(po);
                    }
                    else
                    {
                        cerr << "Tipologia oggetto non corretta" << endl;
                    }
                    x = stream.readLine();
                }
            }
        }
        fileDatabase.close();
}


QVector<personaggio*> database::listaAvversari() const
{
    return avversari;
}
contenitoreOggetti database::listaOggettiMercato() const
{
    return mercato;
}

void database::aggiungiMercanzia(oggetto*o)
{
    mercato.Aggiungi_Oggetto(o);
}

void database::aggiungiAvversario(personaggio*a)
{
    avversari.push_back(a);
}

oggetto *database::ricercaOggettoNelMercato(int i) const
{
    return mercato[i];
}

personaggio *database::ricercaAvversario(int i) const
{
    return avversari[i];
}

void database::rimuoviMercanzia(int n)
{
    if(n<mercato.size())
    {
        mercato[n]=0;
        mercato.Togli_Oggetto(mercato[n]);
    }
}

int database::getAvversariSize()
{
    return avversari.size();
}

int database::getMercanziaSize()
{
    return mercato.size();
}

void database::svuotaAvversari()
{
    for(int i=0; i<avversari.size(); ++i)
    {
        delete avversari[i];
    }
}

void database::svuotaMercato()
{
    for(int i=0; i<mercato.size(); ++i)
    {
        delete mercato[i];
    }
}
