#ifndef CONTENITOREOGGETTI
#define CONTENITOREOGGETTI
#include<iostream>
#include"oggetto.h"
using std::ostream;

class contenitoreOggetti {
    friend class iteratore;

private:
    class nodo; //dichiarazione incompleta di nodo

    class smartp{ //classe smartp
    public:
        nodo*punt;
        smartp(nodo*p=0);
        smartp(const smartp&);
        ~smartp();
        smartp& operator=(const smartp&);
        nodo& operator*() const;
        nodo* operator->() const;
        bool operator==(const smartp&) const;
        bool operator!=(const smartp&) const;
    }; //fine smartp

    class nodo{ // classe nodo
    public:
        nodo();
        nodo(oggetto*, const smartp&);
        ~nodo();
        oggetto*info_oggetto;
        smartp next;
        int riferimenti;
    };//fine nodo

    // campi dati
    smartp first;
public:
    class iteratore{
        friend class contenitoreOggetti;
    private:
        contenitoreOggetti::nodo* puntIt;
    public:
        bool operator==(const iteratore&) const;
        bool operator!=(const iteratore&) const;
        iteratore& operator++();
        iteratore operator++(int);
    };
    int size() const;
    bool Vuota() const;
    void Aggiungi_Oggetto(oggetto*);
    void Togli_Oggetto(const oggetto*);
    oggetto*Estrai_Una();
    oggetto*Estrai_Oggetto(int);
    bool cercaOggetto(const oggetto*) const;
    int cercaPosizioneOggetto(const oggetto*) const;
    oggetto*ricavoOggetto(const oggetto*);
    void Togli_PuntatoriNulli();
    friend ostream& operator<<(ostream&, const contenitoreOggetti&);


    // metodi che usano iteratore
    iteratore begin() const;
    iteratore end() const;
    oggetto*& operator[](int) const;
};

#endif // CONTENITOREOGGETTI

