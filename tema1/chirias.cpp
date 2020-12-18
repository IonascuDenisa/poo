//
// Created by mihaela on 18.12.2020.
//

#include "chirias.h"
#include <fstream>

void chirias::citiref(std::ifstream &f)
{
    locatar::citiref(f);
    f>>inceputul_inchirierii;
    f>>sfarsitul_inchirierii;
    f>>chirie;
}
void chirias::timp()
{
    setp();
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
    this->sfarsitul_inchirierii=Ana.sfarsitul_inchirierii;
    this->chirie=Ana.chirie;
}
chirias::chirias(std::string nume,std::string prenume,std::string cnp,bool fm,std::string inceputul_inchirierii,std::string sfarsitul_inchirierii,int chirie):locatar(nume,prenume,cnp,fm)
{
    this->inceputul_inchirierii=inceputul_inchirierii;
    this->sfarsitul_inchirierii=sfarsitul_inchirierii;
    this->chirie=chirie;

}

