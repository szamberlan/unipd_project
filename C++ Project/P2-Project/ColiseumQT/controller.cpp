#include"controller.h"
#include<sstream>


controller::controller(arena *a) :
    a1(a), sceltaClasse(0), sceltaAbilita(0){}

controller::~controller()
{
    if(a1)
        delete a1;
    removeLabel();
    removeImmagini();
    emptiesZainoWidget();
    emptiesMercaneWidget();
    removeWidget();
}

void controller::insertWidget(QWidget *qw)
{
    if(qw)
    {
        contenitorQWidget.push_back(qw);
    }
}

void controller::removeWidget()
{
    if(!contenitorQWidget.empty())
    {
        for(int i=0; i<contenitorQWidget.size(); i++)
        {
            if(contenitorQWidget[i]->layout())
            {
                delete contenitorQWidget[i]->layout();
            }
            delete contenitorQWidget[i];
        }
        contenitorQWidget.clear();
    }
}

void controller::insertFrontWidget(QWidget*qw)
{
    if(qw)
    {
        contenitorQWidget.push_front(qw);
    }
}

void controller::removeLastWidget()
{
    if(!contenitorQWidget.empty())
    {
        QVector<QWidget*>::iterator it;
        it=contenitorQWidget.end();
        it--;
        delete*it;
        contenitorQWidget.erase(it);
    }
}

void controller::insertLabel(QLabel*lab)
{
    if(lab)
    {
        contenitoreQLabel.push_back(lab);
    }
}

void controller::removeLabel()
{
    if(!contenitoreQLabel.empty())
    {
        QVector<QLabel*>::iterator it;
        it=contenitoreQLabel.begin();
        while(it!=contenitoreQLabel.end())
        {
            delete *it;
            ++it;
        }
        contenitoreQLabel.clear();
    }
}


void controller::insertImmagini(QPaintDevice*imm)
{
    if(imm)
    {
        contenitorImmagini.push_back(imm);
    }
}

void controller::removeImmagini()
{
    if(!contenitorImmagini.empty())
    {
        QVector<QPaintDevice*>::iterator it;
        it=contenitorImmagini.begin();
        while(it!=contenitorImmagini.end())
        {
            delete *it;
            ++it;
        }
        contenitorImmagini.clear();
    }
}

QWidget* controller::ricercaContenitorWidget(int i) const
{
    return contenitorQWidget[i];
}

QWidget *controller::ricercaContenitorWidgetByName(QString name)const
{
    bool find =false;
    int trovato = 0;
    for(int i=0; i<contenitorQWidget.size()&&!find; i++)
    {
        if((contenitorQWidget[i]->objectName())==name)
        {
            find= true;
            trovato=i;
        }
    }
    if(find)
    {
        return contenitorQWidget[trovato];
    }
    else
        return 0;
}

int controller::ricercaIndexContenitorWidgetByName(QString name)const
{
    bool find = false;
    int trovato = 0;
    for(int i=0; i<contenitorQWidget.size()&&!find; i++)
    {
        if((contenitorQWidget[i]->objectName())==name)
        {
            find= true;
            trovato=i;
        }
    }
    if(find)
        return trovato;
    else
        return -1;
}

QLabel*controller::ricercaContenitorQLabel(int i)const
{
    return contenitoreQLabel[i];
}

void controller::sostituisciWidget(QWidget*qw, int ind)
{
    delete contenitorQWidget[ind];
    contenitorQWidget[ind]=qw;
}

void controller::selezioneRazza(int scelta)
{
    sceltaRazza=scelta;
}

void controller::selezioneClasse(int scelta)
{
    sceltaClasse=scelta;
}

void controller::inserimentoNome(QString n)
{
    sceltaNome=n;
}

int controller::getRazzaSelezionata() const
{
    return sceltaRazza;
}

int controller::getClasseSelezionata() const
{
    return sceltaClasse;
}

std::string controller::getNomeSelezionato() const
{
    std::string nome = sceltaNome.toStdString();
    return nome;
}

