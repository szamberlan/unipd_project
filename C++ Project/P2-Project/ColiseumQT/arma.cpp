#include"arma.h"

arma::arma(std::string n, double p, double h, int c, double d, double pd, double sD, double dC):
oggettoDanno(n,p,h,c,d,pd,1.0), percentualeSuperficieDanno(sD), dannoCritico(dC){}

arma::~arma(){}

string arma::getTipologiaOggetto() const
{
    return oggettoDanno::getTipologiaOggetto()+ " Arma";
}

double arma::getSupDanno() const
{
    return percentualeSuperficieDanno;
}

double arma::getDannoCritico() const
{
    return dannoCritico;
}

double arma::calcoloDanno(double bonus) const
{
    if(testProbabilita(bonus))
        return getDanno()*getDannoCritico();
    else
        return getDanno()*bonus;
}

double arma::Mossa1() const {
    return calcoloDanno(getSupDanno());
}

double arma::Mossa2() const {
    return calcoloDanno(getSupDanno()*0.95)*getGrandezza();
}


double arma::Mossa3() const {
    return calcoloDanno(getSupDanno()*0.85)*(1.0+getSupDanno());
}

double arma::Mossa4() const {
    return calcoloDanno(getSupDanno()*0.70)*(getPeso()/5);
}

double arma::DannoEffettuato(int scelta)
{
    if(scelta==1)
    {
        manovrabilita=1.25;
        return Mossa1();
    }
    if(scelta==2)
    {
        manovrabilita=1.5;
        return Mossa2();
    }
    if(scelta==3)
    {
        manovrabilita=2.0;
        return Mossa3();
    }
    if(scelta==4)
    {
        manovrabilita=2.0;
        return Mossa4();
    }
        manovrabilita=1.0;
        return oggettoDanno::DannoEffettuato();
}


string arma::getNomeUtilita(int scelta) const
{
    if(getPrColpire()<=0.50)
    {
        if(getSupDanno()>=0.50)
        {

            if(scelta==1)
            {
                return "Affondo";
            }
            if(scelta==2)
            {
                return "Fendente";
            }
            if(scelta==3)
            {
                return "Diritto Tondo";
            }
            if(scelta==4)
            {
                return "Montante";
            }
            else
                return oggettoDanno::getNomeUtilita(scelta);
        }
        else
        {
            if(scelta==1)
            {
                return "Diritto Tondo";
            }
            if(scelta==2)
            {
                return "Fendente";
            }
            if(scelta==3)
            {
                return "Diritto Sgualembrato";
            }
            if(scelta==4)
            {
                return "Diritto Ridoppio";
            }
            else
                return oggettoDanno::getNomeUtilita(scelta);
        }
    }
    else
    {
        if(getSupDanno()>=0.50)
        {
            if(scelta==1)
            {
                return "Fendente Rapido";
            }
            if(scelta==2)
            {
                return "Affondo Rapido";
            }
            if(scelta==3)
            {
                return "Fendente Caricato";
            }
            if(scelta==4)
            {
                return "Affondo Caricato";
            }
            else
                return oggettoDanno::getNomeUtilita(scelta);
        }
        else
        {
            if(scelta==1)
            {
                return "Colpo Rovescio";
            }
            if(scelta==2)
            {
                return "Affondo Rapido";
            }
            if(scelta==5)
            {
                return "Affondo Mirato";
            }
            if(scelta==4)
            {
                return "Affondo Caricato";
            }
            else
                return oggettoDanno::getNomeUtilita(scelta);
        }

    }

}
string arma::getInfoUtilita(int scelta) const
{
    if(scelta==1)
    {
        std::ostringstream strs;
        strs<<"Mossa che provoca un danno maggiorato di "<<getDannoCritico()<<std::endl;
        strs<<"Danno Ottenuto : "<<getDanno()*getDannoCritico()<<std::endl;
        strs<<"Mossa che ha un probabilità di efficacia del "<<getSupDanno()<<"%"<<std::endl;
        strs<<"Se non ha efficacia il danno ottenuto è "<<getDanno()*getSupDanno()<<std::endl;
        strs<<"Mossa che provoca una perdita di Energia di ";
        strs <<getGrandezza()*getPeso()*1.25<<std::endl;
        string str = strs.str();
        return str;

    }
    if(scelta==2)
    {
        std::ostringstream strs;
        strs<<"Mossa che provoca un danno maggiorato di "<<getDannoCritico()*getGrandezza()<<std::endl;
        strs<<"Danno Ottenuto : "<<getDanno()*getDannoCritico()*getGrandezza()<<std::endl;
        strs<<"Mossa che ha un probabilità di efficacia del "<<(getSupDanno()*0.95)*100<<"%"<<std::endl;
        strs<<"Se non ha efficacia il danno ottenuto è "<<getDanno()*getSupDanno()*0.95<<std::endl;
        strs<<"Mossa che provoca una perdita di Energia di ";
        strs <<getGrandezza()*getPeso()*1.5<<std::endl;
        string str = strs.str();
        return str;
    }
    if(scelta==3)
    {
        std::ostringstream strs;
        strs<<"Mossa che provoca un danno maggiorato di "<<getDannoCritico()*(getSupDanno()+1.0)<<std::endl;
        strs<<"Danno Ottenuto : "<<getDanno()*getDannoCritico()*(getSupDanno()+1.0)<<std::endl;
        strs<<"Mossa che ha un probabilità di efficacia del "<<(getSupDanno()*0.85)*100<<"%"<<std::endl;
        strs<<"Se non ha efficacia il danno ottenuto è "<<getDanno()*getSupDanno()*0.85<<std::endl;
        strs<<"Mossa che provoca una perdita di Energia di ";
        strs <<getGrandezza()*getPeso()*2.0<<std::endl;
        string str = strs.str();
        return str;
    }
    if(scelta==4)
    {
        std::ostringstream strs;
        strs<<"Mossa che provoca un danno maggiorato di "<<getDannoCritico()*(getPeso()/5)<<std::endl;
        strs<<"Danno Ottenuto : "<<getDanno()*getDannoCritico()*(getPeso()/5)<<std::endl;
        strs<<"Mossa che ha un probabilità di efficacia del "<<(getSupDanno()*0.70)*100<<"%"<<std::endl;
        strs<<"Se non ha efficacia il danno ottenuto è "<<getDanno()*getSupDanno()*0.70<<std::endl;
        strs<<"Mossa che provoca una perdita di Energia di ";
        strs <<getGrandezza()*getPeso()*2.0<<std::endl;
        string str = strs.str();
        return str;
    }
    else
    {
            std::ostringstream strs;
            strs<<oggettoDanno::getInfoUtilita();
            strs<<"Effettuare Danno Critico x"<<getDannoCritico()<<std::endl;
            strs <<"Danno critico con la probabilità : "<<getSupDanno()*100<<" %"<<std::endl;
            std::string str = strs.str();
            return str;
    }
}
