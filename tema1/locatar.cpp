//
// Created by mihaela on 18.12.2020.
//

#include "locatar.h"
#include <fstream>
using std::cout;
using std::endl;

std::ostream& operator<<(std::ostream &os , locatar &p)
{
    os<<endl<<p.get_apelativ()<<p.get_nume();
    return os;
}
void locatar::citiref(std::ifstream &f)
{
    f>>prenume>>nume>>cnp>>fm;
}
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
void locatar::schimb_prenume(std::string &prenume2)
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
