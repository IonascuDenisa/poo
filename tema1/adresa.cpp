//
// Created by mihaela on 18.12.2020.
//

#include <fstream>
#include "adresa.h"
void adresa::citire_adresa(std::ifstream &f)
{
    //std::ifstream f("date.txt");
    f>>strada >>numar >>bloc >>etaj >>apartament >>interfon >>oras>>judet;
}
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
    this->apartament = a.apartament;
    this->interfon = a.interfon;
    this->oras = a.oras;
    this->judet = a.judet;
}

void adresa::afisare_adresa() {
    cout << "Adresa introdusa este: strada " << strada << ", numarul " << numar << ", blocul " << bloc << ", etajul ";
    cout << etaj << ", apartament" << apartament << ", interfon" << interfon << ", " << oras << "," << judet;
}

std::string adresa::get_adresa() {
    std::string adres = "Strada " + strada + ", numarul " + std::to_string(numar) + ", blocul " + bloc;
    adres = adres + ", aparatment " + std::to_string(apartament) + ", interfon " + interfon + " " + oras + "," + judet;
    return adres;
}

std::ostream &operator<<(std::ostream &os, const adresa &adresa) {
    os << "strada: " << adresa.strada << " numar: " << adresa.numar << " bloc: " << adresa.bloc << " etaj: "
       << adresa.etaj << " apartament: " << adresa.apartament << " interfon: " << adresa.interfon << " oras: "
       << adresa.oras << " judet: " << adresa.judet;
    return os;
}
