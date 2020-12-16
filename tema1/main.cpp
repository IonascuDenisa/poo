#include <iostream>
#include <vector>
#include <utility>
using std::cout;
using std::endl;

///INCAPERE
class incapere
{
protected:
    std::string nume;
    float lungime,latime;
    friend class locatar;
public:
     explicit incapere(std::string="hol",float=4 ,float=2);
    incapere(const incapere &);
    void afisare_arie() const;
    float arie() const;
    std::string get_nume();
    void schimbare_nume(std::string);
    incapere& operator=(incapere x);
    friend std::ostream& operator<<(std::ostream &os , const incapere &i);
};
std::ostream& operator<< (std::ostream &os,incapere &i)
{
    os<<endl<<i.get_nume()<<" cu "<<i.arie() <<" metrii patrati";
    return os;
}
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

///ADRESA
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
    friend class locatar;
public:
    explicit adresa(std::string="Unirii" ,int =23,std::string="M4 bis" ,int=4 ,int=132 ,std::string="0132",std::string="Bucuresti" ,std::string ="Sector3");
    adresa(const adresa& );
    void afisare_adresa();
    std::string get_adresa();

};
adresa::adresa(std::string strada,int numar,std::string bloc,int etaj,int apartament,std::string interfon,std::string oras,std::string judet)
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

/// LOCATAR
class locatar
{
protected:
    std::string nume;
    std::string prenume;
    std::string cnp;
    bool fm;

public:
    explicit locatar(std::string ="Popescu",std::string="Ana-Maria",std::string ="601225412043", bool=true );
    locatar(const locatar& );
    std::string get_nume();
    std::string get_apelativ() const;
    void schimb_prenume(std::string);
    void schimb_cnp(std::string);
    void schimb_fm();
    friend std::ostream& operator<<(std::ostream &os , const locatar &p);

    std::string get_adresa();
    void afisare_adresa();

};
void locatar::afisare_adresa()
{
    //adr.afisare_adresa();
}
std::string locatar::get_adresa()
{
    return "adresa";
}
locatar::locatar(std::string nume,std::string prenume,std::string cnp,bool fm)
{
    this->nume=nume;
    this->prenume=prenume;
    this->cnp=cnp;
    this->fm=fm;
}
locatar::locatar(const locatar& Ana)
{
    this->nume=Ana.nume;
    this->prenume=Ana.prenume;
    this->cnp=Ana.cnp;
    this->fm=Ana.fm;

}
std::string locatar :: get_nume()
{
    return prenume+" "+nume;
}
void locatar::schimb_prenume(std::string prenume2)
{
    this->prenume=prenume2;
}
void locatar::schimb_cnp(std::string cnp2)
{
    this->cnp=cnp2;
}
void locatar:: schimb_fm()
{
    this->fm=!fm;
}
std::string locatar::get_apelativ() const
{
    return (fm) ? "Doamna " : "Domnul ";
}

class costuri_locatar
{
    int pret_curent;
    int pret_intretinere;
    int pret_gaze;
    int pret_tv_net;
    int pret_chirie;
};

///PERIOADA
class perioada
{
    std::string data1,data2;
    std::string data3="16.12.2020";

public:
    perioada(std::string="12.02.2012",std::string="16.07.2015");
    //perioada(std::string="22.11.2018",int=2);
    static int rdn(int , int , int ) ;
    int durata();
    int durata(std::string,std::string);
    void set_data2(std::string);
    //friend class chirias;
    void afisare_dat();
    void afisare_durata_rotunjita(int);
    void timp_chirie();
    void timp_proprietar();

};
void perioada::timp_proprietar()
{
    int x=durata();
    cout<<"proprietate personala de ";afisare_durata_rotunjita(x);
}
void perioada::timp_chirie()
{
    int x=durata(data3,data1);
    int y=durata(data2,data3);
    cout<<"inchiriat de ";afisare_durata_rotunjita(x);
    if(y>=0)
    {
        cout<<" si va mai locui inca "; afisare_durata_rotunjita(y);
    }
    else cout<<" pe o perioada nederminata";
}
void perioada::afisare_durata_rotunjita(int zi)
{
    if(zi<30)
    {
        if(zi>=20)
            cout<<" de";
        if(zi>1 && zi<20)
            cout<<" zile ";
        if(zi==1)
            cout<<"o zi";
        if(zi==0)
            cout<<" nici o zi ";
    }
    if((zi>=30) && zi < 365)
        if((zi/30)==1)
            cout<<"o luna";
        else
            cout<<zi/30<<" luni ";
    if(zi>=365)
    {
        cout<<zi/365;
        if((zi/365) >= 20 )
            cout<<" de";
        if((zi/365)==1)
            cout<<" an";
        else
            cout<<" ani";
    }

}
void perioada::afisare_dat() {cout<<"marinela"<<data1<<" "<<data2<<" "<<"data curenta este:"<<data3;}
void perioada::set_data2(std::string d)
{
    data2=d;
}
int perioada::rdn(int y, int m, int d) { // Rata Die day one is 0001-01-01
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}
int perioada::durata(std::string data3, std::string data1)
{
    std::string zi_data3_string=data3.substr(0,2);
    int zi_data3=std::stoi(zi_data3_string);

    std::string luna_data3_string=data3.substr(3,2);
    int luna_data3=std::stoi(luna_data3_string);

    std:: string an_data3_string=data3.substr(6,4);
    int an_data3=std::stoi(an_data3_string);

    std::string zi_data1_string=data1.substr(0,2);
    int zi_data1=std::stoi(zi_data1_string);

    std::string luna_data1_string=data1.substr(3,2);
    int luna_data1=std::stoi(luna_data1_string);

    std:: string an_data1_string=data1.substr(6,4);
    int an_data1=std::stoi(an_data1_string);

    int zile = rdn(an_data3, luna_data3, zi_data3) - rdn(an_data1, luna_data1, zi_data1);
    return zile;
}
int perioada::durata()
{
    std::string zi_data3_string=data3.substr(0,2);
    int zi_data3=std::stoi(zi_data3_string);

    std::string luna_data3_string=data3.substr(3,2);
    int luna_data3=std::stoi(luna_data3_string);

    std:: string an_data3_string=data3.substr(6,4);
    int an_data3=std::stoi(an_data3_string);

    std::string zi_data1_string=data1.substr(0,2);
    int zi_data1=std::stoi(zi_data1_string);

    std::string luna_data1_string=data1.substr(3,2);
    int luna_data1=std::stoi(luna_data1_string);

    std:: string an_data1_string=data1.substr(6,4);
    int an_data1=std::stoi(an_data1_string);

    int zile = rdn(an_data3, luna_data3, zi_data3) - rdn(an_data1, luna_data1, zi_data1);
    return zile;
}
perioada::perioada(std::string data1,std::string data2)
{
    this->data1=data1;
    this->data2=data2;
}

