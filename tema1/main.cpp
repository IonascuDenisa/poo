#include <iostream>
#include <utility>
using std::cout;
using std::endl;

class incapere
{
    std::string nume;
    float lungime,latime;
    friend class proprietar;
public:
     explicit incapere(std::string="hol",float=4 ,float=2);
    incapere(const incapere &);
    void afisare_arie() const;
    float arie() const;
    std::string get_nume();
    void schimbare_nume(std::string);
    incapere& operator=(incapere x);
};
void incapere::schimbare_nume(std::string n)
{
    nume=n;
}
incapere& incapere ::operator=(incapere x)
{
    if(this==&x)
        return *this;
    else
    {
        lungime=x.lungime;
        latime=x.latime;
    }
    return *this;
}
incapere::incapere(std::string nume ,float lungime ,float latime )
{
this->nume = std::move(nume);
this->lungime=lungime;
this->latime=latime;
}
incapere::incapere(const incapere &c)
{
    this->nume=c.nume;
    this->lungime = c.lungime;
    this->latime  = c.latime;
}
void incapere::afisare_arie() const
{
    cout<<endl<<"Aceasta incapere are "<<arie()<<" metrii patrati - ";
}
float incapere::arie() const
{
    return lungime*latime;
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
    adresa adr;
public:
    explicit proprietar(std::string ="Popescu",std::string="Ana-Maria",std::string ="601225412043", bool=true,std::string="30.01.2000" );
    proprietar(const proprietar& );
    std::string get_nume();
    std::string get_apelativ() const;
    void schimb_prenume(std::string);
    void schimb_cnp(std::string);
    void schimb_fm();
    friend std::ostream& operator<<(std::ostream &os , const proprietar &p);
    std::string get_data_achizitionare();
    std::string get_adresa();
    void afisare_adresa();
     ///

};
void proprietar::afisare_adresa()
{
    adr.afisare_adresa();
}
std::string proprietar::get_adresa()
{
    return adr.get_adresa();
}
std::string proprietar::get_data_achizitionare()
{
    return data_achizitionare;
}
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

class perioada
{
    std::string data1,data2;
public:
    perioada(std::string,std::string);
    perioada(std::string,proprietar&);
    static int rdn(int , int , int ) ;
    int durata();
};
int perioada::rdn(int y, int m, int d) { /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}
int perioada::durata() //data1=data curenta;data2=data achizitionare sau orice data din trecut
{
    std::string zi_curenta_string=data1.substr(0,2);
    int zi_curenta=std::stoi(zi_curenta_string);

    std::string luna_curenta_string=data1.substr(3,2);
    int luna_curenta=std::stoi(luna_curenta_string);

    std:: string an_curent_string=data1.substr(6,4);
    int an_curent=std::stoi(an_curent_string);

    std::string zi_achizitionare_string=data2.substr(0,2);
    int zi_achizitioare=std::stoi(zi_achizitionare_string);

    std::string luna_achizitionare_string=data2.substr(3,2);
    int luna_achizionare=std::stoi(luna_achizitionare_string);

    std:: string an_achizitionare_string=data2.substr(6,4);
    int an_achizitionare=std::stoi(an_achizitionare_string);

    int zile = rdn(an_curent, luna_curenta, zi_curenta) - rdn(an_achizitionare, luna_achizionare, zi_achizitioare);
    return zile;

}
perioada::perioada(std::string data1,proprietar &p)
{
    this->data1=data1;
    data2=p.get_data_achizitionare();
}
perioada::perioada(std::string data1,std::string data2)
{
    this->data1=data1;
    this->data2=data2;
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

std::ostream& operator<< (std::ostream &os,proprietar &p)
{
    os<<endl<<p.get_apelativ()<<p.get_nume()<<" are o locuinta la adresa "<<p.get_adresa();
    return os;
}

void afisare_durata_rotunjita(int zi)
{
    if(zi<30)
    {
        cout<<zi;
        if(zi>=20)
            cout<<" de";
        cout<<" zile ";
    }
    if((zi>=30) && zi < 365)
        cout<<zi/30<<" luni ";
    if(zi>=365)
    {
        cout<<zi/365;
        if((zi/365) >= 20 )
            cout<<" de";
        cout<<" ani";
    }

}

int main()
{
    proprietar Ana,Ion(Ana);
    adresa adIon;
    Ana.afisare_adresa();cout<<endl;
    Ion.schimb_prenume("Ion");
    Ion.schimb_cnp("5001109562301");
    Ion.schimb_fm();
    int nr_camere=4;
    incapere camera[nr_camere];
    camera[0]= incapere("sufragerie",5,4);
    camera[1]= incapere("dormitor1",4,3);
    camera[2]=camera[1]=camera[3];
    camera[2].schimbare_nume("dormitor2");
    camera[3].schimbare_nume("dormitor3");
    incapere hol("hol",4,2);
    incapere baie("baie",3,2);
    incapere bucatarie("bucatarie",3.5,2.5);
    incapere debara("debara",1,0.5);
    incapere balcon1("balcon",2,2);
    incapere balcon2(balcon1);
    balcon2.afisare_arie();
    cout<<balcon2.get_nume()<<endl;
    perioada Ana_timp("31.10.2020",Ana);
    int zile= Ana_timp.durata();
    cout<<Ana<<" de ";afisare_durata_rotunjita(zile);cout<<"\n";
    cout<<Ion<<" cu o sufragerie de "<<camera[0].arie()<<" de metrii patrati";

    return 0;
}
