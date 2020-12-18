//
// Created by mihaela on 18.12.2020.
//

#include "incapere.h"
#include <fstream>
using std::cout;
using std::endl;
void incapere::citiref(std::ifstream &f)
{
    f>>nume>>lungime>>latime;
}

std::ostream &operator<<(std::ostream &os, incapere i) {
    os<<endl<<i.get_nume()<<" cu "<<i.arie() <<" metrii patrati";
    return os;
}

void incapere::schimbare_nume(std::string &n)
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

