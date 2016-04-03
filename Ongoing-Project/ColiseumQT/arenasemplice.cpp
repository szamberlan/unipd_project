#include"arenasemplice.h"

arenaSemplice::arenaSemplice(personaggio *p, int lvl):
arena(p,lvl), vittoriaArena(false)
{
    personaggio*p1=new assassino("Brazz ",200,200,0,10,0.10,0.10);
    personaggio*p2=new guerriero("Gianluca ",200,200,0,50,0.05,0.05);
    personaggio*p3=new esploratore("GiulioS ",200,200,0,10,0.15,0.05);
    personaggio*p4=new barbaro("GiulioA ",200,200,0,50,0.05,0.05);
    personaggio*p5=new furfante("Daniel ",200,200,0,10,0.10,0.10);
    personaggio*p6=new guerriero("Bersa ",200,200,0,25,0.05,0.10);
    personaggio*p7=new cavaliere("Bellin ",200,200,0,25,0.05,0.10);
    personaggio*p8=new esploratore("Paolo ",200,200,0,10,0.05,0.15);
    personaggio*p9=new guerriero("Parix ",200,200,0,10,0.15,0.05);
    personaggio*p10=new barbaro("Frenk ",200,200,0,100,0.15,0.15);
    personaggio*p11=new esploratore("FiveStarGiulio ",200,200,0,100,0.15,0.15);
    personaggio*p12=new assassino("Brazzale-Volante ",200,200,0,100,0.15,0.15);

    avversari.push_front(p12);
    avversari.push_front(p11);
    avversari.push_front(p10);
    avversari.push_front(p9);
    avversari.push_front(p8);
    avversari.push_front(p7);
    avversari.push_front(p6);
    avversari.push_front(p5);
    avversari.push_front(p4);
    avversari.push_front(p3);
    avversari.push_front(p2);
    avversari.push_front(p1);

    oggetto*mercante[51];
    mercante[0]=new mazza("Mazza Ferrata",4,10,10);
    mercante[1]=new mazza("Mazza Elfica",10,15,20);
    mercante[2]=new mazza("Stella del Mattino",20,25,32);
    mercante[3]=new mazza("Voldendrug",10,62,40);
    mercante[4]=new spada("Spada di Ferro",5,10,10);
    mercante[5]=new spada("Claíomh Solais",10,15,20);
    mercante[6]=new spada("Spada Glasson",20,30,35);
    mercante[7]=new spada("Marchio d'Oro",5,70,40);
    mercante[8]=new pugnale("Pugnale di Ferro",2,4,5);
    mercante[9]=new pugnale("Daga",3,12,12);
    mercante[10]=new pugnale("Kindijal",4,25,25);
    mercante[11]=new pugnale("Spina della Sofferenza",4,50,32);
    mercante[12]=new alabarda("Alabarda di Ferro",7,13,13);
    mercante[13]=new alabarda("Alabarda Eccelsa",12,25,25);
    mercante[14]=new alabarda("Naginata",18,32,32);
    mercante[15]=new alabarda("Guan dao",7,75,35);
    mercante[16]=new ascia("Ascia di Ferro",5,10,10);
    mercante[17]=new ascia("Scure d'Arcione",10,18,22);
    mercante[18]=new ascia("Skeggöx",22,28,33);
    mercante[19]=new ascia("Långyxa",10,60,42);
    mercante[20]=new lancia("Lancia di Ferro",5,12,12);
    mercante[21]=new lancia("Sarissa",10,25,22);
    mercante[22]=new lancia("Lancia di Lúg",15,30,30);
    mercante[23]=new lancia("Gungnir",5,70,35);
    mercante[24]=new armatura("Kastenbrust",20,15,20);
    mercante[25]=new armatura("Corazza da Battaglia",30,20,30);
    mercante[26]=new armatura("Cotta di Maglia",15,10,15);
    mercante[27]=new armatura("Usbergo",35,22,38);
    mercante[28]=new armatura("Armatura a piastre",40,25,40);
    mercante[29]=new armatura("Armatura della Vendetta",45,45,42);
    mercante[30]=new armatura("Armatura gotica",50,50,50);
    mercante[31]=new scudo("Scudo di Ferro",5,1.75,10,5,0.05);
    mercante[32]=new scudo("Pelta",10,1.75,20,12,0.12);
    mercante[33]=new scudo("Dhal",8,1.25,20,12,0.10);
    mercante[34]=new scudo("Oplon",18,1.25,25,15,0.08);
    mercante[35]=new scudo("Scutum",10,2.5,50,25,0.225);
    mercante[36]=new scudo("Scudo a Tre Punte",5,1.75,50,17.25,0.175);
    mercante[37]=new pozione("Pozione Vita +2",4,2,1);
    mercante[38]=new pozione("Pozione Vita +4",6,4,1);
    mercante[39]=new pozione("Pozione Vita +6",8,6,1);
    mercante[40]=new pozione("Pozione Vita +8",10,8,1);
    mercante[41]=new pozione("Pozione Vita +10",12,10,1);
    mercante[42]=new pozione("Pozione Vita +12",14,12,1);
    mercante[43]=new pozione("Pozione Vita +15",16,15,1);
    mercante[44]=new pozione("Pozione Energia +2",4,2,2);
    mercante[45]=new pozione("Pozione Energia +4",6,4,2);
    mercante[46]=new pozione("Pozione Energia +6",8,6,2);
    mercante[47]=new pozione("Pozione Energia +8",10,8,2);
    mercante[48]=new pozione("Pozione Energia +10",12,10,2);
    mercante[49]=new pozione("Pozione Energia +12",14,12,2);
    mercante[50]=new pozione("Pozione Energia +15",16,15,2);
    for(int i=0; i<51; i++)
    {
        aggiungiMercanzia(mercante[i]);
    }
    // Oggetti Per Avversari

    oggetto*pozioneAvversariVita[12];
    oggetto*pozioneAvversariEnergia[12];
    oggetto*armaturaAvversari[12];
    oggetto*armaAvversari[12];
    oggetto*scudoAvversari[12];

    // Pozione Vita per Avversari
    pozioneAvversariVita[0]=new pozione("Pozione Vita +2",4,2,1);
    pozioneAvversariVita[1]=new pozione("Pozione Vita +4",6,4,1);
    pozioneAvversariVita[2]=new pozione("Pozione Vita +6",8,6,1);
    pozioneAvversariVita[3]=new pozione("Pozione Vita +2",4,2,1);
    pozioneAvversariVita[4]=new pozione("Pozione Vita +4",6,4,1);
    pozioneAvversariVita[5]=new pozione("Pozione Vita +6",8,6,1);
    pozioneAvversariVita[6]=new pozione("Pozione Vita +2",4,2,1);
    pozioneAvversariVita[7]=new pozione("Pozione Vita +4",6,4,1);
    pozioneAvversariVita[8]=new pozione("Pozione Vita +6",8,6,1);
    pozioneAvversariVita[9]=new pozione("Pozione Vita +2",4,2,1);
    pozioneAvversariVita[10]=new pozione("Pozione Vita +4",6,4,1);
    pozioneAvversariVita[11]=new pozione("Pozione Vita +6",8,6,1);
    // Pozione Energia per Avversari
    pozioneAvversariEnergia[0]=new pozione("Pozione Energia +2",4,2,2);
    pozioneAvversariEnergia[1]=new pozione("Pozione Energia +4",6,4,2);
    pozioneAvversariEnergia[2]=new pozione("Pozione Energia +6",8,6,2);
    pozioneAvversariEnergia[3]=new pozione("Pozione Energia +2",4,2,2);
    pozioneAvversariEnergia[4]=new pozione("Pozione Energia +4",6,4,2);
    pozioneAvversariEnergia[5]=new pozione("Pozione Energia +6",8,6,2);
    pozioneAvversariEnergia[6]=new pozione("Pozione Energia +2",4,2,2);
    pozioneAvversariEnergia[7]=new pozione("Pozione Energia +4",6,4,2);
    pozioneAvversariEnergia[8]=new pozione("Pozione Energia +6",8,6,2);
    pozioneAvversariEnergia[9]=new pozione("Pozione Energia +2",4,2,2);
    pozioneAvversariEnergia[10]=new pozione("Pozione Energia +4",6,4,2);
    pozioneAvversariEnergia[11]=new pozione("Pozione Energia +6",8,6,2);
    // Armature per Avversari
    armaturaAvversari[0]=new armatura("Cotta di Maglia",15,10,15);
    armaturaAvversari[1]=new armatura("Cotta di Maglia",15,10,15);
    armaturaAvversari[2]=new armatura("Cotta di Maglia",15,10,15);
    armaturaAvversari[3]=new armatura("Cotta di Maglia",15,10,15);
    armaturaAvversari[4]=new armatura("Cotta di Maglia",15,10,15);
    armaturaAvversari[5]=new armatura("Usbergo",35,22,38);
    armaturaAvversari[6]=new armatura("Usbergo",35,22,38);
    armaturaAvversari[7]=new armatura("Usbergo",35,22,38);
    armaturaAvversari[8]=new armatura("Armatura a piastre",40,25,40);
    armaturaAvversari[9]=new armatura("Armatura della Vendetta",45,45,42);
    armaturaAvversari[11]=new armatura("Armatura gotica",50,50,50);
    // Armi per Avversari
    armaAvversari[0]=new ascia("Ascia di Ferro",5,10,10);
    armaAvversari[1]=new spada("Spada di Ferro",5,10,10);
    armaAvversari[2]=new mazza("Mazza Ferrata",4,10,10);
    armaAvversari[3]=new ascia("Scure d'Arcione",10,18,22);
    armaAvversari[4]=new ascia("Scure d'Arcione",10,18,22);
    armaAvversari[5]=new alabarda("Alabarda di Ferro",7,13,13);
    armaAvversari[6]=new alabarda("Alabarda Eccelsa",12,25,25);
    armaAvversari[7]=new pugnale("Kindijal",4,25,25);
    armaAvversari[8]=new ascia("Skeggöx",22,28,33);
    armaAvversari[9]=new lancia("Gungnir",5,70,35);
    armaAvversari[10]=new pugnale("Spina della Sofferenza",4,50,32);
    armaAvversari[11]=new ascia("Långyxa",10,60,42);
    // Scudi per Avversari
    scudoAvversari[0]=new scudo("Scudo di Ferro",5,1.75,10,5,0.05);
    scudoAvversari[1]=new scudo("Scudo di Ferro",5,1.75,10,5,0.05);
    scudoAvversari[2]=new scudo("Scudo di Ferro",5,1.75,10,5,0.05);
    scudoAvversari[3]=new scudo("Scudo di Ferro",5,1.75,10,5,0.05);
    scudoAvversari[4]=new scudo("Scudo di Ferro",5,1.75,10,5,0.05);
    scudoAvversari[5]=new scudo("Pelta",10,1.75,20,12,0.12);
    scudoAvversari[6]=new scudo("Dhal",8,1.25,20,12,0.10);
    scudoAvversari[7]=new scudo("Oplon",18,1.25,25,15,0.08);
    scudoAvversari[8]=new scudo("Scudo di Ferro",5,1.75,10,5,0.05);
    scudoAvversari[9]=new scudo("Pelta",10,1.75,20,12,0.12);
    scudoAvversari[10]=new scudo("Dhal",8,1.25,20,12,0.10);
    scudoAvversari[11]=new scudo("Oplon",18,1.25,25,15,0.08);
    for(int i=0; i<12; i++)
    {
        avversari[i]->equipaggiaArma(armaAvversari[i]);
        avversari[i]->equipaggiaArmatura(armaturaAvversari[i]);
        avversari[i]->equipaggiaScudo(scudoAvversari[i]);
        avversari[i]->equipaggiaPozioneVita(pozioneAvversariVita[i]);
        avversari[i]->equipaggiaPozioneEnergia(pozioneAvversariEnergia[i]);
    }
}

arenaSemplice::~arenaSemplice(){}

int arenaSemplice::testProbabilita() const
{
    double randomValue= qrand()% 100;
    if(randomValue <25)
        return 1;
    else
        if(randomValue<50)
            return 2;
        else
            if(randomValue<75)
                return 3;
            else
                return 4;
}

// Metodi di Ritorno Dati
bool arenaSemplice::getVittoriaArena() const{ return vittoriaArena; }

// Metodi di Modifica Dati
void arenaSemplice::VittoriaArena()
{
    if(getLivello()==12)
        vittoriaArena=true;
}

// Metodi Implementati da Arena
void arenaSemplice::combatti(int scelta)
{
    bool usaPozVita=false;
    if(inCombattimento())
    {
        if(((avversari[getLivello()]->getVitaMax()/3)>avversari[getLivello()]->getVitaAttuale())&&!usaPozVita)
        {
            scontro->svolgiTurno(scelta,5);
            usaPozVita=true;
        }
        else
        {
            if((avversari[getLivello()]->getEnergiaMax()/3)>avversari[getLivello()]->getEnergiaAttuale())
                scontro->svolgiTurno(scelta,6);
            else
            {
                scontro->svolgiTurno(scelta,testProbabilita());
            }
        }
    }
}