void controller::selezioneAbilita(int abilita)
{
    sceltaAbilita=abilita;
}

int controller::getAbilitaSelezionata() const
{
    return sceltaAbilita+1;
}
/*La scelta di mettere dei numeri fissi per quanto riguarda
 * la creazione dei personaggi si basa sul fatto di rendere il gioco
 * più giocabile e quindi più equilibrato*/
void controller::creaPersonaggio()
{
    if(sceltaRazza==1)
    {
        if(sceltaClasse==1)
                a1->creaPersonaggio(getNomeSelezionato(),0.80,0.05,225,200,getAbilitaSelezionata(),0.15);

        if(sceltaClasse==2)
                a1->creaPersonaggio(getNomeSelezionato(),0.75,0.10,200,225,getAbilitaSelezionata(),0.15);
    }
    if(sceltaRazza==2)
    {
        if(sceltaClasse==1)
                a1->creaPersonaggio(getNomeSelezionato(),0.60,0.25,215,210,getAbilitaSelezionata(),0.15);
        if(sceltaClasse==2)
                a1->creaPersonaggio(getNomeSelezionato(),0.65,0.20,210,215,getAbilitaSelezionata(),0.15);
    }
    if(sceltaRazza==3)
    {
        if(sceltaClasse==1)
                a1->creaPersonaggio(getNomeSelezionato(),0.50,0.35,220,205,getAbilitaSelezionata(),0.15);
        if(sceltaClasse==2)
                a1->creaPersonaggio(getNomeSelezionato(),0.50,0.35,205,220,getAbilitaSelezionata(),0.15);
    }
}

QString controller::stampaRobe() const
{
    QString s = QString::number(a1->getLivello());
    QString risultati =QString::fromStdString("Avversari Sconfitti : ");
    return risultati+s;
}
QVector<QString *> controller::stampaMercanzia() const
{
    QVector<QString*> mercanzie ;
    QString nomeOggetto;
    for(int i=0; i<a1->getSizeMercato(); i++)
    {
        nomeOggetto =QString::fromStdString(a1->ricercaNomeOggettoNelMercato(i));
        mercanzie.push_back(new QString(nomeOggetto));
    }
    return mercanzie;
}

QVector<QString*> controller::stampaZaino() const
{
    QVector<QString*>  zainoOggetti;
    QString nomeOggetto;
    for(int i=0; i<a1->getSizeZainoPersonaggio(); i++)
    {
        nomeOggetto =QString::fromStdString(a1->ricercaNomeOggettoNelloZaino(i));
        zainoOggetti.push_back(new QString(nomeOggetto));
    }
    return zainoOggetti;
}

QString controller::stampaCaratteristicheMercanzia(int numb) const
{
    std::ostringstream a;
    a<<*(ricercaMercato(numb));
    std::string B = a.str();
    QString out = QString::fromStdString(B);
    return out;
}

QString controller::stampaCaratteristicheZaino(int numb) const
{
    std::ostringstream a;
    a<<*(ricercaZaino(numb));
    std::string B = a.str();
    QString out = QString::fromStdString(B);
    return out;
}

QString controller::stampaCaratteristicheEquipaggiamento(int numb) const
{
    std::ostringstream a;
    a<<*(ricercaEquipaggiamento(numb));
    std::string B = a.str();
    QString out = QString::fromStdString(B);
    return out;
}

void controller::iniziaCombattimento()
{
    a1->iniziaCombattimento();
}

void controller::combatti(int i)
{
    a1->combatti(i);
}

double controller::getVita(bool i) const
{
    if(i)
    {
        return (a1->getGiocatore()->getVitaAttuale()/a1->getGiocatore()->getVitaMax())*100;
    }
    else
    {
            return (a1->getAvversarioAttuale()->getVitaAttuale()/a1->getAvversarioAttuale()->getVitaMax())*100;
    }
}

double controller::getEnergia(bool i) const
{
    if(i)
    {
        return (a1->getGiocatore()->getEnergiaAttuale()/a1->getGiocatore()->getEnergiaMax())*100;
    }
    else
    {
        return (a1->getAvversarioAttuale()->getEnergiaAttuale()/a1->getAvversarioAttuale()->getEnergiaMax())*100;
    }
}

