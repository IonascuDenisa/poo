#include <iostream>
#include <utility>
using std::cout;
using std::endl;

class incapere
{
    std::string nume;
    float Lu,l;
    friend class proprietar;
public:
     explicit incapere(std::string="hol",float=4 ,float=2);
    incapere(const incapere &);
    void afisare_arie() const;
    float arie() const;
    std::string get_nume();
};

incapere::incapere(std::string nume ,float Lu ,float l )
{
this->nume = std::move(nume);
this->Lu=Lu;
this->l=l;
}
incapere::incapere(const incapere &c)
{
    this->nume=c.nume;
    this->Lu = c.Lu;
    this->l  = c.l;
}
void incapere::afisare_arie() const
{
    cout<<endl<<"Aceasta incapere are "<<Lu*l<<" metrii patrati"<<endl;
}
float incapere::arie() const
{
    return Lu*l;
}
std::string incapere::get_nume()
{
    return nume+" ";
}

class adresa
{
    std::string strada;
    int numar;
    std::string bloc;
    int etaj;
    int apartament;
    std::string interfon;
    std::string oras;
    std::string judet;
    friend class proprietar;
public:
    explicit adresa(std::string="Unirii" ,int =23,std::string="M4 bis" ,int=4 ,int=132 ,std::string="0132",std::string="Bucuresti" ,std::string ="Sector3");
    adresa(const adresa& );
    void afisare_adresa();
    std::string get_adresa();

};

adresa::adresa(std::string strada,int numar,std::string bloc,int etaj,int apartament,
        std::string interfon,std::string oras,std::string judet)
{
this->strada=strada;
this->numar=numar;
this->bloc=bloc;
this->etaj=etaj;
this->apartament=apartament;
this->interfon=interfon;
this->oras=oras;
this->judet=judet;
}
adresa::adresa(const adresa& a)
{
    this->strada=a.strada;
    this->numar=a.numar;
    this->bloc=a.bloc;
    this->etaj=a.etaj;
    this->apartament=a.apartament;
    this->interfon=a.interfon;
    this->oras=a.oras;
    this->judet=a.judet;
}
void adresa:: afisare_adresa()
{
    cout<<"Adresa introdusa este: strada "<<strada<<", numarul "<<numar<<", blocul "<<bloc<<", etajul ";
    cout<<etaj<<", apartament"<<apartament<<", interfon"<<interfon<<", "<<oras<<","<<judet;
}
std::string adresa :: get_adresa()
{
    std::string adres="Strada "+strada+", numarul "+std::to_string(numar)+", blocul "+bloc;
    adres=adres+", aparatment "+std::to_string(apartament)+", interfon "+interfon+" "+oras+","+judet;
    return adres;
}

class proprietar
{
    std::string nume;
    std::string prenume;
    std::string cnp;
    bool fm;
    std::string data_achizitionare;
public:
    explicit proprietar(std::string ="Popescu",std::string="Ana-Maria",std::string ="601225412043", bool=true,std::string="30.01.2000" );
    proprietar(const proprietar& );
    std::string get_nume();
    static int rdn(int , int , int ) ;
    int durata(std::string );
    std::string get_apelativ() const;
    void schimb_prenume(std::string);
    void schimb_cnp(std::string);
    void schimb_fm();

};

proprietar::proprietar(std::string nume,std::string prenume,std::string cnp,
                        bool fm,std::string data_achizitionare)
{
this->nume=nume;
this->prenume=prenume;
this->cnp=cnp;
this->fm=fm;
this->data_achizitionare=data_achizitionare;
}
proprietar::proprietar(const proprietar& Ana)
{
    this->nume=Ana.nume;
    this->prenume=Ana.prenume;
    this->cnp=Ana.cnp;
    this->fm=Ana.fm;
    this->data_achizitionare=Ana.data_achizitionare;
}
std::string proprietar :: get_nume()
{
    return nume+" "+prenume;
}
int proprietar::rdn(int y, int m, int d) { /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}
int proprietar::durata(std::string data_curenta)
{
    std::string zi_curenta_string=data_curenta.substr(0,2);
    int zi_curenta=std::stoi(zi_curenta_string);

    std::string luna_curenta_string=data_curenta.substr(3,2);
    int luna_curenta=std::stoi(luna_curenta_string);

    std:: string an_curent_string=data_curenta.substr(6,4);
    int an_curent=std::stoi(an_curent_string);

    std::string zi_achizitionare_string=data_achizitionare.substr(0,2);
    int zi_achizitioare=std::stoi(zi_achizitionare_string);

    std::string luna_achizitionare_string=data_achizitionare.substr(3,2);
    int luna_achizionare=std::stoi(luna_achizitionare_string);

    std:: string an_achizitionare_string=data_achizitionare.substr(6,4);
    int an_achizitionare=std::stoi(an_achizitionare_string);

    int zile = rdn(an_curent, luna_curenta, zi_curenta) - rdn(an_achizitionare, luna_achizionare, zi_achizitioare);
    return zile;

}
void proprietar::schimb_prenume(std::string prenume2)
{
    this->prenume=prenume2;
}
void proprietar::schimb_cnp(std::string cnp2)
{
    this->cnp=cnp2;
}
void proprietar:: schimb_fm()
{
    this->fm=!fm;
}
std::string proprietar::get_apelativ() const
{
    return (fm) ? "Doamna " : "Domnul ";
}

int main()
{
    proprietar Ana,Ion(Ana);
    adresa adAna,adIon(adAna);
    adAna.afisare_adresa();
    Ion.schimb_prenume("Ion");
    Ion.schimb_cnp("5001109562301");
    Ion.schimb_fm();
    int nr_camere=3;
    incapere camera[nr_camere];
    camera[0]= incapere("sufragerie",5,4);
    camera[1]= incapere("dormitor1",4,3);
    camera[2]= incapere("dormitor2",3.5,3);
    incapere hol("hol",4,2);
    incapere baie("baie",3,2);
    incapere bucatarie("bucatarie",3.5,2.5);
    incapere debara("debara",1,0.5);
    incapere balcon1("balcon",2,2);
    incapere balcon2(balcon1);
    balcon2.afisare_arie();
    cout<<balcon2.get_nume();
    int zile= Ana.durata("31.10.2020");
    if(zile<30)
        cout<<endl<<Ana.get_apelativ()<<Ana.get_nume()<<"are locuinta de la adresa "<<adAna.get_adresa()<<" de "<<zile<<" zile"<<endl;
    if((zile>=30) && zile < 365)
        cout<<endl<<Ana.get_apelativ()<<Ana.get_nume()<<"are locuinta de la adresa "<<adAna.get_adresa()<<" de "<<zile/30<<" luni"<<endl;
    if(zile>=365)
        cout<<endl<<Ana.get_apelativ()<<Ana.get_nume()<<" are locuinta de la adresa "<<adAna.get_adresa()<<" de "<<zile/365<<" ani"<<endl;
    cout<<endl<<Ion.get_apelativ()<<Ion.get_nume()<<"are o locuinta la adresa "<<adIon.get_adresa()<<"cu o sufragerie de "<<camera[0].arie()<<" de metrii patrati";

    return 0;
}