//
// Created by mihaela on 18.12.2020.
//

#include "proprietar.h"
#include <fstream>

void proprietar::citiref(std::ifstream &f)
{
    locatar::citiref(f);
    f>>data_achizitionare;
}
void proprietar::timp()
{
    setp();
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