bool controller::vittoria() const
{
    return a1->vittoria();
}

bool controller::sconfitta() const
{
    return a1->sconfitta();
}

void controller::fineCombattimento(int i)
{
    a1->fineCombattimento(i);
}


QString controller::getNomeMosseArma(int i) const
{
    if(a1->getGiocatore()->getArma())
        return QString::fromStdString(a1->getGiocatore()->getArma()->getNomeUtilita(i));
    else
        return "Attacco Normale";
}

QString controller::getInfoMosseArma(int i) const
{
    if(a1->getGiocatore()->getArma())
        return QString::fromStdString(a1->getGiocatore()->getArma()->getInfoUtilita(i));
    else
        return "Danno Normale del Giocatore senza l'utilizzo di armi : " + QString::number(a1->getGiocatore()->getDanno());
}

bool controller::inCombattimento() const
{
    return a1->inCombattimento();
}

void controller::fillZainoWidget(QAbstractButton* a)
{
    if(a)
    {
        zainoQWidget.push_back(a);
    }
}

void controller::fillMercanteWidget(QAbstractButton *a)
{
    if(a)
    {
        mercanteQWidget.push_back(a);
    }
}

void controller::emptiesZainoWidget()
{

    if(!zainoQWidget.empty())
    {
        QVector<QAbstractButton*>::iterator it;
        it=zainoQWidget.begin();
        while(it!=zainoQWidget.end())
        {
            delete *it;
            ++it;
        }
        zainoQWidget.clear();
    }
}

void controller::emptiesMercaneWidget()
{
    if(!mercanteQWidget.empty())
    {
        QVector<QAbstractButton*>::iterator it;
        it=mercanteQWidget.begin();
        while(it!=mercanteQWidget.end())
        {
            delete *it;
            ++it;
        }
        mercanteQWidget.clear();
    }
}


QAbstractButton* controller::ricercaMercanteWidget(int i) const
{
    return mercanteQWidget[i];
}

QAbstractButton* controller::ricercaZainoWidget(int i) const
{
    return zainoQWidget[i];
}

int controller::getSoldiGiocatore() const
{
    return a1->getGiocatore()->getSoldi();
}


oggetto* controller::ricercaMercato(int i)const
{
    return a1->ricercaOggettoNelMercato(i);
}

oggetto* controller::ricercaZaino(int i)const
{
    return a1->ricercaOggettoNelloZaino(i);
}

const oggetto* controller::ricercaEquipaggiamento(int i) const
{
    return a1->ricercaOggettoNellEquipaggiamento(i);
}

bool controller::compraOggetto(int i)
{
    return a1->compraOggetto(i);
}

bool controller::vendiOggetto(int i)
{
    return a1->vendiOggettobyId(i);
}

bool controller::equipaggiaOggettto(int i)
{
    if(ricercaZaino(i)==0)
        return false;
    if(ricercaZaino(i)->getDanno()>0)
    {
        a1->opzioniZaino(1,i);
        return true;
    }
    else
        if(ricercaZaino(i)->getProtezione()>0)
            if(ricercaZaino(i)->Parata(1,false))
            {
                a1->opzioniZaino(3,i);
                return true;
            }
            else
            {
                a1->opzioniZaino(2,i);
                return true;
            }
        else
            if(ricercaZaino(i)->getAiuto()>0)
            {
                if(ricercaZaino(i)->AiutoCaratteristiche(1,false))
                {
                    a1->opzioniZaino(4,i);
                    return true;
                }
                if(ricercaZaino(i)->AiutoCaratteristiche(2,false))
                {
                    a1->opzioniZaino(5,i);
                    return true;
                }
            }
    return false;
}

void controller::spostaOggetto(int i)
{
    a1->opzioniEquipaggiamento(i);
}

QString controller::stampaCaratteristicheAvversario() const
{
    std::ostringstream a;
    a<<(a1->getAvversarioAttuale()->getInfoMinime());
    std::string B = a.str();
    QString out = QString::fromStdString(B);
    return out;
}