///PROPRIETAR
class proprietar:public locatar
{
    std::string data_achizitionare;
    perioada p;
public:
    proprietar(std::string ="Popescu",std::string="Ana-Maria",std::string ="601225412043", bool=true,std::string="16.12.2020");
    proprietar(const proprietar& );
    std::string get_data_achizitionare();
    void afi();
    void setp();
    void timp();

};
void proprietar::timp()
{
    p.timp_proprietar();
}
void proprietar::setp()
{
    perioada s(data_achizitionare,"0000");
    p=s;
}
void proprietar::afi()
{
    p.afisare_dat() ;
}
proprietar::proprietar(const proprietar &Ana):locatar(Ana)
{
    this->data_achizitionare=Ana.data_achizitionare;
}
proprietar::proprietar(std::string nume,std::string prenume,std::string cnp,bool fm,std::string data_achizitionare):locatar(nume,prenume,cnp,fm)
{
    this->data_achizitionare=data_achizitionare;
    //p.set_data2(get_data_achizitionare);

}
std::string proprietar::get_data_achizitionare()
{
    return data_achizitionare;
}

///CHIRIAS
class chirias :public locatar
{
    std::string inceputul_inchirierii;
    std::string sfarsitul_inchirierii;
    perioada p;
public:
    chirias(std::string ="Snow",std::string="John",std::string ="601225412043", bool=false,std::string="30.01.2011",std::string="17.12.2020");
    chirias(const chirias& );
    std::string get_inceputul_inchirierii();
    std::string get_sfarsitul_inchirierii();
    void setp();
    void timp();


};
void chirias::timp()
{
    p.timp_chirie();
}
void chirias::setp()
{
    perioada s(inceputul_inchirierii,sfarsitul_inchirierii);
    p=s;
}
std::string chirias:: get_inceputul_inchirierii()
{
    return inceputul_inchirierii;
}
std::string chirias:: get_sfarsitul_inchirierii()
{
    return sfarsitul_inchirierii;
}
chirias::chirias(const chirias &Ana):locatar(Ana)
{
    this->inceputul_inchirierii=Ana.inceputul_inchirierii;
    this->sfarsitul_inchirierii=sfarsitul_inchirierii;
}
chirias::chirias(std::string nume,std::string prenume,std::string cnp,bool fm,std::string inceputul_inchirierii,std::string sfarsitul_inchirierii):locatar(nume,prenume,cnp,fm)
{
    this->inceputul_inchirierii=inceputul_inchirierii;
    this->sfarsitul_inchirierii=sfarsitul_inchirierii;

}


///LOCUINTA
class locuinta
{
    adresa a;
    std::vector<incapere>incaperi;
    std::vector<locatar>oameni;
public:
    void add_incaperi(incapere);
    void add_oameni(locatar);
    void afisare_incaperi();
};
void locuinta::add_oameni(locatar om)
{
    oameni.push_back(om);
}
void locuinta::add_incaperi(incapere i)
{
    incaperi.push_back(i);
}
void locuinta::afisare_incaperi()
{
    for(auto &it:incaperi)
    {
        cout<<it<<endl;
    }
}
std::ostream& operator<< (std::ostream &os,locatar &p)
{
    os<<endl<<p.get_apelativ()<<p.get_nume()<<" are o locuinta la adresa "<<p.get_adresa();
    return os;
}

int main()
{
    proprietar Ana;
    chirias Ion;
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
    locuinta L;
    L.add_incaperi(camera[0]);
    L.add_incaperi(camera[2]);
    L.afisare_incaperi();
    balcon2.afisare_arie();
    cout<<balcon2.get_nume()<<endl;
    /*perioada Ana_timp("31.10.2020",Ana);
    int zile= Ana_timp.durata();
    cout<<Ana<<" de ";afisare_durata_rotunjita(zile);cout<<"\n";
    cout<<Ion<<" cu o sufragerie de "<<camera[0].arie()<<" de metrii patrati";
*/


    return 0;
}


