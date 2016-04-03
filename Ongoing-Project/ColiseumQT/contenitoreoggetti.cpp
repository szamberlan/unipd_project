#include"contenitoreoggetti.h"
using std::ostream;
using std::endl;

contenitoreOggetti::smartp::smartp(nodo *p):punt(p)
{ if (punt) punt->riferimenti++; }

contenitoreOggetti::smartp::smartp(const smartp &s):punt(s.punt)
{ if(punt) punt->riferimenti++; }

contenitoreOggetti::smartp::~smartp(){
    if(punt)
    {
        punt->riferimenti--;
        if(punt->riferimenti==0)
            delete punt;
    }
}

contenitoreOggetti::smartp& contenitoreOggetti::smartp::operator =(const smartp& s)
{
    if(this != &s)
    {
        nodo*t=punt;
        punt=s.punt;
        if(punt)
            punt->riferimenti++;
        if(t)
        {
            t->riferimenti--;
            if(t->riferimenti==0)
                delete t;
        }
    }
    return *this;
}

contenitoreOggetti::nodo& contenitoreOggetti::smartp::operator *() const
{
    return *punt;
}

contenitoreOggetti::nodo* contenitoreOggetti::smartp::operator ->() const
{
    return punt;
}

bool contenitoreOggetti::smartp::operator ==(const smartp& p) const
{
    return punt == p.punt;
}

bool contenitoreOggetti::smartp::operator !=(const smartp& p) const
{
    return punt != p.punt;
}

// Metodi di Nodo

contenitoreOggetti::nodo::nodo():riferimenti(0){}

contenitoreOggetti::nodo::nodo(oggetto *o, const smartp & s): info_oggetto(o), next(s) ,riferimenti(0){}

contenitoreOggetti::nodo::~nodo()
{
    if(info_oggetto)
        delete info_oggetto;
}

// Metodi di Iteratore

bool contenitoreOggetti::iteratore::operator ==(const iteratore& i) const { return puntIt==i.puntIt; }

bool contenitoreOggetti::iteratore::operator !=(const iteratore& i) const { return puntIt!=i.puntIt; }

contenitoreOggetti::iteratore& contenitoreOggetti::iteratore::operator ++()
{
    if(puntIt)
        puntIt=puntIt->next.punt;
    return *this;
}

contenitoreOggetti::iteratore contenitoreOggetti::iteratore::operator ++(int){
    iteratore aux = *this;
    if(puntIt) puntIt = puntIt->next.punt;
    return aux;
}

// Metodi di ContenitoreOggetti

bool contenitoreOggetti::Vuota() const { return first ==0; }

int contenitoreOggetti::size() const
{
    int count=1;
    for(iteratore aux= begin(); aux!=end(); aux++)
        count++;
    return count;

}

void contenitoreOggetti::Aggiungi_Oggetto(oggetto *o)
{
    first=new nodo(o,first);
}

oggetto* contenitoreOggetti::Estrai_Una()
{
    oggetto* aux = first->info_oggetto;
    first = first->next;
    return aux;
}

void contenitoreOggetti::Togli_Oggetto(const oggetto * o)
{
    smartp p=first, prec, q;
    smartp original=first;
    first=0;
    while(p!=0 &&(!(p->info_oggetto==o)))
    {
        q=new nodo(p->info_oggetto,p->next);
        p->info_oggetto=0;
        if( prec == 0 )
            first=q;
        else
            prec->next = q;
        prec=q;
        p=p->next;
    }
    if(prec==0)
        first=p->next;
    else
        prec->next = p->next;

}

void contenitoreOggetti::Togli_PuntatoriNulli()
{
    smartp p=first, prec, q;
    smartp original=first;
    first=0;

    while(p!=0 &&(!(p->info_oggetto==0)))
    {
        q=new nodo(p->info_oggetto,p->next);
        if( prec == 0 )
            first=q;
        else
            prec->next = q;
        prec=q;
        p=p->next;
    }
    if(p==0)
    {
        first = original;
    }
    else
    {
        if(prec==0)
            first=p->next;
        else
            prec->next = p->next;
    }
}

bool contenitoreOggetti::cercaOggetto(const oggetto*o) const
{
    iteratore i;
    for(i=this->begin(); (i.puntIt->info_oggetto!=o)&&(i.puntIt!=0); i++){}
    if(i.puntIt==0)
        return false;
    else
        return true;

}

int contenitoreOggetti::cercaPosizioneOggetto(const oggetto *o) const
{
    iteratore i;
    int count=0;
    for(i=this->begin(); (i.puntIt->info_oggetto!=o)&&(i.puntIt!=0); i++){count++;}
        return count;
}

oggetto*contenitoreOggetti::ricavoOggetto(const oggetto *o)
{
    if(cercaOggetto(o))
    {
        return Estrai_Oggetto(cercaPosizioneOggetto(o));
    }
    else
        return 0;
}

oggetto* contenitoreOggetti::Estrai_Oggetto(int pos)
{
    oggetto*o=this->operator [](pos);
    this->operator [](pos)=0;
    Togli_Oggetto(0);
    return o;
}
ostream& operator<<(ostream &os, const contenitoreOggetti &b)
{
    if(b.Vuota()) os<<" Contenitore Vuoto "<<endl;
    else
    {
        contenitoreOggetti::smartp p=b.first; // amicizia
        int i = 1;
        while(p!=0)
        {
            if(p->info_oggetto)
            {
                os<<i++<<") "<<p->info_oggetto->getNome()<<endl;
                p=p->next;
            }
            else
            {
                os<<i++<<") "<<" Vuoto "<<endl;
                p=p->next;
            }
        }
    }
    return os;
}

contenitoreOggetti::iteratore contenitoreOggetti::begin() const
{
    iteratore aux;
    aux.puntIt = first.punt;
    return aux;
}

contenitoreOggetti::iteratore contenitoreOggetti::end() const
{
    iteratore aux;
    aux.puntIt = 0;
    return aux;
}

oggetto *& contenitoreOggetti::operator [](int cerca) const {
    if(cerca<size())
    {
        iteratore it= begin();
        for(int i=0; i<cerca; i++)
        {
            it++;
        }
        return(it.puntIt)->info_oggetto;
    }
    else
        return begin().puntIt->info_oggetto;
}

void contenitoreOggetti::stampaCaratteristicheOggetti() const
{
    if(Vuota())
        std::cout<<" Contenitore Vuoto "<<std::endl;
    else
    {
        smartp p=first;
        int i = 1;
        while(p!=0)
        {
            if(p->info_oggetto)
            {
                std::cout<<"Posizione "<<i++<<") "<<std::endl;
                p->info_oggetto->stampaCaratteristiche();
                std::cout<<"////////////"<<std::endl;
                p=p->next;
            }
            else
            {
                std::cout<<"Posizione "<<i++<<") "<<std::endl;
                std::cout<<"Vuoto"<<std::endl;
                std::cout<<"////////////"<<std::endl;
                p=p->next;
            }
        }
    }
}