QString controller::stampaCaratteristichePersonaggio()const
{
    std::ostringstream a;
    a<<*(a1->getGiocatore());
    std::string B = a.str();
    QString out = QString::fromStdString(B);
    return out;
}

QString controller::stampaAbilitaPersonaggio()const
{
    QString out = QString::fromStdString(a1->getGiocatore()->getInfoAbilita());
    return out;
}

bool controller::presenzaArma() const
{
    if(a1->getGiocatore()->getArma())
        return true;
    else
        return false;
}

int controller::getLivelloArena() const
{
    return a1->getLivello();
}

int controller::nemiciRimasti() const
{
    return a1->avversariRimasti();
}

bool controller::vittoriaArena() const
{
    return a1->vintoArena();
}


QString controller::getNomeClasse1Disponibile() const
{
    if(getRazzaSelezionata()==1)
        return "Barbaro";
    if(getRazzaSelezionata()==3)
        return "Assassino";
    if(getRazzaSelezionata()==2)
        return "Cavaliere";
    return "";
}

QString controller::getNomeClasse2Disponibile() const
{
    if(getRazzaSelezionata()==1)
        return "Guerriero";
    if(getRazzaSelezionata()==3)
        return "Esploratore";
    if(getRazzaSelezionata()==2)
        return "Furfante";
    return "";
}


QString controller::getPathImageClasse1Disponibile() const
{
    if(getRazzaSelezionata()==1)
        return ":/img/img/barbaro_icon.jpg";
    if(getRazzaSelezionata()==3)
        return ":/img/img/assassino_icon.jpg";
    if(getRazzaSelezionata()==2)
        return ":/img/img/cavaliere_icon.jpg";
    return "";
}

QString controller::getPathImageClasse2Disponibile() const
{
    if(getRazzaSelezionata()==1)
        return ":/img/img/guerriero_icon.jpg";
    if(getRazzaSelezionata()==3)
        return ":/img/img/esploratore_icon.jpg";
    if(getRazzaSelezionata()==2)
        return ":/img/img/furfante_icon.jpg";
    return "";
}



bool controller::findOggettoZaino()const
{
    bool tr = false;
    for(int i=0; i<a1->getSizeZainoPersonaggio()&&!tr; i++)
    {
        if(ricercaZainoWidget(i)->isChecked())
        {
            tr= true;
        }
    }
    return tr;
}
int controller::getInfoOggettoCercatoZaino()const
{
    int numb=0;
    bool tr = false;
    if(findOggettoZaino())
    {
        for(int i=0; i<a1->getSizeZainoPersonaggio()&&!tr; i++)
        {
            if(ricercaZainoWidget(i)->isChecked())
            {
                numb= i;
                tr=true;
            }
        }
    }
    return numb;
}

bool controller::findOggettoMercato()const
{
    bool tr = false;
    for(int i=0; i<a1->getSizeMercato()&&!tr; i++)
    {
        if(ricercaMercanteWidget(i)->isChecked())
        {

            tr= true;
        }
    }
    return tr;
}

int controller::getInfoOggettoCercatoMercato()const
{
    bool tr = false;
    int numb=0;
    if(findOggettoMercato())
    {
        for(int i=0; i<a1->getSizeMercato()&&!tr; i++)
        {
            if(ricercaMercanteWidget(i)->isChecked())
            {
                numb= i;
                tr= true;
            }
        }
    }
    return numb;
}

void controller::aggiornaMosse(QStringList*sl)
{
    sl->clear();
    if(presenzaArma())
    {
        sl->push_back(QString("Info "+getNomeMosseArma(1)));
        sl->push_back(QString("Info "+getNomeMosseArma(2)));
        sl->push_back(QString("Info "+getNomeMosseArma(3)));
        sl->push_back(QString("Info "+getNomeMosseArma(4)));
    }
    else
    {
        sl->push_back(QString("Info "+getNomeMosseArma(1)));
    }
}

