#ifndef DATABASE_H
#define DATABASE_H
#include"personaggio.h"
#include"contenitoreoggetti.h"
#include <QFile>
#include <QTextStream>
#include"QTextStream"
#include"arma.h"
#include"pozione.h"
#include"oggettoprotezione.h"
#include"scudo.h"
#include<QVector>

class database
{
private:
    QVector<personaggio*> avversari;
    contenitoreOggetti mercato;
public:
    database();
    ~database();

    QVector<personaggio*> listaAvversari() const;
    contenitoreOggetti listaOggettiMercato() const;

    void load();
    void aggiungiMercanzia(oggetto*);
    void aggiungiAvversario(personaggio*);
    oggetto* ricercaOggettoNelMercato(int) const;
    personaggio* ricercaAvversario(int) const;
    void rimuoviMercanzia(int);
    void rimuoviAvversario(int);

    int getAvversariSize();
    int getMercanziaSize();

    void svuotaAvversari();
    void svuotaMercato();
};
#endif // DATABASE_H

